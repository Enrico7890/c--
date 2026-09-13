#include <iostream>
#include <string>

using namespace std;

/* Usa una classe per rappresentare un contatto, con i campi: nome, cognome, numero di telefono, età.

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

// Una classe e' un modello che descrive quali dati possiede un oggetto
// e quali operazioni possono essere eseguite su quei dati.
class Contatto {
private:
    // I membri private sono accessibili direttamente solo dai metodi della classe.
    // Questo principio si chiama incapsulamento e protegge i dati dall'esterno.
    string nome;       // Nome del contatto.
    string cognome;    // Cognome del contatto.
    int numero;        // Numero di telefono, memorizzato come intero.
    int eta;           // Eta' del contatto.

public:
    // Dichiarazione del costruttore con parametri: crea un Contatto gia' inizializzato.
    // I parametri hanno lo stesso significato dei dati della classe.
    Contatto(string nome, string cognome, int numero, int eta);
    // Costruttore predefinito: crea un Contatto senza parametri.
    Contatto();

    // I getter restituiscono una copia del valore di un attributo privato.
    string getNome();
    string getCognome();
    int getNumero();
    int getEta();

    // I setter modificano gli attributi privati tramite metodi pubblici.
    void setNome(string nome);
    void setCognome(string cognome);
    void setNumero(int numero);
    void setEta(int eta);
};

// Definizione del costruttore con parametri.
// Contatto:: indica che il metodo appartiene alla classe Contatto.
Contatto::Contatto(string n, string c, int num, int e){
    nome = n;       // Copia il parametro n nell'attributo nome dell'oggetto.
    cognome = c;    // Copia il parametro c nell'attributo cognome dell'oggetto.
    numero = num;   // Copia il parametro num nell'attributo numero dell'oggetto.
    eta = e;        // Copia il parametro e nell'attributo eta dell'oggetto.
}

// Definizione del costruttore predefinito.
// Questi valori vengono usati quando si crea un oggetto senza argomenti.
Contatto::Contatto(){
    nome = "";      // Stringa vuota come valore iniziale del nome.
    cognome = "";   // Stringa vuota come valore iniziale del cognome.
    numero = 0;     // Zero come valore iniziale del numero.
    eta = 0;        // Zero come valore iniziale dell'eta'.
}

// Ogni getter permette di leggere un attributo private senza accedervi direttamente.
string Contatto::getNome(){return nome;}       // Restituisce il nome dell'oggetto.
string Contatto::getCognome(){return cognome;} // Restituisce il cognome dell'oggetto.
int Contatto::getNumero(){ return numero;}     // Restituisce il numero dell'oggetto.
int Contatto::getEta(){return eta;}            // Restituisce l'eta' dell'oggetto.

// Ogni setter permette di modificare un attributo private attraverso l'interfaccia pubblica.
void Contatto::setNome(string n){ nome = n; }       // Imposta il nome.
void Contatto::setCognome(string c){ cognome = c; } // Imposta il cognome.
void Contatto::setNumero(int num){ numero = num; }  // Imposta il numero.
void Contatto::setEta(int e){
    // Il controllo impedisce di assegnare un'eta' negativa.
    if (e >= 0) eta = e;  // Aggiorna l'eta' solo se il valore e' valido.
}

int inputn(); // Prototipo della funzione che legge la quantita' di contatti.
// L'array contiene oggetti Contatto; n indica quanti elementi sono validi.
void inputarr(Contatto rubrica [], int n);
void ricercacognome(Contatto rubrica [], int n);
void ricercagiovane(Contatto rubrica [], int n);
void ricercanziano(Contatto rubrica [], int n);
double etamedia(Contatto rubrica [], int n);
void etainferioremedia(Contatto rubrica [], double media, int n);
void etasuperioresoglia(Contatto rubrica [], int n);

int main (){
    // Crea un array di 100 oggetti Contatto usando il costruttore predefinito.
    // Solo i primi n elementi verranno riempiti e utilizzati.
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
    string nome;
    string cognome;
    int numero, eta;
    for (int i = 0; i < n; i++){
        cout << "Nome: ";
        cin >> nome;
        cout << "Cognome: ";
        cin >> cognome;
        cout << "Numero: ";
        cin >> numero;
        cout << "Eta' ";
        cin >> eta;

        // Sintassi generale: oggetto.nomeMetodo(valori_da_passare).
        // I setter vengono usati perche' gli attributi sono private.

        rubrica[i].setNome(nome);       // Chiama il setter dell'i-esimo Contatto.
        rubrica[i].setCognome(cognome); // Modifica il cognome dell'i-esimo Contatto.
        rubrica[i].setNumero(numero);   // Modifica il numero dell'i-esimo Contatto.
        rubrica[i].setEta(eta);         // Modifica l'eta' usando anche il controllo del setter.
    }
}

// permettere di cercare un contatto per cognome e stamparne i dati completi; se non viene trovato, stampare un messaggio d'errore;

void ricercacognome(Contatto rubrica [], int n){
    string cognomecerca;
    int k = 0;
    cout << "Inserisci un cognome da cercare " << endl;
    cin >> cognomecerca;
    for (int i = 0; i < n; i++){
        // rubrica[i] e' un oggetto Contatto; il punto richiama un metodo dell'oggetto.
        if (rubrica[i].getCognome()==cognomecerca){
        cout << "cognome trovato, il nome e' " << rubrica[i].getNome()<< " la sua eta' e' " << rubrica[i].getEta() << " il suo numero e' " << rubrica[i].getNumero() << endl;
        k++;
        }
    }
    if(k==0)
    cout << "nessun cognome found, try again " << endl;
}

//individuare e stampare il contatto più giovane;

void ricercagiovane(Contatto rubrica [], int n){
    int giovane = rubrica[0].getEta();
    int k = 0;
    for (int i = 0; i < n; i++){
        if (rubrica[i].getEta() < giovane){
            giovane = rubrica[i].getEta();
            k = i;
        }
    }
    cout << "il contatto piu' giovane e' " << rubrica[k].getNome() << " " << rubrica[k].getCognome() << " "<< rubrica[k].getNumero() << " con l'eta' " << rubrica[k].getEta() << endl;
}

//individuare e stampare il contatto più anziano;

void ricercanziano(Contatto rubrica [], int n){
    int anziano = rubrica[0].getEta();
    int k = 0;
    for (int i = 0; i < n; i++){
        if (rubrica[i].getEta() > anziano){
            anziano = rubrica[i].getEta();
            k = i;
        }
    }
    cout << "il contatto piu' anziano e' " << rubrica[k].getNome() << " "<< rubrica[k].getCognome() << " "<< rubrica[k].getNumero() << " con l'eta' " << rubrica[k].getEta() << endl;
}

// calcolare l'età media di tutti i contatti;

double etamedia(Contatto rubrica [], int n){
    double media = 0;
        for (int i = 0; i < n; i++){
            media+=rubrica[i].getEta();
        }
    return media / n;
}

// stampare l'elenco di tutti i contatti con un'età inferiore alla media calcolata;

void etainferioremedia(Contatto rubrica [], double media, int n){
    for (int i = 0; i < n; i++)
        if (rubrica[i].getEta() < media)
        cout << "il contatto ha un eta' inferiore alla media' " << rubrica[i].getNome() << " "<< rubrica[i].getCognome()<< " " << rubrica[i].getNumero() << " con l'eta' " << rubrica[i].getEta() << endl;
}

// contare quanti contatti hanno un'età superiore a una soglia inserita dall'utente. */

void etasuperioresoglia(Contatto rubrica [], int n){
    int inputeta = 0;
    int k = 0;
    cout << "Inserisci un eta' " << endl;
    cin >> inputeta;
    for (int i = 0; i < n; i++){
        if (rubrica[i].getEta() > inputeta)
        k++;
    }
    cout << k << " contatti hanno un eta' superiore alla soglia " << endl;
}