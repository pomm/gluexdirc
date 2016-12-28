#define glx__sim
//#include "../src/GlxHit.h"
//#include "../src/GlxEvent.h"
//#include "../src/GlxLutNode.h"
#include "glxtools.C"

Int_t    fNEntries(0);

void drawLight(TString infile="laser44.root"){
  if(infile=="") return;
	const Int_t Nfibers = 1;

  TFile* output = new TFile("lighttime.root", "RECREATE");	

  TH1F * hTime = new TH1F("time",";time, [ns];entries, [#]",300,-25.,275.);

  gSystem->Load("../build/libGlxDirc.so");
  TFile* f = new TFile(infile);
  TTree* t = (TTree*)f->Get("glxlut");
  TClonesArray *fLut[Nfibers];
  for(int ifib=0;ifib<Nfibers;ifib++){
  fLut[ifib] = new TClonesArray("GlxLutNode");
  //t->SetBranchAddress("LUT_0", &fLut);
  t->SetBranchAddress(Form("LUT_%d",ifib),&fLut[ifib]);
  }
  t->GetEntry(0);

  Double_t evtime;	
  GlxLutNode* node;
  Int_t mcpid, pixid;
  for(int i=0; i<20000; i++){
	  for(int jfib=0;jfib<Nfibers;jfib++){
		node = (GlxLutNode*) fLut[jfib]->At(i);
		Int_t size = node->Entries();
		if(size > 0){
  			for(int u=0; u<size; u++){
				evtime = node->GetTime(u);
				hTime->Fill(evtime);
			}
		}
	 } 
  }
  output->Write();

  TCanvas* c = new TCanvas("c","c",800,600);
  TF1* fit = new TF1("fit","gaus(0)",0.,10.);
	

  TCanvas* coc = new TCanvas("coc","coc", 500, 500);
	coc->SetRightMargin(0.1);
	coc->SetTopMargin(0.1);
	coc->SetLeftMargin(0.05);
	coc->SetBottomMargin(0.05);
  coc->cd();
  hTime->Draw();
  
}

