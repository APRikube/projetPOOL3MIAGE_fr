#include "bienimmobilier.h"

int choixBienImmobilier::nextId = 0;

choixBienImmobilier::choixBienImmobilier(unsigned int prix, std::string addresse, unsigned short surface, Vendeur vendeur)
    :m_prix(prix), m_adresse(addresse), m_surface(surface), m_vendeur(vendeur)
{
    m_identifiant = choixBienImmobilier::nextId++;
}

choixBienImmobilier::choixBienImmobilier(const choixBienImmobilier & re)
{
    this->m_identifiant = re.getIdentifiant();
    this->m_adresse = re.getAdresse();
    this->m_prix = re.getPrix();
    this->m_vendeur = re.getVendeur();
    this->m_surface = re.getSurface();
}

//Getters
unsigned int choixBienImmobilier::getPrix() const
{
    return m_prix;
}

std::string choixBienImmobilier::getAdresse() const
{
    return m_adresse;
}

short choixBienImmobilier::getSurface() const
{
    return m_surface;
}

Vendeur choixBienImmobilier::getVendeur() const
{
    return m_vendeur;
}

int choixBienImmobilier::getIdentifiant() const
{
    return m_identifiant;
}

std::string choixBienImmobilier::getType() const
{
    return "real estate";
}

char choixBienImmobilier::getSauvegardeType() const
{
    return 'r';
}

bool choixBienImmobilier::operator<(const choixBienImmobilier & re) const
{
    return (this->getIdentifiant() < re.getIdentifiant());
}

bool choixBienImmobilier::operator==(const choixBienImmobilier & re) const
{
    return (this->getIdentifiant() == re.getIdentifiant());
}

void choixBienImmobilier::afficher() const
{
    std::cout << "Mon bien immobilierrrrrr" << std::endl;
}
