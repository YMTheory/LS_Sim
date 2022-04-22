
#include "G4ProcessManager.hh"
#include "LSPhysicsList.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4DecayPhysics.hh"

#include "G4OpticalPhysics.hh"
#include "G4SystemOfUnits.hh"

// particles

#include "G4OpticalPhoton.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"


LSPhysicsList::LSPhysicsList() : G4VModularPhysicsList()
{
    defaultCutValue = 1.0*mm;

    emPhysicsList = new G4EmLivermorePhysics();
    decayPhysicsList = new G4DecayPhysics();

}

LSPhysicsList::~LSPhysicsList() {
    delete emPhysicsList;
    delete decayPhysicsList;
}

void LSPhysicsList::SetCuts() {
    //SetCutsWithDefault();

    const G4double cutForGamma = defaultCutValue;
    const G4double cutForElectron = defaultCutValue;
    const G4double cutForPositron = defaultCutValue;

    SetCutValue(cutForGamma, "gamma");
    SetCutValue(cutForElectron, "e-");
    SetCutValue(cutForPositron, "e+");

}


void LSPhysicsList::ConstructParticle()
{

    G4OpticalPhoton::OpticalPhotonDefinition();

    G4Gamma::GammaDefinition();
    G4Electron::ElectronDefinition();
    G4Positron::PositronDefinition();

    decayPhysicsList->ConstructParticle();
    emPhysicsList->ConstructParticle();

}

void LSPhysicsList::ConstructProcess()
{
    AddTransportation();
    ConstructOpticalProcess();
    emPhysicsList->ConstructProcess();
    decayPhysicsList->ConstructProcess();
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#include "G4OpAbsorption.hh"
#include "G4OpRayleigh.hh"
#include "G4OpBoundaryProcess.hh"

void LSPhysicsList::ConstructOpticalProcess()
{

    G4OpAbsorption* theAbsProcess         = new G4OpAbsorption();
    G4OpRayleigh* theRayProcess           = new G4OpRayleigh();
    G4OpBoundaryProcess* theBdProcess     = new G4OpBoundaryProcess();
    theBdProcess->SetInvokeSD(false);
    auto particleIterator = GetParticleIterator();
    particleIterator->reset();
    while( (*particleIterator)() ){

        G4ParticleDefinition* particle = particleIterator->value();
        G4ProcessManager* pmanager = particle->GetProcessManager();
        if (theAbsProcess->IsApplicable(*particle)) {
            pmanager -> AddDiscreteProcess(theAbsProcess);
            G4cout << " ===> Registered Absorption Process " << G4endl;
        }

        if(theRayProcess->IsApplicable(*particle)) {
            pmanager -> AddDiscreteProcess(theRayProcess);
            G4cout << " ===> Registered Rayleigh Scatterinng Process " << G4endl;
        }

        if(theBdProcess->IsApplicable(*particle)) {
            pmanager -> AddDiscreteProcess(theBdProcess);
            G4cout << " ===> Registered Boundary Process " << G4endl;
        }
    }
}
