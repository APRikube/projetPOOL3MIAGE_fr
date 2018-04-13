#include "acheteur.h"
#include "visite.h"

using namespace std;

Acheteur::Acheteur()
    : m_propositionAchat(false)
{

}

bool Acheteur::getPropositionAchat() const
{
    return m_propositionAchat;
}

set<Visite> Acheteur::getVisites()
{
    return m_visites;
}

string Acheteur::getSauvegardeType()
{
    return "a";
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
        cout << this->m_prenom << " " << this->m_nom << " a visité ses biens immobiliers :" << endl;
        for(Visite v : m_visites)
        {
            v.afficher();
        }
    } else {
        cout << this->m_prenom << " " << this->m_nom << " n'a visité aucun bien immobilier." << endl;
    }
}
