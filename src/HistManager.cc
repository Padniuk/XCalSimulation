#include <iostream>
#include <TString.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TList.h>
#include <TFile.h>

#include "../include/HistManager.hh"

using std::cout;   using std::endl;

HistManager::HistManager() {}

void HistManager::InitializeHists()
{

  int h_xmin=-2000;
  int h_xmax=2000;
  int h_ymin=1750;
  int h_ymax=3500;
  int h_zmin=-3000;
  int h_zmax=3000;
  int r_max=3600;

  h1[static_cast<int>(h1::energy_evt)] = new TH1F("energy_evt","",100,0,100);
  h1[static_cast<int>(h1::fem_evt)] = new TH1F("fem_evt","",1000,0,1000);

  h1[static_cast<int>(h1::energy)] = new TH1F("energy","",10000,0,0.1);
  h1[static_cast<int>(h1::time)] = new TH1F("time","",30000,0,3000);

  h1[static_cast<int>(h1::energy_ecal)] = new TH1F("energy_ecal","",10000,0,0.1);
  h1[static_cast<int>(h1::time_ecal)] = new TH1F("time_ecal","",30000,0,3000);

  h1[static_cast<int>(h1::energy_hcal)] = new TH1F("energy_hcal","",10000,0,0.1);
  h1[static_cast<int>(h1::time_hcal)] = new TH1F("time_hcal","",30000,0,3000);
  
  h1[static_cast<int>(h1::posx)] = new TH1F("posx","",100,h_xmin, h_xmax);
  h1[static_cast<int>(h1::posy)] = new TH1F("posy","",100,h_ymin, h_ymax);
  h1[static_cast<int>(h1::posz)] = new TH1F("posz","",100,h_zmin, h_zmax);

  h2[static_cast<int>(h2::energy_time_ecal)] = new TH2F("energy_time_ecal","",100,0,0.001,1000,0,100);
  h2[static_cast<int>(h2::energy_time_hcal)] = new TH2F("energy_time_hcal","",100,0,0.001,1000,0,100);

  h3[static_cast<int>(h3::pos_xy_t)] = new TH3F("pos_xy_t","",100,h_xmin, h_xmax,100,h_ymin, h_ymax, 5000, 0, 500);
  h3[static_cast<int>(h3::pos_yz_t)] = new TH3F("pos_yz_t","",100,h_ymin, h_ymax,100,h_zmin, h_zmax, 5000, 0, 500);
  h3[static_cast<int>(h3::pos_xz_t)] = new TH3F("pos_xz_t","",100,h_xmin, h_xmax,100,h_zmin, h_zmax, 5000, 0, 500);
  h3[static_cast<int>(h3::pos_ry_t)] = new TH3F("pos_ry_t","",100,0, r_max,100,h_ymin, h_ymax, 5000, 0, 500);

  for(Int_t i=0; i<1000; i++) {
    h3_pos[i] = new TH3F(Form("pos_%d",i),"",50,h_xmin, h_xmax,50,h_ymin, h_ymax, 50, h_zmin, h_zmax);
  }
  
  Hist2List();
}

void HistManager::Hist2List()
{  
  for (auto ih : h1) {
    h1List->Add(ih);
  }

  for (auto ih: h2) {
    h2List->Add(ih);
  }

  for (auto ih : h3) {
    h3List->Add(ih);
  }
  for(auto ih : h3_pos) {
    h3List_pos->Add(ih);
  }

}

void HistManager::WriteLists( TFile * output)
{
  output->cd();

  h1List->Write();

  h2List->Write();

  TDirectory * d_shower3d = output->mkdir("shower-profiles");
  d_shower3d->cd();
  h3List->Write(); 

  TDirectory * d_pos = output->mkdir("pos");
  d_pos->cd();
  h3List_pos->Write();
}