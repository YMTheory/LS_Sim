
#include "LSTrackingAction.hh"

#include "G4Track.hh"
#include "G4VProcess.hh"

LSTrackingAction::LSTrackingAction()
    : G4UserTrackingAction()
{}

LSTrackingAction::~LSTrackingAction()
{}

void LSTrackingAction::PreUserTrackingAction( const G4Track* track )
{

    //if (track->GetParentID() == 1) // primary e+-
    //{
    //    if (track->GetParticleDefinition()->GetParticleName() == "e+") {
    //        G4cout << track->GetKineticEnergy() << "a ";
    //    }
    //    if (track->GetParticleDefinition()->GetParticleName() == "e-") {
    //        G4cout << track->GetKineticEnergy() << "b ";
    //    }
    //}
}

void LSTrackingAction::PostUserTrackingAction ( const G4Track* ) 
{;}
