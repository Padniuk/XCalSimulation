#ifndef TreeReader_h
#define TreeReader_h

#include <TTree.h>
#include "TreeStructures.hh"

class TreeReader
{
  public:
    TreeReader();
    virtual ~TreeReader() {};
    void InitializeReadEventTreeBranches (TTree *tree, Event_Data &_data, Sim_Branch &_branch);
    void InitializeReadCalorimeterTreeBranches (TTree *tree, Calorimeter_Data &_data, Sim_Branch &_branch);
    
  private: 

};

#endif