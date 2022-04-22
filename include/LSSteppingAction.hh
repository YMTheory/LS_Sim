#ifndef LSSteppingAction_h
#define LSSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class LSEventAction;

class LSSteppingAction : public G4UserSteppingAction
{
    public:
        LSSteppingAction(LSEventAction* event);
        virtual ~LSSteppingAction();


        virtual void UserSteppingAction(const G4Step*);

    private:
        LSEventAction* fEventAction;
};

#endif
