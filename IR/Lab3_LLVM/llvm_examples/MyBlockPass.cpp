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
    int flag;
    MyBlockPass() : BasicBlockPass(ID) { flag = 0; }

    virtual bool runOnBasicBlock(BasicBlock &BB) {
      //errs().write_escaped(BB.getName()) << '\n';
        std::string name1 = "sss";
        std::string name2 = "ttt";
        if(flag == 0){
            BB.setName(name1);
        }
        else{

            BB.setName(name2);
        }
        flag++;
      errs()  << "TEST:" << BB.getName() << '\n';
      // iterating instructions in the current BasickBlock
      for(Instruction &i : BB){
          errs() << "--------------------\n";
          errs() << "Line Number: " << i.getDebugLoc().getLine() << '\n';
          i.print(errs());
          errs() << '\n';
          errs() << " - "<< i.getOpcodeName() << " : ";
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
