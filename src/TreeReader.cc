#include "TreeReader.hh"

TreeReader::TreeReader() {}

void TreeReader::InitializeReadEventTreeBranches(TTree *tree, Event_Data &_data, Sim_Branch &_branch)
{
    tree->SetBranchAddress("evevt", &_data.evevt, &_branch.b_evevt);
    tree->SetBranchAddress("evrun", &_data.evrun, &_branch.b_evrun);
    tree->SetBranchAddress("evwgt", &_data.evwgt, &_branch.b_evwgt);
    tree->SetBranchAddress("evtim", &_data.evtim, &_branch.b_evtim);
    tree->SetBranchAddress("evsig", &_data.evsig, &_branch.b_evsig);
    tree->SetBranchAddress("evene", &_data.evene, &_branch.b_evene);
    tree->SetBranchAddress("evpoe", &_data.evpoe, &_branch.b_evpoe);
    tree->SetBranchAddress("evpop", &_data.evpop, &_branch.b_evpop);
    tree->SetBranchAddress("evnch", &_data.evnch, &_branch.b_evnch);
    tree->SetBranchAddress("evpro", &_data.evpro, &_branch.b_evpro);
}

void TreeReader::InitializeReadCalorimeterTreeBranches(TTree *tree, Calorimeter_Data &_data, Sim_Branch &_branch)
{
    tree->SetBranchAddress("nsch", &_data.nsch, &_branch.b_nsch);
    tree->SetBranchAddress("scori", _data.scori, &_branch.b_scori);
    tree->SetBranchAddress("scci0", _data.scci0, &_branch.b_scci0);
    tree->SetBranchAddress("scci1", _data.scci1, &_branch.b_scci1);
    tree->SetBranchAddress("scpox", _data.scpox, &_branch.b_scpox);
    tree->SetBranchAddress("scpoy", _data.scpoy, &_branch.b_scpoy);
    tree->SetBranchAddress("scpoz", _data.scpoz, &_branch.b_scpoz);
    tree->SetBranchAddress("scene", _data.scene, &_branch.b_scene);
    tree->SetBranchAddress("sctime", _data.sctime, &_branch.b_sctime);
    tree->SetBranchAddress("ncont", _data.ncont, &_branch.b_ncont);
    tree->SetBranchAddress("sccontpdg", _data.sccontpdg, &_branch.b_sccontpdg);
    tree->SetBranchAddress("sccontene", _data.sccontene, &_branch.b_sccontene);
}

// tree->SetBranchAddress("nmcp", &_data.nmcp, &_branch.b_nmcp);
// tree->SetBranchAddress("mcori", _data.mcori, &_branch.b_mcori);
// tree->SetBranchAddress("mcpdg", _data.mcpdg, &_branch.b_mcpdg);
// tree->SetBranchAddress("mcgst", _data.mcgst, &_branch.b_mcgst);
// tree->SetBranchAddress("mcsst", _data.mcsst, &_branch.b_mcsst);
// tree->SetBranchAddress("mcvtx", _data.mcvtx, &_branch.b_mcvtx);
// tree->SetBranchAddress("mcvty", _data.mcvty, &_branch.b_mcvty);
// tree->SetBranchAddress("mcvtz", _data.mcvtz, &_branch.b_mcvtz);
// tree->SetBranchAddress("mcepx", _data.mcepx, &_branch.b_mcepx);
// tree->SetBranchAddress("mcepy", _data.mcepy, &_branch.b_mcepy);
// tree->SetBranchAddress("mcepz", _data.mcepz, &_branch.b_mcepz);
// tree->SetBranchAddress("mcmox", _data.mcmox, &_branch.b_mcmox);
// tree->SetBranchAddress("mcmoy", _data.mcmoy, &_branch.b_mcmoy);
// tree->SetBranchAddress("mcmoz", _data.mcmoz, &_branch.b_mcmoz);
// tree->SetBranchAddress("mcmas", _data.mcmas, &_branch.b_mcmas);
// tree->SetBranchAddress("mcene", _data.mcene, &_branch.b_mcene);
// tree->SetBranchAddress("mccha", _data.mccha, &_branch.b_mccha);
// tree->SetBranchAddress("mctim", _data.mctim, &_branch.b_mctim);
// tree->SetBranchAddress("mcspx", _data.mcspx, &_branch.b_mcspx);
// tree->SetBranchAddress("mcspy", _data.mcspy, &_branch.b_mcspy);
// tree->SetBranchAddress("mcspz", _data.mcspz, &_branch.b_mcspz);
// tree->SetBranchAddress("mccf0", _data.mccf0, &_branch.b_mccf0);
// tree->SetBranchAddress("mccf1", _data.mccf1, &_branch.b_mccf1);
// tree->SetBranchAddress("mcpa0", _data.mcpa0, &_branch.b_mcpa0);
// tree->SetBranchAddress("mcpa1", _data.mcpa1, &_branch.b_mcpa1);
// tree->SetBranchAddress("mcda0", _data.mcda0, &_branch.b_mcda0);
// tree->SetBranchAddress("mcda1", _data.mcda1, &_branch.b_mcda1);
// tree->SetBranchAddress("mcda2", _data.mcda2, &_branch.b_mcda2);
// tree->SetBranchAddress("mcda3", _data.mcda3, &_branch.b_mcda3);
// tree->SetBranchAddress("mcda4", _data.mcda4, &_branch.b_mcda4);
// tree->SetBranchAddress("nrec", &_data.nrec, &_branch.b_nrec);
// tree->SetBranchAddress("rcori", &_data.rcori, &_branch.b_rcori);
// tree->SetBranchAddress("rccid", &_data.rccid, &_branch.b_rccid);
// tree->SetBranchAddress("rctyp", &_data.rctyp, &_branch.b_rctyp);
// tree->SetBranchAddress("rccov", &_data.rccov, &_branch.b_rccov);
// tree->SetBranchAddress("rcrpx", &_data.rcrpx, &_branch.b_rcrpx);
// tree->SetBranchAddress("rcrpy", &_data.rcrpy, &_branch.b_rcrpy);
// tree->SetBranchAddress("rcrpz", &_data.rcrpz, &_branch.b_rcrpz);
// tree->SetBranchAddress("rcgpi", &_data.rcgpi, &_branch.b_rcgpi);
// tree->SetBranchAddress("rcpiu", &_data.rcpiu, &_branch.b_rcpiu);
// tree->SetBranchAddress("rcnpi", &_data.rcnpi, &_branch.b_rcnpi);
// tree->SetBranchAddress("rcfpi", &_data.rcfpi, &_branch.b_rcfpi);
// tree->SetBranchAddress("rcmox", &_data.rcmox, &_branch.b_rcmox);
// tree->SetBranchAddress("rcmoy", &_data.rcmoy, &_branch.b_rcmoy);
// tree->SetBranchAddress("rcmoz", &_data.rcmoz, &_branch.b_rcmoz);
// tree->SetBranchAddress("rcmas", &_data.rcmas, &_branch.b_rcmas);
// tree->SetBranchAddress("rcene", &_data.rcene, &_branch.b_rcene);
// tree->SetBranchAddress("rccha", &_data.rccha, &_branch.b_rccha);
// tree->SetBranchAddress("rcntr", &_data.rcntr, &_branch.b_rcntr);
// tree->SetBranchAddress("rcncl", &_data.rcncl, &_branch.b_rcncl);
// tree->SetBranchAddress("rcnrp", &_data.rcnrp, &_branch.b_rcnrp);
// tree->SetBranchAddress("rcftr", &_data.rcftr, &_branch.b_rcftr);
// tree->SetBranchAddress("rcvts", &_data.rcvts, &_branch.b_rcvts);
// tree->SetBranchAddress("rcvte", &_data.rcvte, &_branch.b_rcvte);
// tree->SetBranchAddress("rccom", &_data.rccom, &_branch.b_rccom);
// tree->SetBranchAddress("npid", &_data.npid, &_branch.b_npid);
// tree->SetBranchAddress("pityp", &_data.pityp, &_branch.b_pityp);
// tree->SetBranchAddress("pipdg", &_data.pipdg, &_branch.b_pipdg);
// tree->SetBranchAddress("pillh", &_data.pillh, &_branch.b_pillh);
// tree->SetBranchAddress("pialg", &_data.pialg, &_branch.b_pialg);
// tree->SetBranchAddress("ntrk", &_data.ntrk, &_branch.b_ntrk);
// tree->SetBranchAddress("trori", &_data.trori, &_branch.b_trori);
// tree->SetBranchAddress("trtyp", &_data.trtyp, &_branch.b_trtyp);
// tree->SetBranchAddress("trch2", &_data.trch2, &_branch.b_trch2);
// tree->SetBranchAddress("trndf", &_data.trndf, &_branch.b_trndf);
// tree->SetBranchAddress("tredx", &_data.tredx, &_branch.b_tredx);
// tree->SetBranchAddress("trede", &_data.trede, &_branch.b_trede);
// tree->SetBranchAddress("trrih", &_data.trrih, &_branch.b_trrih);
// tree->SetBranchAddress("trshn", &_data.trshn, &_branch.b_trshn);
// tree->SetBranchAddress("trnts", &_data.trnts, &_branch.b_trnts);
// tree->SetBranchAddress("trfts", &_data.trfts, &_branch.b_trfts);
// tree->SetBranchAddress("trsip", &_data.trsip, &_branch.b_trsip);
// tree->SetBranchAddress("trsfh", &_data.trsfh, &_branch.b_trsfh);
// tree->SetBranchAddress("trslh", &_data.trslh, &_branch.b_trslh);
// tree->SetBranchAddress("trsca", &_data.trsca, &_branch.b_trsca);
// tree->SetBranchAddress("ntrst", &_data.ntrst, &_branch.b_ntrst);
// tree->SetBranchAddress("tsloc", &_data.tsloc, &_branch.b_tsloc);
// tree->SetBranchAddress("tsdze", &_data.tsdze, &_branch.b_tsdze);
// tree->SetBranchAddress("tsphi", &_data.tsphi, &_branch.b_tsphi);
// tree->SetBranchAddress("tsome", &_data.tsome, &_branch.b_tsome);
// tree->SetBranchAddress("tszze", &_data.tszze, &_branch.b_tszze);
// tree->SetBranchAddress("tstnl", &_data.tstnl, &_branch.b_tstnl);
// tree->SetBranchAddress("tscov", &_data.tscov, &_branch.b_tscov);
// tree->SetBranchAddress("tsrpx", &_data.tsrpx, &_branch.b_tsrpx);
// tree->SetBranchAddress("tsrpy", &_data.tsrpy, &_branch.b_tsrpy);
// tree->SetBranchAddress("tsrpz", &_data.tsrpz, &_branch.b_tsrpz);
// tree->SetBranchAddress("nsth", &_data.nsth, &_branch.b_nsth);
// tree->SetBranchAddress("stori", _data.stori, &_branch.b_stori);
// tree->SetBranchAddress("stci0", _data.stci0, &_branch.b_stci0);
// tree->SetBranchAddress("stci1", _data.stci1, &_branch.b_stci1);
// tree->SetBranchAddress("stpox", _data.stpox, &_branch.b_stpox);
// tree->SetBranchAddress("stpoy", _data.stpoy, &_branch.b_stpoy);
// tree->SetBranchAddress("stpoz", _data.stpoz, &_branch.b_stpoz);
// tree->SetBranchAddress("stedp", _data.stedp, &_branch.b_stedp);
// tree->SetBranchAddress("sttim", _data.sttim, &_branch.b_sttim);
// tree->SetBranchAddress("stmox", _data.stmox, &_branch.b_stmox);
// tree->SetBranchAddress("stmoy", _data.stmoy, &_branch.b_stmoy);
// tree->SetBranchAddress("stmoz", _data.stmoz, &_branch.b_stmoz);
// tree->SetBranchAddress("stptl", _data.stptl, &_branch.b_stptl);
// tree->SetBranchAddress("stmcp", _data.stmcp, &_branch.b_stmcp);
// tree->SetBranchAddress("r2mnrel", &_data.r2mnrel, &_branch.b_r2mnrel);
// tree->SetBranchAddress("r2mf", &_data.r2mf, &_branch.b_r2mf);
// tree->SetBranchAddress("r2mt", &_data.r2mt, &_branch.b_r2mt);
// tree->SetBranchAddress("r2mw", &_data.r2mw, &_branch.b_r2mw);