#ifndef LSPhysicsList_h
#define LSPhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class G4VPhysicsConstructor;
class G4ProductionCuts;

class LSPhysicsList : public G4VModularPhysicsList
{
    public:
        LSPhysicsList();
        virtual ~LSPhysicsList();

    public:
        virtual void SetCuts();

        virtual void ConstructParticle();
        virtual void ConstructProcess();
        void ConstructOpticalProcess();



    private:
        G4VPhysicsConstructor* emPhysicsList;
        G4VPhysicsConstructor* decayPhysicsList;
};

#endif
