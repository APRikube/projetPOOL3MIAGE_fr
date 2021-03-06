#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "bienimmobilier.h"

class Maison : public BienImmobilier
{
private:
    unsigned short m_nbSalles;
    bool m_piscine;
    bool m_garage;
public:
    //Constructeurs
    Maison() = delete;
    Maison(std::string adresse, short surface, unsigned int prix, Vendeur s, unsigned short nbSalles, bool piscine, bool garage);

    //Getters
    unsigned short getNbSalles() const;
    bool hasPiscine() const;
    bool hasGarage() const;
    virtual std::string getType() const;
    virtual char getSauvegardeType() const;

    //Setters
    void setNbSalles(unsigned short nbSalles);
    void setPiscine(bool has);
    void setGarage(bool has);

    //Autre méthodes
    void afficher() const;
};

#endif // HOUSE_H
