#include <iostream>
using namespace std;
//Preso in input un array di N reali, trovare il valore massimo e il valore minimo dell'array e stampare la loro differenza.
const int dim = 100;

int main (){
double array [dim], min, max, diff;
int n;

do {
    cout << "lunghezza dell'array" << endl;
    cin >> n;

} while (n <= 0 || n > dim);

for (int i = 0; i< n; i++){
    cout << "inserisci un numero" << endl;
    cin >> array [i];
    }
        min = array [0];
        max = array [0];    

    for (int i = 0 ;i < n; i++){
        if (array [i] >= max){
            max= array [i];
        }
        else if (array [i] <= min){
            min = array [i];
        } 
    }
     diff = max - min;

    cout << "il valore maggiore e' " << max << endl;
    cout << "il valore minore e'" << min << endl;
    cout << "la loro differenza e'" << diff << endl;
    }
