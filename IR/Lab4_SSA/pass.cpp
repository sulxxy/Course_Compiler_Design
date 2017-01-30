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

    printResults(F);
    return false;
  }

  void visitPHINode(PHINode &Phi) {
    // TODO
  }

  void visitBinaryOperator(Instruction &I) {
    // TODO
    // Hint: ConstExpr::get()
  }

  void visitCmpInst(CmpInst &I) {
    // TODO
    // Hint: ConstExpr::getCompare()
  }

  void visitCastInst(CastInst &I) {
    // TODO
    // Hint: ConstExpr::getCast()
  }

  void visitInstruction(Instruction &I) {
    // TODO Fallback case
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
