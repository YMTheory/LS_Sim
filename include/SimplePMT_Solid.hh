#ifndef SimplePMT_Solid_h
#define SimplePMT_Solid_h 1

#include "globals.hh"
#include "G4SystemOfUnits.hh"
class G4VSolid;

class SimplePMT_Solid
{
    public:
        SimplePMT_Solid();
        ~SimplePMT_Solid();

        G4VSolid* GetSolid(G4String solidname, double thickness=0.0);

    private:
        double m_R;
        double m_H;

};

#endif;
