#include "userinterface.h"

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
    std::string nom;
    std::string prenom;
    std::string adresse;
    std::string type;

    std::cout << "Quel est le nom du nouveau client?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, nom);
    std::cout << "Quel est le prénom du nouveau client?" << std::endl;
    std::getline(std::cin, prenom);
    std::cout << "Quel est l'adresse du nouveau client?" << std::endl;
    std::getline(std::cin, adresse);

    std::cout << "Est-ce que le nouveau client veut acheter un bien immobilier (appuyer sur 1 et valider) ou bien en vendre un (appuer sur 2 et valider)?" << std::endl;
    do {
        std::cin >> type;
    } while (type != "1" && type != "2");

    if (type == "1")
    {
        Acheteur b;
        b.setAdresse(adresse);
        b.setPrenom(prenom);
        b.setNom(nom);
        m_agence->ajoutAcheteur(b);
        m_agence->sauvegarde();
    } else {
        Vendeur s;
        s.setAdresse(adresse);
        s.setPrenom(prenom);
        s.setNom(nom);
        m_agence->ajoutVendeur(s);
        m_agence->sauvegarde();
    }
    std::cout << "Client ajouté !" << std::endl;
}

bool UserInterface::estNombre(std::string str)
{
    if (str.length()==0)
    {
        return false;
    }
    for (unsigned int i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            std::cout << "A nombre est requis" << std::endl;
            return false;
        }
    }
    return true;
}

Acheteur UserInterface::choixAcheteur()
{
    int i = 1;
    std::string choix;
    //Afficher les acheteurs disponibles
    for (Acheteur b : m_agence->getAcheteurs())
    {
        std::cout << i << ") " << b.getPrenom() << " " << b.getNom() << std::endl;
        ++i;
    }

    //Recupère les valeurs entrées au clavier
    do {
        std::cin >> choix;
    } while (!estNombre(choix) && (unsigned int)std::stoi(choix) > m_agence->getAcheteurs().size());

    return m_agence->getAcheteurs()[std::stoi(choix)-1];
}

choixBienImmobilier UserInterface::chooseRealEstate(Vendeur s)
{
    //Affiche tout les biens immobiliers du vendeur
    int i = 1;
    std::string choix;
    std::vector <choixBienImmobilier> vre;
    for (std::pair<choixBienImmobilier*, Vendeur> re : m_agence->getBienImmobiliers())
    {
        if (re.second.getId() == s.getId())
        {
            std::cout << i << ") " << re.first->getAdresse() << " : " << re.first->getPrix() << " ; " << re.first->getSurface() << std::endl;
            vre.push_back(*re.first);
        }
    }
    //Récupère le choix de l'utilisateur
    do {
        std::cin >> choix;
    } while (!estNombre(choix) && (unsigned int)std::stoi(choix) > m_agence->getBienImmobiliers().size());

    return vre[std::stoi(choix)-1];
}

Vendeur UserInterface::choixVendeur()
{
    int i = 1;
    std::string choix;
    //Affiche les vendeurs disponible
    for (Vendeur s : m_agence->getVendeurs())
    {
        std::cout << i << ") " << s.getPrenom() << " " << s.getNom() << std::endl;
        ++i;
    }

    //Lis les valeurs entrées au clavier
    do {
        std::cin >> choix;
    } while (!estNombre(choix) && (unsigned int)std::stoi(choix) > m_agence->getVendeurs().size());

    return m_agence->getVendeurs()[std::stoi(choix)-1];
}

void UserInterface::ajoutBienImmobilier()
{
    if (m_agence->getVendeurs().size() == 0)
    {
        std::cout << "Il n'y a pas de vendeur, vous ne pouvez pas ajouter de bien immobilier." << std::endl;
    } else {
        std::string type;
        std::string prix;
        std::string adresse;
        std::string surface;
        Vendeur vendeur;

        std::cout << "Quel est le type du bien immobilier?" << std::endl;
        std::cout << "1) Appartement" << std::endl;
        std::cout << "2) Maison" << std::endl;
        std::cout << "3) Terrain" << std::endl;
        std::cout << "4) Local professionnel" << std::endl;
        do {
            std::cin >> type;
        } while(!estNombre(type) || (std::stoi(type) > 4) || (std::stoi(type) == 0));

        std::cout << "Quel est le prix du bien immobilier?" << std::endl;
        do {
            std::getline(std::cin, prix);
        } while (!estNombre(prix));

        std::cout << "Quel est l'adresse du bien immobilier?" << std::endl;
        std::getline(std::cin, adresse);

        std::cout << "Quel est la surface de ce bien immobilier?" << std::endl;
        do {
            std::cin >> surface;
        }  while (!estNombre(surface));

        vendeur = choixVendeur();

        switch (std::stoi(type))
        {
        case 1:
        {
            std::string salles;
            std::cout << "De combien de salles est composés l'appartement?" << std::endl;
            do {
                std::cin >> salles;
            } while (!estNombre(salles));

            std::string etage;
            std::cout << "A quel étage se trouve l'appartement? (Pour le rez de chaussé, appuyer sur 0)" << std::endl;
            do {
                std::cin >> etage;
            } while (!estNombre(etage));

            bool garage;
            std::string stringGarage;
            std::cout << "L'appartement a-t-il un garage? (1 pour oui, 0 pour non)" << std::endl;
            std::cin >> stringGarage;
            garage = std::stoi(stringGarage);

            bool cave;
            std::string stringCave;
            std::cout << "L'appartement a-t-il une cave? (1 pour oui, 0 pour non)" << std::endl;
            std::cin >> stringCave;
            cave = std::stoi(stringCave);

            bool balcon;
            std::string stringBalcon;
            std::cout << "L'appartement a-t-il un balcon? (1 pour oui, 0 pour non)" << std::endl;
            std::cin >> stringBalcon;
            balcon = std::stoi(stringBalcon);

            std::string nbAppartBatiment;
            std::cout << "De combien d'appartements est composés le bâtiment ?" << std::endl;
            do {
                std::cin >> nbAppartBatiment;
            } while (!estNombre(nbAppartBatiment));

            Appartement *f = new Appartement(adresse, std::stoi(surface), std::stoi(prix), vendeur, std::stoi(salles), std::stoi(etage)
                   , garage, cave, balcon, std::stoi(nbAppartBatiment));
            m_agence->ajoutBienImmobilier(vendeur, f);
            break;
        }
        case 2 :
        {
            std::string nbSalles;
            std::cout << "De combien de salles est composées la maison?" << std::endl;
            do {
                std::cin >> nbSalles;
            } while (!estNombre(nbSalles));

            bool piscine;
            std::string stringPiscine;
            std::cout << "La maison est-elle composée d'une piscine? (1 pour oui, 0 pour non)" << std::endl;
            std::cin >> stringPiscine;
            piscine = std::stoi(stringPiscine);

            bool garage;
            std::string stringGarage;
            std::cout << "La maison a-t-elle un garage? (1 pour oui, 0 pour non)" << std::endl;
            std::cin >> stringGarage;
            garage = std::stoi(stringGarage);

            Maison *h = new Maison(adresse, std::stoi(surface), std::stoi(prix), vendeur, std::stoi(nbSalles), piscine, garage);
            m_agence->ajoutBienImmobilier(vendeur, h);
            break;
        }
        case 3:
        {
            bool constructible;
            std::string stringConstructible;
            std::cout << "La terrain est-il constructible? (1 pour oui, 0 pour non)"<< std::endl;
            std::cin >> stringConstructible;
            constructible = std::stoi(stringConstructible);

            Terrain *p = new Terrain(constructible, std::stoi(prix), adresse, std::stoi(surface), vendeur);
            m_agence->ajoutBienImmobilier(vendeur, p);
            break;
        }
        case 4:
        {
            std::string tailleVitrine;
            std::cout << "Quel est la taille de la vitrine (En métre carré)?" << std::endl;
            std::cin >> tailleVitrine;

            bool salleDeStockage;
            std::string stringSalleDeStockage;
            std::cout << "Le local a-t-il une salle pour stocker le matériels? (1 pour oui, 0 pour non)" << std::endl;
            std::cin >> stringSalleDeStockage;
            salleDeStockage = std::stoi(stringSalleDeStockage);

            ProfessionalLocal *pl = new ProfessionalLocal(std::stoi(tailleVitrine), salleDeStockage, std::stoi(prix),adresse, std::stoi(surface), vendeur);
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
        std::cout << "Il n'y a pas d'acheteur, vous ne pouvez pas déclarer de visite." << std::endl;
    } else if (m_agence->getVendeurs().size()==0)
    {
        std::cout << "Il n'y a pas de vendeur, vous ne pouvez pas déclarer de visite" << std::endl;
    } else if (m_agence->getBienImmobiliers().size() == 0)
    {
        std::cout << "Il n'y pas de biens immobiliers, vous ne pouvez pas déclarer de visite." << std::endl;
    } else {
        Acheteur b;
        Vendeur s;
        choixBienImmobilier re;
        b = choixAcheteur();
        s = choixVendeur();
        re = chooseRealEstate(s);
        Visite v(b,s,re);
        b.ajoutVisite(v);
    }
}

void UserInterface::afficherClients() const
{
    if (m_agence->getAcheteurs().size() + m_agence->getClients().size() +
            m_agence->getVendeurs().size()==0)
    {
        std::cout << "Il n'y a pas de clients" << std::endl;
    }
    if (m_agence->getVendeurs().size()!=0)
    {
        std::cout << "Vendeurs : " << std::endl;
        for (Vendeur s : this->m_agence->getVendeurs())
        {
            std::cout << s.getPrenom() << " " << s.getNom() << " loge à " << s.getAdresse() << std::endl;
        }
    }
    if (m_agence->getAcheteurs().size()!=0)
    {
        std::cout << "Acheteurs : " << std::endl;
        for (Acheteur b : this->m_agence->getAcheteurs())
        {
            std::cout << b.getPrenom() << " " << b.getNom() << " loge à " << b.getAdresse() << std::endl;
        }
    }
    if (m_agence->getClients().size()!=0)
    {
        std::cout << "Autres clients : " << std::endl;
        for (Client c : this->m_agence->getClients())
        {
            std::cout << c.getPrenom() << " " << c.getNom() << " loge à " << c.getAdresse() << std::endl;
        }
    }
}

void UserInterface::supprimerAcheteur()
{
    if (m_agence->getAcheteurs().size() == 0)
    {
        std::cout << "Il n'y a pas d'acheteur." << std::endl;
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
        std::cout << "Il n'y a pas de vendeur." << std::endl;
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
        std::cout << "Il n'y a pas de bien immobilier" << std::endl;
    } else {
        std::cout << "Choissisez votre vendeur : " << std::endl;
        m_agence->suppressionBienImmobilier(chooseRealEstate(choixVendeur()));
        m_agence->sauvegarde();
    }
}

void UserInterface::afficherBienImmobiliers() const
{
    if (this->m_agence->getBienImmobiliers().size() == 0)
    {
        std::cout << "Il n'y a pas de bien immobilier" << std::endl;
    } else {
        for (std::pair<choixBienImmobilier*,Client> re : this->m_agence->getBienImmobiliers())
        {
            std::cout << "L' " << re.first->getType() << " n°" << re.first->getIdentifiant() << " est disponible pour";
            std::cout << re.first->getPrix() << "€ et vendue par " << re.first->getVendeur().getPrenom();
            std::cout << " " << re.first->getVendeur().getNom() << std::endl;
            re.first->afficher();
        }
    }
}

std::vector<choixBienImmobilier> UserInterface::rechercheBienImmobilierAvecSuperficie(int superficieMin, int superficieMax)
{
    std::vector<choixBienImmobilier> resultat;
    for(std::pair<choixBienImmobilier*,Vendeur> it : m_agence->getBienImmobiliers())
    {
        if(it.first->getSurface() <= superficieMax && it.first->getSurface() >= superficieMin)
        {
            resultat.push_back(*it.first);
        }
    }
    return resultat;
}

std::vector<choixBienImmobilier> UserInterface::rechercheBienImmobilierAvecType(char bienImmobilierType)
{
    std::vector<choixBienImmobilier> resultat;
    for(std::pair<choixBienImmobilier*,Vendeur> it : m_agence->getBienImmobiliers())
    {
        if(it.first->getSauvegardeType() == bienImmobilierType)
        {
            resultat.push_back(*it.first);
        }
    }
    return resultat;
}

std::vector<choixBienImmobilier> UserInterface::rechercheBienImmobilierAvecBudget(unsigned int budget)
{
    std::vector<choixBienImmobilier> resultat;
    for(std::pair<choixBienImmobilier*,Vendeur> it : m_agence->getBienImmobiliers())
    {
        if(it.first->getPrix() <= budget)
        {
            std::cout << it.first->getPrix() << std::endl;
            resultat.push_back(*it.first);
        }
    }
    return resultat;
}

void UserInterface::rechercheBienImmobilier()
{

    //Ask for budget max
    //Ask for type of real estate (or various)
    //Ask for superficy min max
    //Ask for typical stuff related to the type chosen (Example : A balcony for a Flat)
    std::vector<choixBienImmobilier> resultatRecherche;
    unsigned int budget;
    std::string superficieMin;
    std::string superficieMax;
    char bienImmobilierType;
    std::cout << "Appuyer sur B et validé pour retourner au menu !" << std::endl;
    std::cout<< "1) Quel est votre budget max ?" << std::endl;
    std::cout<< "2) Quel type de bien immobilier recherché vous ?" << std::endl;
    std::cout<< "3) Quel superficie ?" << std::endl;

    std::cin >> m_recherche;

    if (m_recherche == "b" || m_recherche == "back")
    {
        m_retourAuMenu = true;
    }
    else if(m_recherche == "1")
    {
        std::cin >> budget;
        resultatRecherche = rechercheBienImmobilierAvecBudget(budget);
    }
    else if(m_recherche == "2")
    {
        std::cout << "l pour un local professionnel" << std::endl;
        std::cout << "t pour un terrain" << std::endl;
        std::cout << "m pour une maison" << std::endl;
        std::cout << "a pour un appartement" << std::endl;
        std::cin >> bienImmobilierType;
        resultatRecherche = rechercheBienImmobilierAvecType(bienImmobilierType);
    }
    else if(m_recherche == "3")
    {
        std::cout<< "Superficie minimale" << std::endl;
        std::cin >> superficieMin;
        while(!estNombre(superficieMin))
        {
            std::cin >> superficieMin;
        }
        std::cout<< "Superficie maximale" << std::endl;
        std::cin >> superficieMax;
        while(!estNombre(superficieMax))
        {
            std::cin >> superficieMax;
        }
        resultatRecherche = rechercheBienImmobilierAvecSuperficie(std::stoi(superficieMin), std::stoi(superficieMax));
    }
    else
    {
        std::cout << "Désolé votre requête n'a pas été reconnu, veuillez en effectuer une nouvelle" << std::endl;
    }

    for(choixBienImmobilier re : resultatRecherche) {
        std::cout << "L' " << re.getType() << " n°" << re.getIdentifiant() << " est disponible pour";
        std::cout << re.getPrix() << "€ et est vendu par " << re.getVendeur().getPrenom();
        std::cout << " " << re.getVendeur().getNom() << std::endl;
    }
    if(resultatRecherche.empty())
    {
        std::cout << "Aucun bien immobilier ne correspond à votre demande" << std::endl;
    }

}

void UserInterface::AfficherMenu() const
{
    std::cout << "Appuyez sur q et validé pour quitter l'application" << std::endl;
    std::cout << "Menu : " << std::endl;
    std::cout << "1) Ajout d'un client" << std::endl;
    std::cout << "2) Ajout d'un bien immobilier" << std::endl;
    std::cout << "3) Declarer une visite" << std::endl;
    std::cout << "4) Afficher tout les clients" << std::endl;
    std::cout << "5) Afficher tout les biens immobiliers" << std::endl;
    std::cout << "6) Supprimer un vendeur" << std::endl;
    std::cout << "7) Supprimer un acheteur" << std::endl;
    std::cout << "8) Supprimer un bien immobilier" << std::endl;
    std::cout << "9) Trouver le bien immobilier de vos rêves" << std::endl;
    std::cout << "10) Autre demande" << std::endl;
}

void UserInterface::lire()
{
    while (!m_quitter)
    {
        AfficherMenu();
        std::cin >> m_requete;
        if (m_requete == "q" || m_requete == "quit" || m_requete == "exit")
        {
            m_quitter = true;
        }
        else if (m_requete == "1")
        {
            ajoutClient();
            system("clear");
        }
        else if (m_requete == "2")
        {
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
                system("clear");
                rechercheBienImmobilier();
                system("clear");
            }
        }
        else if (m_requete == "10")
        {
            system("clear");
            std::cout << "Une autre demande a été traité." << std::endl;
        } else {
            std::cout << "Désolé mais votre requête n'a pas été reconnu, veuillez en effectuer une nouvelle" << std::endl;
        }
    }

}
