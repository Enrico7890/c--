#include <iostream>
#include <string>

using namespace std;

/* Usa uno struct per rappresentare un contatto, con i campi: nome, cognome, numero di telefono, età.

Il programma deve:

chiedere quanti contatti comporranno la rubrica (con controllo di validità sul numero);
permettere l'inserimento dei dati di ciascun contatto;
permettere di cercare un contatto per cognome e stamparne i dati completi; se non viene trovato, stampare un messaggio d'errore;
individuare e stampare il contatto più giovane;
individuare e stampare il contatto più anziano;
calcolare l'età media di tutti i contatti;
stampare l'elenco di tutti i contatti con un'età inferiore alla media calcolata;
contare quanti contatti hanno un'età superiore a una soglia inserita dall'utente. */

const int dim = 100;

// my first struct

struct Contatto
{
    string nome;
    string cognome;
    int numero; // actually (nerd), numero deve essere string altrimenti perdi gli 0 in caso di prefisso. es: 081 perde lo 0.
    int eta;
};

int inputn();
void inputarr(Contatto rubrica [], int n);
void ricercacognome(Contatto rubrica [], int n);
void ricercagiovane(Contatto rubrica [], int n);
void ricercanziano(Contatto rubrica [], int n);
double etamedia(Contatto rubrica [], int n);
void etainferioremedia(Contatto rubrica [], double media, int n);
void etasuperioresoglia(Contatto rubrica [], int n);

int main (){
    Contatto rubrica [dim];

    int n = inputn();
    inputarr(rubrica, n);
    ricercacognome(rubrica, n);
    ricercagiovane(rubrica, n);
    ricercanziano(rubrica, n);
    double media = etamedia(rubrica, n);
    etainferioremedia(rubrica, media, n);
    etasuperioresoglia(rubrica, n);
}

// inserimento dimensione

int inputn(){
    int n = 0;
        do{
            cout << "Inserisci quanti contatti hai in rubrica " << endl;
            cin >> n;
        } while (n <= 0 || n > dim);
    return n;
}

// inseriamo dati nello struct

void inputarr(Contatto rubrica [], int n){
    for (int i = 0; i < n; i++){
        cout << "Nome: ";
        cin >> rubrica[i].nome;
        cout << "Cognome: ";
        cin >> rubrica[i].cognome;
        cout << "Numero: ";
        cin >> rubrica[i].numero;
        cout << "Eta' " << endl;
        cin >> rubrica[i].eta;
    }
}

// permettere di cercare un contatto per cognome e stamparne i dati completi; se non viene trovato, stampare un messaggio d'errore;

void ricercacognome(Contatto rubrica [], int n){
    string cognomecerca;
    int k = 0;
    cout << "Inserisci un cognome da cercare " << endl;
    cin >> cognomecerca;
    for (int i = 0; i < n; i++){
        if (rubrica[i].cognome==cognomecerca){
        cout << "cognome trovato, il nome e' " << rubrica[i].nome << " la sua eta' e' " << rubrica[i].eta << " il suo numero e' " << rubrica[i].numero << endl;
        k++;
        }
    }
    if(k==0)
    cout << "nessun cognome found, try again " << endl;
}

//individuare e stampare il contatto più giovane;

void ricercagiovane(Contatto rubrica [], int n){
    int giovane = rubrica[0].eta;
    int k = 0;
    for (int i = 0; i < n; i++){
        if (rubrica[i].eta < giovane){
            giovane = rubrica[i].eta;
            k = i;
        }
    }
    cout << "il contatto piu' giovane e' " << rubrica[k].nome << " " << rubrica[k].cognome << " "<< rubrica[k].numero << " con l'eta' " << rubrica[k].eta << endl;
}

//individuare e stampare il contatto più anziano;

void ricercanziano(Contatto rubrica [], int n){
    int anziano = rubrica[0].eta;
    int k = 0;
    for (int i = 0; i < n; i++){
        if (rubrica[i].eta > anziano){
            anziano = rubrica[i].eta;
            k = i;
        }
    }
    cout << "il contatto piu' anziano e' " << rubrica[k].nome << " "<< rubrica[k].cognome << " "<< rubrica[k].numero << " con l'eta' " << rubrica[k].eta << endl;
}

// calcolare l'età media di tutti i contatti;

double etamedia(Contatto rubrica [], int n){
    double media = 0;
        for (int i = 0; i < n; i++){
            media+=rubrica[i].eta;
        }
    return media / n;
}

// stampare l'elenco di tutti i contatti con un'età inferiore alla media calcolata;

void etainferioremedia(Contatto rubrica [], double media, int n){
    for (int i = 0; i < n; i++)
        if (rubrica[i].eta < media)
        cout << "il contatto ha un eta' inferiore alla media' " << rubrica[i].nome << " "<< rubrica[i].cognome<< " " << rubrica[i].numero << " con l'eta' " << rubrica[i].eta << endl;
}

// contare quanti contatti hanno un'età superiore a una soglia inserita dall'utente. */

void etasuperioresoglia(Contatto rubrica [], int n){
    int inputeta = 0;
    int k = 0;
    cout << "Inserisci un eta' " << endl;
    cin >> inputeta;
    for (int i = 0; i < n; i++){
        if (rubrica[i].eta > inputeta)
        k++;
    }
    cout << k << " contatti hanno un eta' superiore alla soglia " << endl;
}
