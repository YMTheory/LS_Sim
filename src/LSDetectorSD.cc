#include "LSDetectorSD.hh"
#include "NormalTrackInfo.hh"

#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4StepPoint.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4OpticalPhoton.hh"
#include "G4UnitsTable.hh"

LSDetectorSD::LSDetectorSD( const G4String& name, 
                  const G4String& hitsCollectionName)
    : G4VSensitiveDetector(name),
    fHitsCollection(NULL)
{
    collectionName.insert(hitsCollectionName);

    analysis = LSAnalysisManager::getInstance();

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


}

G4bool LSDetectorSD::ProcessHits( G4Step* aStep, G4TouchableHistory*)
{
    G4Track* track = aStep->GetTrack();
    if (track->GetDefinition() != G4OpticalPhoton::Definition()) {
        return false;
    }
    G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint* postStepPoint = aStep->GetPostStepPoint();

    G4double edep = aStep->GetTotalEnergyDeposit();
    G4double stepLength = aStep->GetStepLength();
    if(edep == 0. ) return false;

    //auto touchable = (aStep->GetPreStepPoint()->GetTouchable());

    // Get pmt id
    //auto pmtNumber = touchable->GetReplicaNumber(1);
    G4double wavelength = 1240. * 1e6 / edep;
    G4double time = postStepPoint->GetGlobalTime();
    G4bool is_from_cerenkov = false;
    G4bool is_reemission = false;
    G4bool is_original_op = false;
    G4VUserTrackInformation* trkinfo = track->GetUserInformation();
    if(trkinfo) {
        NormalTrackInfo* normaltrk = dynamic_cast<NormalTrackInfo*>(trkinfo);
        if(normaltrk) {
            is_from_cerenkov = normaltrk->isFromCerenkov();
            is_reemission = normaltrk->isReemission();
            is_original_op = normaltrk->isOriginalOP();
        }
    }

    LSDetectorHit* hit = new LSDetectorHit();

    fHitsCollection->insert(hit);


    return true;
}



void LSDetectorSD::EndOfEvent(G4HCofThisEvent*)
{
    G4int nofHits = fHitsCollection->entries();
    if ( verboseLevel>1 ) { 
        G4cout << G4endl
                << "-------->Hits Collection: in this event they are " << nofHits 
                << " hits in the tracker chambers: " << G4endl;
         for ( G4int i=0; i<nofHits; i++ ) (*fHitsCollection)[i]->Print();
    }

    analysis -> analyseTotNPE(nofHits);


}

