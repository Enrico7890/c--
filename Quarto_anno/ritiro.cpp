#include <iostream>
#include <string>
using namespace std;

const int dim = 100;

/* Un'agenzia di noleggio auto vuole gestire il proprio parco veicoli tramite array paralleli (targa, modello, prezzo giornaliero, chilometraggio).

Il programma deve:

chiedere quante auto compongono il parco veicoli (con controllo di validità sul numero);
permettere l'inserimento di targa, modello, prezzo giornaliero di noleggio e chilometraggio per ciascuna auto;
permettere di cercare un'auto per targa e stamparne i dati completi; se non viene trovata, stampare un messaggio d'errore;
individuare e stampare l'auto con il prezzo giornaliero più basso;
individuare e stampare l'auto con il chilometraggio più alto;
calcolare il chilometraggio medio del parco veicoli;
stampare l'elenco di tutte le auto con un chilometraggio superiore alla media calcolata (candidate alla manutenzione);
calcolare il ricavo potenziale totale se tutte le auto venissero noleggiate per un numero di giorni inserito dall'utente (somma di prezzo giornaliero × giorni, per ogni auto);
contare quante auto hanno un chilometraggio superiore a una soglia inserita dall'utente (candidate alla sostituzione). */

int inputn();
void inputarr(string targhe[], string modello[], double prezzo[], double chilometri[], int n);
void ricercatarga(string targhe[], string modello[], double prezzo[], double chilometri[], int n);
void ricercaprezzobasso(string targhe[], string modello[], double prezzo[], double chilometri[], int n);
void ricercachilometrialto(string targhe[], string modello[], double prezzo[], double chilometri[], int n);
double chilometrimedi(double chilometri[], int n);
void superioremediakm(string targhe[], string modello[], double prezzo[], double media, double chilometri[],int n);
void ricavopotenziale(double prezzo[], int n);
void sogliasuperiorekm(double chilometri[], int n);

int main(){
    string targhe[dim];
    string modello[dim];
    double prezzo[dim];
    double chilometri[dim];

    int n = inputn();
    inputarr(targhe, modello, prezzo, chilometri, n);
    ricercatarga(targhe, modello, prezzo, chilometri, n);
    ricercaprezzobasso(targhe, modello, prezzo, chilometri, n);
    ricercachilometrialto(targhe, modello, prezzo, chilometri, n);
    double media = chilometrimedi(chilometri, n);
    superioremediakm(targhe, modello, prezzo, media, chilometri, n);
    ricavopotenziale(prezzo, n);
    sogliasuperiorekm(chilometri, n);
}

// input dei numeri di auto

int inputn(){
    int n = 0;
    do{
        cout << "Quante auto puoi hai a disposizione? " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

// input dei cazzo di dati 

void inputarr(string targhe[], string modello[], double prezzo[],double chilometri[], int n){
    for (int i = 0; i < n; i++){
        cout << "Inserisci la targa della macchina " << endl;
        cin >> targhe [i];
        cout << "Inserisci il nome del modello " << endl;
        cin >> modello[i];
        cout << "Quanti chilometri ha la macchina? " << endl;
        cin >> chilometri[i];   
        cout << "Qual e' il prezzo giornaliero " << endl;
        cin >> prezzo[i]; 
    }
}

// permettere di cercare un'auto per targa e stamparne i dati completi; se non viene trovata, stampare un messaggio d'errore;

void ricercatarga(string targhe[], string modello[], double prezzo[], double chilometri[], int n){
    string targacerca;
    int k = 0;
    cout << "Inserisci una targa da cercare " << endl;
    cin >> targacerca;
    for (int i = 0; i < n; i++){
        if (targhe[i]==targacerca){
        cout << "targa trovata, il modello e' " << modello[i] << " il prezzo e' " << prezzo[i] << endl;
        k++;
        }
    }
    if (k==0)
    cout << "Nessuna targa trovata cerca meglio rinnoceronte " << endl;
}

// individuare e stampare l'auto con il prezzo giornaliero più basso;

void ricercaprezzobasso(string targhe[], string modello[], double prezzo[], double chilometri[], int n){
    double prezzomin = prezzo[0];
    int k = 0;
    for (int i = 0; i < n; i++){
        if (prezzomin > prezzo[i]){
        prezzomin=prezzo[i];
        k = i;
        }
    }
    cout << "Il prezzo più basso giornaliero e' di " << prezzomin << " della targa " << targhe[k] << " del modello " << modello[k] << " con km " << chilometri[k] << endl;
}

// individuare e stampare l'auto con il chilometraggio più alto;

void ricercachilometrialto(string targhe[], string modello[], double prezzo[], double chilometri[], int n){
    double kmax = chilometri[0];
    int k = 0;
    for (int i = 0; i < n; i++)
        if (kmax < chilometri[i]){
            kmax = chilometri[i];
            k = i;
        }
    cout << "l'auto con piu' km ha " << kmax << " con targa " << targhe[k] << " il modello " << modello[k] << " il suo prezzo e' " << prezzo[k] << endl;
}

//calcolare il chilometraggio medio del parco veicoli;

double chilometrimedi(double chilometri[], int n){
    double media = 0;
    for (int i = 0; i < n; i++)
        media+= chilometri[i]; 
    return media / n;
}

// stampare l'elenco di tutte le auto con un chilometraggio superiore alla media calcolata (candidate alla manutenzione);

void superioremediakm(string targhe[], string modello[], double prezzo[], double media, double chilometri[], int n){
    for (int i = 0; i < n; i++){
        if (chilometri[i] > media)
        cout << "l' auto " << targhe[i] << " " << modello[i] << " " << prezzo[i] << " ha un chilometraggio di " << chilometri[i] << " che e' superiore alla media di " << media << endl;
    }
}

// calcolare il ricavo potenziale totale se tutte le auto venissero noleggiate per un numero di giorni inserito dall'utente (somma di prezzo giornaliero × giorni, per ogni auto);


void ricavopotenziale(double prezzo[], int n){
    int giorni = 0;
    double ricavo = 0;
    cout << "Inserisci quanti giorni " << endl;
    cin >> giorni;  
        for (int i = 0; i < n; i++){
            ricavo+=prezzo[i]*giorni;
        }
    cout << "Il ricavo potenziale sarebbe " << ricavo << endl;
}

// contare quante auto hanno un chilometraggio superiore a una soglia inserita dall'utente (candidate alla sostituzione).

void sogliasuperiorekm(double chilometri[], int n){
    double sogliamax = 0;
    int k = 0;
    cout << "inserisci una soglia da verificare " << endl;
    cin >> sogliamax;
    for (int i = 0; i < n; i++){
        if (chilometri[i] > sogliamax)
        k++;
    }
    cout << k << " auto hanno chilometraggio superiore alla soglia di " << sogliamax << endl;
}