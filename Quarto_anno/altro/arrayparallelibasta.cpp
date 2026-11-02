#include <iostream>
#include <string>
using namespace std;

/* Realizzare un progetto che, utilizzando l'approccio TOP-DOWN, risolva il seguente problema che utilizza Array Paralleli :
Preso in input un elenco composto da N (N viene preso precedentemente in input)
nomi, cognomi e voti in informatica (N.B.: saranno considerati tre array... nomi, cognomi, voti...), determinare:
il nome e il cognome dell'alunno che ha riportato il voto più alto e di quello che ha riportato il voto più basso;
i nomi e i cognomi di tutti gli alunni che hanno riportato un determinato voto preso in input dall'utente;
i nomi e i cognomi di tutti gli alunni (se esistono!) che hanno riportato il voto medio di tutta la classe.
Si provi a risolvere lo stesso problema del punto precedente utilizzando un ARRAY di STRUCT.
N.B.: le struct nuovi tipo di dato definiti dall'utente che permettono di raggruppare più variabili (chiamate o ) 
anche di tipi diversi (eterogenei) sotto un unico nome. Allo studente è lasciato il compito di "indagare" e "scoprire" come si usano in C/C++. */

const int dim = 100;

int inputn(string);
void inputarray(string nomi[], string cognomi[], double voti[], int);
void votoaltobasso(string nomi[], string cognomi[], double voti[], int);
void determinatovoto(string nomi[], string cognomi[], double voti[], int);
void votomedio(string nomi[], string cognomi[], double voti[], int);

int main(){
    string nomi[dim], cognomi[dim];
    double voti[dim];

    string u = "inserisci dimensione array ";
    int n = inputn(u);
    inputarray(nomi, cognomi, voti, n);
    votoaltobasso(nomi, cognomi, voti, n);
    determinatovoto(nomi, cognomi, voti, n);
    votomedio(nomi, cognomi, voti, n);
}

int inputn(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    } while (num <= 0 || num > dim);
    return num;
}

void inputarray(string nomi[], string cognomi[], double voti[], int n){
    for (int i = 0; i < n; i++){
        cout << "inserisci nome del " << i << " alunno ";
        cin >> nomi[i];
        cout << "inserisci cognome del " << i << " alunno ";
        cin >> cognomi[i];
        cout << "inserisci voto del " << i << " alunno ";
        cin >> voti[i];
    }
}

// il nome e il cognome dell'alunno che ha riportato il voto più alto e di quello che ha riportato il voto più basso;

void votoaltobasso(string nomi[], string cognomi[], double voti[], int n){
    int indice1 = 0, indice2 = 0;
    double votoalto = voti[0];
    double votobasso = voti[0];
    for (int i = 0; i < n; i++){
        if (voti[i] > votoalto){
            votoalto = voti[i];
            indice1 = i;
        }
        if (voti[i] < votobasso){
            votobasso = voti[i];
            indice2 = i;
        }
    }
    cout << "voto piu' alto " << nomi[indice1] << " " << cognomi[indice1] << " con " << voti[indice1] << endl;
    cout << "voto piu' basso " << nomi[indice2] << " " << cognomi[indice2] << " con " << voti[indice2] << endl;
}

// i nomi e i cognomi di tutti gli alunni che hanno riportato un determinato voto preso in input dall'utente;

void determinatovoto(string nomi[], string cognomi[], double voti[], int n){
    double tempvoto = 0;
    int trovati = 0;
    cout << "inserisci voto da cercare " << endl;
    cin >> tempvoto;
    for (int i = 0; i < n; i++){
        if (voti[i] == tempvoto){
            cout << nomi[i] << " " << cognomi[i] << endl;
            trovati++;
        }
    }
    if (trovati == 0)
        cout << "nessun alunno ha quel voto" << endl;
}

// i nomi e i cognomi di tutti gli alunni (se esistono!) che hanno riportato il voto medio di tutta la classe.

void votomedio(string nomi[], string cognomi[], double voti[], int n){
    double somma = 0;
    for (int i = 0; i < n; i++)
        somma += voti[i];
    double media = somma / n;
    cout << "media della classe: " << media << endl;
    int trovati = 0;
    for (int i = 0; i < n; i++){
        if (voti[i] == media){
            cout << nomi[i] << " " << cognomi[i] << endl;
            trovati++;
        }
    }
    if (trovati == 0)
        cout << "nessun alunno ha il voto medio" << endl;
}