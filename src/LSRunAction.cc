#include "LSRunAction.hh"
#include "LSAnalysisManager.hh"

LSRunAction::LSRunAction()
: G4UserRunAction()
{;}


LSRunAction::~LSRunAction()
{;}

void LSRunAction::BeginOfRunAction(const G4Run*)
{
    G4cout << "Begin of One Run" << G4endl;
    LSAnalysisManager* analysis = LSAnalysisManager::getInstance();
    analysis->book();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LSRunAction::EndOfRunAction(const G4Run* )
{
    LSAnalysisManager* analysis = LSAnalysisManager::getInstance();
    analysis->finish();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


