#include "terrain.h"


Terrain::Terrain(bool constructible, unsigned int prix, std::string adresse, short surface, Vendeur vendeur)
    :choixBienImmobilier(prix, adresse, surface, vendeur), m_constructible(constructible)
{

}

std::string Terrain::getType() const
{
    return "plot";
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
