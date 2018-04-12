#include "appartement.h"

using namespace std;

Appartement::Appartement(string addresse, short surface, unsigned int prix, Vendeur seller, unsigned short nbSalles, unsigned int etage, bool garage, bool cave, bool balcon, unsigned int nbAppartBatiment)
    :BienImmobilier(prix, addresse, surface, seller), m_nbSalles(nbSalles), m_etage(etage), m_garage(garage), m_cave(cave), m_balcon(balcon), m_nbAppartBatiment(nbAppartBatiment)
{

}

string Appartement::getType() const
{
    return "appartement";
}

char Appartement::getSauvegardeType() const
{
    return 'a';
}

unsigned short Appartement::getNbSalles() const
{
    return m_nbSalles;
}

unsigned int Appartement::getEtage() const
{
    return m_etage;
}

bool Appartement::getGarage() const
{
    return m_garage;
}

bool Appartement::getCave() const
{
    return m_cave;
}

bool Appartement::getBalcon() const
{
    return  m_balcon;
}

unsigned int Appartement::getNbAppartBatiment() const
{
    return m_nbAppartBatiment;
}

void Appartement::setNbSalles(unsigned short newNbSalles)
{
    this->m_nbSalles = newNbSalles;
}

void Appartement::setEtage(unsigned int newEtage)
{
    this->m_etage = newEtage;
}

void Appartement::setGarage(bool newGarage)
{
    this->m_garage = newGarage;
}

void Appartement::setCave(bool newCave)
{
    this->m_cave = newCave;
}

void Appartement::setBalcon(bool newBalcon)
{
    this->m_balcon = newBalcon;
}

void Appartement::setNbAppartBatiment(unsigned int newNbAppartBatiment)
{
    this->m_nbAppartBatiment = newNbAppartBatiment;
}

void Appartement::afficher() const
{
    cout << "L'appartement est localisé à " << m_adresse << endl;
    cout << "Il est vendu pour " << m_prix << "€" << endl;
    cout << "Ca surface " << m_surface << " est divisé en " << m_nbSalles << " salles." << endl;
    cout << "Il est à l'étage n° " << m_etage << endl << endl;
    if (m_garage)
    {
        cout << "Il a un garage." << endl;
    }
    if (m_cave)
    {
        cout << "Il a une cave." << endl;
    }
    if (m_balcon)
    {
        cout << "Il a aussi un balcon." << endl;
    }
    cout << "Dans le batiment, on peut compter " << m_nbAppartBatiment << " appartements" << endl;
}
