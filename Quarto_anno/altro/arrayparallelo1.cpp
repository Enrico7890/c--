#include <iostream>
#include <string>
using namespace std;

const int dim = 100;

int inputn();
void inputlista(string articoli[], string descrizioni[], double prezzi[], int n);
void menu(string articoli[], string descrizioni[], double prezzi[], int n);
void articolocostoso(string articoli[], double prezzi[], int n);
void detdescrizione(string articoli[], string descrizioni[], int n);
void detprezzo(string articoli[], double prezzi[], int n);
void prezzomedio(double prezzi[], int n);

int main(){
    string articoli[dim];
    string descrizioni[dim];
    double prezzi[dim];
    int n = inputn();
    inputlista(articoli, descrizioni, prezzi, n);
    menu(articoli, descrizioni, prezzi, n);
}

int inputn(){
    int n = 0;
    do {
        cout << "inserisci la dimensione dell'elenco: ";
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

void inputlista(string articoli[], string descrizioni[], double prezzi[], int n){
    for (int i = 0; i < n; i++){
        cout << "articolo: ";
        cin >> articoli[i];
        cout << "descrizione: ";
        cin >> descrizioni[i];
        cout << "prezzo: ";
        cin >> prezzi[i];
    }
}

void menu(string articoli[], string descrizioni[], double prezzi[], int n){
    int scelta = 0;
    do {
        cout << "1 - articoli piu' costosi di una soglia" << endl;
        cout << "2 - descrizione di un articolo" << endl;
        cout << "3 - prezzo di un articolo" << endl;
        cout << "4 - prezzo medio" << endl;
        cout << "5 - termina" << endl;
        cin >> scelta;
        switch (scelta) {
            case 1: articolocostoso(articoli, prezzi, n); break;
            case 2: detdescrizione(articoli, descrizioni, n); break;
            case 3: detprezzo(articoli, prezzi, n); break;
            case 4: prezzomedio(prezzi, n); break;
            case 5: cout << "fine programma" << endl; break;
            default: cout << "scelta non valida" << endl;
        }
    } while (scelta != 5);
}

void articolocostoso(string articoli[], double prezzi[], int n){
    double soglia;
    cout << "inserisci la soglia: ";
    cin >> soglia;
    for (int i = 0; i < n; i++)
        if (prezzi[i] > soglia)
            cout << articoli[i] << " " << prezzi[i] << endl;
}

void detdescrizione(string articoli[], string descrizioni[], int n){
    string nome;
    bool trovato = false;
    cout << "inserisci l'articolo: ";
    cin >> nome;
    for (int i = 0; i < n && !trovato; i++)
        if (articoli[i] == nome){
            cout << descrizioni[i] << endl;
            trovato = true;
        }
    if (!trovato)
        cout << "articolo non trovato" << endl;
}

void detprezzo(string articoli[], double prezzi[], int n){
    string nome;
    bool trovato = false;
    cout << "inserisci l'articolo: ";
    cin >> nome;
    for (int i = 0; i < n && !trovato; i++)
        if (articoli[i] == nome){
            cout << prezzi[i] << endl;
            trovato = true;
        }
    if (!trovato)
        cout << "articolo non trovato" << endl;
}

void prezzomedio(double prezzi[], int n){
    double somma = 0;
    for (int i = 0; i < n; i++)
        somma += prezzi[i];
    cout << "prezzo medio: " << somma / n << endl;
}