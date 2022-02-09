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
   /*Open Files*/

   TFile *ztt_f = new TFile("/Users/mihir/Desktop/Z_tt/ztt/data/emu_zttllcxxx_is722.root");
   TFile *gamma_f = new TFile("/Users/mihir/Desktop/Z_tt/ztt/data/emu_dyemxmg25_py560.root");
	TFile *ww_f = new TFile("/Users/mihir/Desktop/Z_tt/ztt/data/emu_wwllcxxxx_py057.root");
	TFile *tt_f = new TFile("/Users/mihir/Desktop/Z_tt/ztt/data/emu_ttll170xs_hw05.root");

   /*Open Trees*/
   
   TTree *ztt = (TTree *)ztt_f->Get("h10");
   TTree *gamma = (TTree *)gamma_f->Get("h10");
	TTree *ww = (TTree *)ww_f->Get("h10");
	TTree *tt = (TTree *)tt_f->Get("h10");

   gStyle->SetOptStat(1111111);

   Float_t ete1;

   /*Set Branch Addresses*/

   ztt->SetBranchAddress("ete1", &ete1);
   gamma->SetBranchAddress("ete1", &ete1);
   ww->SetBranchAddress("ete1", &ete1);
   tt->SetBranchAddress("ete1", &ete1);

   /*Make a canvas and divide it to fit all four histograms*/

   TCanvas *c1 = new TCanvas("c", "Trial Cuts", 1000, 1000);
   c1->Divide(2, 2);

   /*Create Histograms*/

   TH1F *hpx1 = new TH1F("ete1","ztt",100,9,100);
   TH1F *hpx2 = new TH1F("ete1","gamma",100,9,100);
   TH1F *hpx3 = new TH1F("ete1","ww",100,9,100);
   TH1F *hpx4 = new TH1F("ete1","tt",100,9,100);

   /*Read entries from tree and fill the histogram to draw it*/

   Long64_t nentries = ztt->GetEntries();
   for (Long64_t i=0;i<nentries;i++) {
      ztt->GetEntry(i);
      hpx1->Fill(ete1);
   }
   c1->cd(1);
   hpx1->Draw();


   Long64_t mentries = gamma->GetEntries();
   for (Long64_t i=0;i<mentries;i++) {
      gamma->GetEntry(i);
      hpx2->Fill(ete1);
   }
   c1->cd(2);
   hpx2->Draw();


   Long64_t oentries = ww->GetEntries();
   for (Long64_t i=0;i<oentries;i++) {
      ww->GetEntry(i);
      hpx3->Fill(ete1);
   }
   c1->cd(3);
   hpx3->Draw();

   Long64_t pentries = tt->GetEntries();
   for (Long64_t i=0;i<pentries;i++) {
      tt->GetEntry(i);
      hpx4->Fill(ete1);
   }
   c1->cd(4);
   hpx4->Draw();



}