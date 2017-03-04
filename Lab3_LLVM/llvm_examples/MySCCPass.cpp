/** 
 * Course 703626 - University of Innsbruck, Austria
 * Advanced Compiler Design, Fortgeschrittener Compilerbau (ProSeminar) 
 * Sommersemester 2014
 * Lecturer: Ph.D. Biagio Cosenza
 */

#include <llvm/Pass.h>
#include <llvm/Analysis/CallGraphSCCPass.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

namespace {

class MySCCPass : public CallGraphSCCPass {
public:
    static char ID;
    int sccNum;
    MySCCPass() : CallGraphSCCPass(ID), sccNum(0) {}

    virtual bool runOnSCC(CallGraphSCC &SCC){
        errs() << "SCC " << sccNum++ << '\n';
        // iterating graph nodes in the current SCC	
        for(CallGraphNode *cgn : SCC){
            errs() << " - ";
            cgn->print(errs());
        }
        return false;
    }
};

}// namespace

char MySCCPass::ID = 0;
static RegisterPass<MySCCPass> X("scc-pass", "SCC Pass");