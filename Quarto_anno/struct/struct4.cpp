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

struct Alunno {
    string nome;
    string cognome;
    double voto;
};

int inputn(string);
void inputarray(Alunno alunni[], int);
void votoaltobasso(Alunno alunni[], int);
void determinatovoto(Alunno alunni[], int);
void votomedio(Alunno alunni[], int);

int main(){
    Alunno alunni[dim];

    string u = "inserisci dimensione array ";
    int n = inputn(u);
    inputarray(alunni, n);
    votoaltobasso(alunni, n);
    determinatovoto(alunni, n);
    votomedio(alunni, n);
}

int inputn(string z){
    int num = 0;
    do{
        cout << z;
        cin >> num;
    } while (num <= 0 || num > dim);
    return num;
}

void inputarray(Alunno alunni[], int n){
    for (int i = 0; i < n; i++){
        cout << "inserisci nome del " << i << " alunno ";
        cin >> alunni[i].nome;
        cout << "inserisci cognome del " << i << " alunno ";
        cin >> alunni[i].cognome;
        cout << "inserisci voto del " << i << " alunno ";
        cin >> alunni[i].voto;
    }
}

// il nome e il cognome dell'alunno che ha riportato il voto più alto e di quello che ha riportato il voto più basso;

void votoaltobasso(Alunno alunni[], int n){
    int indice1 = 0, indice2 = 0;
    double votoalto = alunni[0].voto;
    double votobasso = alunni[0].voto;
    for (int i = 0; i < n; i++){
        if (alunni[i].voto > votoalto){
            votoalto = alunni[i].voto;
            indice1 = i;
        }
        if (alunni[i].voto < votobasso){
            votobasso = alunni[i].voto;
            indice2 = i;
        }
    }
    cout << "voto piu' alto " << alunni[indice1].nome << " " << alunni[indice1].cognome << " con " << alunni[indice1].voto << endl;
    cout << "voto piu' basso " << alunni[indice2].nome << " " << alunni[indice2].cognome << " con " << alunni[indice2].voto << endl;
}


// i nomi e i cognomi di tutti gli alunni che hanno riportato un determinato voto preso in input dall'utente;

void determinatovoto(Alunno alunni[], int n){
    double tempvoto = 0;
    int trovati = 0;
    cout << "inserisci voto da cercare " << endl;
    cin >> tempvoto;
    for (int i = 0; i < n; i++){
        if (alunni[i].voto == tempvoto){
            cout << alunni[i].nome << " " << alunni[i].cognome << endl;
            trovati++;
        }
    }
    if (trovati == 0)
        cout << "nessun alunno ha il voto inserito" << endl;
}

// i nomi e i cognomi di tutti gli alunni (se esistono!) che hanno riportato il voto medio di tutta la classe.

void votomedio(Alunno alunni[], int n){
    double somma = 0;
    for (int i = 0; i < n; i++)
        somma += alunni[i].voto;
    double media = somma / n;
    cout << "media della classe: " << media << endl;
    int trovati = 0;
    for (int i = 0; i < n; i++){
        if (alunni[i].voto == media){
            cout << alunni[i].nome << " " << alunni[i].cognome << endl;
            trovati++;
        }
    }
    if (trovati == 0)
        cout << "nessun alunno ha il voto medio" << endl;
}