#include <iostream>
#include <string>

using namespace std;

/* Usa uno struct per rappresentare l'iscrizione di una persona a un corso, 
con i campi: nome (string), corso (string), numero di lezioni frequentate (int), voto finale (double, da 0 a 30, con 0 = corso non ancora terminato).

Il programma deve:

chiedere quante iscrizioni comporranno l'elenco (con controllo di validità sul numero);
permettere l'inserimento dei dati di ciascuna iscrizione;
contare quanti iscritti risultano a un corso specifico inserito dall'utente (es. "quanti sono iscritti a 'Chimica'?");
calcolare la percentuale di iscritti che hanno superato l'esame (voto ≥ 18, escludendo chi ha voto 0 perché non ha ancora terminato il corso);
individuare e stampare l'iscritto con il maggior numero di lezioni frequentate;
stampare l'elenco degli iscritti che hanno un voto finale registrato (voto > 0) ma inferiore a 18 (bocciati), specificando corso e voto;
sostituire il voto di un iscritto, cercato per nome, con un nuovo voto inserito dall'utente (se il nome non esiste, stampare un messaggio d'errore);
calcolare la media dei voti finali, considerando solo chi ha già sostenuto l'esame (voto > 0), gestendo il caso in cui nessuno l'abbia ancora sostenuto (per evitare divisione per zero). */

const int dim = 100;

struct iscrizioni{
    string nome;
    string corso;
    int lezioni;
    double voto;
};

int inputn();
void inputarr(iscrizioni uni [], int n);
void corsi(iscrizioni uni [], int n);
void esame(iscrizioni uni[], int n);
void frequenzalezioni(iscrizioni uni[], int n);
void bocciati (iscrizioni uni[], int n);
void nuovovoto(iscrizioni uni[], int n);
void mediafinali(iscrizioni uni [], int n);

int main(){
    iscrizioni uni [dim];

    int n = inputn();
    inputarr(uni, n);
    corsi(uni, n);
    esame(uni, n);
    frequenzalezioni(uni, n);
    bocciati(uni, n);
    nuovovoto(uni, n);
    mediafinali(uni, n);
}

int inputn(){
    int n = 0;
    do{
        cout << "Quanti iscrizioni ha la tua universita' " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

void inputarr(iscrizioni uni[],int n){
    for (int i = 0; i < n; i++){
        cout << "inserisci il nome ";
        cin >> uni[i].nome;
        cout << "Inserisci il corso ";
        cin >> uni[i].corso;
        cout << "inserisci le lezioni frequentate ";
        cin >> uni[i].lezioni;
        cout << "inserisci il voto ";
        cin >> uni[i].voto; 
    }
}

//contare quanti iscritti risultano a un corso specifico inserito dall'utente (es. "quanti sono iscritti a 'Chimica'?");

void corsi(iscrizioni uni[], int n){
    string corso;
    int k = 0;
    cout << "inserisci un corso " << endl;
    cin >> corso;
    for (int i = 0; i < n; i++){
        if (corso == uni[i].corso)
        k++;
    }
    cout << k << " studenti sono iscritti a questo corso " << endl;
}

// calcolare la percentuale di iscritti che hanno superato l'esame (voto ≥ 18, escludendo chi ha voto 0 perché non ha ancora terminato il corso);

void esame (iscrizioni uni[], int n){
    double percentuale = 0;
    for (int i = 0; i < n; i++)
        if(uni[i].voto >= 18 && uni[i].voto != 0)
        percentuale++;
    percentuale = (percentuale/n)*100;
    cout << "la percentuale che ha superato l'esame e' " << percentuale << endl;
}

//individuare e stampare l'iscritto con il maggior numero di lezioni frequentate;

void frequenzalezioni(iscrizioni uni[], int n){
    int maxlezioni = 0;
    int k = 0;
    for (int i = 0; i < n; i++){
        if (uni[i].lezioni > maxlezioni){
        maxlezioni=uni[i].lezioni;
        k = i;
        }
    }
    cout << "lo studente con la maggior frequenza e' " << uni[k].nome << " con lezioni frequentate: " << maxlezioni << endl;
}

// stampare l'elenco degli iscritti che hanno un voto finale registrato (voto > 0) ma inferiore a 18 (bocciati), specificando corso e voto;

void bocciati (iscrizioni uni[], int n){
    for (int i = 0; i < n; i++){
        if (uni[i].voto > 0 && uni[i].voto < 18){
            cout << "lo studente " << uni[i].nome << " che frequenta il corso " << uni[i].corso << " e' bocciato con voto " << uni[i].voto << endl;
        }
    }
}

// sostituire il voto di un iscritto, cercato per nome, con un nuovo voto inserito dall'utente (se il nome non esiste, stampare un messaggio d'errore);

void nuovovoto(iscrizioni uni[], int n){
    string nome;
    double votonuovo;
    int k = 0;
    cout << "inserisci il nome da cercare per sostituire il voto ";
    cin >> nome;
    cout << "che voto vuoi inserire ";
    cin >> votonuovo;

    for (int i = 0; i < n; i++){
        if (uni[i].nome == nome){
            uni[i].voto = votonuovo;
            cout << " nome trovato il nuovo voto e' " << votonuovo << endl;
            k++;
        }
    }
    if (k == 0)
    cout << "nessun nome trovato " << endl;
}

//calcolare la media dei voti finali, considerando solo chi ha già sostenuto l'esame (voto > 0), gestendo il caso in cui nessuno l'abbia ancora sostenuto (per evitare divisione per zero). */

void mediafinali(iscrizioni uni [], int n){
    double media = 0;
    double somma = 0;
    int k = 0;
    for (int i = 0; i < n; i++){
        if (uni[i].voto > 0){
            somma+=uni[i].voto;
            k++;
        }
    }
    if (k == 0){
    cout << "nessuno ha sostenuto l'esame " << endl;
    return;
    }
    media = somma/k;
    cout << "la media totale dei voti finali di chi ha fatto gli esami e' " << media << endl;
}