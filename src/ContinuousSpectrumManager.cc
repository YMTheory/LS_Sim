#include "ContinuousSpectrumManager.hh"

#include <TFile.h>
#include <TTree.h>

ContinuousSpectrumManager* ContinuousSpectrumManager::fInstance = 0;

ContinuousSpectrumManager::ContinuousSpectrumManager()
{}

ContinuousSpectrumManager::~ContinuousSpectrumManager()
{}


void ContinuousSpectrumManager::BeginOfRunAction()
{
}


void ContinuousSpectrumManager::EndOfRunAction()
{
}


void ContinuousSpectrumManager::BeginOfEventAction(const G4Event* evt)
{
}

void ContinuousSpectrumManager::EndOfEventAction(const G4Event* evt)
{
}

void ContinuousSpectrumManager::LoadContinuousSpectrum()
{
    TFile* ff = new TFile(filename, "read");
    TTree* tt = (TTree*)ff->Get(treename);
    G4cout << "Tree entry = " << tt->GetEntries() << G4endl;
    double m_edep;
    tt->SetBranchAddress("edep", &m_edep);
    for (int i=0; i<nMaxEvt; i++) {
        tt->GetEntry(i);
        edep[i] = m_edep;
    }
}





