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

using namespace std;

double N_ztt = 71393;
double cs_ztt = 13.3;

double N_gamma = 199990;
double cs_gamma = 5.51;

double N_ww = 101792;
double cs_ww = 0.69;

double N_tt = 101339;
double cs_tt = 0.4;

double L = 108.3;
 
void hist_copy()
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

   Float_t nnej;

   /*Set Branch Addresses*/

   ztt->SetBranchAddress("nnej", &nnej);
   gamma->SetBranchAddress("nnej", &nnej);
   ww->SetBranchAddress("nnej", &nnej);
   tt->SetBranchAddress("nnej", &nnej);

   /*Make a canvas and divide it to fit all four histograms*/

   TCanvas *c1 = new TCanvas("c", "Trial Cuts", 1000, 1000);
   c1->Divide(2, 2);

   /*Create Histograms*/

   TH1F *hpx1 = new TH1F("nnej","ztt",1000,0,5);
   TH1F *hpx2 = new TH1F("nnej","gamma",1000,0,5);
   TH1F *hpx3 = new TH1F("nnej","ww",1000,0,5);
   TH1F *hpx4 = new TH1F("nnej","tt",1000,0,5);

   /*Read entries from tree and fill the histogram to draw it*/

   Long64_t zttentries = ztt->GetEntries();
   for (Long64_t i=0;i<zttentries;i++) {
      ztt->GetEntry(i);
      if (nnej>=0 && nnej<5){
         hpx1->Fill(nnej);
      }      
   }
   c1->cd(1);
   hpx1->Draw();


   Long64_t gammaentries = gamma->GetEntries();
   for (Long64_t i=0;i<gammaentries;i++) {
      gamma->GetEntry(i);
      if (nnej>=0 && nnej<5){
         hpx2->Fill(nnej);
      }     
   }
   c1->cd(2);
   hpx2->Draw();


   Long64_t wwentries = ww->GetEntries();
   for (Long64_t i=0;i<wwentries;i++) {
      ww->GetEntry(i);
      if (nnej>=0 && nnej<5) {
         hpx3->Fill(nnej);
      }      
   }
   c1->cd(3);
   hpx3->Draw();

   Long64_t ttentries = tt->GetEntries();
   for (Long64_t i=0;i<ttentries;i++) {
      tt->GetEntry(i);
      if (nnej>=0 && nnej<5) {
         hpx4->Fill(nnej);
      }    
   }
   c1->cd(4);
   hpx4->Draw();

   c1->Print("nnej.pdf");

const char *var = "nnej";
TCut cut = "nnej>=0 && nnej<1";

int n_ztt = ztt->GetEntries(cut);
int n_gamma = gamma->GetEntries(cut);
int n_ww = ww->GetEntries(cut);
int n_tt = tt->GetEntries(cut);

/*Efficiency*/

double eff_ztt = n_ztt/N_ztt;
double eff_gamma = n_gamma / N_gamma;
double eff_ww = n_ww / N_ww;
double eff_tt = n_tt / N_tt;

/*Values*/

double exp_ztt = eff_ztt * cs_ztt * L;
double exp_gamma = eff_gamma * cs_gamma * L;
double exp_ww = eff_ww * cs_ww * L;
double exp_tt = eff_tt * cs_tt * L;
double bkg = exp_gamma + exp_tt + exp_ww;

double ratio = exp_ztt/(exp_gamma + exp_tt + exp_ww);

cout << endl <<
"Entries\nztt: " << n_ztt << " gamma: " << n_gamma <<
" ww: " << n_ww << " tt: " << n_tt << endl << endl;

cout << "Efficiencies\nztt: " << eff_ztt << " gamma: " << eff_gamma <<
" ww: " << eff_ww << " tt: " << eff_tt << endl << endl;

cout << "Expected\nztt: " << exp_ztt << " gamma: " << exp_gamma <<
" ww: " << exp_ww << " tt: " << exp_tt << " bkg: " << bkg << endl << endl;

cout << "Ratio\n" << ratio << endl;

}