/* First-Name Last-Name Matr-No */

/* TODO: Add a short explanation of your algorithm here.
 * E.g., if you use iterative data-flow analysis, write down
 * the used gen/kill sets and flow-equations here. */

// Include some headers that might be useful
#include <llvm/Pass.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/Analysis/CFG.h>
//#include <llvm/IR/InstIterator.h>
#include <llvm/IR/Constants.h>
#include <llvm/ADT/ValueMap.h>
#include <llvm/ADT/BitVector.h>
#include <llvm/ADT/DenseSet.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

namespace {

class DefinitionPass : public FunctionPass {
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
public:
  static char ID;
  DefinitionPass() : FunctionPass(ID) {}

  virtual void getAnalysisUsage(AnalysisUsage &au) const {
    au.setPreservesAll();
  }

  virtual bool runOnFunction(Function &F) {
    // Example: Print all stores and where they occur
    for (BasicBlock &BB : F) {
      for (Instruction &I : BB) {
        if (StoreInst *SI = dyn_cast<StoreInst>(&I)) {
          Value *PtrOp = SI->getPointerOperand(); // Store target
          if (PtrOp->hasName()) {
            DebugLoc Loc = SI->getDebugLoc();
            errs() << "Variable " << PtrOp->getName()
                   << " written on line " << Loc.getLine() << "\n";
          }
        }
      }
    }

    // We did not modify the function
    return false;
  }
};

class FixingPass : public FunctionPass {
public:
  static char ID;
  FixingPass() : FunctionPass(ID) {}

  virtual void getAnalysisUsage(AnalysisUsage &au) const {
    au.setPreservesCFG();
  }

  virtual bool runOnFunction(Function &F) {
    // TODO

    // The function was modified
    return true;
  }
};

} // namespace


char DefinitionPass::ID = 0;
char FixingPass::ID = 1;

// Pass registrations
static RegisterPass<DefinitionPass> X("def-pass", "Uninitialized variable pass");
static RegisterPass<FixingPass> Y("fix-pass", "Fixing initialization pass");
