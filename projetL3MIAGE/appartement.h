#ifndef FLAT_H
#define FLAT_H

#include <iostream>
#include "bienimmobilier.h"

class Appartement : public BienImmobilier
{
private:
    unsigned short m_nbSalles;
    unsigned int m_etage;
    bool m_garage;
    bool m_cave;
    bool m_balcon;
    unsigned int m_nbAppartBatiment;
public:
    //Constructeurs
    Appartement() = delete;
    Appartement(std::string addresse, short surface, unsigned int prix, Vendeur s, unsigned short nbSalles, unsigned int etage, bool garage, bool cave, bool balcon, unsigned int nbAppartBatiment);

    //Getters
    virtual std::string getType() const;
    virtual char getSauvegardeType() const;
    unsigned short getNbSalles() const;
    unsigned int getEtage() const;
    bool getGarage() const;
    bool getCave() const;
    bool getBalcon() const;
    unsigned int getNbAppartBatiment() const;

    //Setters
    void setNbSalles(unsigned short newNbSalles);
    void setEtage(unsigned int etage);
    void setGarage(bool garage);
    void setCave(bool cave);
    void setBalcon(bool balcon);
    void setNbAppartBatiment(unsigned int nbAppartBatiment);

    //Autres méthodes
    void afficher() const;
};

#endif // FLAT_H
