#include <iostream>
using namespace std;

//Preso in input un array di N caratteri, ed un altro carattere a parte, 
//contare quante volte quest'ultimo viene ripetuto all'interno dell'array.

const int dim = 100;

int main (){
char array [dim];
char a;
int n, k = 0;

do {

cout << "Quanto e' lungo il tuo array" << endl;
cin >> n;
} while (n <= 0 || n > dim);

cout << "inserisci il carattere da trovare " << endl;
cin >> a;

for (int i = 0; i < n; i++){

    cout << "Inserisci un carattere " << endl;
    cin >> array[i];

}
for (int i = 0; i < n; i++){
    if (array [i] == a){
        cout << "carattere trovato! " << endl;
        k++;
    }
}
    cout << "il carattere e' presente " << k << " volte" << endl;
}