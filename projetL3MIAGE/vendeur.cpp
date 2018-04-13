#include "vendeur.h"
#include "bienimmobilier.h"
#include <algorithm>

using namespace std;

Vendeur::Vendeur()
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
