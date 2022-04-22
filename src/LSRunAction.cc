#include "LSRunAction.hh"

LSRunAction::LSRunAction()
: G4UserRunAction()
{;}


LSRunAction::~LSRunAction()
{;}

void LSRunAction::BeginOfRunAction(const G4Run*)
{
    G4cout << "Begin of One Run" << G4endl;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LSRunAction::EndOfRunAction(const G4Run* )
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


