#ifndef GUARD_HistManager_h
#define GUARD_HistManager_h

#include <iostream>
#include <map>
#include <TString.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TList.h>
#include <TFile.h> 

class HistManager
{
  public:
    HistManager();
    ~HistManager(){}

  // Methods
  virtual void InitializeHists();
  virtual void Hist2List();
  virtual void WriteLists( TFile * output );

  enum class h1{
    energy,
    time,
    time_ecal,
    time_hcal,
    energy_ecal,
    energy_hcal,
    posx,
    posy,
    posz,
    energy_evt,
    fem_evt,
    dummy,
    last = dummy 
  };
  TH1F * h1[static_cast<int>(h1::last)];

  enum class h2{
    energy_time_ecal,
    energy_time_hcal,
    dummy,
    last = dummy 
  };
  TH2F * h2[static_cast<int>(h2::last)];

  enum class h3{
    pos_xy_t,
    pos_yz_t,
    pos_xz_t,
    pos_ry_t,
    dummy,
    last = dummy 
  };
  TH3F * h3[static_cast<int>(h3::last)];
  
  TH3F * h3_pos[1000];

  private:
    TList* h1List         = new TList();
    TList* h2List         = new TList();
    TList* h3List         = new TList();
    TList* h3List_pos     = new TList();
};

#endif
