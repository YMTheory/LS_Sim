#include "MyAnalysisManager.hh"
#include "MyRootBasedAnalysis.hh"

MyAnalysisManager* MyAnalysisManager::fInstance = 0;

MyAnalysisManager::MyAnalysisManager()
{
    fMyRootBasedAnalysis = new MyRootBasedAnalysis();
    fMyRootBasedAnalysis->Activated();
    
}

MyAnalysisManager::~MyAnalysisManager()
{}

void MyAnalysisManager::BeginOfRunAction()
{
    fMyRootBasedAnalysis->BeginOfRunAction();
}


void MyAnalysisManager::EndOfRunAction()
{
    fMyRootBasedAnalysis->EndOfRunAction();
}


void MyAnalysisManager::BeginOfEventAction(const G4Event* evt)
{
    fMyRootBasedAnalysis->BeginOfEventAction(evt);
}

void MyAnalysisManager::EndOfEventAction(const G4Event* evt)
{
    fMyRootBasedAnalysis->EndOfEventAction(evt);
}


void MyAnalysisManager::PreTrackingAction(const G4Track* aTrack)
{
    fMyRootBasedAnalysis->PreTrackingAction(aTrack);
}

void MyAnalysisManager::PostTrackingAction(const G4Track* aTrack)
{
    fMyRootBasedAnalysis->PostTrackingAction(aTrack);
}


void MyAnalysisManager::SteppingAction(const G4Step* aStep)
{
    fMyRootBasedAnalysis->SteppingAction(aStep);
}



void MyAnalysisManager::SetFileName(G4String val)
{   
    fMyRootBasedAnalysis->SetFileName(val);
}


void MyAnalysisManager::SetBirks1(G4double val)
{
    fMyRootBasedAnalysis->SetBirks1(val);
}


void MyAnalysisManager::SetActivate(G4bool val) {
    if (val)
        fMyRootBasedAnalysis->Activated();
    else
        fMyRootBasedAnalysis->Deactivated();

}

void MyAnalysisManager::AddHitTime(G4double val) {
    fMyRootBasedAnalysis->AddHitTime(val);
}

void MyAnalysisManager::AddHitX(G4double val) {
    fMyRootBasedAnalysis->AddHitX(val);
}

void MyAnalysisManager::AddHitY(G4double val) {
    fMyRootBasedAnalysis->AddHitY(val);
}

void MyAnalysisManager::AddHitZ(G4double val) {
    fMyRootBasedAnalysis->AddHitZ(val);
}


void MyAnalysisManager::SetNPE_tot(G4int val) {
    fMyRootBasedAnalysis->SetNPE_tot(val);
}

void MyAnalysisManager::SetNPE_Cer(G4int val) {
    fMyRootBasedAnalysis->SetNPE_Cer(val);
}

void MyAnalysisManager::SetNPE_sct(G4int val) {
    fMyRootBasedAnalysis->SetNPE_sct(val);
}

