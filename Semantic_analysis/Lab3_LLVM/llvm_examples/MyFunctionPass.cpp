/** 
 * Course 703626 - University of Innsbruck, Austria
 * Advanced Compiler Design, Fortgeschrittener Compilerbau (ProSeminar) 
 * Sommersemester 2014
 * Lecturer: Ph.D. Biagio Cosenza
 */

#include <llvm/Pass.h>
#include <llvm/IR/Function.h>
#include <llvm/Support/raw_ostream.h>

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
        errs() << " - blocks:" << '\n';
        for(BasicBlock &b : F.getBasicBlockList()){
            errs() << "   * ";
            errs().write_escaped(b.getName()) << '\n';
        }	
        errs() << '\n';        
        return false;
    }
};
} // namespace

char MyFunctionPass::ID = 0;
static RegisterPass<MyFunctionPass> X("function-pass", "Function Pass");
 
