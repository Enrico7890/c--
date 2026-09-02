#include <iostream>
using namespace std;
 
/* Preso in input un array di N caratteri, determinare il carattere che precede tutti gli altri 
in ordine alfabetico e quello che invece li segue tutti */
 
const int dim = 100;
 
int inputN();
void inputarr(char [], int);
void minmax(char [], int, char&, char&);
void output(char, char);
 
int main(){
    int n = 0;
    char minchar, maxchar;
    char arr[dim];
 
    n = inputN();
 
    inputarr(arr, n);
 
    minmax(arr, n, minchar, maxchar);
 
    output(minchar, maxchar);
}
 
int inputN(){
    int n = 0;
    do{
        cout << "Inserisci dimensione dell'array " << endl;
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}
 
void inputarr(char arr[], int n){
    for (int i = 0; i < n; i++){
        cout << "Inserisci elemento dell'array: " << endl;
        cin >> arr[i];
    }
}
 
void minmax(char arr[], int n, char& min_char, char& max_char){
    min_char = arr[0];
    max_char = arr[0];
 
    for (int i = 0; i < n; i++){
        if (arr[i] < min_char)
            min_char = arr[i];
        if (arr[i] > max_char)
            max_char = arr[i];
    }
}
 
void output(char min_char, char max_char){
    cout << "Risultati:" << endl;
    cout << "Carattere che precede tutti gli altri " << min_char << endl;
    cout << "Carattere che segue tutti gli altri " << max_char << endl;
}