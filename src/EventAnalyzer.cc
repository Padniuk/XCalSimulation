#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
#include <TBranch.h>
#include <TLeaf.h>
#include <TMath.h>
#include <Math/Vector4D.h>
#include <Math/Vector3D.h>
#include "EventAnalyzer.hh"
#include "TreeReader.hh"

using std::cout;   using std::endl;

EventAnalyzer::EventAnalyzer(TString filename, TString o)
: _hfilename(filename),
  options(o)
{}

Bool_t EventAnalyzer::InitReadTree(TTree* tree)
{

    entriesInNtuple = tree->GetEntries();

    if (!tree) return false;
    fChain = tree;
    fCurrent = -1;
    fChain->SetMakeClass(1);

    TreeReader reader;
    reader.InitializeReadEventTreeBranches(fChain, _evdata, _branch);
    reader.InitializeReadCalorimeterTreeBranches(fChain, _scdata, _branch);

    Notify();

    return true;

}

void EventAnalyzer::CreateFile()
{
    _hfilename.Remove(0, _hfilename.Last('/') + 1);
    _hfilename.ReplaceAll(".root", "");
    _hfilename = "../output/" + _hfilename + "_ready.root";
    _hfile = new TFile(_hfilename, "RECREATE", _hfilename);
}


void EventAnalyzer::InitHists()
{
    _hm.InitializeHists();
}

void EventAnalyzer::WriteFile()
{
    _hm.WriteLists(_hfile);
    _hfile->Close();
}

void EventAnalyzer::Analyze()
{   
    _edep = _fem =0;
    for(int ihit=0; ihit<_scdata.nsch; ++ihit)
    {   
        _hm.h1[static_cast<int>(HistManager::h1::energy)]->Fill(_scdata.scene[ihit]);
        _hm.h1[static_cast<int>(HistManager::h1::time)]->Fill(_scdata.sctime[ihit]);
        _hm.h1[static_cast<int>(HistManager::h1::posx)]->Fill(_scdata.scpox[ihit]);
        _hm.h1[static_cast<int>(HistManager::h1::posy)]->Fill(_scdata.scpoy[ihit]);
        _hm.h1[static_cast<int>(HistManager::h1::posz)]->Fill(_scdata.scpoz[ihit]);
        _hm.h1[static_cast<int>(HistManager::h1::energy_evt)]->Fill(_evdata.evevt, _scdata.scene[ihit]);  
             
        
        if (_scdata.scpoy[ihit] > 1750+17.5*3 && _scdata.scpoy[ihit] < 1750+17.5*15) {
            _hm.h2[static_cast<int>(HistManager::h2::energy_time_ecal)]->Fill(_scdata.scene[ihit], _scdata.sctime[ihit]);
            _hm.h1[static_cast<int>(HistManager::h1::energy_ecal)]->Fill(_scdata.scene[ihit]);
            _hm.h1[static_cast<int>(HistManager::h1::time_ecal)]->Fill(_scdata.sctime[ihit]);
        }

        if (_scdata.scpoy[ihit] > 1750+17.5*19 && _scdata.scpoy[ihit] < 1750+17.5*21+24*17.5*3-17.5*2) {
            _hm.h2[static_cast<int>(HistManager::h2::energy_time_hcal)]->Fill(_scdata.scene[ihit], _scdata.sctime[ihit]);
            _hm.h1[static_cast<int>(HistManager::h1::energy_hcal)]->Fill(_scdata.scene[ihit]);
            _hm.h1[static_cast<int>(HistManager::h1::time_hcal)]->Fill(_scdata.sctime[ihit]);
        }
        
        if(_evdata.evevt == 43) {
            _hm.h3[static_cast<int>(HistManager::h3::pos_xy_t)]->Fill(_scdata.scpox[ihit], _scdata.scpoy[ihit], _scdata.sctime[ihit], _scdata.scene[ihit]);
            _hm.h3[static_cast<int>(HistManager::h3::pos_yz_t)]->Fill(_scdata.scpoy[ihit], _scdata.scpoz[ihit], _scdata.sctime[ihit], _scdata.scene[ihit]);
            _hm.h3[static_cast<int>(HistManager::h3::pos_xz_t)]->Fill(_scdata.scpox[ihit], _scdata.scpoz[ihit], _scdata.sctime[ihit], _scdata.scene[ihit]);
            _hm.h3[static_cast<int>(HistManager::h3::pos_ry_t)]->Fill(TMath::Sqrt(_scdata.scpox[ihit]*_scdata.scpox[ihit]+_scdata.scpoz[ihit]*_scdata.scpoz[ihit]), _scdata.scpoy[ihit], _scdata.sctime[ihit], _scdata.scene[ihit]);

        }
        for(Int_t ipart=0; ipart<_scdata.ncont[ihit]; ipart++)
        {    
            if( _scdata.sccontpdg[ihit][ipart] == 11 || _scdata.sccontpdg[ihit][ipart] == -11 || _scdata.sccontpdg[ihit][ipart] == 22 || _scdata.sccontpdg[ihit][ipart] == 111) {
                _fem+=_scdata.sccontene[ihit][ipart];
            }
        }
        _edep+=_scdata.scene[ihit];
        _hm.h3_pos[_evdata.evevt]->Fill(_scdata.scpox[ihit], _scdata.scpoy[ihit], _scdata.scpoz[ihit], _scdata.scene[ihit]);        
    }
    if(_edep != 0) {
        _hm.h1[static_cast<int>(HistManager::h1::fem_evt)]->Fill(_evdata.evevt, _fem/_edep);
    }
    else {
        _hm.h1[static_cast<int>(HistManager::h1::fem_evt)]->Fill(_evdata.evevt, 0);    
    }
}

Bool_t EventAnalyzer::Notify()
{
   return kTRUE;
}