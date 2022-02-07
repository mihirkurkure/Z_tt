#include <string>

using namespace std;

void cut(bool save_fig=false)
{
	/* Open up data file*/
	TFile *ztt_f = new TFile("/Users/mihir/Desktop/Z_tt/ztt/data/emu_zttllcxxx_is722.root");
	TFile *gamma_f = new TFile("/Users/mihir/Desktop/Z_tt/ztt/data/emu_dyemxmg25_py560.root");
	TFile *ww_f = new TFile("/Users/mihir/Desktop/Z_tt/ztt/data/emu_wwllcxxxx_py057.root");
	TFile *tt_f = new TFile("/Users/mihir/Desktop/Z_tt/ztt/data/emu_ttll170xs_hw05.root");

	/* Get Trees */
	TTree *ztt = (TTree *)ztt_f->Get("h10");
	TTree *gamma = (TTree *)gamma_f->Get("h10");
	TTree *ww = (TTree *)ww_f->Get("h10");
	TTree *tt = (TTree *)tt_f->Get("h10");


	/* Set up canvas */
	TCanvas *c1 = new TCanvas("c", "Trial Cuts", 1000, 1000);

	gStyle->SetOptStat(111111);     // Show all statistics
	c1->Divide(2, 2);               // two columns, two rows

	/* Set up the labels for the histograms */
	TPaveText *ztt_l = new TPaveText();
	ztt_l->AddText("Z->TT");
	TPaveText *gamma_l = new TPaveText();
	gamma_l->AddText("Gamma");
	TPaveText *ww_l = new TPaveText();
	ww_l->AddText("WW");
	TPaveText *tt_l = new TPaveText();
	tt_l->AddText("tt");


	/* Define variable to check */
	const char *var = "ete1";

	/* Define Cuts */
	TCut basic_cut = "ete1 < 40";
	

	/* Draw histograms */
	c1->cd(1);                      // Change the current canvas
	ztt->Draw(var, basic_cut);      // Draw the histogram for the variable with the cut
	ztt_l->Draw();                  // Draw the label for the histogram title

	c1->cd(2);
	gamma->Draw(var, basic_cut);
	gamma_l->Draw();

	c1->cd(3);
	ww->Draw(var, basic_cut);
	ww_l->Draw();

	c1->cd(4);
	tt->Draw(var, basic_cut);
	tt_l->Draw();
}