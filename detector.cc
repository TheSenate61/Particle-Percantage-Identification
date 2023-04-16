#include "detector.hh"
#include "G4RunManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4OpticalPhoton.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) :
G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}


G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    G4Track* aTrack = aStep->GetTrack();
    G4ParticleDefinition* particleDef = aTrack->GetDefinition();
    G4double energyDeposit = aStep->GetTotalEnergyDeposit();

    if (particleDef == G4OpticalPhoton::OpticalPhotonDefinition()) {
        G4double photonEnergy = aTrack->GetTotalEnergy();
        photonEnergy = photonEnergy/6.62607015E-34;
        G4cout << "Optical photon produced with energy: " << photonEnergy << " MeV" << G4endl;
        G4CsvAnalysisManager *man = G4CsvAnalysisManager::Instance();
        G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
        man->FillNtupleIColumn(0, evt);
        man->FillNtupleDColumn(1, photonEnergy); 
        man->AddNtupleRow(0);     
    }

    return true;
}
//In this .cc file we first get all total energy deposited in the simulation
//Then write an if code that will extract only the optical photons and give us their total energies
//If you only write the total energy deposited verison of it you will see a lot of '0's because the optical photons were newly created therefore they wont be able to deposit any energy
//In the last part we fill the csv file with the resulted optical photon energies
