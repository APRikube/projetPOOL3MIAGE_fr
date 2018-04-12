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

void Vendeur::ajoutBienImmobilierAVendre(BienImmobilier re)
{
    m_bienImmobilierAVendre.push_back(re);
}

void Vendeur::vendreBienImmobilier(BienImmobilier re)
{
    m_bienImmobilierAVendre.erase(std::remove(m_bienImmobilierAVendre.begin(), m_bienImmobilierAVendre.end(), re), m_bienImmobilierAVendre.end());
}

std::vector<BienImmobilier> Vendeur::getBienImmobilierAVendre() const
{
    return m_bienImmobilierAVendre;
}
