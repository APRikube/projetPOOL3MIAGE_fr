#include "vendeur.h"
#include "bienimmobilier.h"
#include <algorithm>
Vendeur::Vendeur()
{

}


std::string Vendeur::getType() const
{
    return "real estate";
}

void Vendeur::ajoutBienImmobilierAVendre(choixBienImmobilier re)
{
    m_bienImmobilierAVendre.push_back(re);
}

void Vendeur::vendreBienImmobilier(choixBienImmobilier re)
{
    m_bienImmobilierAVendre.erase(std::remove(m_bienImmobilierAVendre.begin(), m_bienImmobilierAVendre.end(), re), m_bienImmobilierAVendre.end());
}

std::vector<choixBienImmobilier> Vendeur::getBienImmobilierAVendre() const
{
    return m_bienImmobilierAVendre;
}
