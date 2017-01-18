/** 
 * Course 703626 - University of Innsbruck, Austria
 * Advanced Compiler Design, Fortgeschrittener Compilerbau (ProSeminar) 
 * Sommersemester 2014
 * Lecturer: Ph.D. Biagio Cosenza
 */

#include <llvm/Analysis/LoopPass.h>
#include <llvm/Support/raw_ostream.h>
using namespace llvm;

namespace {

class MyLoopPass : public LoopPass {
public:
    static char ID;
    MyLoopPass() : LoopPass(ID) {}

    bool runOnLoop(Loop *L, LPPassManager &LPPM) {
      L->print(errs());
      for(BasicBlock *b : L->getBlocks()) {
          errs() << " - "; 
          errs().write_escaped(b->getName()) << '\n';
      }
      errs() << '\n';
      return false;
    }
};
}// namespace

char MyLoopPass::ID = 0;
static RegisterPass<MyLoopPass> X("loop-pass", "Loop Pass");