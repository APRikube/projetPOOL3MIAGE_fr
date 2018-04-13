#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

class Client
{
protected:
    static int m_id;
    int m_identifiant;
    std::string m_nom;
    std::string m_prenom;
    std::string m_adresse;
public:
    //Constructor
    Client();
    Client(std::string nom, std::string prenom, std::string adresse);

    //Getters
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getAdresse() const;
    int getId() const;
    virtual std::string getSauvegardeType() const;

    //Setters
    void setNom(std::string newNom);
    void setPrenom(std::string newPrenom);
    void setAdresse(std::string newAdresse);

};

#endif // CUSTOMER_H
