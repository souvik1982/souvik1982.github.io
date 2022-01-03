int DsAnalysis()
{

  TFile *signalFile = new TFile("MyDChainFile_Data_50.root");
  signalFile->cd("MyDChainProc");
  TTree *signalTree = (TTree*)gDirectory->Get("nt5");
  
  TFile *bgFile = new TFile("MyDChainFile_Data_32.root");
  bgFile->cd("MyDChainProc");
  TTree *bgTree = (TTree*)gDirectory->Get("nt5");  
  
  TH1D *phiM_signal = new TH1D("phiM_signal", "phiM_signal", 100, .95, 1.15); phiM_signal->SetLineColor(kRed);
  TH1D *phiM_bg = new TH1D("phiM_bg", "phiM_bg", 100, .95, 1.15); phiM_bg->SetLineColor(kBlue);
  signalTree->Draw("phiM>>phiM_signal");
  bgTree->Draw("phiM>>phiM_bg");  
  
  TH1D *dsPlusM_signal = new TH1D("dsPlusM_signal", "dsPlusM_signal", 100, 1.9, 2.1); dsPlusM_signal->SetLineColor(kRed);
  TH1D *dsPlusM_bg = new TH1D("dsPlusM_bg", "dsPlusM_bg", 100, 1.9, 2.1); dsPlusM_bg->SetLineColor(kBlue);
  signalTree->Draw("dsPlusM>>dsPlusM_signal", "abs(phiM-1.0195)<0.015");
  bgTree->Draw("dsPlusM>>dsPlusM_bg", "abs(phiM-1.0195)<0.015");
  
  TH1D *DeltaE_signal = new TH1D("DeltaE_signal", "DeltaE", 100, -0.1, 0.2); DeltaE_signal->SetLineColor(kRed);
  TH1D *DeltaE_bg = new TH1D("DeltaE_bg", "DeltaE", 100, -0.1, 0.2); DeltaE_bg->SetLineColor(kBlue);
  signalTree->Draw("DeltaE>>DeltaE_signal", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02");
  bgTree->Draw("DeltaE>>DeltaE_bg", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02");
  
  TH1D *MBC_signal = new TH1D("MBC_signal", "MBC", 100, 2., 2.2); MBC_signal->SetLineColor(kRed);
  TH1D *MBC_bg = new TH1D("MBC_bg","MBC", 100, 2., 2.2); MBC_bg->SetLineColor(kBlue);
  signalTree->Draw("MBC>>MBC_signal", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05");
  bgTree->Draw("MBC>>MBC_bg", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05");
  
  TH1D *DeltaM_signal = new TH1D("DeltaM_signal", "DeltaM", 100, 0.0, 0.2); DeltaM_signal->SetLineColor(kRed);
  TH1D *DeltaM_bg = new TH1D("DeltaM_bg", "DeltaM", 100, 0.0, 0.2); DeltaM_bg->SetLineColor(kBlue);
  signalTree->Draw("DeltaM>>DeltaM_signal", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
  bgTree->Draw("DeltaM>>DeltaM_bg", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
  
  TH1D *RatioHitsToExpected_electron_signal = new TH1D("RatioHitsToExpected_electron_signal", "RatioHitsToExpected_electron_signal", 10, 0., 1.); RatioHitsToExpected_electron_signal->SetLineColor(kRed);
  TH1D *RatioHitsToExpected_electron_bg = new TH1D("RatioHitsToExpected_electron_bg", "RatioHitsToExpected_electron_bg", 10, 0., 1.); RatioHitsToExpected_electron_bg->SetLineColor(kRed);
  signalTree->Draw("kElectron1RatioHitsToExpected>>RatioHitsToExpected_electron_signal", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
  bgTree->Draw("kElectron1RatioHitsToExpected>>RatioHitsToExpected_electron_bg", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
  
  TH1D *RatioHitsToExpected_positron_signal = new TH1D("RatioHitsToExpected_positron_signal", "RatioHitsToExpected_positron_signal", 10, 0., 1.); RatioHitsToExpected_positron_signal->SetLineColor(kRed);
  TH1D *RatioHitsToExpected_positron_bg = new TH1D("RatioHitsToExpected_positron_bg", "RatioHitsToExpected_positron_bg", 10, 0., 1.); RatioHitsToExpected_positron_bg->SetLineColor(kRed);
  signalTree->Draw("kElectron2RatioHitsToExpected>>RatioHitsToExpected_positron_signal", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
  bgTree->Draw("kElectron2RatioHitsToExpected>>RatioHitsToExpected_positron_bg", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
  
  TH1D *HitsExpected_electron_signal = new TH1D("HitsExpected_electron_signal", "HitsExpected_electron_signal", 100, 0., 100.);
  TH1D *HitsExpected_electron_bg = new TH1D("HitsExpected_electron_bg", "HitsExpected_electron_bg", 100, 0., 100.);
  signalTree->Draw("kElectron1HitsExpected>>HitsExpected_electron_signal", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
  bgTree->Draw("kElectron1HitsExpected>>HitsExpected_electron_bg", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
  
  TH1D *HitsExpected_positron_signal = new TH1D("HitsExpected_positron_signal", "HitsExpected_positron_signal", 100, 0., 100.);
  TH1D *HitsExpected_positron_bg = new TH1D("HitsExpected_positron_bg", "HitsExpected_positron_bg", 100, 0., 100.);
  signalTree->Draw("kElectron2HitsExpected>>HitsExpected_positron_signal", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
  bgTree->Draw("kElectron2HitsExpected>>HitsExpected_positron_bg", "abs(phiM-1.0195)<0.015 && abs(dsPlusM-1.96849)<0.02 && abs(DeltaE)<0.05 && abs(MBC-2.112)<0.005");
    
  
  TCanvas *phiM = new TCanvas("phiM");
  phiM->Divide(1,2);
  phiM->cd(1);
  phiM_signal->Draw();
  phiM->cd(2);
  phiM_bg->Draw(); 
  
  TCanvas *dsPlusM = new TCanvas("dsPlusM");
  dsPlusM->Divide(1,2);
  dsPlusM->cd(1);
  dsPlusM_signal->Draw();
  dsPlusM->cd(2);
  dsPlusM_bg->Draw();
  
  TCanvas *DeltaE = new TCanvas("DeltaE");
  DeltaE->Divide(1,2);
  DeltaE->cd(1);
  DeltaE_signal->Draw();
  DeltaE->cd(2);
  DeltaE_bg->Draw();
  
  TCanvas *MBC = new TCanvas("MBC");
  MBC->Divide(1,2);
  MBC->cd(1);
  MBC_signal->Draw();
  MBC->cd(2);
  MBC_bg->Draw();
  
  TCanvas *DeltaM = new TCanvas("DeltaM");
  DeltaM->Divide(1,2);
  DeltaM->cd(1);
  DeltaM_signal->Draw();
  DeltaM->cd(2);
  DeltaM_bg->Draw();
  
  TCanvas *RatioHitsToExpected_electron = new TCanvas("RatioHitsToExpected_electron");
  RatioHitsToExpected_electron->Divide(1,2);
  RatioHitsToExpected_electron->cd(1);
  RatioHitsToExpected_electron_signal->Draw();
  RatioHitsToExpected_electron->cd(2);
  RatioHitsToExpected_electron_bg->Draw();
  
  TCanvas *RatioHitsToExpected_positron = new TCanvas("RatioHitsToExpected_positron");
  RatioHitsToExpected_positron->Divide(1,2);
  RatioHitsToExpected_positron->cd(1);
  RatioHitsToExpected_positron_signal->Draw();
  RatioHitsToExpected_positron->cd(2);
  RatioHitsToExpected_positron_bg->Draw();
  
  TCanvas *HitsExpected_electron = new TCanvas("HitsExpected_electron");
  HitsExpected_electron->Divide(1,2);
  HitsExpected_electron->cd(1);
  HitsExpected_electron_signal->Draw();
  HitsExpected_electron->cd(2);
  HitsExpected_electron_bg->Draw();
  
  TCanvas *HitsExpected_positron = new TCanvas("HitsExpected_positron");
  HitsExpected_positron->Divide(1,2);
  HitsExpected_positron->cd(1);
  HitsExpected_positron_signal->Draw();
  HitsExpected_positron->cd(2);
  HitsExpected_positron_bg->Draw();
  
  
}


