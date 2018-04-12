#include "agence.h"

std::vector<Client> Agence::getClients() const
{
    return m_clients;
}

std::map<BienImmobilier*, Vendeur> Agence::getBienImmobiliers() const
{
    return m_bienImmobiliers;
}

void Agence::ajoutClient(Client &client)
{
    m_clients.push_back(client);
}

void Agence::ajoutBienImmobilier(Vendeur &vendeur, BienImmobilier *bienImmobilier)
{
    m_bienImmobiliers.insert(std::make_pair(bienImmobilier, vendeur));
}

void Agence::vendre(BienImmobilier re)
{
    m_bienImmobiliers.erase(m_bienImmobiliers.find(&re));
    std::cout << "Bien immobilier vendu" << std::endl;
}

void Agence::sauvegarde()
{
    sauvegardeVendeurs();
    sauvegardeAcheteurs();
    sauvegardeBienImmobiliers();
}

void Agence::sauvegardeVendeurs()
{
    std::ofstream fichier_vendeur("../save/vendeurs.txt", std::ios::out | std::ios::trunc);
    if(fichier_vendeur) {
        for(Vendeur v : m_vendeurs) {
            fichier_vendeur << v.getNom() << ":" << v.getPrenom() << ":"
                         << v.getAdresse() << "\n";
        }
        fichier_vendeur.close();
    } else {
        std::cerr << "Impossible d'ouvrir vendeurs.txt" << std::endl;
    }
}

void Agence::sauvegardeAcheteurs()
{
    std::ofstream fichier_acheteur("../save/acheteurs.txt", std::ios::out | std::ios::trunc);
    if(fichier_acheteur) {
        for(Acheteur a : m_acheteur) {
            fichier_acheteur << a.getNom() << ":" << a.getPrenom() << ":"
                        << a.getAdresse() << "\n";
        }
        fichier_acheteur.close();
    } else {
        std::cerr << "Impossible d'ouvrir acheteurs.txt" << std::endl;
    }
}

void Agence::sauvegardeBienImmobiliers()
{
    std::ofstream fichier_bienImmobilier("../save/bienImmobiliers.txt", std::ios::out | std::ios::trunc);
    if(fichier_bienImmobilier) {
        for (std::pair<BienImmobilier*,Client> b : m_bienImmobiliers) {
            if(b.first->getSauvegardeType() == 'a') {
                Appartement *f = dynamic_cast<Appartement*>(b.first);
                fichier_bienImmobilier << "a:" << f->getAdresse() << ":" << f->getSurface() << ":" << f->getPrix() << ":"
                                 << f->getVendeur().getId() << ":" << f->getNbSalles() << ":" << f->getEtage()
                                 << ":" << f->getGarage() << ":" << f->getCave()
                                 << ":" << f->getBalcon() << ":" << f->getNbAppartBatiment();

            } else if(b.first->getSauvegardeType() == 'l') {
                LocalProfessionnel *pl = dynamic_cast<LocalProfessionnel*>(b.first);
                fichier_bienImmobilier << "l:" << pl->getTailleVitrine() << ":" << pl->getSalleDeStockage()
                                 << ":" << pl->getPrix() << ":" << pl->getAdresse() << ":" << pl->getSurface()
                                 << ":" << pl->getVendeur().getId();

            } else if(b.first->getSauvegardeType() == 'm') {
                Maison *h = dynamic_cast<Maison*>(b.first);
                fichier_bienImmobilier << "h:" << h->getPrix() << ":" << h->getAdresse() << ":" << h->getSurface() << ":"
                                 << h->getVendeur().getId() << ":" << h->getNbSalles() << ":"
                                 << h->hasPiscine() << ":" << h->hasGarage();

            } else if (b.first->getSauvegardeType() == 't') {
                Terrain *p = dynamic_cast<Terrain*>(b.first);
                fichier_bienImmobilier << "t:" << p->getPrix() << ":" << p->getAdresse() << ":" << p->getSurface() << ":"
                                 << p->getVendeur().getId() << ":" << p->getConstructible();

            }
        }
        fichier_bienImmobilier.close();
    } else {
        std::cerr << "Impossible d'ouvrir bienImmobiliers.txt" << std::endl;
    }
}

void Agence::ouverture()
{
    ouvertureVendeurs();
    ouvertureAcheteurs();
    ouvertureBienImmobiliers();
}

void Agence::ouvertureVendeurs()
{
    std::ifstream fichier_vendeur("../save/vendeurs.txt", std::ios::in);
    if(fichier_vendeur) {
        std::string contenu;
        while(std::getline(fichier_vendeur, contenu)) {
            std::vector<std::string> vendeur_infos = separation(contenu,':');
            Vendeur s;
            s.setNom(vendeur_infos[0]);
            s.setPrenom(vendeur_infos[1]);
            s.setAdresse(vendeur_infos[2]);
            m_vendeurs.push_back(s);
        }
    } else {
        std::cerr << "Impossible d'ouvrir vendeurs.txt" << std::endl;
    }
}

void Agence::ouvertureAcheteurs()
{
    std::ifstream fichier_acheteur("../save/acheteurs.txt", std::ios::in);
    if(fichier_acheteur) {
        std::string contenu;
        while(std::getline(fichier_acheteur, contenu)) {
            std::vector<std::string> acheteur_infos = separation(contenu,':');
            Acheteur b;
            b.setNom(acheteur_infos[0]);
            b.setPrenom(acheteur_infos[1]);
            b.setAdresse(acheteur_infos[2]);
            m_acheteur.push_back(b);
        }
    } else {
        std::cerr << "Impossible d'ouvrir acheteurs.txt" << std::endl;
    }
}

void Agence::ouvertureAppartement(std::vector<std::string> infos)
{
    Vendeur v = trouverVendeur(infos[4]);
    Appartement *a = new Appartement(infos[1], std::stoi(infos[2]), std::stoi(infos[3]), v, std::stoi(infos[5]), std::stoi(infos[6]), std::stoi(infos[7]), std::stoi(infos[8]), std::stoi(infos[9]), std::stoi(infos[10]));
    ajoutBienImmobilier(v, a);
}

void Agence::ouvertureLocalProfessionnel(std::vector<std::string> infos)
{
    Vendeur v = trouverVendeur(infos[6]);
    LocalProfessionnel *lp = new LocalProfessionnel(std::stoi(infos[1]), std::stoi(infos[2]), std::stoi(infos[3]), infos[4], std::stoi(infos[5]), v);
    ajoutBienImmobilier(v, lp);
}

void Agence::ouvertureMaison(std::vector<std::string> infos)
{
    Vendeur v = trouverVendeur(infos[4]);
    Maison *m = new Maison(infos[1], std::stoi(infos[2]), std::stoi(infos[3]), v, std::stoi(infos[5]), std::stoi(infos[6]), std::stoi(infos[7]));
    ajoutBienImmobilier(v, m);
}

void Agence::ouvertureTerrains(std::vector<std::string> infos)
{
    Vendeur v = trouverVendeur(infos[5]);
    Terrain *t = new Terrain(std::stoi(infos[1]),std::stoi(infos[2]), infos[3], std::stoi(infos[4]), v);
    ajoutBienImmobilier(v, t);
}

void Agence::ouvertureBienImmobiliers()
{
    std::ifstream fichier_bienImmbilier("../save/bienImmobiliers.txt", std::ios::in);
    if(fichier_bienImmbilier) {
        std::string contenu;
        while(std::getline(fichier_bienImmbilier, contenu)) {
            std::vector<std::string> bienImmobiliersinfos = separation(contenu,':');
            if(bienImmobiliersinfos[0] == "a"){
                ouvertureAppartement(bienImmobiliersinfos);
            } else if(bienImmobiliersinfos[0] == "l") {
                ouvertureLocalProfessionnel(bienImmobiliersinfos);
            } else if(bienImmobiliersinfos[0] == "m") {
                ouvertureMaison(bienImmobiliersinfos);
            } else if(bienImmobiliersinfos[0] == "t") {
                ouvertureTerrains(bienImmobiliersinfos);
            }
        }
    } else {
        std::cerr << "Impossible d'ouvrir bienImmobiliers.txt" << std::endl;
    }
}

Vendeur Agence::trouverVendeur(std::string id) const
{
    Vendeur v;
    for(Vendeur s : m_vendeurs) {
        if(s.getId() == std::stoi(id)) {
            v=s;
        }
    }
    return v;
}

std::vector<Vendeur> Agence::getVendeurs()const
{
    return m_vendeurs;
}

std::vector<Acheteur> Agence::getAcheteurs() const
{
    return m_acheteur;
}

void Agence::ajoutAcheteur(Acheteur &b)
{
    m_acheteur.push_back(b);
}

void Agence::ajoutVendeur(Vendeur &s)
{
    m_vendeurs.push_back(s);
}

std::vector<std::string> Agence::separation(std::string stringASeparer, char separateur)
{
    std::vector<std::string> stringSeparer;
    std::string::size_type stTemp = stringASeparer.find(separateur);

    while(stTemp != std::string::npos)
    {
        stringSeparer.push_back(stringASeparer.substr(0, stTemp));
        stringASeparer = stringASeparer.substr(stTemp + 1);
        stTemp = stringASeparer.find(separateur);
    }

    stringSeparer.push_back(stringASeparer);

    return stringSeparer;
}
bool Agence::estNombre(std::string str)
{
    if (str.length()==0)
    {
        return false;
    }
    for (unsigned short i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            std::cout << "Un nombre est requis." << std::endl;
            return false;
        }
    }
    return true;
}

void Agence::suppressionAcheteur()
{
    int i = 1;
    std::string choix;
    for (Acheteur b : m_acheteur)
    {
        std::cout << i << ") " << b.getPrenom() << " " << b.getNom() << std::endl;
        ++i;
    }

    do {
        std::cin >> choix;
    } while (!estNombre(choix) && (unsigned int)std::stoi(choix) > m_acheteur.size());
    //Supprimer toutes les visites
    m_acheteur[std::stoi(choix) - 1].getVisites().clear();
    //Supprimer le vendeur
    m_acheteur.erase(m_acheteur.begin()+std::stoi(choix) - 1);
}

void Agence::suppressionVendeur()
{
    int i = 1;
    std::string choix;
    for (Vendeur s : m_vendeurs)
    {
        std::cout << i << ") " << s.getPrenom() << " " << s.getNom() << std::endl;
        ++i;
    }

    do {
        std::cin >> choix;
    } while (!estNombre(choix) && (unsigned int)std::stoi(choix) > m_vendeurs.size());
    //Supprimer tout les bien immobiliers
    for (std::pair<BienImmobilier*, Vendeur> pre : m_bienImmobiliers)
    {
        if (pre.second.getId() == m_vendeurs[std::stoi(choix) - 1].getId())
        {
            m_bienImmobiliers.erase(pre.first);
        }
    }
    //Supprimer le vendeur
    m_vendeurs.erase(m_vendeurs.begin()+std::stoi(choix) - 1);
}

void Agence::suppressionBienImmobilier(BienImmobilier re)
{
    m_bienImmobiliers.erase(m_bienImmobiliers.find(&re));
}
