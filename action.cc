#include "action.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);
    
    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
}
//this is a simple code that Initializes the actions that will take place using our header file
