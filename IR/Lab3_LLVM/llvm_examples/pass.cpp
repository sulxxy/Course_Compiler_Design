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
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/SymbolTableListTraits.h>

#include <sstream>
#include <vector>
#include <set>

const int MAX_DEF_CNT = 10;

using namespace llvm;

namespace {

    //store IN[] OUT[] gen[] kill[]
    class DataFlowSets{
        private:
            BitVector* OUT;
            BitVector* IN;
            BitVector* GEN;
            BitVector* KILL;
        public:
            DataFlowSets(){
                OUT = new BitVector(MAX_DEF_CNT);
                IN = new BitVector(MAX_DEF_CNT);
                GEN = new BitVector(MAX_DEF_CNT);
                KILL = new BitVector(MAX_DEF_CNT);
            }

            //set or get properties
            BitVector* getOUT(){
                return OUT;
            }

            //set or get properties
            void setOUT(int index, int bit){
                (*OUT)[index] = bit;
            }

            //set or get properties
            void setOUT(BitVector bv){
                //(*OUT)[6] = 1;
                *OUT = bv;
            }

            //set or get properties
            BitVector* getIN(){
                return IN;
            }

            //set or get properties
            void setIN(int index, int bit){
                (*IN)[index] = bit;
            }
            //set or get properties
            void setIN(BitVector bv){
                *IN = bv;
            }

            //set or get properties
            BitVector* getGEN(){
                return GEN;
            }

            //set or get properties
            void setGEN(int index, int bit){
                (*GEN)[index] = bit;
            }
            //set or get properties
            void setGEN(BitVector bv){
                *GEN = bv;
            }

            //set or get properties
            BitVector* getKILL(){
                return KILL;
            }

            //set or get properties
            void setKILL(int index, int bit){
                (*KILL)[index] = bit;
            }

            //set or get properties
            void setKILL(BitVector bv){
                *KILL = bv;
            }

            std::string asString(){
                std::stringstream ss;
                ss << "\nGEN: " << std::endl;
                for(int i = 0; i < GEN->size(); i++){
                    ss << (*GEN)[i] << '\t';
                }
                ss << "\nKILL: " << std::endl;
                for(int i = 0; i < KILL->size(); i++){
                    ss << (*KILL)[i] << '\t';
                }
                ss << "\nOUT: " << std::endl;
                for(int i = 0; i < OUT->size(); i++){
                    ss << (*OUT)[i] << '\t';
                }
                ss << "\nIN: " << std::endl;
                for(int i = 0; i < IN->size(); i++){
                    ss << (*IN)[i] << '\t';
                }
                return ss.str();
            }
    };

    class DefinitionPass : public FunctionPass {
        private:
            std::set<StringRef> variables_in_current_block;
            ValueMap<BasicBlock*, DataFlowSets*> basicblock_dataflow_sets_map ;
            ValueMap<BasicBlock*, int*> visited_times_for_each_bb;
            //ValueMap<StoreInst*, int>  value_index_map;
            std::vector<StoreInst*> definitions_globally;

        public:
            static char ID;
            DefinitionPass() : FunctionPass(ID) {}

            virtual void getAnalysisUsage(AnalysisUsage &au) const {
                au.setPreservesAll();
            }

            virtual bool runOnFunction(Function &F) {
            // Example: Print all stores and where they occur
                for (BasicBlock &BB : F) {
                    DataFlowSets* dataflow_sets_in_current_basicblock = calculateDataFlowSets(BB);
                    basicblock_dataflow_sets_map.insert(std::pair<BasicBlock*, DataFlowSets*>(&BB, dataflow_sets_in_current_basicblock));
                    visited_times_for_each_bb.insert(std::pair<BasicBlock*, int*>(&BB, new int(0)));
                    /*for (Instruction &I : BB) {
                        if (StoreInst *SI = dyn_cast<StoreInst>(&I)) {
                            Value *PtrOp = SI->getPointerOperand(); // Store target
                            if (PtrOp->hasName()) {
                                DebugLoc Loc = SI->getDebugLoc();
                                errs() << "Variable " << PtrOp->getName()
                                    << " written on line " << Loc.getLine() << "\n";
                            }
                        }
                    }*/
                }
                bool change = true;
                while(change){
                    change = false;
                    //errs()<<"\n=============================================================\n";
                    for(BasicBlock &BB : F){
                        //errs()<<"\n======\n";
                        int* times_the_current_bb_has_been_visited = visited_times_for_each_bb.lookup(&BB);
                        (*times_the_current_bb_has_been_visited)++;
                        BitVector tmpIN(MAX_DEF_CNT);
                        BitVector tmpOUT(MAX_DEF_CNT);
                        DataFlowSets* dataflow_sets_in_current_basicblock = basicblock_dataflow_sets_map.lookup(&BB);
                        int j = 0;
                        for(pred_iterator i = pred_begin(&BB); i != pred_end(&BB); i++){
                            //IN[BB]
                            BasicBlock* bp = *i;
                            //errs() << "DEBUG:  " << *(visited_times_for_each_bb.lookup(bp))<<'\n';
                            if((*(visited_times_for_each_bb.lookup(bp))) != 0){
                                if(j == 0){
                                    tmpIN = *(basicblock_dataflow_sets_map.lookup(bp)->getOUT());
                                    j++;
                                }
                                else{
                                    tmpIN &= *(basicblock_dataflow_sets_map.lookup(bp)->getOUT());
                                }
                            }
                        }
                        //OUT[BB]
                        tmpOUT |= *(dataflow_sets_in_current_basicblock->getGEN()) ;
                        tmpOUT |= tmpIN;
                        if(tmpOUT != *(dataflow_sets_in_current_basicblock->getOUT())){
                            change = true;
                        }
                        dataflow_sets_in_current_basicblock->setIN(tmpIN);
                        dataflow_sets_in_current_basicblock->setOUT(tmpOUT);
                        //errs() << basicblock_dataflow_sets_map.lookup(&BB)->asString() << '\n';
                    }
                }

                variables_in_current_block.clear();
                std::set<StringRef> func_arguments;
                for(Argument& a: F.getArgumentList()){
                    func_arguments.insert(a.getName());
                }
                for(BasicBlock &BB : F){
                    //errs() << basicblock_dataflow_sets_map.lookup(&BB)->asString() << '\n';
                    std::vector<StoreInst*> definitions_locally;
                    BitVector sets_of_current_basicblock = *(basicblock_dataflow_sets_map.lookup(&BB)->getIN());
                    BitVector GEN_in_current_block(MAX_DEF_CNT);
                    //sets_of_current_basicblock |= *(basicblock_dataflow_sets_map.lookup(&BB)->getGEN());
                    /*if(sets_of_current_basicblock.none()){
                        sets_of_current_basicblock = *(basicblock_dataflow_sets_map.lookup(&BB)->getGEN());
                    }*/
                    for(Instruction &i : BB){
                        if( LoadInst* li = dynamic_cast<LoadInst*>(&i) ){
                            int j = 0, k = 0;
                            /* find defintions in IN */
                            for(j = 0; j < sets_of_current_basicblock.size(); j++){
                                if(1 == sets_of_current_basicblock[j]){
                                    if(definitions_globally.at(j-1)->getPointerOperand()->getName() ==li->getPointerOperand()->getName()){
                                        //errs() << '\n' << li->getPointerOperand()->getName() << "  initialized\n" ;
                                        break;
                                    }
                                }
                            }
                            /* If not found, find defintion in current real-time gen */
                            if(j == sets_of_current_basicblock.size()){
                                for(j = 0; j < GEN_in_current_block.size(); j++){
                                    if(1 == GEN_in_current_block[j]){
                                        if(definitions_locally.at(j-1)->getPointerOperand()->getName() ==li->getPointerOperand()->getName()){
                                            //errs() << '\n' << li->getPointerOperand()->getName() << "  initialized\n" ;
                                            break;
                                        }
                                    }
                                }
                                /* if still not found, find definition in argument list*/
                                if(j == GEN_in_current_block.size()){
                                    if(func_arguments.find(li->getPointerOperand()->getName()) != func_arguments.end()){
                                        //find
                                        //errs() << "\n ==== Find Arg ===\n";
                                    }
                                    else{
                                        //errs() << "\n ==== Not Find Arg ===\n" << func_arguments.size() << ;
                                        errs() << "Variable " << li->getPointerOperand()->getName() << " may be uninitialized on line " << i.getDebugLoc().getLine() << '\n';
                                    }
                                }

                            }
                        }
                        /* generate current GEN in real-time*/
                        else if(StoreInst* si = dynamic_cast<StoreInst*>(&i)){
                            //if(si->getPointerOperand()->getName() != ""){
                                if(variables_in_current_block.find(si->getPointerOperand()->getName()) != variables_in_current_block.end()){
                                    //definitions_globally.push_back(si);
                                    //dataflow_sets->setGEN(definitions_globally.size() ,1);
                                }
                                else{
                                    variables_in_current_block.insert(si->getPointerOperand()->getName());
                                    definitions_locally.push_back(si);
                                    GEN_in_current_block[definitions_locally.size()] = 1;
                                }
                            //}
                        }
                    }
                }


                /*clear and reset all initialized members, in case they will "dirty" the following functions*/
            // We did not modify the function
            return false;
            }

            DataFlowSets* calculateDataFlowSets(BasicBlock &bb){
                DataFlowSets* dataflow_sets = new DataFlowSets();
                //std::vector<StoreInst*> definitions_in_current_block;
                int initialization_index = 0;

                // traverse to calculate GEN KILL
                for(Instruction &i : bb){
                    if( AllocaInst* ai = dynamic_cast<AllocaInst*>(&i) ){
                        /*errs() << "======Allocate=======" << '\n';
                        ai->print(errs());
                        errs() << "\nName: "<< ai->getName() << '\n';
                        std::pair<Value*, int> tmp = std::pair<Value*, int>(ai, 9);
                        valueMap.insert(tmp);*/
                    }
                    else if(StoreInst* si = dynamic_cast<StoreInst*>(&i)){
                            //if(initialization_index != -1){
                            if(si->getPointerOperand()->getName() != ""){
                            /*errs() << "======Store=======" << '\n';
                            si->print(errs());
                            errs() << "\nOperand: "<< *(si->getPointerOperand()) << '\n';
                            errs() << "Operand Name: "<< si->getPointerOperand()->getName() << '\n';*/
                            /*int index = value_index_map.size();
                            std::pair<StoreInst*, int> tmp = std::pair<Value*, int>(si, index+1);
                            value_index_map.erase(si);
                            value_index_map.insert(tmp);*/


                            /*remove former definitions on the same variable, which is downward exposed*/
                            /*TODO: There's a !BUG! here: the function initializationIndexWhenLoading() can only return the index of the first item. However, when there're 2 more definitions, the function cannot run successfully.*/
                            /*if(variables_in_current_block.find(si->getPointerOperand()->getName()) != variables_in_current_block.end()){
                                int index = initializationIndexWhenLoading(definitions_in_current_block, si->getPointerOperand());
                                dataflow_sets->setGEN(definitions_globally.size() + index + 1, 0);
                                definitions_in_current_block.push_back(si);
                                dataflow_sets->setGEN(definitions_globally.size() + definitions_in_current_block.size(),1);
                            }
                            else{
                                variables_in_current_block.insert(si->getPointerOperand()->getName());
                                definitions_in_current_block.push_back(si);
                                dataflow_sets->setGEN(definitions_globally.size() + definitions_in_current_block.size(),1);
                            }*/
                            if(variables_in_current_block.find(si->getPointerOperand()->getName()) != variables_in_current_block.end()){
                                int index = initializationIndexWhenLoading(definitions_globally, si->getPointerOperand());
                                dataflow_sets->setGEN(index + 1, 1);
                                //definitions_globally.push_back(si);
                                //dataflow_sets->setGEN(definitions_globally.size() ,1);
                            }
                            else{
                                variables_in_current_block.insert(si->getPointerOperand()->getName());
                                definitions_globally.push_back(si);
                                dataflow_sets->setGEN(definitions_globally.size() ,1);
                            }
                        }
                        initialization_index = 0;
                    }
                    else if( LoadInst* li = dynamic_cast<LoadInst*>(&i) ){
                        /*errs() << "======Load=======" << '\n';
                        li->print(errs());
                        errs() << "\nOperand: "<< *(li->getPointerOperand()) << '\n';
                        errs() << "Operand Name: "<< li->getPointerOperand()->getName() << '\n';
                        errs() << "Lookup Value: " << valueMap.lookup(li->getPointerOperand()) << '\n' << "Size: " << valueMap.size() << '\n';*/

                        /*when loading, we need to ensure the loading variable has been defined. That is to say, the loading variable should have been stored in the definitions_in_current_block*/
                        //initialization_index = initializationIndexWhenLoading(definitions_in_current_block, li->getPointerOperand());
                        //initialization_index = initializationIndexWhenLoading(definitions_globally, li->getPointerOperand());

                    }
                }

                /*for(std::vector<StoreInst*>::iterator i = definitions_in_current_block.begin(), e = definitions_in_current_block.end(); i !=e; i++){
                    definitions_globally.push_back(*i);
                }*/

                return dataflow_sets;
            }

            /* lookup the item with the name of Value* v, return the index of the item in vector vs */
            int initializationIndexWhenLoading(std::vector<StoreInst*>& vs, Value* v){
                for(std::vector<StoreInst*>::iterator i = vs.begin(); i != vs.end(); i++){
                    if((*i)->getPointerOperand()->getName() == v->getName()){
                        return i-vs.begin();
                    }
                }
                return -1;
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
//char FixingPass::ID = 1;

// Pass registrations
static RegisterPass<DefinitionPass> X("def-pass", "Uninitialized variable pass");
//static RegisterPass<FixingPass> Y("fix-pass", "Fixing initialization pass");
