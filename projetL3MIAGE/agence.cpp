#include "agence.h"

using namespace std;

vector<Client> Agence::getClients() const
{
    return m_clients;
}

map<BienImmobilier*, Vendeur> Agence::getBienImmobiliers() const
{
    return m_bienImmobiliers;
}

void Agence::ajoutClient(Client &client)
{
    m_clients.push_back(client);
}

void Agence::ajoutBienImmobilier(Vendeur &vendeur, BienImmobilier *bienImmobilier)
{
    m_bienImmobiliers.insert(make_pair(bienImmobilier, vendeur));
}

void Agence::vendre(BienImmobilier re)
{
    m_bienImmobiliers.erase(m_bienImmobiliers.find(&re));
    cout << "Bien immobilier vendu" << endl;
}

void Agence::sauvegarde()
{
    sauvegardeVendeurs();
    sauvegardeAcheteurs();
    sauvegardeBienImmobiliers();
}

void Agence::sauvegardeVendeurs()
{
    ofstream fichier_vendeur("../save/vendeurs.txt", ios::out | ios::trunc);
    if(fichier_vendeur) {
        for(Vendeur v : m_vendeurs) {
            fichier_vendeur << v.getNom() << ":" << v.getPrenom() << ":"
                         << v.getAdresse() << "\n";
        }
        fichier_vendeur.close();
    } else {
        cerr << "Impossible d'ouvrir vendeurs.txt" << endl;
    }
}

void Agence::sauvegardeAcheteurs()
{
    ofstream fichier_acheteur("../save/acheteurs.txt", ios::out | ios::trunc);
    if(fichier_acheteur) {
        for(Acheteur a : m_acheteur) {
            fichier_acheteur << a.getNom() << ":" << a.getPrenom() << ":"
                        << a.getAdresse() << "\n";
        }
        fichier_acheteur.close();
    } else {
        cerr << "Impossible d'ouvrir acheteurs.txt" << endl;
    }
}

void Agence::sauvegardeBienImmobiliers()
{
    ofstream fichier_bienImmobilier("../save/bienImmobiliers.txt", ios::out | ios::trunc);
    if(fichier_bienImmobilier) {
        for (pair<BienImmobilier*,Client> b : m_bienImmobiliers) {
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
        cerr << "Impossible d'ouvrir bienImmobiliers.txt" << endl;
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
    ifstream fichier_vendeur("../save/vendeurs.txt", ios::in);
    if(fichier_vendeur) {
        string contenu;
        while(getline(fichier_vendeur, contenu)) {
            vector<string> vendeur_infos = separation(contenu,':');
            Vendeur s;
            s.setNom(vendeur_infos[0]);
            s.setPrenom(vendeur_infos[1]);
            s.setAdresse(vendeur_infos[2]);
            m_vendeurs.push_back(s);
        }
    } else {
        cerr << "Impossible d'ouvrir vendeurs.txt" << endl;
    }
}

void Agence::ouvertureAcheteurs()
{
    ifstream fichier_acheteur("../save/acheteurs.txt", ios::in);
    if(fichier_acheteur) {
        string contenu;
        while(getline(fichier_acheteur, contenu)) {
            vector<string> acheteur_infos = separation(contenu,':');
            Acheteur b;
            b.setNom(acheteur_infos[0]);
            b.setPrenom(acheteur_infos[1]);
            b.setAdresse(acheteur_infos[2]);
            m_acheteur.push_back(b);
        }
    } else {
        cerr << "Impossible d'ouvrir acheteurs.txt" << endl;
    }
}

void Agence::ouvertureAppartement(vector<string> infos)
{
    Vendeur v = trouverVendeur(infos[4]);
    Appartement *a = new Appartement(infos[1], stoi(infos[2]), stoi(infos[3]), v, stoi(infos[5]), stoi(infos[6]), stoi(infos[7]), stoi(infos[8]), stoi(infos[9]), stoi(infos[10]));
    ajoutBienImmobilier(v, a);
}

void Agence::ouvertureLocalProfessionnel(vector<string> infos)
{
    Vendeur v = trouverVendeur(infos[6]);
    LocalProfessionnel *lp = new LocalProfessionnel(stoi(infos[1]), stoi(infos[2]), stoi(infos[3]), infos[4], stoi(infos[5]), v);
    ajoutBienImmobilier(v, lp);
}

void Agence::ouvertureMaison(vector<string> infos)
{
    Vendeur v = trouverVendeur(infos[4]);
    Maison *m = new Maison(infos[1], stoi(infos[2]), stoi(infos[3]), v, stoi(infos[5]), stoi(infos[6]), stoi(infos[7]));
    ajoutBienImmobilier(v, m);
}

void Agence::ouvertureTerrains(vector<string> infos)
{
    Vendeur v = trouverVendeur(infos[5]);
    Terrain *t = new Terrain(stoi(infos[1]),stoi(infos[2]), infos[3], stoi(infos[4]), v);
    ajoutBienImmobilier(v, t);
}

void Agence::ouvertureBienImmobiliers()
{
    ifstream fichier_bienImmbilier("../save/bienImmobiliers.txt", ios::in);
    if(fichier_bienImmbilier) {
        string contenu;
        while(getline(fichier_bienImmbilier, contenu)) {
            vector<string> bienImmobiliersinfos = separation(contenu,':');
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
        cerr << "Impossible d'ouvrir bienImmobiliers.txt" << endl;
    }
}

Vendeur Agence::trouverVendeur(string id) const
{
    Vendeur v;
    for(Vendeur s : m_vendeurs) {
        if(s.getId() == stoi(id)) {
            v=s;
        }
    }
    return v;
}

vector<Vendeur> Agence::getVendeurs()const
{
    return m_vendeurs;
}

vector<Acheteur> Agence::getAcheteurs() const
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

vector<string> Agence::separation(string stringASeparer, char separateur)
{
    vector<string> stringSeparer;
    string::size_type stTemp = stringASeparer.find(separateur);

    while(stTemp != string::npos)
    {
        stringSeparer.push_back(stringASeparer.substr(0, stTemp));
        stringASeparer = stringASeparer.substr(stTemp + 1);
        stTemp = stringASeparer.find(separateur);
    }

    stringSeparer.push_back(stringASeparer);

    return stringSeparer;
}
bool Agence::estNombre(string str)
{
    if (str.length()==0)
    {
        return false;
    }
    for (unsigned short i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            cout << "Un nombre est requis." << endl;
            return false;
        }
    }
    return true;
}

void Agence::suppressionAcheteur()
{
    int i = 1;
    string choix;
    for (Acheteur b : m_acheteur)
    {
        cout << i << ") " << b.getPrenom() << " " << b.getNom() << endl;
        ++i;
    }

    do {
        cin >> choix;
    } while (!estNombre(choix) && (unsigned int)stoi(choix) > m_acheteur.size());
    //Supprimer toutes les visites
    m_acheteur[stoi(choix) - 1].getVisites().clear();
    //Supprimer le vendeur
    m_acheteur.erase(m_acheteur.begin()+stoi(choix) - 1);
}

void Agence::suppressionVendeur()
{
    int i = 1;
    string choix;
    for (Vendeur s : m_vendeurs)
    {
        cout << i << ") " << s.getPrenom() << " " << s.getNom() << endl;
        ++i;
    }

    do {
        cin >> choix;
    } while (!estNombre(choix) && (unsigned int)stoi(choix) > m_vendeurs.size());
    //Supprimer tout les bien immobiliers
    for (pair<BienImmobilier*, Vendeur> pre : m_bienImmobiliers)
    {
        if (pre.second.getId() == m_vendeurs[stoi(choix) - 1].getId())
        {
            m_bienImmobiliers.erase(pre.first);
        }
    }
    //Supprimer le vendeur
    m_vendeurs.erase(m_vendeurs.begin()+stoi(choix) - 1);
}

void Agence::suppressionBienImmobilier(BienImmobilier re)
{
    map<BienImmobilier*,Vendeur>::iterator it = m_bienImmobiliers.begin();
    while(it != m_bienImmobiliers.end())
    {
        if (*it->first == re)
        {
           m_bienImmobiliers.erase(it++);
        }
        else
        {
            it++;
        }
    }
}
