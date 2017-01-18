/** 
 * Course 703626 - University of Innsbruck, Austria
 * Advanced Compiler Design, Fortgeschrittener Compilerbau (ProSeminar) 
 * Sommersemester 2014
 * Lecturer: Ph.D. Biagio Cosenza
 */

#include <llvm/Analysis/RegionPass.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

namespace {

class MyRegionPass : public RegionPass {
public:
    static char ID;

    MyRegionPass() : RegionPass(ID) {}

    virtual void getAnalysisUsage(AnalysisUsage &au) const {
        au.setPreservesAll();
    }

    virtual bool runOnRegion(Region *R, RGPassManager &RGM){
        errs() << "region ";
        R->print(errs());
    
        // iterating region nodes in the current region	
        errs() << " - subregions:";        
        errs() << "\n";
        for(auto &sub : *R){
            errs() << " * ";
            sub->print(errs());
        }
        errs() << '\n';
        return false;
    }
};

}// namespace

char MyRegionPass::ID = 0;
static RegisterPass<MyRegionPass> X("region-pass", "Region Pass");
