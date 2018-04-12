#ifndef VISIT_H
#define VISIT_H

#include <iostream>
#include "acheteur.h"
#include "client.h"
#include "vendeur.h"
#include "bienimmobilier.h"

class Visite
{
private:
    Acheteur m_acheteur;
    Vendeur m_vendeur;
    BienImmobilier m_re;
public:
    //Constructors
    Visite() = delete;
    Visite(Acheteur b, Vendeur s, BienImmobilier re);

    //Getters
    Acheteur getAcheteur() const;
    Vendeur getVendeur() const;
    BienImmobilier getBienImmobilier() const;

    //Setters
    void setAcheteur(Acheteur newAcheteur);
    void setVendeur(Vendeur newVendeur);
    void setBienImmobilier(BienImmobilier newBienImmobilier);

    //Operators
    bool operator<(Visite const& v) const;

    //Other Methods
    void afficher() const;
};

#endif // VISIT_H
