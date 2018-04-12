#include "acheteur.h"
#include "visite.h"

Acheteur::Acheteur()
    : m_propositionAchat(false)
{

}

bool Acheteur::getPropositionAchat() const
{
    return m_propositionAchat;
}

std::set<Visite> Acheteur::getVisites()
{
    return m_visites;
}

void Acheteur::setPropositionAchat(bool newValue)
{
    m_propositionAchat = newValue;
}

void Acheteur::ajoutVisite(Visite v)
{
    this->m_visites.insert(v);
}

void Acheteur::afficherVisites() const
{
    if (!m_visites.empty()){
        std::cout << this->m_prenom << " " << this->m_nom << " a visité ses biens immobiliers :" << std::endl;
        for(Visite v : m_visites)
        {
            v.afficher();
        }
    } else {
        std::cout << this->m_prenom << " " << this->m_nom << " n'a visité aucun bien immobilier." << std::endl;
    }
}
