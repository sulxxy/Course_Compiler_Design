/**
 * Course 703626 - University of Innsbruck, Austria
 * Advanced Compiler Design, Fortgeschrittener Compilerbau (ProSeminar)
 * Sommersemester 2014
 * Lecturer: Ph.D. Biagio Cosenza
 */

#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
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
          if(AllocaInst* ai = dynamic_cast< AllocaInst* >(&i)){
              errs() << "\nVN:  " << ai->getName() << '\n';
          }
          if(CallInst* ci = dynamic_cast< CallInst* >(&i)){
              errs() << "\nParaName0:  " << ci->getAttributes().getAsString(0) << '\n';
              for(ArrayRef< Attribute >::iterator i = ci->getAttributes().begin(5); i != ci->getAttributes().end(5); i++){
              errs() << "\nParaName1:  " << i << '\n';
              }
              errs() << "\nFuncName:  " << ci->getCalledFunction()->getName() << '\n';
          }
          if(StoreInst* si = dynamic_cast< StoreInst* >(&i)){
              if(si->getPointerOperand()->getName() == ""){
                  errs() << "\n=========empty==========\n";
              }
              errs() << "\nVN:  " << si->getPointerOperand()->getName() << '\n';
          }
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
