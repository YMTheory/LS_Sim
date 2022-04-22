
#include "LSDetectorSD.hh"

#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

LSDetectorSD::LSDetectorSD( const G4String& name, 
                  const G4String& hitsCollectionName)
    : G4VSensitiveDetector(name),
    fHitsCollection(NULL)
{
    collectionName.insert(hitsCollectionName);

}

LSDetectorSD::~LSDetectorSD()
{;}


void LSDetectorSD::Initialize(G4HCofThisEvent* hce)
{
    // Create hits collection
    fHitsCollection
        = new LSDetectorHitsCollection( SensitiveDetectorName, collectionName[0]);
    
    // Add this collection in hce
    G4int hcID 
        = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection( hcID, fHitsCollection );

    G4cout << "******************** Sensitive Detector Initialize ******************" << G4endl;

}

G4bool LSDetectorSD::ProcessHits( G4Step* aStep, G4TouchableHistory*)
{
    G4double edep = aStep->GetTotalEnergyDeposit();
    G4double stepLength = aStep->GetStepLength();
    G4cout << aStep->GetTrack()->GetTrackID() << " " << edep << " " << stepLength << G4endl;
    //if(edep == 0. && stepLength == 0. ) return false;

    auto touchable = (aStep->GetPreStepPoint()->GetTouchable());

    // Get pmt id
    //auto pmtNumber = touchable->GetReplicaNumber(1);

    LSDetectorHit* hit = new LSDetectorHit();

    fHitsCollection->insert(hit);


    return true;
}



void LSDetectorSD::EndOfEvent(G4HCofThisEvent*)
{
  if ( verboseLevel>1 ) { 
     G4int nofHits = fHitsCollection->entries();
     G4cout << G4endl
            << "-------->Hits Collection: in this event they are " << nofHits 
            << " hits in the tracker chambers: " << G4endl;
     for ( G4int i=0; i<nofHits; i++ ) (*fHitsCollection)[i]->Print();
  }
     G4int nofHits = fHitsCollection->entries();
     G4cout << G4endl
            << "-------->Hits Collection: in this event they are " << nofHits 
            << " hits in the tracker chambers: " << G4endl;
}

