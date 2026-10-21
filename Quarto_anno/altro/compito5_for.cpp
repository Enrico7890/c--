// Preso in input un array di N interi, ed un altro intero a parte, contare quante volte quest'ultimo viene ripetuto all'interno dell'array
#include <iostream>
using namespace std;

const int dim = 100;
// Costante globale: dim.

// Parametri formali: nessuno.
int inputn();
// Parametri formali: arr (array: puntatore passato per valore), n (int passato per valore).
int inputnumeri(int[], int);
// Parametri formali: arr (array: puntatore passato per valore), num e n (int passati per valore).
int ripetere(int[], int, int);
// Parametro formale: j (int passato per valore).
void output(int);

// main non ha parametri formali. Variabili locali: k, i, a, z.
// Parametri attuali nelle chiamate: inputnumeri(k, i), ripetere(k, a, i), output(z).
// k è passato come puntatore all'array per valore; i, a e z come interi per valore.
int main()
{
    int k[dim];
    int i = inputn();
    int a = inputnumeri(k, i);
    int z = ripetere(k, a, i);
    output(z);
}

// Nessun parametro attuale/formale. Variabile locale: n.
int inputn()
{
    int n = 0;
    do
    {
        cout << "Inserisci la dimensione " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

// Parametri attuali: k e i (da main); formali: arr e n.
// arr, puntatore al primo elemento dell'array, e n sono passati per valore.
// Variabili locali: i e num.
int inputnumeri(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "inserisci elemento array " << endl;
        cin >> arr[i];
    }
    cout << "inserisci un numero da cercare " << endl;
    int num = 0;
    cin >> num;
    return num;
}

// Parametri attuali: k, a e i (da main); formali: arr, num e n.
// arr (puntatore al primo elemento), num e n sono passati per valore.
// Variabili locali: j e i.
int ripetere(int arr[], int num, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
            j++;
    }
    return j;
}

// Parametro attuale: z (da main); parametro formale: j, passato per valore.
// Variabili locali: nessuna.
void output(int j)
{
    cout << "il numero viene ripetuto nell'array " << j << " volte" << endl;
}