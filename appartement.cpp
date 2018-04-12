#include "appartement.h"

Appartement::Appartement(std::string addresse, short surface, unsigned int prix, Vendeur seller, unsigned short nbSalles, unsigned int etage, bool garage, bool cave, bool balcon, unsigned int nbAppartBatiment)
    :choixBienImmobilier(prix, addresse, surface, seller), m_nbSalles(nbSalles), m_etage(etage), m_garage(garage), m_cave(cave), m_balcon(balcon), m_nbAppartBatiment(nbAppartBatiment)
{

}

std::string Appartement::getType() const
{
    return "flat";
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
    std::cout << "C'est un appartement vendu par " << m_vendeur.getPrenom() << " " << m_vendeur.getNom() << std::endl;
    std::cout << "L'appartement est localisé à " << m_adresse << std::endl;
    std::cout << "Il est vendu pour " << m_prix << "€" << std::endl;
    std::cout << "Ca surface " << m_surface << " est divisé en " << m_nbSalles << " salles." << std::endl;
    std::cout << "Il est à l'étage n° " << m_etage << std::endl;
    if (m_garage)
    {
        std::cout << "Il a un garage." << std::endl;
    }
    if (m_cave)
    {
        std::cout << "Il a une cave." << std::endl;
    }
    if (m_balcon)
    {
        std::cout << "Il a aussi un balcon." << std::endl;
    }
    std::cout << "Dans le batiment, on peut compter " << m_nbAppartBatiment << " appartements" << std::endl;
}
