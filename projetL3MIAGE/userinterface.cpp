#include "userinterface.h"

using namespace std;

UserInterface::UserInterface(Agence *agence)
    :m_quitter(false),m_retourAuMenu(false),m_agence(agence)
{

}

bool UserInterface::estValider() const
{
    return !m_quitter;
}

void UserInterface::ajoutClient()
{
    string nom;
    string prenom;
    string adresse;
    string type;

    cout << "Quel est le nom du nouveau client?" << endl;
    cin.ignore();
    getline(cin, nom);
    cout << "Quel est le prénom du nouveau client?" << endl;
    getline(cin, prenom);
    cout << "Quel est l'adresse du nouveau client?" << endl;
    getline(cin, adresse);

    cout << "Est-ce que le nouveau client veut acheter un bien immobilier (appuyer sur 1 et valider) ou bien en vendre un (appuer sur 2 et valider)?" << endl;
    do {
        cin >> type;
    } while (type != "1" && type != "2");

    if (type == "1")
    {
        Acheteur a(nom, prenom, adresse);
        m_agence->ajoutAcheteur(a);
        m_agence->sauvegarde();
    } else {
        Vendeur v(nom, prenom, adresse);
        m_agence->ajoutVendeur(v);
        m_agence->sauvegarde();
    }
    cout << "Client ajouté !" << endl;
}

bool UserInterface::estNombre(string str)
{
    if (str.length()==0)
    {
        return false;
    }
    for (unsigned int i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            cout << "A nombre est requis" << endl;
            return false;
        }
    }
    return true;
}

Acheteur UserInterface::choixAcheteur()
{
    int i = 1;
    string choix;
    //Afficher les acheteurs disponibles
    for (Acheteur b : m_agence->getAcheteurs())
    {
        cout << i << ") " << b.getPrenom() << " " << b.getNom() << endl;
        ++i;
    }

    //Recupère les valeurs entrées au clavier
    do {
        cin >> choix;
    } while (!estNombre(choix) || (unsigned int)stoi(choix) > m_agence->getAcheteurs().size() || (unsigned int)stoi(choix) == 0);

    return m_agence->getAcheteurs()[stoi(choix)-1];
}

BienImmobilier UserInterface::choixBienImmobilier(Vendeur s)
{
    //Affiche tout les biens immobiliers du vendeur
    int i = 1;
    string choix;
    vector<BienImmobilier> vre;
    for (pair<BienImmobilier*, Vendeur> re : m_agence->getBienImmobiliers())
    {
        if (re.second.getId() == s.getId())
        {
            cout << i << ") " << re.first->getAdresse() << " : " << re.first->getPrix() << " ; " << re.first->getSurface() << endl;
            vre.push_back(*re.first);
        }
    }
    //Récupère le choix de l'utilisateur
    do {
        cin >> choix;
    } while (!estNombre(choix) || (unsigned int)stoi(choix) > m_agence->getBienImmobiliers().size() || (unsigned int)stoi(choix) == 0);

    return vre[stoi(choix)-1];
}

Vendeur UserInterface::choixVendeur()
{
    int i = 1;
    string choix;
    //Affiche les vendeurs disponible
    for (Vendeur s : m_agence->getVendeurs())
    {
        cout << i << ") " << s.getPrenom() << " " << s.getNom() << endl;
        ++i;
    }

    //Lis les valeurs entrées au clavier
    do {
        cin >> choix;
    } while (!estNombre(choix) || (unsigned int)stoi(choix) > m_agence->getVendeurs().size() || (unsigned int)stoi(choix) == 0);

    return m_agence->getVendeurs()[stoi(choix)-1];
}

void UserInterface::ajoutBienImmobilier()
{
    if (m_agence->getVendeurs().size() == 0)
    {
        cout << "Il n'y a pas de vendeur, vous ne pouvez pas ajouter de bien immobilier." << endl;
    } else {
        string type;
        string prix;
        string adresse;
        string surface;
        Vendeur vendeur;

        cout << "Quel est le type du bien immobilier ?" << endl;
        cout << "1) Appartement" << endl;
        cout << "2) Maison" << endl;
        cout << "3) Terrain" << endl;
        cout << "4) Local professionnel" << endl;
        do {
            cin >> type;
        } while(!estNombre(type) || (stoi(type) > 4) || (stoi(type) == 0));

        cout << "Quel est le prix du bien immobilier ?" << endl;
        do {
            getline(cin, prix);
        } while (!estNombre(prix));

        cout << "Quel est l'adresse du bien immobilier ?" << endl;
        getline(cin, adresse);

        cout << "Quel est la surface de ce bien immobilier ?" << endl;
        do {
            cin >> surface;
        }  while (!estNombre(surface));

        cout << "Qui en est le vendeur ?" << endl;
        vendeur = choixVendeur();

        switch (stoi(type))
        {
        case 1:
        {
            string salles;
            cout << "De combien de salles est composés l'appartement ?" << endl;
            do {
                cin >> salles;
            } while (!estNombre(salles));

            string etage;
            cout << "A quel étage se trouve l'appartement? (Pour le rez de chaussé, appuyer sur 0)" << endl;
            do {
                cin >> etage;
            } while (!estNombre(etage));

            bool garage;
            string stringGarage;
            cout << "L'appartement a-t-il un garage? (1 pour oui, 0 pour non)" << endl;
            cin >> stringGarage;
            garage = stoi(stringGarage);

            bool cave;
            string stringCave;
            cout << "L'appartement a-t-il une cave? (1 pour oui, 0 pour non)" << endl;
            cin >> stringCave;
            cave = stoi(stringCave);

            bool balcon;
            string stringBalcon;
            cout << "L'appartement a-t-il un balcon? (1 pour oui, 0 pour non)" << endl;
            cin >> stringBalcon;
            balcon = stoi(stringBalcon);

            string nbAppartBatiment;
            cout << "De combien d'appartements est composés le bâtiment ?" << endl;
            do {
                cin >> nbAppartBatiment;
            } while (!estNombre(nbAppartBatiment));

            Appartement *f = new Appartement(adresse, stoi(surface), stoi(prix), vendeur, stoi(salles), stoi(etage)
                   , garage, cave, balcon, stoi(nbAppartBatiment));
            m_agence->ajoutBienImmobilier(vendeur, f);
            break;
        }
        case 2 :
        {
            string nbSalles;
            cout << "De combien de salles est composées la maison?" << endl;
            do {
                cin >> nbSalles;
            } while (!estNombre(nbSalles));

            bool piscine;
            string stringPiscine;
            cout << "La maison est-elle composée d'une piscine? (1 pour oui, 0 pour non)" << endl;
            cin >> stringPiscine;
            piscine = stoi(stringPiscine);

            bool garage;
            string stringGarage;
            cout << "La maison a-t-elle un garage? (1 pour oui, 0 pour non)" << endl;
            cin >> stringGarage;
            garage = stoi(stringGarage);

            Maison *h = new Maison(adresse, stoi(surface), stoi(prix), vendeur, stoi(nbSalles), piscine, garage);
            m_agence->ajoutBienImmobilier(vendeur, h);
            break;
        }
        case 3:
        {
            bool constructible;
            string stringConstructible;
            cout << "La terrain est-il constructible? (1 pour oui, 0 pour non)"<< endl;
            cin >> stringConstructible;
            constructible = stoi(stringConstructible);

            Terrain *p = new Terrain(constructible, stoi(prix), adresse, stoi(surface), vendeur);
            m_agence->ajoutBienImmobilier(vendeur, p);
            break;
        }
        case 4:
        {
            string tailleVitrine;
            cout << "Quel est la taille de la vitrine (En métre carré)?" << endl;
            cin >> tailleVitrine;

            bool salleDeStockage;
            string stringSalleDeStockage;
            cout << "Le local a-t-il une salle pour stocker le matériels? (1 pour oui, 0 pour non)" << endl;
            cin >> stringSalleDeStockage;
            salleDeStockage = stoi(stringSalleDeStockage);

            LocalProfessionnel *pl = new LocalProfessionnel(stoi(tailleVitrine), salleDeStockage, stoi(prix),adresse, stoi(surface), vendeur);
            m_agence->ajoutBienImmobilier(vendeur, pl);
            break;
        }
        default:
        {
            break;
        }
        }
        m_agence->sauvegarde();
    }
}

void UserInterface::declarerVisite()
{
    if (m_agence->getAcheteurs().size() == 0)
    {
        cout << "Il n'y a pas d'acheteur, vous ne pouvez pas déclarer de visite." << endl;
    } else if (m_agence->getVendeurs().size()==0)
    {
        cout << "Il n'y a pas de vendeur, vous ne pouvez pas déclarer de visite" << endl;
    } else if (m_agence->getBienImmobiliers().size() == 0)
    {
        cout << "Il n'y pas de biens immobiliers, vous ne pouvez pas déclarer de visite." << endl;
    } else {
        Acheteur b;
        Vendeur s;
        BienImmobilier re;
        b = choixAcheteur();
        s = choixVendeur();
        re = choixBienImmobilier(s);
        Visite v(b,s,re);
        b.ajoutVisite(v);
    }
}

void UserInterface::afficherClients() const
{
    if (m_agence->getAcheteurs().size()+
            m_agence->getVendeurs().size()==0)
    {
        cout << "Il n'y a pas de clients" << endl;
    }
    if (m_agence->getVendeurs().size()!=0)
    {
        cout << "Vendeurs : " << endl;
        for (Vendeur s : this->m_agence->getVendeurs())
        {
            cout << s.getPrenom() << " " << s.getNom() << " loge à " << s.getAdresse() << endl;
        }
    }
    if (m_agence->getAcheteurs().size()!=0)
    {
        cout << "Acheteurs : " << endl;
        for (Acheteur b : this->m_agence->getAcheteurs())
        {
            cout << b.getPrenom() << " " << b.getNom() << " loge à " << b.getAdresse() << endl;
        }
    }
}

void UserInterface::supprimerAcheteur()
{
    if (m_agence->getAcheteurs().size() == 0)
    {
        cout << "Il n'y a pas d'acheteur." << endl;
    }
    else {
        m_agence->suppressionAcheteur();
        m_agence->sauvegarde();
    }
}

void UserInterface::supprimerVendeur()
{
    if (m_agence->getVendeurs().size()==0)
    {
        cout << "Il n'y a pas de vendeur." << endl;
    }
    else {
        m_agence->suppressionVendeur();
        m_agence->sauvegarde();
    }
}

void UserInterface::supprimerBienImmobilier()
{
    if (m_agence->getBienImmobiliers().size()==0)
    {
        cout << "Il n'y a pas de bien immobilier" << endl;
    } else {
        cout << "Choissisez votre vendeur : " << endl;
        m_agence->suppressionBienImmobilier(choixBienImmobilier(choixVendeur()));
        m_agence->sauvegarde();
    }
}

void UserInterface::afficherBienImmobiliers() const
{
    if (this->m_agence->getBienImmobiliers().size() == 0)
    {
        cout << "Il n'y a pas de bien immobilier" << endl;
    } else {
        for (pair<BienImmobilier*,Client> re : this->m_agence->getBienImmobiliers())
        {
            cout << "L'" << re.first->getType() << " n° " << re.first->getIdentifiant() << " est disponible pour ";
            cout << re.first->getPrix() << "€ et vendu par " << re.first->getVendeur().getPrenom();
            cout << " " << re.first->getVendeur().getNom() << endl;
            re.first->afficher();
        }
    }
}

vector<BienImmobilier> UserInterface::rechercheBienImmobilierAvecSuperficie(int superficieMin, int superficieMax)
{
    vector<BienImmobilier> resultat;
    for(pair<BienImmobilier*,Vendeur> it : m_agence->getBienImmobiliers())
    {
        if(it.first->getSurface() <= superficieMax && it.first->getSurface() >= superficieMin)
        {
            resultat.push_back(*it.first);
        }
    }
    return resultat;
}

vector<BienImmobilier> UserInterface::rechercheBienImmobilierAvecType(char bienImmobilierType)
{
    vector<BienImmobilier> resultat;
    for(pair<BienImmobilier*,Vendeur> it : m_agence->getBienImmobiliers())
    {
        if(it.first->getSauvegardeType() == bienImmobilierType)
        {
            resultat.push_back(*it.first);
        }
    }
    return resultat;
}

vector<BienImmobilier> UserInterface::rechercheBienImmobilierAvecBudget(unsigned int budget)
{
    vector<BienImmobilier> resultat;
    for(pair<BienImmobilier*,Vendeur> it : m_agence->getBienImmobiliers())
    {
        if(it.first->getPrix() <= budget)
        {
            cout << it.first->getPrix() << endl;
            resultat.push_back(*it.first);
        }
    }
    return resultat;
}

void UserInterface::rechercheBienImmobilier()
{
    vector<BienImmobilier> resultatRecherche;
    unsigned int budget;
    string superficieMin;
    string superficieMax;
    char bienImmobilierType;
    cout << "Appuyer sur B et validé pour retourner au menu !" << endl;
    cout<< "1) Quel est votre budget max ?" << endl;
    cout<< "2) Quel type de bien immobilier recherché vous ?" << endl;
    cout<< "3) Quel superficie ?" << endl;

    cin >> m_recherche;

    if (m_recherche == "b" || m_recherche == "back")
    {
        m_retourAuMenu = true;
    }
    else if(m_recherche == "1")
    {
        cin >> budget;
        cout << budget << endl;
        resultatRecherche = rechercheBienImmobilierAvecBudget(budget);
    }
    else if(m_recherche == "2")
    {
        cout << "l pour un local professionnel" << endl;
        cout << "t pour un terrain" << endl;
        cout << "m pour une maison" << endl;
        cout << "a pour un appartement" << endl;
        cin >> bienImmobilierType;
        resultatRecherche = rechercheBienImmobilierAvecType(bienImmobilierType);
    }
    else if(m_recherche == "3")
    {
        cout<< "Superficie minimale" << endl;
        cin >> superficieMin;
        while(!estNombre(superficieMin))
        {
            cin >> superficieMin;
        }
        cout<< "Superficie maximale" << endl;
        cin >> superficieMax;
        while(!estNombre(superficieMax))
        {
            cin >> superficieMax;
        }
        resultatRecherche = rechercheBienImmobilierAvecSuperficie(stoi(superficieMin), stoi(superficieMax));
    }
    else
    {
        cout << "Désolé votre requête n'a pas été reconnu, veuillez en effectuer une nouvelle" << endl;
    }

    for(BienImmobilier re : resultatRecherche) {
        cout << "L' " << re.getType() << " n°" << re.getIdentifiant() << " est disponible pour";
        cout << re.getPrix() << "€ et est vendu par " << re.getVendeur().getPrenom();
        cout << " " << re.getVendeur().getNom() << endl;
    }
    if(resultatRecherche.empty())
    {
        cout << "Aucun bien immobilier ne correspond à votre demande" << endl;
    }

}

void UserInterface::AfficherMenu() const
{
    cout << "Appuyez sur q et validé pour quitter l'application" << endl;
    cout << "Menu : " << endl;
    cout << "1) Ajout d'un client" << endl;
    cout << "2) Ajout d'un bien immobilier" << endl;
    cout << "3) Declarer une visite" << endl;
    cout << "4) Afficher tout les clients" << endl;
    cout << "5) Afficher tout les biens immobiliers" << endl;
    cout << "6) Supprimer un vendeur" << endl;
    cout << "7) Supprimer un acheteur" << endl;
    cout << "8) Supprimer un bien immobilier" << endl;
    cout << "9) Trouver le bien immobilier de vos rêves" << endl;
    cout << "10) Effectuer une proposition d'achat" << endl;
}

void UserInterface::lire()
{
    while (!m_quitter)
    {
        AfficherMenu();
        cin >> m_requete;
        if (m_requete == "q" || m_requete == "quit" || m_requete == "exit")
        {
            m_quitter = true;
        }
        else if (m_requete == "1")
        {
            system("clear");
            ajoutClient();
            system("clear");
        }
        else if (m_requete == "2")
        {
            system("clear");
            ajoutBienImmobilier();
            system("clear");
        }
        else if (m_requete == "3")
        {
            declarerVisite();
        }
        else if (m_requete == "4")
        {
            system("clear");
            afficherClients();
        }
        else if (m_requete == "5")
        {
            system("clear");
            afficherBienImmobiliers();
        }
        else if (m_requete == "6")
        {
            supprimerVendeur();
            system("clear");
        }
        else if (m_requete == "7")
        {
            supprimerAcheteur();
            system("clear");
        }
        else if (m_requete == "8")
        {
            supprimerBienImmobilier();
            system("clear");
        }
        else if (m_requete == "9")
        {
            while(!m_retourAuMenu)
            {
                rechercheBienImmobilier();
            }
            m_retourAuMenu = false;
        }
        else if (m_requete == "10")
        {

            system("clear");
            if(m_agence->getAcheteurs().size() !=0)
            {
                vector<Acheteur> acheteurDuBien;
                string choix;
                int compteurBE = 1;
                int compteurA = 1;
                for(pair<BienImmobilier*,Client> re : m_agence->getBienImmobiliers()) {
                    cout <<compteurBE << ") L' " << re.first->getType() << " n°" << re.first->getIdentifiant() << " est disponible pour";
                    cout << re.first->getPrix() << "€"<<endl;
                    ++compteurBE;
                }
                do {
                    cin >> choix;
                } while (!estNombre(choix) || (unsigned int)stoi(choix) > m_agence->getBienImmobiliers().size() || (unsigned int)stoi(choix) == 0);

                BienImmobilier *bienImmobilierChoisi;
                compteurBE=1;
                for(pair<BienImmobilier*,Client> re : m_agence->getBienImmobiliers()) {

                    if(compteurBE==stoi(choix))
                    {
                        bienImmobilierChoisi = re.first;
                    }
                    ++compteurBE;
                }

                cout << "Pour quel acheteur ?" << endl;
                for(Acheteur a : m_agence->getAcheteurs()) {
                    cout << compteurA <<") "<<a.getPrenom() << " " << a.getNom() << " loge à " << a.getAdresse() << endl;
                    ++compteurA;
                }
                do {
                    cin >> choix;
                } while (!estNombre(choix) || (unsigned int)stoi(choix) > m_agence->getBienImmobiliers().size() || (unsigned int)stoi(choix) == 0);

                for(pair<BienImmobilier*,vector<Acheteur>> re : m_agence->getPropositionAchats())
                {
                    if(re.first == bienImmobilierChoisi)
                    {
                        acheteurDuBien = re.second;
                        re.second.push_back(m_agence->getAcheteurs()[stoi(choix)-1]);
                        //acheteurDuBien.push_back(m_agence->getVendeurs()[stoi(choix)-1]);
                        //m_agence->getPropositionAchats()
                    }
                }
                if(acheteurDuBien.empty())
                {
                    acheteurDuBien.push_back(m_agence->getAcheteurs()[stoi(choix)-1]);
                    m_agence->getPropositionAchats().insert(pair<BienImmobilier*,vector<Acheteur>>(bienImmobilierChoisi,acheteurDuBien));
                }

            }
            else
            {
                cout << "Pas d'acheteur pour effectuer une proposition d'achat. " << endl;
            }

        } else {
            cout << "Désolé mais votre requête n'a pas été reconnu, veuillez en effectuer une nouvelle" << endl;
        }
    }

}
