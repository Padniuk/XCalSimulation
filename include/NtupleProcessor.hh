#ifndef NtupleProcessor_h
#define NtupleProcessor_h
#include <TString.h>
#include "EventAnalyzer.hh"
#include "TreeIterator.hh"

class NtupleProcessor
{
  public:
    NtupleProcessor(TString input="",TString o="", int me = -1);
    ~NtupleProcessor(){}

    EventAnalyzer  eAnalyzer;
    TreeIterator   tIter;
    TString        input_file;
    TString        options;        // Extra options for this processing.
    int            maxEvents;      // Max number of events to run over in this ntuple

    TFile          *ntupleFile;

  private: 

};

#endif