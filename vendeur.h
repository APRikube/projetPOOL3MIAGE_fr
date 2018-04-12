#ifndef SELLER_H
#define SELLER_H

#include "client.h"
#include <vector>

class choixBienImmobilier;

class Vendeur : public Client
{
private:
    std::vector<choixBienImmobilier> m_bienImmobilierAVendre;
public:
    Vendeur();

    virtual std::string getType() const;
    void ajoutBienImmobilierAVendre(choixBienImmobilier re);
    void vendreBienImmobilier(choixBienImmobilier re);

    //Getter
    std::vector<choixBienImmobilier> getBienImmobilierAVendre() const;

};

#endif // SELLER_H
