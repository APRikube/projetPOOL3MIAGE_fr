#include "vendeur.h"
#include "bienimmobilier.h"
#include <algorithm>

using namespace std;

Vendeur::Vendeur()
    : Client()
{

}

Vendeur::Vendeur(string nom, string prenom, string adresse)
    : Client(nom, prenom, adresse)
{

}

string Vendeur::getType() const
{
    return "real estate";
}

char Vendeur::getSauvegardeType() const
{
    return 'v';
}
