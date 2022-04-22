
#include "LSDetectorHit.hh"

G4ThreadLocal G4Allocator<LSDetectorHit>* LSDetectorHitAllocator = 0;

LSDetectorHit::LSDetectorHit()
    : G4VHit(),
      m_npe(0), m_cer_npe(0), m_sct_npe(0)
{;}

LSDetectorHit::~LSDetectorHit()
{;}


LSDetectorHit::LSDetectorHit( const LSDetectorHit& right)
    : G4VHit()
{
    m_npe = right.m_npe;
    m_cer_npe = right.m_cer_npe;
    m_sct_npe = right.m_sct_npe;
}


const LSDetectorHit& LSDetectorHit::operator=(const LSDetectorHit& right)
{
    m_npe = right.m_npe;
    m_cer_npe = right.m_cer_npe;
    m_sct_npe = right.m_sct_npe;

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
    G4cout << "NPE = " << m_npe << ", CerNPE = " << m_cer_npe << ", SctNPE = " << m_sct_npe << G4endl;
}





