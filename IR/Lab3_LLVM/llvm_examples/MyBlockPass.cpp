/**
 * Course 703626 - University of Innsbruck, Austria
 * Advanced Compiler Design, Fortgeschrittener Compilerbau (ProSeminar)
 * Sommersemester 2014
 * Lecturer: Ph.D. Biagio Cosenza
 */

#include <llvm/IR/Type.h>
#include <llvm/Pass.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Instructions.h>

using namespace llvm;

namespace {

class MyBlockPass : public BasicBlockPass {
public:
    static char ID;
    MyBlockPass() : BasicBlockPass(ID) {}

    virtual bool runOnBasicBlock(BasicBlock &BB) {
      errs().write_escaped(BB.getName()) << '\n';
      // iterating instructions in the current BasickBlock
      for(Instruction &i : BB){
          //errs() << "Instruction: ";
          //i.print(errs());
          //errs() << '\n';
          errs() << " - "<< i.getOpcodeName() << " : ";
          if(AllocaInst *al = dynamic_cast<AllocaInst*>(&i)){
              errs() << "TEST: This is an allocation statement\n" << al->getName() << '\n';
          }
          if(StoreInst *sl = dynamic_cast<StoreInst*>(&i)){
              errs() << "TEST: This is an store statement\n" << sl->getName() << '\n';
          }
          Type *type = i.getType();
          type->print(errs());
          errs() << '\n';
      }
      errs() << '\n';
      return false;
    }
  };
} // namespace

char MyBlockPass ::ID = 0;
static RegisterPass<MyBlockPass > X("block-pass", "Block Pass");
