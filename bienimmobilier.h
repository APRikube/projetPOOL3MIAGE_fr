#ifndef REALESTATE_H
#define REALESTATE_H

#include "vendeur.h"

class choixBienImmobilier
{
protected:
    static int nextId;
    unsigned int m_prix;
    std::string m_adresse;
    short m_surface;
    Vendeur m_vendeur;
    int m_identifiant;
public:
    //Constructors
    choixBienImmobilier() = default;
    choixBienImmobilier(const choixBienImmobilier & re);
    choixBienImmobilier(unsigned int prix, std::string addresse, unsigned short surface, Vendeur vendeur);

    //Getters
    unsigned int getPrix() const;
    std::string getAdresse() const;
    short getSurface() const;
    Vendeur getVendeur() const;
    int getIdentifiant() const;

    virtual std::string getType() const;
    virtual char getSauvegardeType() const;

    //Setters

    //Operator
    bool operator<(const choixBienImmobilier & re) const;
    bool operator ==(const choixBienImmobilier & re) const;

    //Autres
    virtual void afficher() const;
};

#endif // REALESTATE_H
