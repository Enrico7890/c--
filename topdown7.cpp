#include <iostream>
using namespace std;

//Letti da input i valori di N misurazioni (inserite in un array) si calcoli:
//l'errore assoluto: EA = (Valore_Max - Valore_Min)/2 (dove Valore_Max e Valore_Min sono il valore massimo e il valore minimo di tali misurazioni)
//l'errore relativo: ER = EA/Vm (dove Vm è la media aritmetica dei valori).

const int dim = 100;

int inputn();
void inputarr(int arr [], int n);
int erroreass (int arr [], int n);
double errore2 (int arr [], int n, int erroreassoluto);
void output (int arr [], int n, int erroreassoluto, double errorerel); 

int main (){

    int n = inputn();
    int arr[dim];
    inputarr(arr, n);
    
    int erroreassoluto = erroreass(arr, n);
    double errorerel = errore2(arr, n, erroreassoluto);
    
    output(arr, n, erroreassoluto, errorerel);
}

int inputn(){  
    int n = 0;
    do {
        cout << "inserisci la lunghezza del tuo array ";
        cin >> n;
    } while (n <= 0 || n > dim); 
    return n;
}

void inputarr(int arr [], int n){
for (int i = 0; i < n; i++){
    cout << "inserisci un numero nell'array " << endl;
    cin >> arr[i];
    }
}

int erroreass (int arr [], int n){
int max = arr [0];
int min = arr [0];
int erroreassoluto = 0;

for (int i = 0; i < n; i++){
    if (arr[i] > max)
        max = arr[i];
    if (arr [i] < min)
        min = arr[i];
    }

erroreassoluto = (max-min)/2;

return erroreassoluto;
}

double errore2 (int arr [], int n, int erroreassoluto){
    int somma = 0;
    double media = 0;
    double errorerel = 0;
    for (int i = 0; i < n; i++){
        somma+=arr[i];
    }
    media = (double)somma / n;
    if (media < 0) media = -media;  
    errorerel = erroreassoluto / media;
    return errorerel;
}

void output (int arr [], int n, int erroreassoluto, double errorerel){
    cout << "l'errore assoluto e' " << erroreassoluto << endl;
    cout << "l'errore relativo e' " << errorerel << endl;
}