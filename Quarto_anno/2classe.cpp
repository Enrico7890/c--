#include <iostream>
#include <string>

using namespace std;

const int dim = 100;

// Traccia: Classe Libro

// Crea una classe Libro con questi campi privati:

// titolo (string)
// autore (string)
// prezzo (double)
// disponibile (bool) — indica se il libro è in magazzino o no

// La classe deve avere:

// un costruttore senza parametri (valori di default: stringhe vuote, prezzo 0, disponibile true)
// un costruttore con parametri (titolo, autore, prezzo, disponibile) che inizializza tutto
// un getter per ciascun campo
// un setter per ciascun campo — per setPrezzo, aggiungi un controllo: se il prezzo passato è negativo, non lo assegnare
// un metodo stampa() che stampa tutti i dati del libro in una riga

class Libro{
    private:
    string titolo;
    string autore;
    double prezzo;
    bool disponibile;

    public:
    void stampa();
    Libro(string titolo, string autore, double prezzo, bool disponibile);
    Libro();

    string gettitolo();
    string getautore();
    double getprezzo();
    bool getdisponibile();

    void settitolo(string titolo);
    void setautore(string autore);
    void setprezzo(double prezzo);
    void setdisponibile(bool disponibile);
};

Libro::Libro(string t, string a, double p, bool d){
    titolo = t;
    autore = a;
    prezzo = p;
    disponibile = d;
}

Libro::Libro(){
    titolo = "";
    autore = "";
    prezzo = 0;
    disponibile = true;
}

void Libro::stampa(){
    cout << titolo << " di " << autore << " " << prezzo << "€" << endl;
    if (disponibile)
        cout << "Disponibile" << endl;
    else
        cout << "Non disponibile" << endl;
}

string Libro::gettitolo(){return titolo;}
string Libro::getautore(){return autore;}
double Libro::getprezzo(){return prezzo;}
bool Libro::getdisponibile(){return disponibile;}

void Libro::settitolo(string t){titolo = t;}
void Libro::setautore(string a){autore = a;}
void Libro::setprezzo(double p){if (p >= 0) prezzo = p;}
void Libro::setdisponibile(bool d){disponibile = d;}