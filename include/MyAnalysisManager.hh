#ifndef MyAnalysisManager_h
#define MyAnalysisManager_h

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include <iomanip>

class MyRootBasedAnalysis;

class MyAnalysisManager
{
public:
    MyAnalysisManager();
    ~MyAnalysisManager();

    static MyAnalysisManager* GetInstance()
    {
        if (MyAnalysisManager::fInstance == NULL)
            MyAnalysisManager::fInstance = new MyAnalysisManager();
        return MyAnalysisManager::fInstance;
    }

    void BeginOfEventAction(const G4Event *evt);
    void EndOfEventAction(const G4Event *evt);

    void BeginOfRunAction();
    void EndOfRunAction();

    void SteppingAction(const G4Step *aStep);
    void PreTrackingAction(const G4Track *aTrack);
    void PostTrackingAction(const G4Track *aTrack);


    void SetFileName(G4String val);
    void SetBirks1(G4double val);
    void SetActivate(G4bool val);

    void AddHitTime(G4double val);
    void AddHitX(G4double val);
    void AddHitY(G4double val);
    void AddHitZ(G4double val);

    void SetNPE_tot(G4int val);
    void SetNPE_Cer(G4int val);
    void SetNPE_sct(G4int val);

    private:
        static MyAnalysisManager* fInstance;
        MyRootBasedAnalysis* fMyRootBasedAnalysis;


};

#endif
