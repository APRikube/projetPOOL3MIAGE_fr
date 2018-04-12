#ifndef PLOT_H
#define PLOT_H

#include <iostream>
#include "bienimmobilier.h"

class Terrain : public choixBienImmobilier
{
private:
    bool m_constructible;

public:
    Terrain() = delete;
    Terrain(bool constructible,unsigned int prix, std::string adresse, short surface, Vendeur vendeur);
    virtual std::string getType() const;
    virtual char getSauvegardeType() const;

    //Getters
    bool getConstructible() const;

    //Setters
    void setConstructible(bool constructible);
};

#endif // PLOT_H
