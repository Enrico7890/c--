// Preso in input un array di N caratteri, ed altri due caratteri a parte x e y, 
// sostituire nell’array tutte le occorrenze di x con y 
//(ossia tutte gli elementi dell’array che contengono il valore di x dovranno contenere il valore di y)

#include <iostream>
using namespace std;

const int dim = 100;
// Costante globale: dim.

// inputn: parametri formali e attuali: nessuno; variabile locale: n.
int inputn();
// input: parametri formali a[], x&, y&, n. Alla chiamata da main,
// gli attuali sono a, b, c, k: a è l'array, b e c sono passati per
// riferimento, k per valore. Variabile locale: i.
void input(char[], char&, char&, int);
// sostituisci: parametri formali a[], x&, y&, n. Alla chiamata da main,
// gli attuali sono a, b, c, k: a è l'array, b e c sono passati per
// riferimento, k per valore. Variabile locale: i.
void sostituisci(char[], char&, char&, int);
// output: parametri formali a[], x&, y&, n. Alla chiamata da main,
// gli attuali sono a, b, c, k: a è l'array, b e c sono passati per
// riferimento, k per valore. Variabile locale: i.
void output(char[], char&, char&, int);

int main(){
    // Parametri formali/attuali: nessuno. Variabili locali: a, b, c, k.
    char a[dim], b, c;
    int k;

    k = inputn();
    input(a, b, c, k);
    sostituisci(a, b, c, k);
    output(a, b, c, k);
}

int inputn(){
    // Nessun parametro; variabile locale: n.
    int n = 0;
    cout << "Inserisci la dimensione " << endl;
    cin >> n;
    do {
        cout << "Inserisci la dimensione " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);

    return n;
}

void input(char a[], char& x, char& y, int n){
    // Formali: a[], x&, y&, n (n passato per valore); attuali da main:
    // a, b, c, k. Variabile locale: i.
    cout << "Inserisci il carattere x ";
    cin >> x;
    cout << "Inserisci il carattere y ";
    cin >> y;

    cout << "Riempi l'array " << endl;
    int i = 0;
    do {
        cin >> a[i];
        i++;
    } while (i < n);
}

void sostituisci(char a[], char& x, char& y, int n){
    // Formali: a[], x&, y&, n (n passato per valore); attuali da main:
    // a, b, c, k. Variabile locale: i.
    int i = 0;
    do {
        if (a[i] == x){
            a[i] = y;
        }
        i++;
    } while (i < n);
}

void output(char a[], char& x, char& y, int n){
    // Formali: a[], x&, y&, n (n passato per valore); attuali da main:
    // a, b, c, k. Variabile locale: i.
    cout << "Array finale";
    int i = 0;
    do {
        cout << a[i] << " ";
        i++;
    } while (i < n);
    cout << endl;
    cout << "x = " << x << " y = " << y << endl;
}