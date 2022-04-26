#ifndef LSParticleSourceMessenger_h
#define LSParticleSourceMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class LSParticleSource;

class G4ParticleTable;
class G4UIcommand;
class G4UImessenger;
class G4UIcmdWithoutParameter;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWith3VectorAndUnit;


class LSParticleSourceMessenger : public G4UImessenger {

    public:
        LSParticleSourceMessenger(LSParticleSource* fPtclGun);
        ~LSParticleSourceMessenger();

        void SetNewValue(G4UIcommand* cmd, G4String newValues);

    private:
        G4ParticleTable* particleTable;
        LSParticleSource* fParticleGun;

    private:
        G4UIdirectory               *gunDirectory;

        G4UIcmdWithAString          *particleCmd;
        G4UIcmdWithAString          *momTypeCmd;
        G4UIcmdWithADoubleAndUnit   *energyCmd;
        G4UIcmdWith3VectorAndUnit   *momCmd;
        G4UIcmdWith3VectorAndUnit   *posCmd;
};

#endif





