#include <iostream>
using namespace std;

int main (){

    const int dim = 100;
    int array[dim];
    int i, n;
    int somma = 0;
    int prodotto = 1;

    do{
        cout << "Inserisci quanti numeri vuoi nell'array" << endl;
        cout << "(Attenzione: il numero deve essere compreso tra 1 e " << dim << ")" << endl;
        cin >> n;
    }while(n <= 0 || n > dim);

    for(i = 0; i < n; i++){
        cout << "Inserisci un numero per l'array" << endl;
        cin >> array[i];
    }

    for(i = 0; i < n; i++){

        if(array[i] % 2 == 0){
            somma = somma + array[i];
        }
        else{
            prodotto = prodotto * array[i];
        }

    }

    cout << "La somma dei numeri pari e' " << somma << endl;
    cout << "Il prodotto dei numeri dispari e' " << prodotto << endl;

}