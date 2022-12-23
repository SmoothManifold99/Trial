#include <iostream>
#include <TMath.h>
#include <TF1.h>
#include <TGraph.h>
#include <TGraphErrors.h>

void calib()
{
TCanvas *c1 = new TCanvas("c1");

TGraphErrors *g1 = new TGraphErrors("/Users/filippopesce/opt/anaconda3/envs/labfisica/macros/Calib_Im.txt.rtf");
g1->SetTitle("Calibration");
g1->GetYaxis()->SetTitle("Energy[keV]");
g1->GetXaxis()->SetTitle("channel");
g1->SetMarkerStyle(20);
g1->Draw("AP");

TF1 *f1 = new TF1("f1","[0]+[1]*x",0,20000);
f1->SetParameters(0,1);
f1->SetParameter(1,1);

TF1 *f2 = new TF1("f2","[0]*1/(x)",0,100);
f2->SetParameter(0,1);

g1->Fit("f1");
}