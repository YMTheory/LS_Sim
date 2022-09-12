#ifndef LSDetectorConstructionMessenger_h
#define LSDetectorConstructionMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class LSDetectorConstruction;

class G4UIcommand;
class G4UIdirectory;
class G4UIcmdWithADouble;

class LSDetectorConstructionMessenger : public G4UImessenger {
    
    public:
        LSDetectorConstructionMessenger(LSDetectorConstruction* fLSDet);
        ~LSDetectorConstructionMessenger();

        void SetNewValue(G4UIcommand* cmd, G4String newValues);

    private:
        LSDetectorConstruction* LSDet;    

    private:
        G4UIdirectory*          lsdetDirectory;
        G4UIcmdWithADouble*     scaleRayLCmd; 
        
};


#endif