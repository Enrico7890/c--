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
 
void inputN(int& n);
void inputArray(double arr[], int n);
void contaPositivi(double arr[], int n, int& pos);
void contaNegativi(double arr[], int n, int& neg);
void calcolaMedia(double arr[], int n, double& media);
void calcolaProdotto(double arr[], int n, double& prod);
void modificaElementi(double arr[], int n, double x, double media, double prodotto);
void stampaArray(double arr[], int n);
 
int main()
{
    int n;
    inputN(n);
    
    double arr[dim];
    inputArray(arr, n);
    
    double x;
    cout << "Inserire x ";
    cin >> x;
    
    cout << "array originale ";
    stampaArray(arr, n);
    
    int posPrim, negPrim;
    contaPositivi(arr, n, posPrim);
    contaNegativi(arr, n, negPrim);
    cout << "Positivi: " << posPrim << ", Negativi: " << negPrim << endl;
    
    double media, prodotto;
    calcolaMedia(arr, n, media);
    calcolaProdotto(arr, n, prodotto);
    cout << "Media: " << media << ", Prodotto: " << prodotto << endl;
    
    modificaElementi(arr, n, x, media, prodotto);
    
    cout << "array modificato ";
    stampaArray(arr, n);
    
    int posSecond, negSecond;
    contaPositivi(arr, n, posSecond);
    contaNegativi(arr, n, negSecond);
    cout << "Positivi: " << posSecond << ", Negativi: " << negSecond << endl;
}
 
void inputN(int& n)
{
    cout << "inserire numero elementi ";
    cin >> n;
}
 
void inputArray(double arr[], int n)
{
    cout << "Inserire gli elementi" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
 
void contaPositivi(double arr[], int n, int& pos)
{
    pos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) pos++;
    }
}
 
void contaNegativi(double arr[], int n, int& neg)
{
    neg = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) neg++;
    }
}
 
void calcolaMedia(double arr[], int n, double& media)
{
    double somma = 0;
    for (int i = 0; i < n; i++) {
        somma += arr[i];
    }
    media = somma / n;
}
 
void calcolaProdotto(double arr[], int n, double& prod)
{
    prod = 1;
    for (int i = 0; i < n; i++) {
        prod *= arr[i];
    }
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
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << "...";
    }
}