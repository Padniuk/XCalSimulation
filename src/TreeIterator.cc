#include <iomanip>
#include <iostream>
#include <string>
#include <TString.h>
#include "TreeIterator.hh"
#include "HistManager.hh"

typedef unsigned long counter;

using std::cout;  using std::endl;   using std::setw;   using std::string;


void TreeIterator::Begin(TTree * /*tree*/){}


void TreeIterator::SlaveBegin(TTree * /*tree*/)
{
  // Initialize log, counters
    nEntries          = 0;
    nEntriesProcessed = 0;
    eAnalyzer.CreateFile();
    eAnalyzer.InitHists();
}

void TreeIterator::Init(TTree *tree)
{
  // Initialize the current tree.
  if (!tree) return;
  fChain = tree;
  fChain->SetMakeClass(0);
  nEntries = tree->GetEntries();
  finalEntry = nEntries-1;
  // Initialize Event Handler, adding the criteria of each HistoMaker to it's list of criteria.
  eAnalyzer.InitReadTree(fChain);  
}


Bool_t TreeIterator::Notify()
{
  Init(fChain);
  return kTRUE;
}

Bool_t TreeIterator::Process(Long64_t entry)
{
    fChain->GetEntry(entry);
    nEntriesProcessed++;
    eAnalyzer.Analyze();
    return true;
}

void TreeIterator::SlaveTerminate(){}

void TreeIterator::Terminate()
{
  eAnalyzer.WriteFile();
}