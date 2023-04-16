#include "run.hh"
#include "G4CsvAnalysisManager.hh"
MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}


void MyRunAction::BeginOfRunAction(const G4Run*)
{
    G4CsvAnalysisManager *man = G4CsvAnalysisManager::Instance();
    
    man->SetVerboseLevel(1);
    man->SetNtupleMerging(true);
    
    man->CreateNtuple("my_ntuple", "Event ID and Particle Energies");
    man->CreateNtupleIColumn("EventID");
    man->CreateNtupleDColumn("PhotonEnergy");
    man->CreateNtupleDColumn("ProtonEnergy");
    man->CreateNtupleDColumn("KaonEnergy");
    man->CreateNtupleDColumn("ElectronEnergy");
    man->CreateNtupleDColumn("PionEnergy");

    
    man->FinishNtuple();
    man->OpenFile("output.csv");

}
void MyRunAction::EndOfRunAction(const G4Run*)
{
    G4CsvAnalysisManager *man = G4CsvAnalysisManager::Instance();
    
    man->Write();
    man->CloseFile();


}

//This code is pretty basic but super important
//We create the csv file that we will edit and later be used for machine learning
