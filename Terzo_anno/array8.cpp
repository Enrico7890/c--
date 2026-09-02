#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main (){

    const int dim = 100;
    int array[dim];
    int i, n;
    int x;

    do{
        cout << "Inserisci quanti numeri vuoi nell'array" << endl;
        cout << "(Attenzione: il numero deve essere compreso tra 1 e " << dim << ")" << endl;
        cin >> n;
    }while(n <= 0 || n > dim);

    for(i = 0; i < n; i++){
        cout << "Inserisci un numero per l'array" << endl;
        cin >> array[i];
    }

    srand(time(0));
    x = rand() % 10 + 1;

    cout << "Il numero casuale generato e' " << x << endl;

    for(i = 0; i < n; i++){
        array[i] = array[i] + x;
    }

    cout << "Il nuovo array e' " << endl;

    for(i = 0; i < n; i++){
        cout << array[i] << endl;
    }

}