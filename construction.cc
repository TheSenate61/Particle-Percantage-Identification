#include "construction.hh"
MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_GLASS_LEAD");  //Creation Of The World Material which is also the radiator out of Glass
    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m); //Creation of the Box where out simulation will take place
    
    //Setting up the Radiator Environment
    G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2};
    G4double rindexWorld[2] = {1.1,1.1};
    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);
    worldMat->SetMaterialPropertiesTable(mptWorld);
    
    
    //Defining the logical volumes
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    G4LogicalVolume *logicRadiator = new G4LogicalVolume(solidRadiator,target_radiator, "logicalRadiator");	
    //Defining the Physical Volumes
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),logicWorld, "physWorld", 0, false, 0, true);
    G4VPhysicalVolume *physRadiator = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicRadiator, "physRadiator", logicWorld, false, 0, true);
    
    //Defining the detector that detects the optical photons from the cherenkov light
    G4Box *solidDetector = new G4Box("solidDetector", 0.5*m,0.5*m,0.5*m); 
    logicDetector = new G4LogicalVolume(solidDetector,worldMat,"logicDetector");
    G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicDetector, "physDetector", logicWorld, false, 0, true);
    
    
    return physWorld;
    
}

void MyDetectorConstruction::ConstructSDandField()
{
    MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
    
    logicDetector->SetSensitiveDetector(sensDet);
}
//this .cc file defines the information about the materials that we will use in the simulation
