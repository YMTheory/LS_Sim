
#ifndef LSDetectorHit_h
#define LSDetectorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"

class LSDetectorHit : public G4VHit
{
    public:
        LSDetectorHit();
        LSDetectorHit(const LSDetectorHit&);
        virtual ~LSDetectorHit();

        // operators
        const LSDetectorHit& operator=(const LSDetectorHit&);
        G4int operator==(const LSDetectorHit&) const;

        inline void* operator new    (size_t);
        inline void operator  delete (void*);

        // methods from base class
        virtual void Draw();
        virtual void Print();

        void SetNPE(int npe)        { m_npe = npe; }
        int GetNPE()                { return m_npe; }

        void SetCerNPE(int npe)     { m_cer_npe = npe; }
        int GetCerNPE()             { return m_cer_npe; }

        void SetSctNPE(int npe)     { m_sct_npe = npe; }
        int GetSctNPE()             { return m_sct_npe; }

    private:
        int m_npe;
        int m_cer_npe;
        int m_sct_npe;

};


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

typedef G4THitsCollection<LSDetectorHit> LSDetectorHitsCollection;

extern G4ThreadLocal G4Allocator<LSDetectorHit>* LSDetectorHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

inline void* LSDetectorHit::operator new(size_t)
{
  if(!LSDetectorHitAllocator)
      LSDetectorHitAllocator = new G4Allocator<LSDetectorHit>;
  return (void *) LSDetectorHitAllocator->MallocSingle();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

inline void LSDetectorHit::operator delete(void *hit)
{
  LSDetectorHitAllocator->FreeSingle((LSDetectorHit*) hit);
}


#endif
