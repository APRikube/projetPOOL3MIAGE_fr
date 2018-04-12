#include "localprofessionnel.h"

ProfessionalLocal::ProfessionalLocal()
{

}

ProfessionalLocal::ProfessionalLocal(unsigned short tailleVitrine, bool salleDeStockageDeMateriaux, unsigned int prix, std::string adresse, short surface, Vendeur vendeur)
    :choixBienImmobilier(prix, adresse, surface, vendeur), m_tailleVitrine(tailleVitrine), m_salleDeStockageDeMateriaux(salleDeStockageDeMateriaux)
{
}

bool ProfessionalLocal::getSalleDeStockage() const
{
    return m_salleDeStockageDeMateriaux;
}

std::string ProfessionalLocal::getType() const
{
    return "professional local";
}

char ProfessionalLocal::getSauvegardeType() const
{
    return 'l';
}

unsigned short ProfessionalLocal::getTailleVitrine() const
{
    return m_tailleVitrine;
}

void ProfessionalLocal::setSalleDeStockage(bool newSalleDeStockage)
{
    m_salleDeStockageDeMateriaux = newSalleDeStockage;
}
void ProfessionalLocal::setTailleVitrine(int newTailleVitrine)
{
    m_tailleVitrine = newTailleVitrine;
}


