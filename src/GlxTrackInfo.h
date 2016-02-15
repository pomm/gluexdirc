// -----------------------------------------
// GlxTrackInfo.h
//
// Created on: 18.10.2013
// Author: R.Dzhygadlo at gsi.de
// -----------------------------------------

#ifndef GlxTrackInfo_h
#define GlxTrackInfo_h 1

#include "GlxPhotonInfo.h"

#include "TObject.h"
#include "TClonesArray.h"
#include "TString.h"
#include "TVector3.h"
#include <vector>

class GlxTrackInfo : public TObject {

public:    
  
  // Default constructor
  GlxTrackInfo ();
  
  // Default destructor
  ~GlxTrackInfo ();

  // Copy constructor 
  GlxTrackInfo (const GlxTrackInfo& val):TObject() { *this = val; }  
  
  // Mutators
  void SetMcPdg(Int_t val)              {fMcPdg = val;}
  void SetMcMomentum(TVector3 val)      {fMcMomentum = val;}
  void SetMcMomentumInBar(TVector3 val) {fMcMomentumInBar = val;}
  void SetMcCherenkov(Double_t val)     {fMcCherenkov = val;}
  void SetMcTimeInBar(Double_t val)     {fMcTimeInBar = val;}

  void SetPdg(Int_t val)                {fPdg = val;}
  void SetMomentum(TVector3 val)        {fMomentum = val;}
  void SetCherenkov(Double_t val)       {fCherenkov = val;}
  void SetAngle(Double_t val)           {fAngle = val;}
  void SetInfo(TString val)	        {fInfo = val;}

  void AddPhoton(GlxPhotonInfo photon);
  void AddInfo(TString val)	        {fInfo += val;}

  // Accessors 
  Int_t    GetMcPdg()	                {return fMcPdg;}    
  TVector3 GetMcMomentum()	        {return fMcMomentum;}
  TVector3 GetMcMomentumInBar()	        {return fMcMomentumInBar;}
  Double_t GetMcCherenkov()	        {return fMcCherenkov;}
  Double_t GetMcTimeInBar()	        {return fMcTimeInBar;}
  
  Int_t    GetPdg()	                {return fPdg;}    
  TVector3 GetMomentum()	        {return fMomentum;}
  Double_t GetCherenkov()	        {return fCherenkov;}
  Double_t GetAngle()	                {return fAngle;}
  TString  GetInfo()	                {return fInfo;}

  Int_t    GetPhotonSize()	        {return fPhotonSize;}
  GlxPhotonInfo GetPhoton(Int_t id)     {return fPhotonArray[id];}

protected:

  std::vector<GlxPhotonInfo> fPhotonArray;
  Int_t fPhotonSize;

  Int_t    fMcPdg;
  TVector3 fMcMomentum;
  TVector3 fMcMomentumInBar;
  Double_t fMcCherenkov;
  Double_t fMcTimeInBar;

  Int_t    fPdg;
  TVector3 fMomentum;
  Double_t fCherenkov;
  Double_t fAngle;
  TString  fInfo;
    
  ClassDef(GlxTrackInfo,1)
};

#endif
