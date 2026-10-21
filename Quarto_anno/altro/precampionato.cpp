#include <iostream>
#include <string>
using namespace std;
 
const int dim = 100;

/* Un piccolo negozio indipendente vuole 
tenere traccia del proprio catalogo tramite array paralleli (titolo, autore, prezzo, copie disponibili).
chiedere quanti libri comporranno il catalogo (con controllo di validità sul numero, come nei tuoi esercizi precedenti);
permettere l'inserimento di titolo, autore, prezzo e numero di copie disponibili per ciascun libro;
permettere di cercare un libro per titolo e stamparne i dati completi;
individuare e stampare il libro con il prezzo più alto;
individuare e stampare il libro con meno copie disponibili in magazzino;
calcolare il prezzo medio del catalogo;
stampare l'elenco di tutti i libri con un prezzo inferiore alla media calcolata;
calcolare il valore totale del magazzino (somma di prezzo × copie disponibili per ogni libro);
contare quanti libri risultano esauriti (copie disponibili uguali a zero). */

int inputn();
void inputarr(string titoli[], string autori[], double prezzo [], int numerocopie[], int n);
void ricercatitolo(string titoli[], string autori[], double prezzo[], int numerocopie[], int n);
void libroprezzoalto(string titoli[], string autori[], double prezzo[], int numerocopie [], int n);
void libromenocopie(string titoli[], string autori[], double prezzo[], int numerocopie[], int n);
double prezzomedio(double prezzo[], int n);
void prezzoinferioremedia(string titoli[], string autori[], double prezzo[], double media, int n);
void valoretot(string titoli[], string autori[], double prezzo[], int numerocopie[], int n);
void libriesauriti(string titoli[], string autori[], int numerocopie[], int n);

int main(){
    string titoli[dim];
    string autori [dim];
    double prezzo [dim];
    int numerocopie[dim];

    int n = inputn();
    inputarr(titoli, autori, prezzo, numerocopie, n);
    ricercatitolo(titoli, autori, prezzo, numerocopie, n);
    libroprezzoalto(titoli, autori, prezzo, numerocopie, n);
    libromenocopie(titoli, autori, prezzo, numerocopie, n);
    double media = prezzomedio(prezzo, n);
    prezzoinferioremedia(titoli, autori, prezzo, media, n);
    valoretot(titoli, autori, prezzo, numerocopie, n);
    libriesauriti(titoli, autori, numerocopie, n);
}

// prendiamo in input il numero dei giovannigpt libri

int inputn(){
    int n = 0;
    do{
        cout << "Inserisci quanti libri compongono il catalogo " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

// prendiamo in input i cazzo di array parallelepipedi

void inputarr(string titoli[], string autori[], double prezzo [], int numerocopie[], int n){
    for (int i = 0; i < n; i++){
        cout << "inserisci il titolo del libro " << endl;
        cin >> titoli[i];
        cout << "inserisci l'autore del libro " << endl;
        cin >> autori[i];
        cout << "inserisci il prezzo del libro " << endl;
        cin >> prezzo[i];
        cout << "inserisci il numero di copie rimaste del libro " << endl;
        cin >> numerocopie[i];
    }
}

// permettere di cercare un libro per titolo e stamparne i dati completi;

void ricercatitolo(string titoli[], string autori[], double prezzo[], int numerocopie[], int n){
    string titolodacercare;
    int k = 0;
        cout << "inserisci un titolo da cercare " << endl;
        cin >> titolodacercare;
        for (int i = 0 ; i < n; i++){
            if (titolodacercare==titoli[i]){
                cout << "titolo trovato l'autore e' " << autori[i] << " il prezzo e' " << prezzo[i] << " le copie rimaste sono " << numerocopie[i] << endl;
                k++;
            }
         }
    if (k == 0)
        cout << "nessun libro con quel titolo trovato " << endl;
}

// individuare e stampare il libro con il prezzo più alto;

void libroprezzoalto(string titoli[], string autori[], double prezzo[], int numerocopie [], int n){
   double maxprezzo = prezzo [0];
   int k = 0;
    for (int i = 0; i < n; i++){
        if (maxprezzo < prezzo[i]){
        maxprezzo = prezzo[i];
        k = i;
        }
    }
    cout << "il libro col prezzo piu' alto e' " << titoli[k] << " di " << autori[k] << " con il prezzo " << maxprezzo << endl;
}

// individuare e stampare il libro con meno copie disponibili in magazzino;

void libromenocopie(string titoli[], string autori[], double prezzo[], int numerocopie[], int n){
   int mincopie = numerocopie[0];
   int k = 0;
        for (int i = 0; i < n; i++){
            if (mincopie > numerocopie[i]){
            mincopie = numerocopie[i];
            k = i;
            }
        }
    cout << "il libro con meno copie disponibili e' " << titoli[k] << " con " << mincopie << " rimaste" << endl;
}

// calcolare il prezzo medio del catalogo;

double prezzomedio(double prezzo[], int n){
    double somma = 0;
        for (int i = 0; i < n; i++){
            somma+=prezzo[i];
        }
        return somma/n;
}

// stampare l'elenco di tutti i libri con un prezzo inferiore alla media calcolata;

void prezzoinferioremedia(string titoli[], string autori[], double prezzo[], double media, int n){
    for (int i = 0; i < n; i++){
        if (prezzo[i] < media)
        cout << "il libro " << titoli[i] << " di " << autori[i] << " ha un prezzo inferiore alla media " << endl;
    }
}

// calcolare il valore totale del magazzino (somma di prezzo × copie disponibili per ogni libro);

void valoretot(string titoli[], string autori[], double prezzo[], int numerocopie[], int n){
    double valoretotale = 0;
        for (int i = 0; i < n; i++){
           valoretotale+= prezzo[i]*numerocopie[i];
        }
    cout << "il valore totale è " << valoretotale << endl;
}

// contare quanti libri risultano esauriti (copie disponibili uguali a zero). */

void libriesauriti(string titoli[], string autori[], int numerocopie[], int n){
    for (int i = 0; i < n; i++)
        if (numerocopie[i] == 0)
        cout << "il libro " << titoli[i] << " di " << autori[i] << " ha esaurito il numero di copie " << endl;
}