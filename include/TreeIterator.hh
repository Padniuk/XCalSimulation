#ifndef TreeIterator_h
#define TreeIterator_h
#include <map>
#include <sstream>
#include <vector>
#include <TBranch.h>
#include <TChain.h>
#include <TSelector.h>
#include <TTree.h>
#include "EventAnalyzer.hh"

typedef unsigned long counter;

class TreeIterator : public TSelector
{
  public:
    TreeIterator(EventAnalyzer &eh) : eAnalyzer(eh), fChain(0) {}
    
    virtual ~TreeIterator(){}
    
    virtual Int_t   Version() const { return 2; }
    virtual void    Begin     (TTree *tree);
    virtual void    SlaveBegin(TTree *tree);
    virtual void    Init      (TTree *tree);
    virtual Bool_t  Notify();
    virtual Bool_t  Process   (Long64_t entry);

    virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
    virtual void    SetOption(const char *option) { fOption = option; }
    virtual void    SetObject(TObject *obj)       { fObject = obj;    }
    virtual void    SetInputList(TList *input)    { fInput  = input;  }
    virtual TList  *GetOutputList() const         { return fOutput;   }

    virtual void    SlaveTerminate();
    virtual void    Terminate();

  // Entry handler & list of Histogram Extractors
    EventAnalyzer &eAnalyzer;

    TTree *fChain;

    Long64_t nEntries;
    Long64_t finalEntry;
    Long64_t nEntriesProcessed;


  private: 

};

#endif