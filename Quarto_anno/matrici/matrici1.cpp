#include <iostream>
#include <string>

using namespace std;

const int R = 4;
const int C = 4;

/* Traccia: Analisi di una Matrice

Data una matrice quadrata di interi 4×4, riempita dall'utente, il programma deve:

calcolare la somma di tutti gli elementi della matrice;
trovare il valore massimo e il valore minimo, specificando in quale riga e colonna si trovano;
calcolare la media di tutti gli elementi;
stampare la somma di ogni singola riga;
stampare la somma di ogni singola colonna;
calcolare la somma della diagonale principale;
calcolare la somma della diagonale secondaria;
chiedere un valore all'utente e stampare tutte le posizioni (riga, colonna) in cui quel valore compare nella matrice; se non compare mai, stampare un messaggio;
contare quanti elementi della matrice sono pari e quanti dispari;
sostituire tutti gli elementi negativi della matrice con 0, e stampare la matrice risultante. */

void inputmatrice(int matrice [][C]);
int somma(int matrice [][C]);
void minmax(int matrice [][C]);
void media(int matrice [][C], int somma1);
void sommariga(int matrice [][C]);
void sommacolonna(int matrice [][C]);
void sommadiagonale(int matrice [][C]);
void sommasecondadiagonale(int matrice [][C]);
void inpututenten(int matrice [][C]);
void paridispari(int matrice [][C]);
void negativi(int matrice [][C]);

int main(){
    int matrice [R][C];

    inputmatrice(matrice);  
    int somma1 = somma(matrice);
    minmax(matrice);
    media(matrice, somma1);
    sommariga(matrice);
    sommacolonna(matrice);
    sommadiagonale(matrice);
    sommasecondadiagonale(matrice);
    inpututenten(matrice);
    paridispari(matrice);
    negativi(matrice);
}   

void inputmatrice(int matrice [][C]){
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << "Inserisci la riga " << i << " e la colonna " << j; 
            cin >> matrice[i][j];
        }
    }
}

// calcolare la somma di tutti gli elementi della matrice;

int somma(int matrice [][C]){
    int somma1 = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            somma1 += matrice[i][j];
        }
    }
    cout << "la somma e' " << somma1 << endl;
    return somma1;
}

//trovare il valore massimo e il valore minimo, specificando in quale riga e colonna si trovano;

void minmax(int matrice [][C]){
    int rigamax = 0;
    int colonnamax= 0; 
    int rigamin = 0;
    int colonnamin = 0;
    int min = matrice[0][0];
    int max = matrice[0][0];
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (min > matrice[i][j]){
                min = matrice[i][j];
                rigamin = i;
                colonnamin = j;
            }
            if (max < matrice[i][j]){
            max = matrice[i][j];
            rigamax = i;
            colonnamax = j;
            }
        }
    }
    cout << "Il minimo e' " << min << " colonna " << colonnamin << " riga " << rigamin << " il massimo e' " << max << " colonna " << colonnamax << " riga " << rigamax << endl;
}

// calcolare la media di tutti gli elementi;

void media(int matrice [][C], int somma1){
    double media1 = (double)somma1 / (R * C);
    cout << "la media e' "<< media1 << endl;
}

//stampare la somma di ogni singola riga;

void sommariga(int matrice [][C]){
    for (int i = 0; i < R; i++){
        int sommaR = 0;
        for (int j = 0; j < C; j++){
        sommaR+=matrice[i][j];
        }
        cout << " la somma e' " << sommaR;
    }
}

//stampare la somma di ogni singola colonna;

void sommacolonna(int matrice [][C]){
    for (int j = 0; j < C; j++){
        int sommaC = 0;
        for (int i = 0; i < R; i++){
        sommaC+=matrice[i][j];
        }
        cout << " la somma e' " << sommaC;
    }
}

//calcolare la somma della diagonale principale;

void sommadiagonale(int matrice [][C]){
    int sommadiag = 0;
    for (int i = 0; i < R; i++){
        sommadiag+=matrice[i][i];
    }
    cout << "la somma diagonale e' " << sommadiag;
}

//calcolare la somma della diagonale secondaria;

void sommasecondadiagonale(int matrice [][C]){
    int sommadiag2= 0;
        for (int i = 0; i < R ; i++){
            sommadiag2+=matrice[i][C-1-i];
        }
        cout << "la somma diagonale secondaria e' " << sommadiag2;
    }

// chiedere un valore all'utente e stampare tutte le posizioni (riga, colonna) in cui quel valore compare nella matrice; se non compare mai, stampare un messaggio;

void inpututenten(int matrice [][C]){
    int valore = 0;
    bool k = false;
    cout << "Inserisci un valore " << endl;
    cin >> valore; 
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (valore == matrice[i][j]){
            cout << "valore trovato alla riga " << i << " colonna " << j;
            k = true;
            }
        }
    }
    if (k == false)
    cout << "niente trovato nabbo " << endl;
}

// contare quanti elementi della matrice sono pari e quanti dispari;

void paridispari(int matrice [][C]){
    int ipari = 0;
    int idispari = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (matrice[i][j] % 2 == 0)
                ipari++;
            else 
            idispari++;
        }
    }
    cout << "pari: " << ipari << " dispari: " << idispari << endl;
}

// sostituire tutti gli elementi negativi della matrice con 0, e stampare la matrice risultante. */

void negativi(int matrice [][C]){
    for (int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if (matrice[i][j] < 0){
                matrice[i][j] = 0;
                
            }
            cout << "la matrice risultante e' \t" << matrice[i][j] << endl;
        }
    }
}