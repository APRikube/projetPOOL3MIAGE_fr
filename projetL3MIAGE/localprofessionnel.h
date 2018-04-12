#ifndef PROFESSIONALLOCAL_H
#define PROFESSIONALLOCAL_H

#include <iostream>
#include "bienimmobilier.h"

class LocalProfessionnel : public BienImmobilier
{
private:
    unsigned short m_tailleVitrine;
    bool m_salleDeStockageDeMateriaux;
public:
    //Constructors
    LocalProfessionnel();
    LocalProfessionnel(unsigned short tailleVitrine, bool salleDeStockageDeMateriaux,
                      unsigned int prix, std::string adresse, short surface, Vendeur vendeur);

    //Getters
    virtual std::string getType() const;
    virtual char getSauvegardeType() const;
    bool getSalleDeStockage() const;
    unsigned short getTailleVitrine() const;

    //Setters
    void setSalleDeStockage(bool newSalleDeStockage);
    void setTailleVitrine(int newTailleVitrine);

    //Autre méthodes
    void afficher() const;
};

#endif // PROFESSIONALLOCAL_H
