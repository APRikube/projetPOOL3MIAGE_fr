#include "client.h"

using namespace std;

int Client::m_id = 0;

Client::Client()
    :m_identifiant(++m_id), m_nom("Unknown"), m_prenom("Unknown"), m_adresse("Unknown")
{
}

Client::Client(string nom, string prenom, string adresse)
    :m_identifiant(++m_id), m_nom(nom), m_prenom(prenom), m_adresse(adresse)
{}

string Client::getNom() const
{
    return m_nom;
}

string Client::getPrenom() const
{
    return m_prenom;
}

string Client::getAdresse() const
{
    return m_adresse;
}

int Client::getId() const
{
    return m_identifiant;
}

char Client::getSauvegardeType() const
{
    return 'c';
}

void Client::setNom(string newNom)
{
    this->m_nom = newNom;
}

void Client::setPrenom(string newPrenom)
{
    this->m_prenom = newPrenom;
}

void Client::setAdresse(string newAdresse)
{
    this->m_adresse = newAdresse;
}

