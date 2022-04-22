
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

        void SetTime(double time)       { m_time = time; }
        double GetTime()                { return m_time; }
        
    private:
        int m_time;

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
