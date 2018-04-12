#include "localprofessionnel.h"

LocalProfessionnel::LocalProfessionnel()
{

}

LocalProfessionnel::LocalProfessionnel(unsigned short tailleVitrine, bool salleDeStockageDeMateriaux, unsigned int prix, std::string adresse, short surface, Vendeur vendeur)
    :BienImmobilier(prix, adresse, surface, vendeur), m_tailleVitrine(tailleVitrine), m_salleDeStockageDeMateriaux(salleDeStockageDeMateriaux)
{
}

bool LocalProfessionnel::getSalleDeStockage() const
{
    return m_salleDeStockageDeMateriaux;
}

std::string LocalProfessionnel::getType() const
{
    return "local professionnel";
}

char LocalProfessionnel::getSauvegardeType() const
{
    return 'l';
}

unsigned short LocalProfessionnel::getTailleVitrine() const
{
    return m_tailleVitrine;
}

void LocalProfessionnel::setSalleDeStockage(bool newSalleDeStockage)
{
    m_salleDeStockageDeMateriaux = newSalleDeStockage;
}
void LocalProfessionnel::setTailleVitrine(int newTailleVitrine)
{
    m_tailleVitrine = newTailleVitrine;
}


