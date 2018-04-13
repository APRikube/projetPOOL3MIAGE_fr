#ifndef BUYER_H
#define BUYER_H

#include <set>
#include "client.h"

class Visite;

class Acheteur : public Client
{
protected:
    bool m_propositionAchat;
    std::set<Visite> m_visites;
public:
    Acheteur();
    Acheteur(std::string nom, std::string prenom, std::string adresse);

    //Getters
    bool getPropositionAchat() const;
    std::set<Visite> getVisites();
    virtual char getSauvegardeType() const;

    //Setters
    void setPropositionAchat(bool newValue);

    //Autres méthodes
    void ajoutVisite(Visite v);
    void afficherVisites() const;
};

#endif // BUYER_H
