#include "bienimmobilier.h"

int BienImmobilier::nextId = 0;

BienImmobilier::BienImmobilier(unsigned int prix, std::string addresse, unsigned short surface, Vendeur vendeur)
    :m_prix(prix), m_adresse(addresse), m_surface(surface), m_vendeur(vendeur)
{
    m_identifiant = BienImmobilier::nextId++;
}

BienImmobilier::BienImmobilier(const BienImmobilier & re)
{
    this->m_identifiant = re.getIdentifiant();
    this->m_adresse = re.getAdresse();
    this->m_prix = re.getPrix();
    this->m_vendeur = re.getVendeur();
    this->m_surface = re.getSurface();
}

//Getters
unsigned int BienImmobilier::getPrix() const
{
    return m_prix;
}

std::string BienImmobilier::getAdresse() const
{
    return m_adresse;
}

short BienImmobilier::getSurface() const
{
    return m_surface;
}

Vendeur BienImmobilier::getVendeur() const
{
    return m_vendeur;
}

int BienImmobilier::getIdentifiant() const
{
    return m_identifiant;
}

std::string BienImmobilier::getType() const
{
    return "bien immobilier";
}

char BienImmobilier::getSauvegardeType() const
{
    return 'b';
}

bool BienImmobilier::operator<(const BienImmobilier & re) const
{
    return (this->getIdentifiant() < re.getIdentifiant());
}

bool BienImmobilier::operator==(const BienImmobilier & re) const
{
    return (this->getIdentifiant() == re.getIdentifiant());
}

void BienImmobilier::afficher() const
{
    std::cout << "Mon bien immobilierrrrrr" << std::endl;
}
