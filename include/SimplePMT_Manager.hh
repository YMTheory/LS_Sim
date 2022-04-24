#ifndef SimplePMT_Manager_h
#define SimplePMT_Manager_h 1

#include "globals.hh"
#include "G4SystemOfUnits.hh"
class G4VSolid;

class SimplePMT_Manager
{
    public:
        SimplePMT_Manager();
        ~SimplePMT_Manager();

        G4VSolid* GetSolid(G4String solidname, double thickness=0.0);

    private:
        double m_R;
        double m_H;

};

#endif;
