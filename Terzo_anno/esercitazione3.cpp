#include <iostream> 
#include <string> 
using namespace std;

/* Utilizzando l'approccio TOP-DOWN, scrivere il codice nel linguaggio C++, che risolva 
il seguente problema che utilizza Array Paralleli:

Preso in input un elenco composto da N (N viene preso precedentemente in input) nomi 
degli atleti, pesi corporei (in kg) e altezze (in cm) (N.B.: saranno considerati tre 
array... nomi, pesi, altezze...), determinare:

* l'atleta con il peso massimo e quello con il peso minimo;
* il peso medio degli atleti;
* gli atleti che hanno un peso superiore al peso medio;
* gli atleti che hanno un'altezza inferiore a un valore inserito in input;
* l'atleta che ha un peso uguale al peso medio. */
const int dim = 100;
int inputn();
void inputdati(string nomi[], float pesi[], float altezze[], int n);
void massimominimo(string nomi[], float pesi[], int n, float &max); 
void pesomedio(float pesi[], int n, float &media);
void pesosupmedia(string nomi[], float pesi[], int n, float media);
void altezzainferiore(string nomi[], float altezze[], int n);
void pesovicinomedia(string nomi[], float pesi[], int n, float media);

int main (){
    int n;
    float max, media;
    string nomi[dim];
    float pesi[dim], altezze[dim];

    n = inputn();
    inputdati(nomi, pesi, altezze, n);
    massimominimo(nomi, pesi, n, max);
    pesomedio(pesi, n, media);
    pesosupmedia(nomi, pesi, n, media);
    altezzainferiore(nomi, altezze, n);
    pesovicinomedia(nomi, pesi, n, media);
}
int inputn (){
    int n = 0;
    do {
        cout << "inserisci la lunghezza degli array " << endl;
        cin >> n;
    } while (n < 0 || n> dim);

    return n;
}

void inputdati(string nomi[], float pesi [], float altezze [], int n){
    for (int i = 0; i < n ; i++){
        cout << "inserisci i nomi "  << endl;
        cin >> nomi[i];
        cout << "inserisci i pesi " << endl;
        cin >> pesi[i];
        cout << "inserisci le altezze " << endl;
        cin >> altezze [i];
    }
}

void massimominimo(string nomi[], float pesi[], int n, float &max){
    int k = 0;
    int z = 0;
    float min = pesi[0];
    max = pesi[0];
    for (int i = 1; i < n ; i++){
        if (pesi[i] > max){
            max = pesi[i];
            k = i;
        }
        if (pesi[i] < min){
            min = pesi[i];
            z = i;
        }
    }
    cout << "il peso massimo e' " << max << " di " << nomi[k] << endl;
    cout << "il peso minimo e' " << min << " di " << nomi[z] << endl;
}

void pesomedio(float pesi[], int n, float &media){
    float somma = 0; 
    for (int i = 0; i < n; i++)
        somma += pesi[i];

    media = somma/n;

    cout << "la media e' " << media << endl;
}

void pesosupmedia(string nomi[], float pesi[], int n, float media){
    for (int i = 0; i < n; i++)
        if (pesi[i] > media){
            cout << "l'atleta " << nomi[i] << " supera la media con il peso di " << pesi[i] << endl;
        }
}

void altezzainferiore(string nomi[], float altezze[], int n){
    float altezze2;
    cout << "inserisci un'altezza " << endl;
    cin >> altezze2;
    for (int i = 0; i < n; i++){
        if(altezze[i] < altezze2)
            cout << "l'atleta " << nomi[i] << " ha un'altezza inferiore a quella inserita " << endl;
    }
}

void pesovicinomedia(string nomi[], float pesi[], int n, float media){
    for (int i = 0; i < n; i++){
        if(pesi[i] == media)
            cout << "l'atleta " << nomi[i] << " ha il peso uguale alla media " << media << endl;
    }
}