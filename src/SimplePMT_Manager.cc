#include "SimplePMT_Manager.hh"

#include "G4Tubs.hh"
#include "G4SystemOfUnits.hh"

SimplePMT_Manager::SimplePMT_Manager()
{;}

SimplePMT_Manager::~SimplePMT_Manager()
{;}

G4VSolid*
SimplePMT_Manager::GetSolid(G4String solidname, double thickness)
{
    m_R = 254*mm;
    m_H = 150*mm;

    // a very simple only-tubs PMT geometry
    G4Tubs* pmttube_solid = new G4Tubs(
                                    solidname,
                                    0*mm,
                                    m_R,
                                    m_H,
                                    0*deg,
                                    360*deg);

    return pmttube_solid;

}










