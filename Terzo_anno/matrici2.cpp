#include <iostream>
using namespace std;

/*
Dichiara una matrice int voti[5][4] dove le 5 righe rappresentano gli studenti e le 4 colonne le materie.
Realizza le seguenti funzioni:
leggi — inserisce i voti da tastiera
stampa — mostra la matrice formattata
mediaStudente — calcola la media dei voti per ogni studente (riga)
miglioreStudente — trova e stampa l'indice dello studente con la media più alta
*/

int r = 5;
int c = 4;

void leggi(int voti[][4]);
void stampa(int voti[][4]);
float mediaStudente(int voti[][4], int riga);
void miglioreStudente(int voti[][4]);

int main(){
    int voti[5][4];

    leggi(voti);
    stampa(voti);
    miglioreStudente(voti);
}

void leggi(int voti[][4]){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << "Inserisci voto studente " << i + 1 << " materia " << j + 1 << ": ";
            cin >> voti[i][j];
        }
    }
}

void stampa(int voti[][4]){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << voti[i][j] << "\t";
        }
        cout << endl;
    }
}

float mediaStudente(int voti[][4], int riga){
    int somma = 0;
    for (int j = 0; j < c; j++){
        somma += voti[riga][j];
    }
    return (float)somma / c;
}

void miglioreStudente(int voti[][4]){
    int indiceMigliore = 0;
    float mediaMax = mediaStudente(voti, 0);

    for (int i = 1; i < r; i++){
        float media = mediaStudente(voti, i);
        cout << "Media studente " << i + 1 << ": " << media << endl;
        if (media > mediaMax){
            mediaMax = media;
            indiceMigliore = i;
        }
    }

    cout << "Il migliore studente e' il numero " << indiceMigliore + 1 << " con media " << mediaMax << endl;
}