/**
 * Course 703626 - University of Innsbruck, Austria
 * Advanced Compiler Design, Fortgeschrittener Compilerbau (ProSeminar)
 * Sommersemester 2014
 * Lecturer: Ph.D. Biagio Cosenza
 */

#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Analysis/CFG.h>
#include <llvm/ADT/ValueMap.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Instructions.h>

using namespace llvm;

namespace {

class MyFunctionPass  : public FunctionPass {
public:
    static char ID;
    MyFunctionPass  () : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F) {
        errs().write_escaped(F.getName()) << '\n';

        // iterate arguments
        errs() << " - args:" << '\n';
        for(Argument &a : F.getArgumentList()){
            errs() << "   - ";
            errs().write_escaped(a.getName()) << '\n';
        }

        // iterate BB in a function
        /*errs() << " - Seq blocks:" << '\n';
        for(BasicBlock &b : F.getBasicBlockList()){
            errs() << "====" << '\n';
            for(Instruction &i : b){
                i.print(errs());
                errs() << '\n';
            }
            errs() << '\n';
        }*/
        errs() << " - Graph blocks:" << '\n';
        for(BasicBlock &b : F.getBasicBlockList()){
            errs() << "=================" << '\n';
            //TODO: calculate IN[b] and OUT[b]
            calculateOUT(b);

            //Traverse the successors
            for(succ_iterator PI=succ_begin(&b), E = succ_end(&b); PI != E; PI++){
                BasicBlock *t = *PI;
                //TODO: detect uses without definition
                /*for(Instruction &i : *t){
                    i.print(errs());
                    errs() << '\n';
                }*/
            }
            errs() << '\n';
        }
        errs() << '\n';
        return false;
    }

private:
    ValueMap<Value*, int>  valueMap;

    void calculateOUT(BasicBlock &bb){
        int flag = 0;
        for(Instruction &i : bb){
            if( AllocaInst* ai = dynamic_cast<AllocaInst*>(&i) ){
                errs() << "======Allocate=======" << '\n';
                ai->print(errs());
                errs() << "\nName: "<< ai->getName() << '\n';
                std::pair<Value*, int> tmp = std::pair<Value*, int>(ai, 9);
                valueMap.insert(tmp);
            }
            else if( StoreInst* si = dynamic_cast<StoreInst*>(&i) ){
                errs() << "======Store=======" << '\n';
                si->print(errs());
                errs() << "\nOperand: "<< *(si->getPointerOperand()) << '\n';
                errs() << "Operand Name: "<< si->getPointerOperand()->getName() << '\n';
                std::pair<Value*, int> tmp = std::pair<Value*, int>(si->getPointerOperand(), 1);
                valueMap.erase(si->getPointerOperand());
                valueMap.insert(tmp);
            }
            else if( LoadInst* li = dynamic_cast<LoadInst*>(&i) ){
                errs() << "======Load=======" << '\n';
                li->print(errs());
                errs() << "\nOperand: "<< *(li->getPointerOperand()) << '\n';
                errs() << "Operand Name: "<< li->getPointerOperand()->getName() << '\n';
                errs() << "Lookup Value: " << valueMap.lookup(li->getPointerOperand()) << '\n' << "Size: " << valueMap.size() << '\n';

            }
            else{

            }
        }
    }
};
} // namespace

char MyFunctionPass::ID = 0;
static RegisterPass<MyFunctionPass> X("function-pass", "Function Pass");

