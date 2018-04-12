#include "visite.h"

using namespace std;

Visite::Visite(Acheteur b, Vendeur s, BienImmobilier re)
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

BienImmobilier Visite::getBienImmobilier() const
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

void Visite::setBienImmobilier(BienImmobilier newBienImmobilier)
{
    m_re = newBienImmobilier;
}

void Visite::afficher() const
{
    cout << "Il concerne le bien immobilier de " << m_vendeur.getNom() << endl;
    cout << "Ce bien immobilier est localisé à " << m_re.getAdresse() << endl;
    cout << "Il couvre une superficie de " << m_re.getSurface() << " métres carrés " << endl;
    cout << "Il est vendu pour le prix de : " << m_re.getPrix() << endl;
}

bool Visite::operator<(Visite const & v) const
{
    return (this->m_vendeur.getNom() < v.getVendeur().getNom());
}
