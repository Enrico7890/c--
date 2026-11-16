/* Realizzare un progetto che, utilizzando l'approccio TOP-DOWN, risolve il seguente problema con l'uso delle STRUCT:

🏀 Gestire un elenco di alunni di cui si conoscono
nomi, cognomi e voti in informatica (N.B.: sarà considerato un array di una Struct con tre campi: nomi, cognomi, voti...). 
Attraverso un menù prevedere le seguenti operazioni:
inserire un nuovo alunno (con nome, cognome, voto);
visualizzare quanti alunni sono presenti in elenco;
visualizzare la media dei voti di tutti gli alunni presenti in elenco;
visualizzare il nome e il cognome dell’alunno che ha riportato il voto più alto e di quello che ha riportato il voto più basso;
visualizzare i nomi e i cognomi di tutti gli alunni che hanno riportato un determinato voto preso in input dall'utente;
visualizzare i nomi e i cognomi di tutti gli alunni (se esistono!) che hanno riportato il voto medio di tutta la classe;
terminare il programma.
Nota: Terminata la realizzazione del progetto con l'approccio TOP-DOWN, si provi a risolverlo anche l'approccio OOP 
(ricorrendo anche all'ausilio dell'IA se necessario...) */

#include <iostream>
#include <string>
using namespace std;

const int dim = 100;

struct Alunno {
    string nome;
    string cognome;
    double voto;
};

class Elenco {
private:
    Alunno studenti[dim];
    int n;

public:
    Elenco();
    void inserisci();
    int getN();
    double media();
    void votoAltoBasso();
    void cercaPerVoto();
    void cercaVotoMedio();
};

void menu(Elenco& elenco);

int main(){
    Elenco classe;
    menu(classe);
}

Elenco::Elenco(){
    n = 0;
}

void menu(Elenco& elenco){
    int scelta = 0;
    do{
        cout << "1. Inserisci alunno  2. Numero alunni  3. Media  4. Piu' alto e piu' basso  5. Cerca per voto  6. Voto medio  0. Esci" << endl;
        cin >> scelta;
        switch (scelta){
            case 1:
            elenco.inserisci();
            break;
            case 2:
            cout << "Alunni presenti: " << elenco.getN() << endl;
            break;
            case 3:
            cout << "Media dei voti: " << elenco.media() << endl;
            break;
            case 4:
            elenco.votoAltoBasso();
            break;
            case 5:
            elenco.cercaPerVoto();
            break;
            case 6:
            elenco.cercaVotoMedio();
            break;
        }
    } while (scelta != 0);
}

void Elenco::inserisci(){
    if (n >= dim){
        cout << "Elenco pieno" << endl;
        return;
    }
    cout << "Nome: ";
    cin >> studenti[n].nome;
    cout << "Cognome: ";
    cin >> studenti[n].cognome;
    cout << "Voto: ";
    cin >> studenti[n].voto;
    n++;
}

int Elenco::getN(){
    return n;
}

double Elenco::media(){
    double somma = 0;
    for (int i = 0; i < n; i++)
        somma += studenti[i].voto;
    return somma / n;
}

void Elenco::votoAltoBasso(){
    int alto = 0, basso = 0;
    for (int i = 0; i < n; i++){
        if (studenti[i].voto > studenti[alto].voto)
            alto = i;
        if (studenti[i].voto < studenti[basso].voto)
            basso = i;
    }
    cout << "Voto piu' alto: " << studenti[alto].nome << " " << studenti[alto].cognome << " (" << studenti[alto].voto << ")" << endl;
    cout << "Voto piu' basso: " << studenti[basso].nome << " " << studenti[basso].cognome << " (" << studenti[basso].voto << ")" << endl;
}

void Elenco::cercaPerVoto(){
    double cercato = 0;
    int trovati = 0;
    cout << "Inserisci il voto da cercare: ";
    cin >> cercato;
    for (int i = 0; i < n; i++){
        if (studenti[i].voto == cercato){
            cout << studenti[i].nome << " " << studenti[i].cognome << endl;
            trovati++;
        }
    }
    if (trovati == 0)
        cout << "Nessun alunno ha quel voto" << endl;
}

void Elenco::cercaVotoMedio(){
    double m = media();
    int trovati = 0;
    for (int i = 0; i < n; i++){
        if (studenti[i].voto == m){
            cout << studenti[i].nome << " " << studenti[i].cognome << endl;
            trovati++;
        }
    }
    if (trovati == 0)
        cout << "Nessun alunno ha il voto medio della classe" << endl;
}