#ifndef SELLER_H
#define SELLER_H

#include "client.h"
#include <vector>

class BienImmobilier;

class Vendeur : public Client
{
public:
    //Constructeurs
    Vendeur();
    Vendeur(std::string nom, std::string prenom, std::string adresse);


    //Getter
    virtual char getSauvegardeType() const;
    virtual std::string getType() const;

};

#endif // SELLER_H
