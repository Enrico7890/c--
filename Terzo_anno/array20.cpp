#include <iostream>
using namespace std;

//Preso in input un array di N caratteri, ed altri due caratteri a parte x e y, 
//sostituire nell’array tutte le occorrenze di x con y 
//(ossia tutte gli elementi dell’array che contengono il valore di x dovranno contenere il valore di y)

const int dim = 100;
int n = 0;

void sostituisci(char arr[dim], char x, char y){}

int main(){
    char x, y, arr[dim];
    cout << "Quanti caratteri? ";
    cin >> n;

    cout << "inserisci " << n << " caratteri: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "carattere da sostituire ";
    cin >> x;
    cout << "carattere sostituto ";
    cin >> y;

    sostituisci;{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            arr[i] = y;
}
    cout << "Array risultante: ";

    for (int i = 0; i < n; i++)
        cout << arr[i];
}