#include "vendeur.h"
#include "bienimmobilier.h"
#include <algorithm>

using namespace std;

Vendeur::Vendeur()
{

}


string Vendeur::getType() const
{
    return "real estate";
}

void Vendeur::ajoutBienImmobilierAVendre(BienImmobilier re)
{
    m_bienImmobilierAVendre.push_back(re);
}

void Vendeur::vendreBienImmobilier(BienImmobilier re)
{
    m_bienImmobilierAVendre.erase(remove(m_bienImmobilierAVendre.begin(), m_bienImmobilierAVendre.end(), re), m_bienImmobilierAVendre.end());
}

vector<BienImmobilier> Vendeur::getBienImmobilierAVendre() const
{
    return m_bienImmobilierAVendre;
}
