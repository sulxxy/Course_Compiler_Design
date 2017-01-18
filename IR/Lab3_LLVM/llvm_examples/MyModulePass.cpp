/** 
 * Course 703626 - University of Innsbruck, Austria
 * Advanced Compiler Design, Fortgeschrittener Compilerbau (ProSeminar) 
 * Sommersemester 2014
 * Lecturer: Ph.D. Biagio Cosenza
 */
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instructions.h"

#include <iostream>
#include <string>

using namespace llvm;
using namespace std;

namespace
{

class MyModulePass : public ModulePass {
  
  public:
  static char ID;

  MyModulePass() : ModulePass(ID) { }
  ~MyModulePass() { }
 
  virtual void getAnalysisUsage(AnalysisUsage &au) const {
    au.setPreservesAll();
  }

  virtual bool runOnModule(Module& m) {
    cerr << "Module " << m.getModuleIdentifier() << endl;
    for (Module::iterator mi = m.begin(), me = m.end(); mi != me; ++mi) {
      runOnFunction(*mi);
    }
    return false;
  }

  virtual bool runOnFunction(Function &f) {    
    string name = f.getName();
    cout << name << endl;
    return false;
  }
                                                                                   
}; // class MyModulePass
 

  // LLVM uses the address of this static member to identify the pass
  char MyModulePass::ID = 0; 

  static RegisterPass<MyModulePass> X("function-info", "MyModulePass");

} // namespace
