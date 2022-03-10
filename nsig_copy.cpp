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
 
void nsig_copy()
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
   Float_t ptm1;
   Float_t memu;
   Float_t dlrm1e1;
   Float_t nnej;

   /*Set Branch Addresses*/

  /* ztt->SetBranchAddress("ete1", &ete1);
   gamma->SetBranchAddress("ete1", &ete1);
   ww->SetBranchAddress("ete1", &ete1);
   tt->SetBranchAddress("ete1", &ete1); */

   const char *var = "(ete1) && (ptm1) && (memu) && (dlrm1e1) && (nnej)";
TCut cut = "(ete1>=10 && ete1<=30) && (ptm1>=5 && ptm1<=40) && (memu>=25 && memu<=70) && (dlrm1e1>=3.1 && dlrm1e1<=3.8) && (nnej<=1)";

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

double ratio = exp_ztt/(exp_gamma + exp_tt + exp_ww);

cout << endl <<
"Entries\nztt: " << n_ztt << " gamma: " << n_gamma <<
" ww: " << n_ww << " tt: " << n_tt << endl << endl;

cout << "Efficiencies\nztt: " << eff_ztt << " gamma: " << eff_gamma <<
" ww: " << eff_ww << " tt: " << eff_tt << endl << endl;

cout << "Expected\nztt: " << exp_ztt << " gamma: " << exp_gamma <<
" ww: " << exp_ww << " tt: " << exp_tt << endl << endl;

cout << "Ratio\n" << ratio << endl;

}