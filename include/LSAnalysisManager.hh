
#ifndef LSAnalysisManager_h
#define LSAnalysisManager_h 1

#include "globals.hh"

class LSAnalysisManager  {
    
    public:

        //LSAnalysisManager();
        virtual ~LSAnalysisManager();

        void book();

        void finish();
        
        //method to call to create an instance of this class
        static LSAnalysisManager* getInstance();
        
        void analyseEventID(G4int evtid);
        void analyseTotNPE(G4int number);
        void analyseCerNPE(G4int number);
        void analyseSctNPE(G4int number);
        void analyseAddNtupleRow();

        void SetOutputName(G4String name) { outputFileName = name; }


    private:
        LSAnalysisManager();

        G4String outputFileName;

        static LSAnalysisManager* instance;
        
};

#endif
