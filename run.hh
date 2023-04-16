#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"

#include "G4CsvAnalysisManager.hh"

class MyRunAction : public G4UserRunAction
{
public:
    MyRunAction();
    ~MyRunAction();
    
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
    
};

#endif
//This header file will help us run the simulation and give actual results