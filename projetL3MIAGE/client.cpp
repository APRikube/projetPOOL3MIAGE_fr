#include "client.h"

int Client::m_id = 0;

Client::Client()
    :m_identifiant(++m_id), m_nom("Unknown"), m_prenom("Unknown"), m_adresse("Unknown")
{
}

Client::Client(std::string nom, std::string prenom, std::string adresse)
    :m_identifiant(++m_id), m_nom(nom), m_prenom(prenom), m_adresse(adresse)
{}

std::string Client::getNom() const
{
    return m_nom;
}

std::string Client::getPrenom() const
{
    return m_prenom;
}

std::string Client::getAdresse() const
{
    return m_adresse;
}

int Client::getId() const
{
    return m_id;
}

void Client::setNom(std::string newNom)
{
    this->m_nom = newNom;
}

void Client::setPrenom(std::string newPrenom)
{
    this->m_prenom = newPrenom;
}

void Client::setAdresse(std::string newAdresse)
{
    this->m_adresse = newAdresse;
}

