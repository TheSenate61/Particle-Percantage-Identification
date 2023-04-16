#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4CsvAnalysisManager.hh"
class MySensitiveDetector : public G4VSensitiveDetector
{
public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();
private:
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
    
};


#endif

//Here is the header file for our detector these lines of code will guide us to create a detector for the detection of optical photons in the simulation
