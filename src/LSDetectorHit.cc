
#include "LSDetectorHit.hh"

G4ThreadLocal G4Allocator<LSDetectorHit>* LSDetectorHitAllocator = 0;

LSDetectorHit::LSDetectorHit()
    : G4VHit(),
      time(0)
{;}

LSDetectorHit::~LSDetectorHit()
{;}


LSDetectorHit::LSDetectorHit( const LSDetectorHit& right)
    : G4VHit()
{
    time = right.time;
    edep = right.edep;
    wavelength = right.wavelength;
}


const LSDetectorHit& LSDetectorHit::operator=(const LSDetectorHit& right)
{
    time = right.time;
    edep = right.edep;
    wavelength = right.wavelength;

    return *this;
}

G4int LSDetectorHit::operator==(const LSDetectorHit& right) const
{
    return (  this == &right ) ? 1 : 0;
}
void LSDetectorHit::Draw()
{

}

void LSDetectorHit::Print()
{
    G4cout << "Hit Time : " << time << G4endl;
}





