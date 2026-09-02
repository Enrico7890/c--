/*
Preso in input un array di N numeri reali, determinare il numero dei suoi 
elementi positivi e dei suoi elementi negativi. 
 
Inoltre preso in input un altro numero a parte x, modificare ciascun elemento 
dell'array coincidente con il valore inserito x in modo tale che esso contenga 
sé stesso sommato alla media di tutti gli elementi dell'array e sottratto del 
loro prodotto.
 
Determinare infine il numero degli elementi positivi e degli elementi negativi 
anche del nuovo array così ottenuto.
*/
 
#include <iostream>
using namespace std;
 
const int dim = 100;
 
int inputN();
void inputArray(double arr[], int n);
int contaPositivi(double arr[], int n);
int contaNegativi(double arr[], int n);
double calcolaMedia(double arr[], int n);
double calcolaProdotto(double arr[], int n);
void modificaElementi(double arr[], int n, double x, double media, double prodotto);
void stampaArray(double arr[], int n);
 
int main()
{
    int n = inputN();
    
    double arr[dim];
    inputArray(arr, n);
    
    double x;
    cout << "Inserire x";
    cin >> x;
    
    cout << " Array originale: ";
    stampaArray(arr, n);
    
    int posPrim = contaPositivi(arr, n);
    int negPrim = contaNegativi(arr, n);
    cout << "Positivi: " << posPrim << ", Negativi: " << negPrim << endl;
    
    double media = calcolaMedia(arr, n);
    double prodotto = calcolaProdotto(arr, n);
    cout << "media " << media << " prodotto: " << prodotto << endl;
    
    modificaElementi(arr, n, x, media, prodotto);
    
    cout << "Array modificato ";
    stampaArray(arr, n);
    
    int posSecond = contaPositivi(arr, n);
    int negSecond = contaNegativi(arr, n);
    cout << "Positivi: " << posSecond << ", Negativi: " << negSecond << endl;
}
 
int inputN()
{
    int n;
    cout << "Inserire numero elementi ";
    cin >> n;
    return n;
}
 
void inputArray(double arr[], int n)
{
    cout << "Inserire gli elementi ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
 
int contaPositivi(double arr[], int n)
{
    int conta = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) conta++;
    }
    return conta;
}
 
int contaNegativi(double arr[], int n)
{
    int conta = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) conta++;
    }
    return conta;
}
 
double calcolaMedia(double arr[], int n)
{
    double somma = 0;
    for (int i = 0; i < n; i++) {
        somma += arr[i];
    }
    return somma / n;
}
 
double calcolaProdotto(double arr[], int n)
{
    double prodotto = 1;
    for (int i = 0; i < n; i++) {
        prodotto *= arr[i];
    }
    return prodotto;
}
 
void modificaElementi(double arr[], int n, double x, double media, double prodotto)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            arr[i] = x + media - prodotto;
        }
    }
}
 
void stampaArray(double arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) 
        cout << "... ";
    }
}