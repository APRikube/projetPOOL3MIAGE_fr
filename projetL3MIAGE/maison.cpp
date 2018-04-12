#include "maison.h"

using namespace std;

Maison::Maison(string adresse, short surface, unsigned int prix, Vendeur seller, unsigned short nbSalles, bool piscine, bool garage)
    :BienImmobilier(prix, adresse, surface, seller), m_nbSalles(nbSalles), m_piscine(piscine), m_garage(garage)
{

}

unsigned short Maison::getNbSalles() const
{
    return m_nbSalles;
}

bool Maison::hasPiscine() const
{
    return m_piscine;
}

bool Maison::hasGarage() const
{
    return m_garage;
}

void Maison::setNbSalles(unsigned short nbSalles)
{
    m_nbSalles = nbSalles;
}

void Maison::setPiscine(bool has)
{
    m_piscine = has;
}

void Maison::setGarage(bool has)
{
    m_garage = has;
}

string Maison::getType() const
{
    return "maison";
}

char Maison::getSauvegardeType() const
{
    return 'm';
}

void Maison::afficher() const
{
    cout << "L'appartement est localisé à " << m_adresse << endl;
    cout << "Il est vendu pour " << m_prix << "€" << endl;
    cout << "Ca surface est de " << m_surface << " métres carrés et est composé de " << m_nbSalles << endl;

    if (m_piscine)
    {
        cout << "Elle possède une piscine." << endl;
    }
    if (m_garage)
    {
        cout << "Elle possède un garage." << endl;
    }
}
