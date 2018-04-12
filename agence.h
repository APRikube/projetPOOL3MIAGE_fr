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
    std::vector<Client> m_clients;
    std::vector<Vendeur> m_vendeurs;
    std::vector<Acheteur> m_acheteur;
    std::map<choixBienImmobilier*, Vendeur> m_bienImmobiliers;
public:
    //Constructors
    Agence() = default;

    //Getters
    std::vector<Client> getClients() const;
    std::map<choixBienImmobilier *, Vendeur> getBienImmobiliers() const;
    std::vector<Vendeur> getVendeurs() const;
    std::vector<Acheteur> getAcheteurs() const;
    //Setters

    //Other Methods
    void ajoutClient(Client &client);
    void ajoutBienImmobilier(Vendeur &vendeur, choixBienImmobilier *bienImmobilier);
    void ajoutAcheteur(Acheteur &b);
    void ajoutVendeur(Vendeur &s);
    void suppressionAcheteur();
    void suppressionVendeur();
    void suppressionBienImmobilier(choixBienImmobilier re);
    void vendre(choixBienImmobilier re);

    //save methods
    void sauvegarde();
    void sauvegardeVendeurs();
    void sauvegardeAcheteurs();
    void sauvegardeBienImmobiliers();

    //Autre méthodes
    void ouvertureVendeurs();
    void ouvertureAcheteurs();
    Appartement ouvertureAppartement(std::vector<std::string> infos);
    void ouvertureBienImmobiliers();
    void ouverture();
    std::vector<std::string> separation(std::string stringASeparer, char separateur);

    Vendeur trouverVendeur(std::string id) const;
    bool estNombre(std::string str);
};

#endif // AGENCY_H
