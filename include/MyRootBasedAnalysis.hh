#ifndef MyRootBasedAnalysis_h
#define MyRootBasedAnalysis_h 1

#include <iomanip>
#include "TFile.h"
#include "G4Event.hh"
#include "G4Track.hh"

class TFile;
class TTree;

class MyRootBasedAnalysis
{
    public:
        MyRootBasedAnalysis();
        ~MyRootBasedAnalysis();

        void BeginOfEventAction(const G4Event *evt);
        void EndOfEventAction(const G4Event *evt);

        void BeginOfRunAction();
        void EndOfRunAction();

        void SteppingAction(const G4Step *aStep);
        void PreTrackingAction(const G4Track *aTrack);
        void PostTrackingAction(const G4Track *aTrack);

        inline void SetFileName(G4String fname) { fFileName = fname; }
        inline void SetBirks1(G4double val)     { m_BirksConstant1 = val;}
        inline void Activated() { active = true; }
        inline void Deactivated() { active = false; }
        inline bool IsActivated() { return active; }

        inline void AddHitTime(G4double val) {vec_hit_time.push_back(val);}
        inline void AddHitX(G4double val) {vec_hit_x.push_back(val);}
        inline void AddHitY(G4double val) {vec_hit_y.push_back(val);}
        inline void AddHitZ(G4double val) {vec_hit_z.push_back(val);}

        inline void SetNPE_tot(G4int val) {npe_tot = val;}
        inline void SetNPE_Cer(G4int val) {npe_Cer = val;}
        inline void SetNPE_sct(G4int val) {npe_sct = val;}

        double calculateQuenched(const G4Step* aStep);

    private:
        G4String fFileName;

        bool active = false;

        TFile* fRootFp;
        TTree* fTree;

        double m_BirksConstant1;
        double m_BirksConstant2;

        Int_t           pdf_id;
        Float_t         pre_x;
        Float_t         pre_y;
        Float_t         pre_z;
        Float_t         edep;
        Float_t         qedep;
        Float_t         track_length;

        Int_t           npe_tot;
        Int_t           npe_Cer;
        Int_t           npe_sct;

        std::vector<Float_t> vec_hit_time;
        std::vector<Float_t> vec_hit_x;
        std::vector<Float_t> vec_hit_y;
        std::vector<Float_t> vec_hit_z;

};



#endif
