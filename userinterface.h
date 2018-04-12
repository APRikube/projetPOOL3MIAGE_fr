#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <string>
#include "agence.h"
#include "acheteur.h"
#include "vendeur.h"
#include "visite.h"
#include "appartement.h"
#include "maison.h"
#include "terrain.h"
#include "localprofessionnel.h"

class UserInterface
{
private:
    bool m_quitter;
    bool m_retourAuMenu;
    std::string m_requete;
    std::string m_recherche;
    Agence *m_agence;
public:
    UserInterface() = delete;
    UserInterface(Agence *agence);

    void lire();

    //Getters
    bool estValider() const;

    //Setters

    //Autres méthodes
    void AfficherMenu() const;
    void afficherClients() const;
    void afficherBienImmobiliers() const;

    void ajoutClient();
    void ajoutBienImmobilier();
    void declarerVisite();

    void supprimerAcheteur();
    void supprimerVendeur();
    void supprimerBienImmobilier();

    void rechercheBienImmobilier();
    std::vector<choixBienImmobilier> rechercheBienImmobilierAvecSuperficie(int superficieMin, int superficieMax);
    std::vector<choixBienImmobilier> rechercheBienImmobilierAvecType(char bienImmobilierType);
    std::vector<choixBienImmobilier> rechercheBienImmobilierAvecBudget(unsigned int budget);

    bool estNombre(std::string str);

    Vendeur choixVendeur();
    Acheteur choixAcheteur();
    choixBienImmobilier chooseRealEstate(Vendeur s);
};

#endif // USERINTERFACE_H
