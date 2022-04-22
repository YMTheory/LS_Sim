
#include "LSDetectorHit.hh"

G4ThreadLocal G4Allocator<LSDetectorHit>* LSDetectorHitAllocator = 0;

LSDetectorHit::LSDetectorHit()
    : G4VHit(),
      m_time(0)
{;}

LSDetectorHit::~LSDetectorHit()
{;}


LSDetectorHit::LSDetectorHit( const LSDetectorHit& right)
    : G4VHit()
{
    m_time = right.m_time;
}


const LSDetectorHit& LSDetectorHit::operator=(const LSDetectorHit& right)
{
    m_time = right.m_time;

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
    G4cout << "Hit Time : " << m_time << G4endl;
}





