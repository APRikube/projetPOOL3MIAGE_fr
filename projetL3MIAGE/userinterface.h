
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
    //Constructeurs
    UserInterface() = delete;
    UserInterface(Agence *agence);

    //Getters
    bool estValider() const;

    void lire();

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
    std::vector<BienImmobilier> rechercheBienImmobilierAvecSuperficie(int superficieMin, int superficieMax);
    std::vector<BienImmobilier> rechercheBienImmobilierAvecType(char bienImmobilierType);
    std::vector<BienImmobilier> rechercheBienImmobilierAvecBudget(unsigned int budget);

    bool estNombre(std::string str);

    Vendeur choixVendeur();
    Acheteur choixAcheteur();
    BienImmobilier choixBienImmobilier(Vendeur s);
};

#endif // USERINTERFACE_H
