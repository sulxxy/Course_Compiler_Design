/* Name Surname */

#include <llvm/Pass.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/InstVisitor.h>
#include <llvm/IR/CFG.h>
#include <llvm/IR/InstIterator.h>
#include <llvm/IR/Constants.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/ADT/DenseSet.h>
#include <llvm/ADT/APFloat.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

namespace {

/* Represents state of a single Value. There are three possibilities:
 *  * undefined: Initial state. Unknown whether constant or not.
 *  * constant: Value is constant.
 *  * overdefined: Value is not constant. */
class State {
public:
    State() : Kind(UNDEFINED), Const(nullptr) {}

    bool isOverdefined() const { return Kind == OVERDEFINED; }
    bool isUndefined() const { return Kind == UNDEFINED; }
    bool isConstant() const { return Kind == CONSTANT; }
    Constant *getConstant() const {
        assert(isConstant());
        return Const;
    }

    void markOverdefined() { Kind = OVERDEFINED; }
    void markUndefined() { Kind = UNDEFINED; }
    void markConstant(Constant *C) {
        Kind = CONSTANT;
        Const = C;
    }

    void print(raw_ostream &O) const {
        switch (Kind) {
        case UNDEFINED: O << "undefined"; break;
        case OVERDEFINED: O << "overdefined"; break;
        case CONSTANT: O << "const " << *Const; break;
        }
    }

private:
    enum {
        OVERDEFINED,
        UNDEFINED,
        CONSTANT
    } Kind;
    Constant *Const;
};

raw_ostream &operator<<(raw_ostream &O, const State &S) {
    S.print(O);
    return O;
}

class ConstPropPass : public FunctionPass, public InstVisitor<ConstPropPass> {
public:
    static char ID;
    ConstPropPass() : FunctionPass(ID) {}

    virtual void getAnalysisUsage(AnalysisUsage &au) const {
        au.setPreservesAll();
    }

    virtual bool runOnFunction(Function &F) {
        // TODO Implement constant propagation
        bool change_flag = true;
        while(change_flag){
            change_flag = false;
            for(BasicBlock& bb : F){
                for(Instruction &i : bb){
                    State i_pre_status = getValueState(&i);
                    visit(i);
                    if(!state_equals(i_pre_status, getValueState(&i))){
                        change_flag = true;
                    }
                }
            }
        }

        printResults(F);
        return false;
    }


    void visitPHINode(PHINode &Phi) {
        // TODO
        State ret_state = State();
        int constant_operand_count = 0;
        Constant* previous_const;
        for(PHINode::block_iterator begin=Phi.block_begin(); begin != Phi.block_end(); begin++){
            Value* v = Phi.getIncomingValueForBlock(*begin);
            State operand_state = getValueState(v);
            //errs() << *v << "\n";
            if(operand_state.isOverdefined()){
                ret_state.markOverdefined();
                StateMap.erase(&Phi);
                StateMap.insert({&Phi, ret_state});
                return ;
            }
            if(operand_state.isConstant()){
                if(0 == constant_operand_count){
                    previous_const = operand_state.getConstant();
                }
                constant_operand_count++;
                if(constant_operand_count >=2 && !constant_equals(previous_const, operand_state.getConstant())){
                    ret_state.markOverdefined();
                    StateMap.erase(&Phi);
                    StateMap.insert({&Phi, ret_state});
                    return ;
                }
                previous_const = operand_state.getConstant();
            }
        }
        if(constant_operand_count >= 1){
            ret_state.markConstant(previous_const);
            StateMap.erase(&Phi);
            StateMap.insert({&Phi, ret_state});
            return ;
        }
        ret_state.markUndefined();
        StateMap.erase(&Phi);
        StateMap.insert({&Phi, ret_state});
        //errs() << "DEBUG: This is PHI\n";
    }

    bool state_equals(State s1, State s2){
        if(s1.isOverdefined() && s2.isOverdefined()){
            return true;
        }
        if(s1.isUndefined() && s2.isUndefined()){
            return true;
        }
        if(s1.isConstant() && s2.isConstant()){
            if(constant_equals(s1.getConstant(),s2.getConstant())){
                return true;
            }
        }
        return false;
    }

    bool constant_equals(Constant *c1, Constant *c2){
        if(ConstantInt* CI1 = dyn_cast<ConstantInt>(c1)){
            if(ConstantInt* CI2 = dyn_cast<ConstantInt>(c2)){
                if(CI1->getSExtValue() == CI2->getSExtValue()){
                    return true;
                }
            }
        }
        if(ConstantFP* CF1 = dyn_cast<ConstantFP>(c1)){
            if(ConstantFP* CF2 = dyn_cast<ConstantFP>(c2)){
                if(CF1->getValueAPF().compare(CF2->getValueAPF()) == APFloat::cmpEqual){
                    return true;
                }
            }
        }
        return false;
    }

    void visitBinaryOperator(Instruction &I) {
        // TODO
        // Hint: ConstExpr::get()

        Value* operand0 = I.getOperand(0);
        Value* operand1 = I.getOperand(1);
        unsigned opcode = I.getOpcode();
        State ret_state = State();
        //errs() << "DEBUG: This is Operator\n";
        if(getValueState(operand0).isOverdefined() || getValueState(operand1).isOverdefined()){
            ret_state.markOverdefined();
            StateMap.erase(&I);
            StateMap.insert({&I, ret_state});
            return ;
        }
        if(getValueState(operand0).isUndefined() || getValueState(operand1).isUndefined()){
            ret_state.markUndefined();
            StateMap.erase(&I);
            StateMap.insert({&I, ret_state});
            return ;
        }
        if(getValueState(operand0).isConstant() && getValueState(operand1).isConstant()){
            Constant* ret_const = ConstantExpr::get(opcode, getValueState(operand0).getConstant(), getValueState(operand1).getConstant());
            ret_state.markConstant(ret_const);
            StateMap.erase(&I);
            StateMap.insert({&I, ret_state});
            return ;
        }
        /*if(Constant* bo = dyn_cast<Constant>(operand0)){
            errs() << "DEBUG: This is Constant Operator\n";
        }
        else{
            errs() << "DEBUG: This is Operator\n";
        }*/
    }

    void visitCmpInst(CmpInst &I) {
        // TODO
        // Hint: ConstExpr::getCompare()
        Value* operand0 = I.getOperand(0);
        Value* operand1 = I.getOperand(1);
        unsigned short pred = I.getPredicate();
        State ret_state = State();
        //errs() << "DEBUG: This is Cmp\n";
        if(getValueState(operand0).isOverdefined() || getValueState(operand1).isOverdefined()){
            ret_state.markOverdefined();
            StateMap.erase(&I);
            StateMap.insert({&I, ret_state});
            return ;
        }
        if(getValueState(operand0).isUndefined() || getValueState(operand1).isUndefined()){
            ret_state.markUndefined();
            StateMap.erase(&I);
            StateMap.insert({&I, ret_state});
            return ;
        }
        if(getValueState(operand0).isConstant() && getValueState(operand1).isConstant()){
            Constant* ret_const = ConstantExpr::getCompare(pred, getValueState(operand0).getConstant(), getValueState(operand1).getConstant());
            ret_state.markConstant(ret_const);
            StateMap.erase(&I);
            StateMap.insert({&I, ret_state});
            return ;
        }
    }

    void visitCastInst(CastInst &I) {
        // TODO
        // Hint: ConstExpr::getCast()
        //errs() << "DEBUG: This is Cast\n";
        Value* operand0 = I.getOperand(0);
        //Value* operand1 = I.getOperand(1);
        unsigned short opcode = I.getOpcode();
        State ret_state = State();
        if(getValueState(operand0).isOverdefined() ){
            ret_state.markOverdefined();
            StateMap.erase(&I);
            StateMap.insert({&I, ret_state});
            return ;
        }
        if(getValueState(operand0).isUndefined() ){
            ret_state.markUndefined();
            StateMap.erase(&I);
            StateMap.insert({&I, ret_state});
            return ;
        }
        if(getValueState(operand0).isConstant() ){
            Constant* ret_const = ConstantExpr::getCast(opcode, getValueState(operand0).getConstant(), I.getDestTy());
            ret_state.markConstant(ret_const);
            StateMap.erase(&I);
            StateMap.insert({&I, ret_state});
            return ;
        }
    }

    void visitInstruction(Instruction &I) {
        // TODO Fallback case
        State ret_state = State();
        ret_state.markOverdefined();
        StateMap.erase(&I);
        StateMap.insert({&I, ret_state});
        //errs() << "DEBUG: This is others\n";
    }

private:
  /* Gets the current state of a Value. This method also lazily
   * initializes the state if there is no entry in the StateMap
   * for this Value yet. The initial value is CONSTANT for
   * Constants and UNDEFINED for everything else. */
    State &getValueState(Value *Val) {
        auto It = StateMap.insert({ Val, State() });
        State &S = It.first->second;

        if (!It.second) {
        // Already in map, return existing state
            return S;
        }

        if (Constant *C = dyn_cast<Constant>(Val)) {
        // Constants are constant...
            S.markConstant(C);
        }

        if (Argument *C = dyn_cast<Argument>(Val)) {
        // Function argument
            //errs() << "DEBUG: This is a function argument\n";
            S.markOverdefined();
        }

        // Everything else is undefined (the default)
        return S;
        }

    /* Print the final result of the analysis. */
    void printResults(Function &F) {
        for (BasicBlock &BB : F) {
            for (Instruction &I : BB) {
                State S = getValueState(&I);
                errs() << I << "\n    -> " << S << "\n";
            }
        }
    }

    // Map from Values to their current State
    DenseMap<Value *, State> StateMap;
    // Worklist of instructions that need to be (re)processed
    SmallVector<Value *, 64> WorkList;
};

}

// Pass registration
char ConstPropPass::ID = 0;
static RegisterPass<ConstPropPass> X("const-prop-pass", "Constant propagation pass");
