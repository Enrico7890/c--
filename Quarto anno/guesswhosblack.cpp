#include <iostream>
#include <string>
using namespace std;

const int dim = 100;
/* Un piccolo circolo sportivo vuole digitalizzare la gestione dei propri iscritti a un torneo. Scrivi un programma in C++ che permetta di gestire i dati dei partecipanti tramite array paralleli (nome, cognome, età, punteggio ranking).
 Il programma deve:
chiedere all'utente quanti giocatori partecipano al torneo (con controllo che il numero sia valido, ad esempio tra 1 e una dimensione massima fissata);
permettere l'inserimento di nome, cognome, età e punteggio ranking per ciascun giocatore;
permettere di cercare un giocatore per cognome e stamparne i dati completi;
individuare e stampare il giocatore con il ranking più alto;
individuare e stampare il giocatore più giovane;
calcolare l'età media di tutti i partecipanti;
stampare l'elenco di tutti i giocatori con un'età superiore alla media calcolata;
calcolare quanti giocatori hanno un ranking superiore a una soglia inserita dall'utente. */

int inputN();
void inputarr(string nomi[], string cognomi[], int eta[], double ranking [], int n);
void cercacognome(string nomi[], string cognomi[], int eta[], double ranking [], int n);
void cercaranking(string nomi[], string cognomi[], double ranking [], int n);
void cercagiovane(string nomi[], string cognomi[], int eta [], int n);
int etamedio(int eta [], int n);
void etasopramedia(string nomi [], string cognomi [], int eta [], int etamedia, int n);
void rankingsuperiore(double ranking[], int n);

int main(){
    string cognomi[dim];
    string nomi [dim];
    int eta [dim];
    double ranking [dim];

    int n = inputN();
    inputarr(nomi, cognomi, eta, ranking, n);
    cercagiovane(nomi, cognomi, eta, n);
    cercaranking(nomi, cognomi, ranking, n);
    cercacognome(nomi, cognomi, eta, ranking, n);
    int etamedia = etamedio(eta, n);
    etasopramedia(nomi, cognomi, eta, etamedia, n);
    rankingsuperiore(ranking, n);
}

int inputN(){
    int n = 0;
    do {
        cout << "quanti giocatori partecipano? " << endl;
        cin >> n;
        if (n > dim)
        cout << "che cazzo fai?? inserisci un numero valido, coglione" << endl;
    }while (n <= 0 || n > dim);
    return n;
}

void inputarr(string nomi[], string cognomi[], int eta[], double ranking [], int n){
    for (int i = 0; i < n; i++){
        cout << "Inserisci il nome " << endl;
        cin >> nomi[i];
        cout << "Inserisci il cognome " << endl;
        cin >> cognomi[i];
        cout << "Inserisci l'età " << endl;
        cin >> eta[i];
        cout << "inserisci il ranking" << endl;
        cin >> ranking[i];
    }
}

void cercacognome(string nomi[], string cognomi[], int eta[], double ranking [], int n){
    string cognomericerca;
    cout << "inserisci il cognome da cercare " << endl;
    cin >> cognomericerca;

    for(int i = 0; i < n; i++){
        if (cognomericerca==cognomi[i]){
            cout << "cognome trovato!, il nome è " << nomi[i] << endl;
            cout << "l'età è " << eta[i] << endl;
            cout << "il ranking è " << ranking[i] << endl;
        }
    }
}

void cercaranking(string nomi[], string cognomi[], double ranking [], int n){
    int indice = 0;
    int rankmax = ranking[0];
    for (int i = 1; i < n; i++){
        if (ranking[i] > rankmax){
        rankmax = ranking[i];
        indice = i;
        }
    }
    cout << "il ranking maggiore è " << rankmax << " di " << cognomi[indice] << nomi[indice];
}

void cercagiovane(string nomi[], string cognomi[], int eta [], int n){
    int indice = 0;
    int giovane = eta[0];
    for (int i = 1; i < n; i++){
        if (eta[i] < giovane){
        giovane = eta[i];
        indice = i;
        }
    }
    cout << "il più giovane è " << cognomi[indice] << nomi [indice] << " con anni " << giovane;
}

int etamedio(int eta [], int n){
    int somma = 0;
    int etamedia = 0;
    for (int i = 0; i < n; i++)
    somma+=eta[i];

    etamedia = somma/n;
    return etamedia;
}

void etasopramedia(string nomi [], string cognomi [], int eta [], int etamedia, int n){
    for (int i = 0; i < n; i++){
        if (eta[i] > etamedia){
            cout << "il giocatore " << nomi[i] << cognomi[i] << " è sopra l'età media" << endl;
        }
    }
}

void rankingsuperiore(double ranking[], int n){
    int inputranking = 0;
    int indice = 0;
    cout << "Inserisci un ranking in input " << endl;
    cin >> inputranking;
    
    for (int i = 0; i < n; i++){
        if (ranking[i] > inputranking)
        indice ++;
    }
    cout << indice << " giocatori hanno ranking superiore alla soglia" << endl;
}