#ifndef TreeStructures_h
#define TreeStructures_h
#include "TBranch.h"

struct Sim_Branch
{
    public:
        TBranch        *b_evevt;
        TBranch        *b_evrun;
        TBranch        *b_evwgt;
        TBranch        *b_evtim;
        TBranch        *b_evsig;
        TBranch        *b_evene;
        TBranch        *b_evpoe;
        TBranch        *b_evpop;
        TBranch        *b_evnch;
        TBranch        *b_evpro;
        TBranch        *b_nmcp;
        TBranch        *b_mcori;
        TBranch        *b_mcpdg;
        TBranch        *b_mcgst;
        TBranch        *b_mcsst;
        TBranch        *b_mcvtx;
        TBranch        *b_mcvty;
        TBranch        *b_mcvtz;
        TBranch        *b_mcepx;
        TBranch        *b_mcepy;
        TBranch        *b_mcepz;
        TBranch        *b_mcmox;
        TBranch        *b_mcmoy;
        TBranch        *b_mcmoz;
        TBranch        *b_mcmas;
        TBranch        *b_mcene;
        TBranch        *b_mccha;
        TBranch        *b_mctim;
        TBranch        *b_mcspx;
        TBranch        *b_mcspy;
        TBranch        *b_mcspz;
        TBranch        *b_mccf0;
        TBranch        *b_mccf1;
        TBranch        *b_mcpa0;
        TBranch        *b_mcpa1;
        TBranch        *b_mcda0;
        TBranch        *b_mcda1;
        TBranch        *b_mcda2;
        TBranch        *b_mcda3;
        TBranch        *b_mcda4;
        TBranch        *b_nrec;
        TBranch        *b_rcori;
        TBranch        *b_rccid;
        TBranch        *b_rctyp;
        TBranch        *b_rccov;
        TBranch        *b_rcrpx;
        TBranch        *b_rcrpy;
        TBranch        *b_rcrpz;
        TBranch        *b_rcgpi;
        TBranch        *b_rcpiu;
        TBranch        *b_rcnpi;
        TBranch        *b_rcfpi;
        TBranch        *b_rcmox;
        TBranch        *b_rcmoy;
        TBranch        *b_rcmoz;
        TBranch        *b_rcmas;
        TBranch        *b_rcene;
        TBranch        *b_rccha;
        TBranch        *b_rcntr;
        TBranch        *b_rcncl;
        TBranch        *b_rcnrp;
        TBranch        *b_rcftr;
        TBranch        *b_rcvts;
        TBranch        *b_rcvte;
        TBranch        *b_rccom;
        TBranch        *b_npid; 
        TBranch        *b_pityp;
        TBranch        *b_pipdg;
        TBranch        *b_pillh;
        TBranch        *b_pialg;
        TBranch        *b_ntrk;
        TBranch        *b_trori;
        TBranch        *b_trtyp;
        TBranch        *b_trch2;
        TBranch        *b_trndf;
        TBranch        *b_tredx;
        TBranch        *b_trede;
        TBranch        *b_trrih;
        TBranch        *b_trshn;
        TBranch        *b_trnts;
        TBranch        *b_trfts;
        TBranch        *b_trsip;
        TBranch        *b_trsfh;
        TBranch        *b_trslh;
        TBranch        *b_trsca;
        TBranch        *b_ntrst;
        TBranch        *b_tsloc;
        TBranch        *b_tsdze;
        TBranch        *b_tsphi;
        TBranch        *b_tsome;
        TBranch        *b_tszze;
        TBranch        *b_tstnl;
        TBranch        *b_tscov;
        TBranch        *b_tsrpx;
        TBranch        *b_tsrpy;
        TBranch        *b_tsrpz;
        TBranch        *b_nsth;
        TBranch        *b_stori;
        TBranch        *b_stci0;
        TBranch        *b_stci1;
        TBranch        *b_stpox;
        TBranch        *b_stpoy;
        TBranch        *b_stpoz;
        TBranch        *b_stedp;
        TBranch        *b_sttim;
        TBranch        *b_stmox;
        TBranch        *b_stmoy;
        TBranch        *b_stmoz;
        TBranch        *b_stptl;
        TBranch        *b_stmcp;
        TBranch        *b_nsch;
        TBranch        *b_scori;
        TBranch        *b_scci0;
        TBranch        *b_scci1;
        TBranch        *b_scpox;
        TBranch        *b_scpoy;
        TBranch        *b_scpoz;
        TBranch        *b_scene;
        TBranch        *b_sctime;
        TBranch        *b_r2mnrel;
        TBranch        *b_r2mf;
        TBranch        *b_r2mt;
        TBranch        *b_r2mw;
        TBranch        *b_ncont;
        TBranch        *b_sccontpdg;
        TBranch        *b_sccontene;
};


struct Event_Data {
    public:
        Int_t           evevt;
        Int_t           evrun;
        Float_t         evwgt;
        Long64_t        evtim;
        Float_t         evsig;
        Float_t         evene;
        Float_t         evpoe;
        Float_t         evpop;
        Int_t           evnch;
        Char_t          evpro[1];
};

// struct Other_Data
// {
//     public:
//         Int_t           r2mnrel;
//         Int_t           r2mf[1];
//         Int_t           r2mt[1];
//         Float_t         r2mw[1];
// };

struct MC_Particle_Data {
    public:
        Int_t           nmcp;
        Int_t           mcori[30];
        Int_t           mcpdg[30];
        Int_t           mcgst[30];
        Int_t           mcsst[30];
        Float_t         mcvtx[30];
        Float_t         mcvty[30];
        Float_t         mcvtz[30];
        Float_t         mcepx[30];
        Float_t         mcepy[30];
        Float_t         mcepz[30];
        Float_t         mcmox[30];
        Float_t         mcmoy[30];
        Float_t         mcmoz[30];
        Float_t         mcmas[30];
        Float_t         mcene[30];
        Float_t         mccha[30];
        Float_t         mctim[30];
        Float_t         mcspx[30];
        Float_t         mcspy[30];
        Float_t         mcspz[30];
        Int_t           mccf0[30];
        Int_t           mccf1[30];
        Int_t           mcpa0[30];
        Int_t           mcpa1[30];
        Int_t           mcda0[30];
        Int_t           mcda1[30];
        Int_t           mcda2[30];
        Int_t           mcda3[30];
        Int_t           mcda4[30];
};

struct RepoParticle_Data {
    public:
        Int_t           nrec;
        Int_t           rcori[1];
        Int_t           rccid[1];
        Int_t           rctyp[1];
        Float_t         rccov[1][10];
        Float_t         rcrpx[1];
        Float_t         rcrpy[1];
        Float_t         rcrpz[1];
        Float_t         rcgpi[1];
        Int_t           rcpiu[1];
        Int_t           rcnpi[1];
        Int_t           rcfpi[1];
        Float_t         rcmox[1];
        Float_t         rcmoy[1];
        Float_t         rcmoz[1];
        Float_t         rcmas[1];
        Float_t         rcene[1];
        Float_t         rccha[1];
        Int_t           rcntr[1];
        Int_t           rcncl[1];
        Int_t           rcnrp[1];
        Int_t           rcftr[1];
        Int_t           rcvts[1];
        Int_t           rcvte[1];
        Int_t           rccom[1];
        Int_t           npid;
        Int_t           pityp[1];
        Int_t           pipdg[1];
        Float_t         pillh[1];
        Int_t           pialg[1];
};

struct Track_Data {
    public:
        Int_t           ntrk;
        Int_t           trori[1];
        Int_t           trtyp[1];
        Float_t         trch2[1];
        Int_t           trndf[1];
        Float_t         tredx[1];
        Float_t         trede[1];
        Float_t         trrih[1];
        Int_t           trshn[1][12];
        Int_t           trnts[1];
        Int_t           trfts[1];
        Int_t           trsip[1];
        Int_t           trsfh[1];
        Int_t           trslh[1];
        Int_t           trsca[1];
        Int_t           ntrst;
        Int_t           tsloc[1];
        Float_t         tsdze[1];
        Float_t         tsphi[1];
        Float_t         tsome[1];
        Float_t         tszze[1];
        Float_t         tstnl[1];
        Float_t         tscov[1][15];
        Float_t         tsrpx[1];
        Float_t         tsrpy[1];
        Float_t         tsrpz[1];
};

struct Tracker_Data {
    public:
        Int_t           nsth;
        Int_t           stori[8000];
        Int_t           stci0[8000];
        Int_t           stci1[8000];
        Double_t        stpox[8000];
        Double_t        stpoy[8000];
        Double_t        stpoz[8000];
        Float_t         stedp[8000];
        Float_t         sttim[8000];
        Float_t         stmox[8000];
        Float_t         stmoy[8000];
        Float_t         stmoz[8000];
        Float_t         stptl[8000];
        Int_t           stmcp[8000];
};

struct Calorimeter_Data {
    public:
        Int_t           nsch;
        Int_t           scori[8000];
        Int_t           scci0[8000];
        Int_t           scci1[8000];
        Float_t         scpox[8000];
        Float_t         scpoy[8000];
        Float_t         scpoz[8000]; 
        Float_t         scene[8000]; 
        Float_t         sctime[8000];
        Int_t           ncont[8000];
        Int_t           sccontpdg[8000][100];
        Float_t         sccontene[8000][100];
};


#endif