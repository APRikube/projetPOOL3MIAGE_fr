#ifndef SELLER_H
#define SELLER_H

#include "client.h"
#include <vector>

class BienImmobilier;

class Vendeur : public Client
{
public:
    Vendeur();

    virtual std::string getType() const;

    //Getter
    virtual char getSauvegardeType() const;

};

#endif // SELLER_H
