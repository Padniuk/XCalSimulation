#ifndef EventAnalyzer_h
#define EventAnalyzer_h

#include <TString.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>
#include <fstream>
#include "TreeStructures.hh"
#include "TreeReader.hh"

#include "HistManager.hh"

class EventAnalyzer
{
  public:
    EventAnalyzer(TString filename, TString o="");
    virtual ~EventAnalyzer(){};
    
  // methods
    Bool_t           InitReadTree( TTree* ); // Maps class variables to an input TTree.
    void             InitHists();
    void             CreateFile();
    void             WriteFile();
    void             Analyze();
    // Bool_t           Select( Selector s );
    virtual Bool_t   Notify();

  
  // Running Variables
    TString  options;  // Options input with TreeIterator.
    TTree   *fChain;   //!pointer to the analyzed TTree or TChain
    Int_t    fCurrent; //!current Tree number in a TChain
    long entriesInNtuple  ;

    HistManager   _hm;


  private:
    Double_t _fem;
    Double_t _edep;
    Event_Data _evdata;
    Calorimeter_Data _scdata;

    Sim_Branch  _branch;

    TFile * _hfile;
    
    TTree * _hTree;

    TString _hfilename;

};

#endif