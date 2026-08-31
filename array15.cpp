#include <iostream>
using namespace std;
//Preso in input un array di interi, calcolare la media dei suoi elementi e successivamente creare due nuovi Array: 
//il primo con i valori Minori della media trovata, il secondo con i valori maggiori della media trovata.

const int dim = 100;

int main() {

    int array[dim], arraymin[dim], arraymag[dim];
    int cmin = 0, cmag = 0;
    float media = 0;
    int n;

    do {
        cout << "Quanto e' lungo il tuo array? ";
        cin >> n;
    } while (n <= 0 || n > dim);

    for (int i = 0; i < n; i++) {
        cout << "Inserisci il numero " << i + 1 << ": ";
        cin >> array[i];
    }

    for (int i = 0; i < n; i++)
        media += array[i];
    media /= n;

    cout << "Media " << media << endl;

    for (int i = 0; i < n; i++) {
        if (array[i] < media)
            arraymin[cmin++] = array[i];
        else if (array[i] > media)
            arraymag[cmag++] = array[i];
    }

    cout << "Valori minori della media " << media << endl;
    for (int i = 0; i < cmin; i++)
        cout << arraymin[i] << " ";

    cout << "Valori maggiori della media " << media << endl;
    for (int i = 0; i < cmag; i++)
        cout << arraymag[i] << " ";
}