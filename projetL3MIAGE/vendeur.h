#ifndef SELLER_H
#define SELLER_H

#include "client.h"
#include <vector>

class BienImmobilier;

class Vendeur : public Client
{
private:
    std::vector<BienImmobilier> m_bienImmobilierAVendre;
public:
    Vendeur();

    virtual std::string getType() const;
    void ajoutBienImmobilierAVendre(BienImmobilier re);
    void vendreBienImmobilier(BienImmobilier re);

    //Getter
    std::vector<BienImmobilier> getBienImmobilierAVendre() const;
    virtual std::string getSauvegardeType() const;

};

#endif // SELLER_H
