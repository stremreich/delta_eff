// Delta Eff Code
// Stephen Trembath-Reichert

#include "TH2.h"
#include "TH1F.h"
#include "stdio.h"

void delta_eff(const char *LCTname1, const char *LCTname2, const char *SEGname1, const char *SEGname2) {

  gROOT->ProcessLine(".L CMSStyle.C");
  gROOT->ProcessLine("CMSStyle()");
  gROOT->LoadMacro("CMSStyle.C");
  CMSStyle();

  gStyle->SetOptStat("emr");
  gStyle->SetStatFont(132);
  gStyle->SetStatX(0.4);
  gStyle->SetStatY(0.7);
  gStyle->SetStatBorderSize(0);

  TFile f1LCT(LCTname1);
  TFile f2LCT(LCTname2);
  TFile f1SEG(SEGname1);
  TFile f2SEG(SEGname2);
  TFile fout("DEffPlots.root", "RECREATE");

  TH2F *hist2017LCT = (TH2F*)f1LCT.Get("LCTEff");
  TH2F *hist2016LCT = (TH2F*)f2LCT.Get("LCTEff");
  TH2F *hist2017SEG = (TH2F*)f1SEG.Get("SEGEff");
  TH2F *hist2016SEG = (TH2F*)f2SEG.Get("SEGEff");

  TH1F *delta_eff_LCThist = new TH1F("DEffLCT", "", 120, -150, 150);
  
  TH1F *delta_eff_LCThist_1 = new TH1F("DEffLCT1", "", 120, -150, 150);
  TH1F *delta_eff_LCThist_2 = new TH1F("DEffLCT2", "", 120, -150, 150);
  TH1F *delta_eff_LCThist_3 = new TH1F("DEffLCT3", "", 120, -150, 150);
  TH1F *delta_eff_LCThist_4 = new TH1F("DEffLCT4", "", 120, -150, 150);

  TH1F *delta_eff_LCThist_1cut = new TH1F("DEffLCT1cut", "", 40, -20, 20);
  TH1F *delta_eff_LCThist_2cut = new TH1F("DEffLCT2cut", "", 40, -20, 20);
  TH1F *delta_eff_LCThist_3cut = new TH1F("DEffLCT3cut", "", 40, -20, 20);
  TH1F *delta_eff_LCThist_4cut = new TH1F("DEffLCT4cut", "", 40, -20, 20);

  TH1F *delta_eff_SEGhist = new TH1F("DEffSEG", "", 120, -150, 150);
  
  TH1F *delta_eff_SEGhist_1 = new TH1F("DEffSEG1", "", 120, -150, 150);
  TH1F *delta_eff_SEGhist_2 = new TH1F("DEffSEG2", "", 120, -150, 150);
  TH1F *delta_eff_SEGhist_3 = new TH1F("DEffSEG3", "", 120, -150, 150);
  TH1F *delta_eff_SEGhist_4 = new TH1F("DEffSEG4", "", 120, -150, 150);

  TH1F *delta_eff_SEGhist_1cut = new TH1F("DEffSEG1cut", "", 40, -20, 20);
  TH1F *delta_eff_SEGhist_2cut = new TH1F("DEffSEG2cut", "", 40, -20, 20);
  TH1F *delta_eff_SEGhist_3cut = new TH1F("DEffSEG3cut", "", 40, -20, 20);
  TH1F *delta_eff_SEGhist_4cut = new TH1F("DEffSEG4cut", "", 40, -20, 20);

  // Fill LCT hist
  double deff = 0;
  for(int xbin = 1; xbin <= (hist2017LCT->GetNbinsX()); xbin++) {
    for(int ybin = 1; ybin <= (hist2017LCT->GetNbinsY()); ybin++) {
      deff = hist2017LCT->GetBinContent(xbin, ybin) - hist2016LCT->GetBinContent(xbin, ybin);
      if(!((ybin == 2 || ybin == 4 || ybin == 6 || ybin == 15 || ybin == 17 || ybin == 19) && (xbin > 18))) { 
	// All stations
	delta_eff_LCThist->Fill(deff);
	
	if(ybin > 6 && ybin < 15) {
	  // Station 1
	  delta_eff_LCThist_1->Fill(deff);
	  if (deff > -20 && deff < 20) {
	     delta_eff_LCThist_1cut->Fill(deff);
	  }
	} else if(ybin == 5 || ybin == 6 || ybin == 15 || ybin == 16) {
	  // Station 2
	  delta_eff_LCThist_2->Fill(deff);
	  if (deff > -20 && deff < 20) {
	     delta_eff_LCThist_2cut->Fill(deff);
	  }
	} else if(ybin == 3 || ybin == 4 || ybin == 17 || ybin == 18) {
	  // Station 3
	  delta_eff_LCThist_3->Fill(deff);
	  if (deff > -20 && deff < 20) {
	     delta_eff_LCThist_3cut->Fill(deff);
	  }
	} else {
	  // Station 4
	  delta_eff_LCThist_4->Fill(deff);
	  if (deff > -20 && deff < 20) {
	     delta_eff_LCThist_4cut->Fill(deff);
	  }
	}
      }
    }
  }

  // Fill segment hist
  
  for(int xbin = 1; xbin <= (hist2017SEG->GetNbinsX()); xbin++) {
    for(int ybin = 1; ybin <= (hist2017SEG->GetNbinsY()); ybin++) {
      deff = hist2017SEG->GetBinContent(xbin, ybin) - hist2016SEG->GetBinContent(xbin, ybin);
      if(!((ybin == 2 || ybin == 4 || ybin == 6 || ybin == 15 || ybin == 17 || ybin == 19) && (xbin > 18))) { 
	// All stations
	delta_eff_SEGhist->Fill(deff);
	
	if(ybin > 6 && ybin < 15) {
	  // Station 1
	  delta_eff_SEGhist_1->Fill(deff);
	  if (deff > -20 && deff < 20) {
	     delta_eff_SEGhist_1cut->Fill(deff);
	  }
	} else if(ybin == 5 || ybin == 6 || ybin == 15 || ybin == 16) {
	  // Station 2
	  delta_eff_SEGhist_2->Fill(deff);
	  if (deff > -20 && deff < 20) {
	     delta_eff_SEGhist_2cut->Fill(deff);
	  }
	} else if(ybin == 3 || ybin == 4 || ybin == 17 || ybin == 18) {
	  // Station 3
	  delta_eff_SEGhist_3->Fill(deff);
	  if (deff > -20 && deff < 20) {
	     delta_eff_SEGhist_3cut->Fill(deff);
	  }
	} else {
	  // Station 4
	  delta_eff_SEGhist_4->Fill(deff);
	  if (deff > -20 && deff < 20) {
	     delta_eff_SEGhist_4cut->Fill(deff);
	  }
	}
      }
    }
  }

  // Set extra histogram style options

  TPaveText *pt1 = new TPaveText(0.165, 0.94, 0.315, 0.99, "NDC");
  pt1->SetFillStyle(0);
  pt1->SetBorderSize(0);
  pt1->SetTextSize(0.04);
  pt1->SetTextAlign(12);
  pt1->AddText("CMS Preliminary 2017");

  TPaveText *pt2 = new TPaveText(0.835, 0.94, 0.965, 0.99, "NDC");
  pt2->SetFillStyle(0);
  pt2->SetBorderSize(0);
  pt2->SetTextSize(0.04);
  pt2->SetTextAlign(12);
  pt2->AddText("#sqrt{s}=13 TeV");

  TPaveText *st1 = new TPaveText(0.2, 0.8, 0.3, 0.85, "NDC");
  st1->SetFillStyle(0);
  st1->SetBorderSize(0);
  st1->SetTextSize(0.04);
  st1->SetTextAlign(12);
  st1->AddText("Station 1");

  TPaveText *st2 = new TPaveText(0.2, 0.8, 0.3, 0.85, "NDC");
  st2->SetFillStyle(0);
  st2->SetBorderSize(0);
  st2->SetTextSize(0.04);
  st2->SetTextAlign(12);
  st2->AddText("Station 2");

  TPaveText *st3 = new TPaveText(0.2, 0.8, 0.3, 0.85, "NDC");
  st3->SetFillStyle(0);
  st3->SetBorderSize(0);
  st3->SetTextSize(0.04);
  st3->SetTextAlign(12);
  st3->AddText("Station 3");

  TPaveText *st4 = new TPaveText(0.2, 0.8, 0.3, 0.85, "NDC");
  st4->SetFillStyle(0);
  st4->SetBorderSize(0);
  st4->SetTextSize(0.04);
  st4->SetTextAlign(12);
  st4->AddText("Station 4");

  TIter next(gDirectory->GetList());
   TObject *obj;
   while ((obj=next())) {
      if (obj->InheritsFrom("TH1")) {
        TH1 *h = (TH1*)obj;
        h->GetXaxis()->SetTitle("#Delta Chamber Efficiency (%)");
	h->GetYaxis()->SetTitle("Number of CSCs");
	h->SetStats(1);
      }
   }

   

  // Draw and save histograms

  TCanvas *DEffLCTCanvas = new TCanvas();
  delta_eff_LCThist->Draw();
  /*
  gPad->Update();
  TPaveStats *st = (TPaveStats*)delta_eff_LCThist->GetListOfFunctions()->FindObject("stats");
  st->SetFillStyle(0);
  st->SetBorderSize(0);
  st->SetY1NDC(0.7);
  st->SetY2NDC(0.8);
  st->SetX1NDC(0.2);
  st->SetX2NDC(0.35);
  st->Draw();
  */
  pt1->Draw();
  pt2->Draw();
  DEffLCTCanvas->SaveAs("DEffLCT.png");
  
  TCanvas *DEffLCTCanvaslog = new TCanvas();
  DEffLCTCanvaslog->SetLogy();
  delta_eff_LCThist->Draw();
  pt1->Draw();
  pt2->Draw();
  DEffLCTCanvaslog->SaveAs("DEffLCTlog.png");

  TCanvas *DEffLCTCanvaslog_1 = new TCanvas();
  DEffLCTCanvaslog_1->SetLogy();vector<vector<EffDataPt>> LCTdata;
  delta_eff_LCThist_1->Draw();
  pt1->Draw();
  pt2->Draw();
  st1->Draw();
  DEffLCTCanvaslog_1->SaveAs("DEffLCTlog1.png");

  TCanvas *DEffLCTCanvas_1cut = new TCanvas();
  delta_eff_LCThist_1cut->Draw();
  pt1->Draw();
  pt2->Draw();
  st1->Draw();
  DEffLCTCanvas_1cut->SaveAs("DEffLCT1cut.png");

  TCanvas *DEffLCTCanvaslog_2 = new TCanvas();
  DEffLCTCanvaslog_2->SetLogy();
  delta_eff_LCThist_2->Draw();
  pt1->Draw();
  pt2->Draw();
  st2->Draw();
  DEffLCTCanvaslog_2->SaveAs("DEffLCTlog2.png");

  TCanvas *DEffLCTCanvas_2cut = new TCanvas();
  delta_eff_LCThist_2cut->Draw();
  pt1->Draw();
  pt2->Draw();
  st2->Draw();
  DEffLCTCanvas_2cut->SaveAs("DEffLCT2cut.png");

  TCanvas *DEffLCTCanvaslog_3 = new TCanvas();
  DEffLCTCanvaslog_3->SetLogy();
  delta_eff_LCThist_3->Draw();
  pt1->Draw();
  pt2->Draw();
  st3->Draw();
  DEffLCTCanvaslog_3->SaveAs("DEffLCTlog3.png");

  TCanvas *DEffLCTCanvas_3cut = new TCanvas();
  delta_eff_LCThist_3cut->Draw();
  pt1->Draw();
  pt2->Draw();
  st3->Draw();
  DEffLCTCanvas_3cut->SaveAs("DEffLCT3cut.png");

  TCanvas *DEffLCTCanvaslog_4 = new TCanvas();
  DEffLCTCanvaslog_4->SetLogy();
  delta_eff_LCThist_4->Draw();
  pt1->Draw();
  pt2->Draw();
  st4->Draw();
  DEffLCTCanvaslog_4->SaveAs("DEffLCTlog4.png");
  
  TCanvas *DEffLCTCanvas_4cut = new TCanvas();
  delta_eff_LCThist_4cut->Draw();
  pt1->Draw();
  pt2->Draw();
  st4->Draw();
  DEffLCTCanvas_4cut->SaveAs("DEffLCT4cut.png");

  TCanvas *DEffSEGCanvas = new TCanvas();
  delta_eff_SEGhist->Draw();
  pt1->Draw();
  pt2->Draw();
  DEffSEGCanvas->SaveAs("DEffSEG.png");
  
  TCanvas *DEffSEGCanvaslog = new TCanvas();
  DEffSEGCanvaslog->SetLogy();
  delta_eff_SEGhist->Draw();
  pt1->Draw();
  pt2->Draw();
  DEffSEGCanvaslog->SaveAs("DEffSEGlog.png");

  TCanvas *DEffSEGCanvaslog_1 = new TCanvas();
  DEffSEGCanvaslog_1->SetLogy();
  delta_eff_SEGhist_1->Draw();
  pt1->Draw();
  pt2->Draw();
  st1->Draw();
  DEffSEGCanvaslog_1->SaveAs("DEffSEGlog1.png");

  TCanvas *DEffSEGCanvas_1cut = new TCanvas();
  delta_eff_SEGhist_1cut->Draw();
  pt1->Draw();
  pt2->Draw();
  st1->Draw();
  DEffSEGCanvas_1cut->SaveAs("DEffSEG1cut.png");

  TCanvas *DEffSEGCanvaslog_2 = new TCanvas();
  DEffSEGCanvaslog_2->SetLogy();
  delta_eff_SEGhist_2->Draw();
  pt1->Draw();
  pt2->Draw();
  st2->Draw();
  DEffSEGCanvaslog_2->SaveAs("DEffSEGlog2.png");

  TCanvas *DEffSEGCanvas_2cut = new TCanvas();
  delta_eff_SEGhist_2cut->Draw();
  pt1->Draw();
  pt2->Draw();
  st2->Draw();
  DEffSEGCanvas_2cut->SaveAs("DEffSEG2cut.png");

  TCanvas *DEffSEGCanvaslog_3 = new TCanvas();
  DEffSEGCanvaslog_3->SetLogy();
  delta_eff_SEGhist_3->Draw();
  pt1->Draw();
  pt2->Draw();
  st3->Draw();
  DEffSEGCanvaslog_3->SaveAs("DEffSEGlog3.png");

  TCanvas *DEffSEGCanvas_3cut = new TCanvas();
  delta_eff_SEGhist_3cut->Draw();
  pt1->Draw();
  pt2->Draw();
  st3->Draw();
  DEffSEGCanvas_3cut->SaveAs("DEffSEG3cut.png");

  TCanvas *DEffSEGCanvaslog_4 = new TCanvas();
  DEffSEGCanvaslog_4->SetLogy();
  delta_eff_SEGhist_4->Draw();
  pt1->Draw();
  pt2->Draw();
  st4->Draw();
  DEffSEGCanvaslog_4->SaveAs("DEffSEGlog4.png");

  TCanvas *DEffSEGCanvas_4cut = new TCanvas();
  delta_eff_SEGhist_4cut->Draw();
  pt1->Draw();
  pt2->Draw();
  st4->Draw();
  DEffSEGCanvas_4cut->SaveAs("DEffSEG4cut.png");
  
  // Write hists to file

  fout.Write();
}
