#include <iostream>
#include <TString.h>
#include <TFile.h> 
#include "NtupleProcessor.hh"

using std::cout;   using std::endl;
using std::string;

NtupleProcessor::NtupleProcessor(TString input, TString o, int me)
: eAnalyzer(input, o), tIter(eAnalyzer), input_file(input), options(o), maxEvents(me)
{
  // PARAM output
    cout << "  [NtupleProcessor]\n"
            "    Input File: " << input_file   << "\n"
            "    Options:    " << options   << "\n"
            "    MaxEntries: " << me   << "\n"
    << endl;

  // TString dummy_label = "rv02-02.sv02-02.mILD_l5_o1_v02.E250-SetA.I500010.P2f_z_h.eL.pR.n002.d_dstm_15162_000";
  // TString filename = "data/" + dummy_label + ".root";

  ntupleFile = TFile::Open(input_file);
  if(!ntupleFile) cout << "NtupleProcessor: ERROR: Unable to open file " << input_file << endl;
  TTree *ntuple   = (TTree*) ntupleFile->Get("MyLCTuple");
  if(!ntuple) cout << "NtupleProcessor: ERROR: Unable to open ttree in " << input_file << endl;

  if(maxEvents!=-1) ntuple->Process(&tIter, options, maxEvents);
  else              ntuple->Process(&tIter, options);

}