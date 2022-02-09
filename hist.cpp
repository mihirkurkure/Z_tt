#include <string>
#include "TCanvas.h"
#include "TSystem.h"
#include "TFile.h"
#include "TH2.h"
#include "TNtuple.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TFrame.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TNtuple.h"
 
void hist()
{

   TFile *ztt_f = new TFile("/Users/mihir/Desktop/Z_tt/ztt/data/emu_zttllcxxx_is722.root");
   
   TTree *ztt = (TTree *)ztt_f->Get("h10");

   Float_t ete1;
   

   ztt->SetBranchAddress("ete1", &ete1);

   TH1F *hpx = new TH1F("ete1","ZTT",100,30,80);

   gStyle->SetOptStat(111111);


   Long64_t nentries = ztt->GetEntries();
   for (Long64_t i=0;i<nentries;i++) {
      ztt->GetEntry(i);
      hpx->Fill(ete1);
   }
   

   hpx->Draw();



}