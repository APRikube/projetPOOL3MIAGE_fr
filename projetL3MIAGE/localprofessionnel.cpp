#include "localprofessionnel.h"

using namespace std;

LocalProfessionnel::LocalProfessionnel()
{

}

LocalProfessionnel::LocalProfessionnel(unsigned short tailleVitrine, bool salleDeStockageDeMateriaux, unsigned int prix, string adresse, short surface, Vendeur vendeur)
    :BienImmobilier(prix, adresse, surface, vendeur), m_tailleVitrine(tailleVitrine), m_salleDeStockageDeMateriaux(salleDeStockageDeMateriaux)
{
}

bool LocalProfessionnel::getSalleDeStockage() const
{
    return m_salleDeStockageDeMateriaux;
}

string LocalProfessionnel::getType() const
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

void LocalProfessionnel::afficher() const
{
    cout << "L'appartement est localisé à " << m_adresse << endl;
    cout << "Il est vendu pour " << m_prix << "€" << endl;
    cout << "Ca surface est de " << m_surface << " métres carrés." << endl;
    cout << "La taille de la vitrine est de " << m_tailleVitrine << "." << endl;
    if (m_salleDeStockageDeMateriaux)
    {
        cout << "Il possède une salle permettant de stocker le matériels." << endl;
    }
}


