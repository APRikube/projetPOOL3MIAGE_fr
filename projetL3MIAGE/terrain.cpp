#include "terrain.h"

using namespace std;

Terrain::Terrain(bool constructible, unsigned int prix, string adresse, short surface, Vendeur vendeur)
    :BienImmobilier(prix, adresse, surface, vendeur), m_constructible(constructible)
{

}

string Terrain::getType() const
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

void Terrain::afficher() const
{
    cout << "L'appartement est localisé à " << m_adresse << endl;
    cout << "Il est vendu pour " << m_prix << "€" << endl;
    cout << "Ca surface est de " << m_surface << " métres carrés" << endl;
    if (m_constructible)
    {
        cout << "De plus, c'est un terrain constructible." << endl;
    }
}
