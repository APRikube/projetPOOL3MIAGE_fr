#include <iostream>

#include "agence.h"
#include "acheteur.h"
#include "vendeur.h"
#include "userinterface.h"
#include "visite.h"

using namespace std;

int main()
{
    Agence agency;
    agency.ouverture();
    UserInterface ui(&agency);
    std::cout << "Welcome to your new Agency Handling software" << std::endl;
    while (ui.estValider())
    {
        ui.lire();
    }
    agency.sauvegarde();
    std::cout << "Thank you for using our software, see you !" << std::endl;
    return 0;
}
