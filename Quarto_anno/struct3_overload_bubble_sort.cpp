#include <iostream>
#include <string>
using namespace std;

const int dim = 100;

/* Il programma deve:

chiedere quanti eventi comporranno l'elenco (con controllo di validità sul numero);
permettere l'inserimento dei dati di ciascun evento (titolo, data completa giorno/mese/anno, luogo, numero di partecipanti);
permettere di cercare un evento per titolo e stamparne i dati completi, data inclusa (formattata come gg/mm/aaaa); se non viene trovato, stampare un messaggio d'errore;
contare quanti eventi si svolgono in un anno specifico inserito dall'utente;
individuare e stampare l'evento con il maggior numero di partecipanti;
stampare l'elenco di tutti gli eventi che si svolgono in un mese specifico inserito dall'utente (es. "tutti gli eventi di dicembre"), ordinati per giorno crescente all'interno del mese;
dato un evento (cercato per titolo), stampare se si trova prima o dopo un altro evento (cercato per titolo), confrontando le rispettive date (anno, poi mese, poi giorno);
calcolare il numero medio di partecipanti tra tutti gli eventi. */

// operator overload 

// TipoRitorno operator<simbolo>(parametri){
    // logica
// }

struct Data {
    int giorno;
    int mese;
    int anno;
};

struct Evento {
    string titolo;
    Data data;
    string luogo;
    int partecipanti;
};

bool operator<(const Data& a, const Data& b){
    if (a.anno != b.anno) 
    return a.anno < b.anno;
    if (a.mese != b.mese) 
    return a.mese < b.mese;
    return a.giorno < b.giorno;
}

bool operator==(const Data& a, const Data& b){
    return a.anno == b.anno && a.mese == b.mese && a.giorno == b.giorno;
}

int inputn();
void inputarr(Evento eventi[], int n);
void ricercaevento(Evento eventi[], int n);
void eventiannuali(Evento eventi[], int n);
void ordinaperpartecipanti(Evento eventi[], int n);
void eventopartecipanti(Evento eventi[], int n);
void eventimese (Evento eventi[], int n);
void eventoprimadopo(Evento eventi[], int n);
void mediapartecipanti(Evento eventi[], int n);

int main (){
    Evento eventi [dim];

    int n = inputn();
    inputarr(eventi, n);
    ricercaevento(eventi, n);
    eventiannuali(eventi, n);
    ordinaperpartecipanti(eventi, n);
    eventopartecipanti(eventi, n);
    eventimese(eventi, n);
    eventoprimadopo(eventi, n);
    mediapartecipanti(eventi, n);
}

int inputn(){
    int n = 0;
    do{
        cout << "Inserisci quanti eventi ci sono " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

void inputarr(Evento eventi[], int n){
    for (int i = 0; i < n; i++){
        cout << "inserisci un giorno ";
        cin >> eventi[i].data.giorno;
        cout << "inserisci un mese ";
        cin >> eventi[i].data.mese;
        cout << "inserisci un anno ";
        cin >> eventi[i].data.anno;
        cout << "inserisci un titolo ";
        cin >> eventi[i].titolo;
        cout << "inserisci un luogo ";
        cin >> eventi[i].luogo;
        cout << "quanti partecipanti? ";
        cin >> eventi[i].partecipanti; 
    }
}

//permettere di cercare un evento per titolo e stamparne i dati completi, data inclusa (formattata come gg/mm/aaaa); se non viene trovato, stampare un messaggio d'errore;

void ricercaevento(Evento eventi[], int n){
    string titolo;
    int k = 0;
    cout << "inserisci un evento da cercare " << endl;
    cin >> titolo;
    for (int i = 0; i < n; i++){
        if (eventi[i].titolo==titolo){
            cout << "i dati sono " << eventi[i].luogo << " "<< eventi[i].partecipanti << " "<< eventi[i].data.giorno<< " " << eventi[i].data.mese << " "<< eventi[i].data.anno << endl;
            k++;
        }
    }
    if (k==0)
    cout << "errore titolo non trovato " << endl;
}

// contare quanti eventi si svolgono in un anno specifico inserito dall'utente;

void eventiannuali(Evento eventi[], int n){
    int k = 0;
    int anno = 0;
    cout << "inserisci un anno " << endl;
    cin >> anno;
    for (int i = 0; i < n; i++){
        if (anno==eventi[i].data.anno)
            k++;
    }
    cout << "gli eventi nell' anno " << anno << " sono " << k;
}

// individuare e stampare l'evento con il maggior numero di partecipanti;

void ordinaperpartecipanti(Evento eventi[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (eventi[j].partecipanti > eventi[j+1].partecipanti){
                Evento temp = eventi[j];
                eventi[j] = eventi[j+1];
                eventi[j+1] = temp;
            }
        }
    }
    cout << "Eventi ordinati per numero di partecipanti (crescente):" << endl;
    for (int i = 0; i < n; i++){
        cout << eventi[i].titolo << " " << eventi[i].partecipanti << " partecipanti" << endl;
    }
}

//stampare l'elenco di tutti gli eventi che si svolgono in un mese specifico inserito dall'utente (es. "tutti gli eventi di dicembre"), ordinati per giorno crescente all'interno del mese;

void eventimese (Evento eventi[], int n){
    int mese;
    cout << "inserisci un mese (1-12) " << endl;
    cin >> mese;
    for (int i = 0; i < n; i++){
        if (mese == eventi[i].data.mese){
            cout << "l'evento e' " << eventi[i].luogo << " "<< eventi[i].partecipanti << " "<< eventi[i].data.giorno<< " " << eventi[i].data.mese << " "<< eventi[i].data.anno << endl;
        }
    }
}

//dato un evento (cercato per titolo), stampare se si trova prima o dopo un altro evento (cercato per titolo), confrontando le rispettive date (anno, poi mese, poi giorno);

void eventoprimadopo(Evento eventi[], int n){
    string titolo1, titolo2;
    int k1 = -1, k2 = -1;

    cout << "Titolo primo evento ";
    cin >> titolo1;
    cout << "Titolo secondo evento ";
    cin >> titolo2;

    for (int i = 0; i < n; i++){
        if (eventi[i].titolo == titolo1) k1 = i;
        if (eventi[i].titolo == titolo2) k2 = i;
    }

    if (k1 == -1 || k2 == -1){
        cout << "Uno o entrambi gli eventi non sono stati trovati" << endl;
        return;
    }

    if (eventi[k1].data == eventi[k2].data)
        cout << "I due eventi si svolgono nella stessa data" << endl;
    else if (eventi[k1].data < eventi[k2].data)
        cout << eventi[k1].titolo << " si svolge prima di " << eventi[k2].titolo << endl;
    else
        cout << eventi[k1].titolo << " si svolge dopo " << eventi[k2].titolo << endl;
}

// calcolare il numero medio di partecipanti tra tutti gli eventi.

void mediapartecipanti(Evento eventi[], int n){
    double media = 0;
    for (int i = 0; i < n; i++){
        media+=eventi[i].partecipanti;
    }
    cout << media/ n;
}