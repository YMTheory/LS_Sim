#include "LSParticleSource.hh"

#include "G4Event.hh"
#include "Randomize.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4ParticleTable.hh"
#include "G4PrimaryParticle.hh"
#include "G4PhysicalConstants.hh"

LSParticleSource::LSParticleSource() {

    me = 0.511*MeV;

    m_particle          = NULL;
    m_energy            = 1.0*MeV;
    m_MomType           = "iso";    // candidates: iso, direction, range
    m_Mom               = G4ThreeVector(1., 0., 0.);
    m_pos               = G4ThreeVector(0, 0, 0);

    theMessenger        = new LSParticleSourceMessenger(this);
}

LSParticleSource::~LSParticleSource()
{
    delete theMessenger;
}

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

    G4double p =sqrt(m_energy*m_energy + 2*me*m_energy);

    G4double rndm, rndm2;
    G4double px, py, pz;

    G4double sintheta, sinphi, costheta, cosphi;
    rndm = G4UniformRand();
    costheta = -1 + rndm * 2;
    sintheta = std::sqrt(1. - costheta*costheta);

    rndm2 = G4UniformRand();
    G4double Phi = 2 * pi * rndm2; 
    sinphi = std::sin(Phi);
    cosphi = std::cos(Phi);

    px = -sintheta * cosphi * p;
    py = -sintheta * sinphi * p;
    pz = -costheta * p;

    G4double ResMag = std::sqrt((px*px) + (py*py) + (pz*pz));
    px = px/ResMag;
    py = py/ResMag;
    pz = pz/ResMag;

    m_Mom.setX(px);
    m_Mom.setY(py);
    m_Mom.setZ(pz);

}

void LSParticleSource::SetMomentum(G4ThreeVector mom)
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

    if(m_MomType == "iso") {
        GenerateIsotropicFlux();
    }

    G4PrimaryVertex* vertex = new G4PrimaryVertex(m_pos, 0);
    G4PrimaryParticle* particle = new G4PrimaryParticle(m_particle, m_Mom.x(), m_Mom.y(), m_Mom.z());
    particle->SetKineticEnergy(m_energy);
    vertex->SetPrimary(particle);
    event->AddPrimaryVertex(vertex);
}





