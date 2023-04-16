#include "generator.hh"
#include "G4FieldManager.hh"
#include "G4ClassicalRK4.hh"
#include "Randomize.hh"
#include "G4KaonMinus.hh"
#include "G4Electron.hh"
#include "G4PionMinus.hh"
#include "G4RunManager.hh"
#include "G4RunM.hh"
MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    
    // Generate protons
    G4ParticleDefinition *particleP = particleTable->FindParticle("proton");
    G4ThreeVector posP(0.,0.,0.);
    G4ThreeVector momP(0.,0.,1.);
    fParticleGun->SetParticleDefinition(particleP);
    fParticleGun->SetParticlePosition(posP);
    fParticleGun->SetParticleMomentumDirection(momP);
    G4double proton_energy = G4UniformRand() * (1.4 - 0.7) + 0.7; // generate a random energy
    fParticleGun->SetParticleEnergy(proton_energy * GeV);
    fParticleGun->GeneratePrimaryVertex(anEvent);
    
    // Generate electrons
    G4ParticleDefinition *particleE = particleTable->FindParticle("e-");
    G4ThreeVector posE(0.,0.,0.);
    G4ThreeVector momE(0.,0.,1.);
    fParticleGun->SetParticleDefinition(particleE);
    fParticleGun->SetParticlePosition(posE);
    fParticleGun->SetParticleMomentumDirection(momE);
    G4double electron_energy = G4UniformRand() * (1.8 - 0.7) + 0.7; // generate a random energy
    fParticleGun->SetParticleEnergy(electron_energy * GeV);
    fParticleGun->GeneratePrimaryVertex(anEvent);
    
    // Generate kaons
    G4ParticleDefinition *particleK = particleTable->FindParticle("kaon-");
    G4ThreeVector posK(0.,0.,0.);
    G4ThreeVector momK(0.,0.,1.);
    fParticleGun->SetParticleDefinition(particleK);   
    fParticleGun->SetParticlePosition(posK);
    fParticleGun->SetParticleMomentumDirection(momK);   
    G4double kaon_energy = G4UniformRand() * (1.8 - 0.7) + 0.7; // generate a random energy
    fParticleGun->SetParticleEnergy(kaon_energy * GeV);
    fParticleGun->GeneratePrimaryVertex(anEvent);
    
    // Generate pions
    G4ParticleDefinition *particlePi = particleTable->FindParticle("pi-");
    G4ThreeVector posPi(0.,0.,0.);
    G4ThreeVector momPi(0.,0.,1.);
    fParticleGun->SetParticleDefinition(particlePi);   
    fParticleGun->SetParticlePosition(posPi);
    fParticleGun->SetParticleMomentumDirection(momPi);   
    G4double pion_energy = G4UniformRand() * (1.8 - 0.7) + 0.7; // generate a random energy
    fParticleGun->SetParticleEnergy(pion_energy * GeV);
    fParticleGun->GeneratePrimaryVertex(anEvent);

    G4CsvAnalysisManager *man = G4CsvAnalysisManager::Instance();
    man->FillNtupleDColumn(2, proton_energy);
    man->FillNtupleDColumn(3, kaon_energy);
    man->FillNtupleDColumn(4, electron_energy);
    man->FillNtupleDColumn(5, pion_energy);
    man->AddNtupleRow(0);

}
//This code creates protons,kaons,electrons and pions
//They all have the same positions and momentums but have different energy levels which are decided randomly using 'G4UniformRand'
