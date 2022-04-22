
#include "LSTrackingAction.hh"

#include "G4Track.hh"

LSTrackingAction::LSTrackingAction()
    : G4UserTrackingAction()
{}

LSTrackingAction::~LSTrackingAction()
{}

void LSTrackingAction::PreUserTrackingAction( const G4Track* track )
{
    G4cout << track->GetTrackID() << " " << track->GetParentID() << G4endl;
    if(track->GetCreatorProcess()){
        const G4VProcess* proc = track->GetCreatorProcess();
        G4cout << track->GetTrackID() << " " << track->GetParticleDefinition()->GetParticleName() 
           << " " << G4endl;
    }
}

void LSTrackingAction::PostUserTrackingAction ( const G4Track* ) 
{;}
