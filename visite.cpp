#include "visite.h"

Visite::Visite(Acheteur b, Vendeur s, choixBienImmobilier re)
    :m_acheteur(b), m_vendeur(s), m_re(re)
{
}

Acheteur Visite::getAcheteur() const
{
    return m_acheteur;
}

Vendeur Visite::getVendeur() const
{
    return m_vendeur;
}

choixBienImmobilier Visite::getBienImmobilier() const
{
    return m_re;
}

void Visite::setAcheteur(Acheteur newAcheteur)
{
    m_acheteur = newAcheteur;
}

void Visite::setVendeur(Vendeur newVendeur)
{
    m_vendeur = newVendeur;
}

void Visite::setBienImmobilier(choixBienImmobilier newBienImmobilier)
{
    m_re = newBienImmobilier;
}

void Visite::afficher() const
{
    std::cout << "Il concerne le bien immobilier de " << m_vendeur.getNom() << std::endl;
    std::cout << "Ce bien immobilier est localisé à " << m_re.getAdresse() << std::endl;
    std::cout << "Il couvre une superficie de " << m_re.getSurface() << " métres carrés " << std::endl;
    std::cout << "Il est vendu pour le prix de : " << m_re.getPrix() << std::endl;
}

bool Visite::operator<(Visite const & v) const
{
    return (this->m_vendeur.getNom() < v.getVendeur().getNom());
}
