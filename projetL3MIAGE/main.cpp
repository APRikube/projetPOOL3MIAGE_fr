#include <iostream>

#include "agence.h"
#include "acheteur.h"
#include "vendeur.h"
#include "userinterface.h"
#include "visite.h"

using namespace std;

int main()
{
    Agence agence;
    agence.ouverture();
    UserInterface ui(&agence);
    cout << "Bienvenue dans l'application de gestion de votre agence" << endl;
    while (ui.estValider())
    {
        ui.lire();
    }
    agence.sauvegarde();
    std::cout << "Fermeture de l'application" << std::endl;
    return 0;
}
