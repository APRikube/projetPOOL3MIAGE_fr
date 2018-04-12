#include "terrain.h"


Terrain::Terrain(bool constructible, unsigned int prix, std::string adresse, short surface, Vendeur vendeur)
    :BienImmobilier(prix, adresse, surface, vendeur), m_constructible(constructible)
{

}

std::string Terrain::getType() const
{
    return "terrain";
}

char Terrain::getSauvegardeType() const
{
    return 't';
}

bool Terrain::getConstructible() const
{
    return m_constructible;
}

void Terrain::setConstructible(bool newConstructible)
{
    this->m_constructible = newConstructible;
}
