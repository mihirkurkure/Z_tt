#note: in pyroot you don't have to link branch to the variables(leaf) as they are available by 'tree.leaf'
import ROOT
from ROOT import TCanvas, TFile, TPad, TH1F
from ROOT import gROOT

#make canvas
c1 = TCanvas('c1','Trial Cuts', 1000,1000)
c1.Divide(2,2)

#open files
ztt_f = TFile('/Users/mihir/Desktop/Z_tt/ztt/data/emu_zttllcxxx_is722.root')
gamma_f = TFile('/Users/mihir/Desktop/Z_tt/ztt/data/emu_dyemxmg25_py560.root')
ww_f = TFile('/Users/mihir/Desktop/Z_tt/ztt/data/emu_wwllcxxxx_py057.root')
tt_f = TFile('/Users/mihir/Desktop/Z_tt/ztt/data/emu_ttll170xs_hw05.root')

#open Trees
ztt = ztt_f.Get("h10")
gamma = gamma_f.Get("h10")
ww = ww_f.Get("h10")
tt = tt_f.Get("h10")

#set style for stats box
ROOT.gStyle.SetOptStat(1111111)

#create histograms
hpx1 = TH1F('ete1', 'ZTT', 100,10,100)
hpx2 = TH1F('ete1', 'Gamma', 100,10,100)
hpx3 = TH1F('ete1', 'WW', 100,10,100)
hpx4 = TH1F('ete1', 'TT', 100,10,100)

#open first part of the canvas to draw ztt hist
c1.cd(1)
zttentries = ztt.GetEntries()

for i in range(0,zttentries):
    ztt.GetEntry(i)
    hpx1.Fill(ztt.ete1)  #fill the hist
hpx1.Draw()  #draw the hist

#open second part of the canvas to draw gamma hist
c1.cd(2)
gammaentries = gamma.GetEntries()

for i in range(0,gammaentries):
    gamma.GetEntry(i)
    hpx2.Fill(gamma.ete1)
hpx2.Draw()

#open third part of the canvas to draw ww hist
c1.cd(3)
wwentries = ww.GetEntries()

for i in range(0,wwentries):
    ww.GetEntry(i)
    hpx3.Fill(ww.ete1)
hpx3.Draw()

#open fourth part of the canvas to draw tt hist
c1.cd(4)
ttentries = tt.GetEntries()

for i in range(0,ttentries):
    tt.GetEntry(i)
    hpx4.Fill(tt.ete1)
hpx4.Draw()


c1.Draw()
c1.Print('ete1.pdf')