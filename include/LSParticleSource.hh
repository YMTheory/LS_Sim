#ifndef LSParticleSource_h
#define LSParticleSource_h

#include "G4ParticleDefinition.hh"
#include "G4VPrimaryGenerator.hh"
#include "G4ThreeVector.hh"
#include "LSParticleSourceMessenger.hh"

class LSParticleSource : public G4VPrimaryGenerator 
{
    
    public:
        LSParticleSource();
        ~LSParticleSource();

        void GeneratePrimaryVertex(G4Event* event);

    public:
        void SetParticleDefinition(G4ParticleDefinition* aParticleDefinition);
        
        void SetKineticEnergy(G4double energy);
        void SetMomentumType(G4String type);
        void GenerateIsotropicFlux();
        void SetMomentum(G4ThreeVector mom);
        void SetPosition(G4ThreeVector pos);
        
    private:
        G4double                me;

        G4String                m_MomType;
        G4ThreeVector           m_Mom;
        G4double                m_energy;
        G4ThreeVector           m_pos;
        G4ParticleDefinition*   m_particle;

    
    private:
        LSParticleSourceMessenger* theMessenger;

};


#endif


