#include "LSParticleSource.hh"

#include "G4Event.hh"
#include "Randomize.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"

LSParticleSource::LSParticleSource() {
    m_particle          = NULL;
    m_energy            = 1.0*MeV;
    m_MomType           = "iso";
    m_Mom               = G4ThreeVector(1., 0., 0.);
    m_pos               = G4ThreeVector(0, 0, 0);
}

LSParticleSource::~LSParticleSource()
{}

void LSParticleSource::SetParticleDefinition(G4ParticleDefinition* aParticleDefinition) 
{
    m_particle = aParticleDefinition;
}


void LSParticleSource::SetKineticEnergy(G4double energy)
{
    m_energy = energy;
}

void LSParticleSource::SetMomentumType(G4String type)
{
    m_MomType = type;
}


void LSParticleSource::GenerateIsotropicFlux()
{
    
}

void LSParticleSource::SetParticleMomentum(G4ThreeVector mom)
{
    m_Mom = mom;
}

void LSParticleSource::SetPosition(G4ThreeVector pos)
{
    m_pos = pos;
}

void LSParticleSource::GeneratePrimaryVertex(G4Event* event)
{
    if(m_particle == NULL) {
        G4cout << "No particle has been defined !" << G4endl;
        return;
    }

    G4PrimaryVertex* vertex = new G4PrimaryVertex(m_pos, 0);
    G4PrimaryParticle* particle = new G4PrimaryParticle(m_particle, m_Mom.x(), m_Mom.y(), m_Mom.z());
    particle->SetKineticEnergy(m_energy);
    vertex->SetPrimary(particle);
    event->AddPrimaryVertex(vertex);
}





