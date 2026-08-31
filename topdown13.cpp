#include <iostream>
#include <string>
using namespace std;

const int dim = 100;

int inputN();
void inputarr(string nomi[], string cognomi[], int voti[], int n);
void votodet(string nomi[], string cognomi[], int voti[], int n);
void votomax(string nomi[], string cognomi[], int voti[], int n);
void votomin(string nomi[], string cognomi[], int voti[], int n);
void votomedio(string nomi[], string cognomi[], int voti[], int n);

int main() {
    string nomi[dim];
    string cognomi[dim];
    int voti[dim];
    int n = inputN();
    
    inputarr(nomi, cognomi, voti, n);
    votodet(nomi, cognomi, voti, n);
    votomax(nomi, cognomi, voti, n);
    votomin(nomi, cognomi, voti, n);
    votomedio(nomi, cognomi, voti, n);
}

int inputN() {
    int n = 0;
    do {
        cout << "Inserisci la lunghezza del tuo array: ";
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

void inputarr(string nomi[], string cognomi[], int voti[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Inserisci il nome: ";
        cin >> nomi[i];
        cout << "Inserisci il cognome: ";
        cin >> cognomi[i];
        cout << "Inserisci il voto: ";
        cin >> voti[i];
    }
}

void votodet(string nomi[], string cognomi[], int voti[], int n) {
    int voti2 = 0;
    cout << "Inserisci un voto da cercare: ";
    cin >> voti2;
    for (int i = 0; i < n; i++) {
        if (voti[i] == voti2) {
            cout << "Lo studente " << nomi[i] << " " << cognomi[i] << " ha il voto " << voti2 << endl;
        }
    }
}

void votomax(string nomi[], string cognomi[], int voti[], int n) {
    int max = voti[0];
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (voti[i] > max) {
            max = voti[i];
            indice = i;
        }
    }
    cout << "Voto massimo: " << nomi[indice] << cognomi[indice] << " con voto " << max << endl;
}

void votomin(string nomi[], string cognomi[], int voti[], int n) {
    int min = voti[0];
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (voti[i] < min) {
            min = voti[i];
            indice = i;
        }
    }
    cout << "Voto minimo: " << nomi[indice] << cognomi[indice] << " con voto " << min << endl;
}

void votomedio(string nomi[], string cognomi[], int voti[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += voti[i];
    }
    double media = (double)somma / n;
    cout << "Media della classe: " << media << endl;
    for (int i = 0; i < n; i++) {
        if (voti[i] == media) {
            cout << "Con voto medio " << nomi[i] <<  cognomi[i] << endl;
        }
    }
}