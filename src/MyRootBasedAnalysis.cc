#include "MyRootBasedAnalysis.hh"

#include "G4Material.hh"
#include "G4OpticalPhoton.hh"

#include "TFile.h"
#include "TTree.h"


MyRootBasedAnalysis::MyRootBasedAnalysis()
{
    SetFileName("output.root");
}

MyRootBasedAnalysis::~MyRootBasedAnalysis()
{
}

void MyRootBasedAnalysis::BeginOfRunAction()
{
    if (not active)
        return;

    fRootFp = new TFile(fFileName, "recreate");
    if (!fRootFp)
    {
        G4cout << "\n====>MyRootBasedAnalysis::BeginOfRunAction(): "
               << "cannot open " << fFileName << G4endl;
        return;
    }

    fTree = new TTree("sim", "Tree of data events");
    fTree->Branch("edep", &edep, "edep/F");
    fTree->Branch("Qedep", &qedep, "qedep/F");

    return;

}

void MyRootBasedAnalysis::EndOfRunAction()
{
    if (not active)
        return;
    if (!fRootFp)
    {
        G4cout << "\n====>MyRootBasedAnalysis::EndOfRunAction(): "
               << "cannot open " << fFileName << G4endl;
        return;
    }

    //------- add your codes down here
    //

    G4cout << "\n====>In total " << fTree->GetEntries() << " Events have been stored." << G4endl;
    fRootFp->Write();
    fRootFp->Close();
    return;
}


void MyRootBasedAnalysis::BeginOfEventAction(const G4Event* )
{
    if (!active)
        return;

    // Initialization :
    edep = 0.;
    qedep = 0.;

    //------- add your codes down here
    //
    return;
}


void MyRootBasedAnalysis::EndOfEventAction(const G4Event* )
{
    if (!active)
        return;


    fTree->Fill();

    //------- add your codes down here
    //
    return;
}


void MyRootBasedAnalysis::PreTrackingAction(const G4Track* aTrack)
{
    if (!active)
        return;

    //------- add your codes down here
    return;
}


void MyRootBasedAnalysis::PostTrackingAction(const G4Track* aTrack)
{
    if (!active)
        return;

    //------- add your codes down here
    //
    return;
}


void MyRootBasedAnalysis::SteppingAction(const G4Step* aStep)
{
    if (!active)
        return;

    //------- add your codes down here
    G4Track* aTrack = aStep->GetTrack();
    G4double m_edep = aStep->GetTotalEnergyDeposit();

    if (m_edep > 0 and aTrack->GetDefinition()!=G4OpticalPhoton::Definition()){
        edep += m_edep; 
    }

    return;
}







