#include "LSPhysicsListMessenger.hh"
#include "LSPhysicsList.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithABool.hh"

LSPhysicsListMessenger::LSPhysicsListMessenger(LSPhysicsList* phyList)
    : LSPhyList(phyList)

{

    phyDirectory = new G4UIdirectory("/LS/phys/");
    phyDirectory -> SetGuidance("Physics List Registeration.");

    opticalCmd = new G4UIcmdWithABool("/LS/phys/enableoptical", this);
    opticalCmd -> SetGuidance("If Enable Optical Simulation.");
    opticalCmd -> SetParameterName("enableoptical", true);
    opticalCmd -> SetDefaultValue(true);


}



LSPhysicsListMessenger::~LSPhysicsListMessenger()
{
    delete opticalCmd;
    delete phyDirectory;
}


void LSPhysicsListMessenger::SetNewValue
(G4UIcommand* cmd, G4String newValues) {
    
    if (cmd == opticalCmd) 
        LSPhyList -> DoOpticalSim(opticalCmd->GetNewBoolValue(newValues));

    else
        G4cout << "Error: Unknow Command !!! " << G4endl;
}

