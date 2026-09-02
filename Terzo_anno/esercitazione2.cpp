#include <iostream>
#include <string>
using namespace std;

/* Utilizzando l'approccio TOP-DOWN, scrivere il codice nel linguaggio C++, che risolva 
il seguente problema che utilizza Array Paralleli:

Preso in input un elenco composto da N (N viene preso precedentemente in input) nomi 
di città e le temperature massime registrate (in °C) (N.B.: saranno considerati due 
array... città, temperature...), determinare:

* il nome della città con la temperatura più alta e quello della città con la 
  temperatura più bassa;
* la temperatura media tra tutte le città;
* i nomi di tutte le città che hanno una temperatura superiore a un valore inserito 
  in input dall'utente;
* il nome della città che ha una temperatura più vicina alla media (temperatura meno 
  diversa dalla media). */
const int dim = 100;
int inputn();
void inputdati(string citta[], int temp[], int n);
void tempaltabassa(string citta[], int temp[], int n, int tempalta, int tempbassa);
void tempmedia(string citta[], int temp[], int n, float &media);
void temperaturadet(string citta[], int temp[], int n, int temp2);
void tempvicinomedia(string citta[], int temp[], int n, float &media);

int main (){
    int n, tempalta, tempbassa, temp2;
    float media;
    int temp[dim];
    string citta[dim];

    n = inputn();
    inputdati(citta, temp, n);
    tempaltabassa(citta, temp, n, tempalta, tempbassa);
    tempmedia(citta, temp, n, media);
    temperaturadet(citta, temp, n, temp2);
    tempvicinomedia(citta, temp, n, media);
}

int inputn(){
    int n = 0;
    do{
        cout << "inserisci quante citta " << endl;
        cin >> n;
    }   while (n < 0 || n > dim);
    return n;
}

void inputdati(string citta[], int temp[], int n){
    for (int i = 0; i < n; i++){
        cout << "Inserisci le citta " << endl;
        cin >> citta[i];

        cout <<"inserisci le temperature" << endl;
        cin >> temp[i];
    }
}

void tempaltabassa(string citta[], int temp[], int n, int tempalta, int tempbassa){
    tempalta = temp[0];
    tempbassa = temp[0];

    for (int i = 1; i < n; i++){
        if (temp[i] > tempalta)
        tempalta = temp[i];
        if (temp[i] < tempbassa)
        tempbassa = temp[i];
    }
    cout << "la temperatura piu alta e' " << tempalta << endl;
    cout << "la temperatura piu bassa e' " << tempbassa << endl;
}

void tempmedia(string citta[], int temp[], int n, float &media){
    int somma = 0;
    for (int i = 0; i < n; i++){
    somma = somma + temp[i];
    }
    media = (float)somma/n;
}

void temperaturadet(string citta[], int temp[], int n, int temp2){
    cout << "inserisci una temperatura " << endl;
    cin >> temp2;
    for (int i = 0; i < n; i++)
    if (temp[i]> temp2){
        cout << "la citta " << citta[i] << "ha una temperatura maggiore della media" << endl;
    }
}

void tempvicinomedia(string citta[], int temp[], int n, float &media){
    int differenza = abs(temp[0] - media);
    int indice = 0;
    
    for (int i = 1; i < n; i++)
    {
        int diff = abs(temp[i] - media);
        if (diff < differenza)
        {
            differenza = diff;
            indice = i;
        }
    }
    cout << "Citta' piu' vicina alla media: " << citta[indice] << temp[indice] << endl;
}
