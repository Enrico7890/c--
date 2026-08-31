#include <iostream>
using namespace std;

//Preso in input un array di N interi, ed un altro intero a parte, 
//contare quante volte quest'ultimo viene ripetuto all'interno dell'array;

const int dim = 100;
int n = 0;

void conta(int array [dim], int x, int &conteggio){
    conteggio = 0;
    for (int i = 0; i < n; i++){
        if (array[i] == x){
            conteggio++;
        }
    }
}
int main (){
    int array [dim], x, conteggio = 0;
    do{
    cout << "inserisci la lunghezza del tuo array " << endl;
    cin >> n;
    } while (n <= 0 || n>dim);

    cout << "inserisci i numeri del tuo array " << endl;

    for (int i = 0; i < n ; i++){
        cin >> array [i];
    }

    cout << "inserisci l'intero da trovare " << endl;
    cin >> x;   
    
    conta (array, x, conteggio);

    cout << "Il numero " << x << " appare " << conteggio << " volte" << endl;
}