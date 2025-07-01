#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Person
{
protected:
    string nume;
    int varsta;
public:
    Person(string nume = "necunoscut", int varsta = 0) :nume(nume), varsta(varsta) {}
    virtual void afisareInfo()
    {
        cout << nume << " " << varsta;
    }
    virtual~Person(){}
};
class Angajat :public Person {
   
protected:
    string Functie;
    float Salariu;
    int Id;
public:
    Angajat():Person("necunoscut", 0), Functie("necunoscut"), Salariu(0), Id(-1) {}

    Angajat(string nume, int varsta, string functie, float salariu, int id): Person(nume, varsta), Functie(functie), Salariu(salariu), Id(id){}
    void afisareInfo() override
    {
        cout << "Nume "<< nume << " Varsta " << varsta<<" Functie " << Functie << " salariu " << Salariu << " ID " << Id<<endl;
    }
    int getId() const { return Id; }
    string getName() const { return nume; }
    int getAge() const { return varsta; }
    string getFn() const { return Functie; }
    float getSal() const { return Salariu; }
};

class Produs {
protected:
    string nume;
    int cantitate;
    float pret;
public:
    Produs(string nume = "necunoscut", int cantitate = 0, float pret =0.0) :nume(nume), cantitate(cantitate), pret(pret) {}
    virtual void afisareProdus()
    {
        cout << "denumire produs: " << nume << " cantitate: " << cantitate << " pret " << pret << endl;
    }
    string getName() const { return nume; }
    int getQuantity() const { return cantitate; }
    float getPrice() const { return pret; }
    void modifyQuantity(int m) { cantitate = m; }
};

void afisareProdus(Produs* p)
{
    p->afisareProdus();
}
void afisare(Angajat* a)
{
    a->afisareInfo();
}

string toLowerString(const string& s) {
    string lower = s;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

void adaugaProdus(vector<Produs>&produse)
{
    string nume;
    int cantitate;
    float pret;

    cout << "Introdu denumirea produsului: ";
    getline(cin >> ws, nume);

    cout << "Introdu cantitatea: ";
    cin >> cantitate;

    cout << "Introdu pretul: ";
    cin>> pret;
    Produs produs(nume, cantitate, pret);
    produse.push_back(produs);
}
void afisareProduse(vector<Produs>produse)
{
    for (auto& produs : produse)
    {
        afisareProdus(&produs);
    }
}
void adaugareProduseFisier(vector<Produs>& produse, const string& file)
{
    ifstream fin(file);
    if (!fin)
        cerr << "eroare deschidere fisier\n";
    string nume;
    int cantitate;
    float pret;
    while (fin >> nume >> cantitate >> pret)
    {
        Produs produs(nume, cantitate, pret);
        produse.push_back(produs);
    }
    fin.close();
    cout << "produse incarcarcate cu succes\n";
}
void inserareProdusInFisier(vector<Produs>produse, const string&file)
{
    ofstream fout(file);
    if (!fout)
        cerr << "Eroare scriere in fisier";
    for (int i = 0; i < produse.size(); i++)
        fout << produse[i].getName() << " " << produse[i].getQuantity() << " " << produse[i].getPrice() << endl;
}
void modificaCantitate(vector<Produs>& produse)
{
    string nume;
    int m;
    bool ok = false;
    cout << "Introduceti nume produs: ";
    for (int i = 0; i < produse.size(); i++)
    {
        if (toLowerString(produse[i].getName()) == toLowerString(nume))
        {
            cout << "Introduceti cantitate produs: ";
            cin >> m;
            produse[i].modifyQuantity(m); ok = true;
        }
    }
    ok == false ? cout << "Produs negasit\n" : cout << "Succes\n";
}
void stergeProdus(vector<Produs>& produse)
{
    string nume;
    bool ok = false;
    cout << "Introduceti nume produs: ";
    for (auto prod = produse.begin(); prod!=produse.end(); prod++)
    {
        if (toLowerString(prod->getName()) == toLowerString(nume))
        {
            produse.erase(prod);
            afisareProduse(produse);
            ok = true;
        }
    }
    ok == false ? cout << "Produs negasit\n" : cout << " sters cu Succes\n";
    adaugareProduseFisier(produse, "Produse.txt");
}

void incarcaAngajatiDinFisier(vector<Angajat>& angajati, const string& numeFisier, int*n)
{
    ifstream fin(numeFisier);
    if (!fin)
    {
        cerr << "Eroare la deschiderea fișierului.\n";
        return;
    }

    int id, varsta;
    string nume, functie;
    float salariu;
    while (fin >> id >> nume >> varsta >> functie >> salariu) 
    {
        Angajat angajat(nume, varsta, functie, salariu, id);
        angajati.push_back(angajat);
    }
    fin.close();
    cout << "Angajații au fost încărcați cu succes.\n";
}
void incaracAngajatiInFisier(vector<Angajat>& angajati, const string& file)
{
    ofstream fout(file);
    if (!fout)
        cerr << "Eroare scriere angajati fisier\n";
    for (int i = 0; i < angajati.size(); i++)
    {
        fout << angajati[i].getId() << " "<< angajati[i].getName() << " "<< angajati[i].getAge() << " "<< angajati[i].getFn() << " "<< angajati[i].getSal() << endl;
    }
}
void adaugareAngajat(vector<Angajat>&angajati, int *n)
{
    string nume;
    int varsta;
    string functie;
    float salariu;

    cout << "Introdu numele angajatului: ";
    getline(cin >> ws, nume);

    cout << "Introdu varsta angajatului: ";
    cin >> varsta;

    cout << "Introdu functia angajatului: ";
    getline(cin >> ws, functie);

    cout << "Introdu salariul angajatului: ";
    cin >> salariu;
    Angajat angajat(nume, varsta, functie, salariu, angajati.size()+1);
    angajati.push_back(angajat);
    incaracAngajatiInFisier(angajati, "Angajati.txt");
}
void afisareAngajati(vector<Angajat> angajati)
{
    for (int i = 0; i < angajati.size(); i++)
    {
        afisare(&angajati[i]);
    }
}
Angajat cautaAngajat(const vector<Angajat>& angajati)
{
    string nume;
    cout << "Introdu numele angajatului pe care vrei sa-l cauti: ";
    getline(cin >> ws, nume);

    for (const auto& a : angajati)
    {
        if (a.getName() == nume)
            return a;
    }

    cout << "Angajatul nu a fost gasit.\n";
    return Angajat();
}
void stergeAngajat(vector<Angajat>& angajati)
{
    int id;
    cout << "Indroduceti Id dupa care vrei sa stergeti persoana: ";
    cin >> id;
    bool gasit = false;
    for (auto it = angajati.begin(); it!=angajati.end(); it++)
    {
        if (it->getId() == id)
        {
            angajati.erase(it);
            gasit = true;
            cout << "Angajat șters cu succes.\n";
            afisareAngajati(angajati);
            break;
        }
    }
    if (!gasit)
    {
        cout << "Angajatul nu poate fi gasit\n";
    }
    incaracAngajatiInFisier(angajati, "Angajati.txt");
}

void afisareMeniuAngajati()
{
    cout << "==============================\n";
    cout << "       Employee Menu  \n";
    cout << "==============================\n";
    cout << "1. Adauga angajat\n";
    cout << "2. Afiseaza angajati\n";
    cout << "3. Sterge angajat\n";
    cout << "4. Cauta angajat\n";
    cout << "0. Inapoi la meniul principal\n";
    cout << "------------------------------\n";
    cout << "Alege opțiunea: ";

}
void afisareMeniuProduse() {
    cout << "\n--- Meniu Produse ---\n";
    cout << "1. Adauga produs\n";
    cout << "2. Afiseaza produse\n";
    cout << "3. Sterge produs\n";
    cout << "4. Modifica cantitate produs\n";
    cout << "5. Cauta produs -- nu facce nmc deocamdata\n";
    cout << "0. Inapoi la meniul principal\n";
    // aici adaugi functionalitatile pentru produse
}

int main()
{
    vector<Angajat>angajati;
    vector<Produs>produse;
    int n = 0;//nr de angajati;
    int option1;
   
    incarcaAngajatiDinFisier(angajati, "Angajati.txt", &n);
    adaugareProduseFisier(produse, "Produse.txt");

    do {
        cout << "\n=========== MENIU PRINCIPAL ===========\n";
        cout << "1. Gestionare Angajati\n";
        cout << "2. Gestionare Produse\n";
        cout << "-1. Iesire\n";
        cout << "Alege optiunea: ";
        cin >> option1;

        switch (option1) {
        case 1: // Gestionare Angajati
        {
            int option2;
            do {
                afisareMeniuAngajati();
                cout << "Introduceti optiune: ";
                cin >> option2;
                switch (option2) {
                case 1: adaugareAngajat(angajati, &n); break;
                case 2: afisareAngajati(angajati); break;
                case 3: stergeAngajat(angajati); break;
                case 4: cautaAngajat(angajati); break;
                case 0: cout << "Iesire din meniul Angajati...\n"; break;
                default: cout << "Optiune invalida.\n";
                }
            } while (option2 != 0);
            break;
        }

        case 2: // Gestionare Produse
        {
            int option2;
            do {
                afisareMeniuProduse();
                cout << "Introduceti optiune: ";
                cin >> option2;
                switch (option2) {
                case 1: adaugaProdus(produse); break;
                case 2: afisareProduse(produse); break;
                case 3: stergeProdus(produse); break;
                case 4: modificaCantitate(produse); break;
                case 0: cout << "Iesire din meniul Produse...\n"; break;
                default: cout << "Optiune invalida.\n";
                }
            } while (option2 != 0);
            break;
        }

        case -1:
            cout << "Iesire din program...\n";
            break;

        default:
            cout << "Optiune invalida. Incearca din nou.\n";
        }

    } while (option1 != -1);
}
