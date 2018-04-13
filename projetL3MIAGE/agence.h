#ifndef AGENCY_H
#define AGENCY_H

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <fstream>

#include "client.h"
#include "bienimmobilier.h"
#include "acheteur.h"
#include "visite.h"
#include "appartement.h"
#include "localprofessionnel.h"
#include "maison.h"
#include "terrain.h"

class Agence
{
private:
    std::vector<Vendeur> m_vendeurs;
    std::vector<Acheteur> m_acheteur;
    std::map<BienImmobilier*, Vendeur> m_bienImmobiliers;
    std::map<BienImmobilier*,std::vector<Acheteur>> _propositionAchats;
public:
    //Constructors
    Agence() = default;

    //Getters
    std::map<BienImmobilier *, Vendeur> getBienImmobiliers() const;
    std::vector<Vendeur> getVendeurs() const;
    std::vector<Acheteur> getAcheteurs() const;
    std::map<BienImmobilier *, std::vector<Acheteur> > getPropositionAchats() const;
    //Setters

    //Other Methods
    void ajoutBienImmobilier(Vendeur &vendeur, BienImmobilier *bienImmobilier);
    void ajoutAcheteur(Acheteur &b);
    void ajoutVendeur(Vendeur &s);
    void suppressionAcheteur();
    void suppressionVendeur();
    void suppressionBienImmobilier(BienImmobilier re);

    //save methods
    void sauvegarde();
    void sauvegardeVendeurs();
    void sauvegardeAcheteurs();
    void sauvegardeBienImmobiliers();

    //Autre méthodes
    void ouvertureVendeurs();
    void ouvertureAcheteurs();
    void ouvertureAppartement(std::vector<std::string> infos);
    void ouvertureLocalProfessionnel(std::vector<std::string> infos);
    void ouvertureMaison(std::vector<std::string> infos);
    void ouvertureTerrains(std::vector<std::string> infos);
    void ouvertureBienImmobiliers();
    void ouverture();
    std::vector<std::string> separation(std::string stringASeparer, char separateur);

    Vendeur trouverVendeur(std::string id) const;
    bool estNombre(std::string str);
};

#endif // AGENCY_H
