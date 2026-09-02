#include <iostream>
using namespace std;
 
const int dim = 100;
 
int inputn();
void inputarr(char [][50], int);
void inputarr(double [], int);
void cifra(char [][50], double [], double [], int);
void articolo(char [][50], double [], int);
 
int main(){
    int n;
    char articoli[dim][50];
    double quant[dim], prezzo[dim];
    n = inputn();
    inputarr(articoli, n);
    inputarr(quant, n);
    inputarr(prezzo, n);
    cifra(articoli, quant, prezzo, n);
    articolo(articoli, quant, n);
}
 
int inputn(){
    int n = 0;
    do{
        cout << "inserisci la dimensione dell'array: ";
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}
 
void inputarr(char arr[][50], int n){
    for (int i = 0; i < n; i++){
        cout << "inserisci articolo " << endl;
        cin >> arr[i];
    }
}
 
void inputarr(double arr[], int n){
    for (int i = 0; i < n; i++){
        cout << "inserisci valore " << endl;
        cin >> arr[i];
    }
}
 
void cifra(char arr[][50], double quant[], double prezzo[], int n){
    double cifra = 0;
    cout << "inserisci una cifra ";
    cin >> cifra;
    for (int i = 0; i < n; i++){
        if (cifra == prezzo[i])
            cout << "prodotto: " << arr[i] << " costa " << prezzo[i] << endl;
    }
}
 
void articolo(char arr[][50], double quant[], int n){
    char nome[50];
    cout << "inserisci un articolo: ";
    cin >> nome;
    for (int i = 0; i < n; i++){
        int j = 0;
        while (nome[j] == arr[i][j]) 
            j++;
        if (nome[j] == arr[i][j])
            cout << "quantita di " << arr[i] << quant[i] << endl;
    }
    cout << "articolo non trovato" << endl;
}