#include "LSParticleSourceMessenger.hh"
#include "LSParticleSource.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "G4OpticalPhoton.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4ios.hh"

LSParticleSourceMessenger::LSParticleSourceMessenger(LSParticleSource* fPtclGun)
    : fParticleGun(fPtclGun)
{
    gunDirectory = new G4UIdirectory("/LS/gun/");
    gunDirectory -> SetGuidance("Particle Source Control Commands");

    // particle type :
    particleCmd = new G4UIcmdWithAString("/LS/gun/particle", this);
    particleCmd->SetGuidance("Set particle type.");
    particleCmd->SetParameterName("particleName", true);
    particleCmd->SetDefaultValue("e-");

    // momentum type :
    momTypeCmd = new G4UIcmdWithAString("/LS/gun/momtype", this);
    momTypeCmd->SetGuidance("Set momentum type.");
    momTypeCmd->SetParameterName("momType", true);
    momTypeCmd->SetDefaultValue("iso");

    // momentum vector :
    momCmd = new G4UIcmdWith3VectorAndUnit("/LS/gun/mom", this);
    momCmd->SetGuidance("Set momentum of the particle.");
    momCmd->SetParameterName("PX", "PY", "PZ", true, true);
    momCmd->SetDefaultUnit("MeV");
    momCmd->SetUnitCandidates("eV MeV GeV");

    // kinetic energy :
    energyCmd = new G4UIcmdWithADoubleAndUnit("/LS/gun/energy", this);
    energyCmd->SetGuidance("Set kinetic energy.");
    energyCmd->SetParameterName("KE", true);
    energyCmd->SetDefaultValue(1);
    energyCmd->SetDefaultUnit("MeV");
    energyCmd->SetUnitCandidates("eV MeV GeV");

    // position :
    posCmd = new G4UIcmdWith3VectorAndUnit("/LS/gun/position", this);
    posCmd->SetGuidance("Set particle position.");
    posCmd->SetParameterName("X", "Y", "Z", true, true);
    posCmd->SetDefaultUnit("mm");
    posCmd->SetUnitCandidates("mm cm m");


}

LSParticleSourceMessenger::~LSParticleSourceMessenger()
{
    delete particleCmd;
    delete momTypeCmd;
    delete momCmd;
    delete posCmd;
    delete energyCmd;

    delete gunDirectory;
}




void LSParticleSourceMessenger::SetNewValue
(G4UIcommand* cmd, G4String newValues) {

    if (cmd == particleCmd) {
        G4ParticleDefinition* pd = particleTable->FindParticle(newValues);
        if (pd != NULL)
            fParticleGun->SetParticleDefinition(pd);
    }

    else if (cmd == momTypeCmd)
        fParticleGun->SetMomentumType(newValues);

    else if (cmd == momCmd)
        fParticleGun->SetMomentum(momCmd->GetNew3VectorValue(newValues));

    else if (cmd == energyCmd) 
        fParticleGun->SetKineticEnergy(energyCmd->GetNewDoubleValue(newValues));

    else if (cmd == posCmd)
        fParticleGun->SetPosition(posCmd->GetNew3VectorValue(newValues));

    else
        G4cout << "Error: Unknow Command !!! " << G4endl;

}





