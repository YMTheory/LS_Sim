#include "MyAnalysisManager.hh"
#include "MyRootBasedAnalysis.hh"

MyAnalysisManager* MyAnalysisManager::fInstance = 0;

MyAnalysisManager::MyAnalysisManager()
{
    fMyRootBasedAnalysis = new MyRootBasedAnalysis();

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












