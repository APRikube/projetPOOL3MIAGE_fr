#ifndef REALESTATE_H
#define REALESTATE_H

#include "vendeur.h"

class BienImmobilier
{
protected:
    static int nextId;
    unsigned int m_prix;
    std::string m_adresse;
    short m_surface;
    Vendeur m_vendeur;
    int m_identifiant;
public:
    //Constructeurs
    BienImmobilier() = default;
    BienImmobilier(const BienImmobilier & re);
    BienImmobilier(unsigned int prix, std::string addresse, unsigned short surface, Vendeur vendeur);
    virtual ~BienImmobilier();

    //Getters
    unsigned int getPrix() const;
    std::string getAdresse() const;
    short getSurface() const;
    Vendeur getVendeur() const;
    int getIdentifiant() const;
    virtual std::string getType() const;
    virtual char getSauvegardeType() const;

    //Operator
    bool operator<(const BienImmobilier & re) const;
    bool operator ==(const BienImmobilier & re) const;

    //Autres
    virtual void afficher() const;
};

#endif // REALESTATE_H
