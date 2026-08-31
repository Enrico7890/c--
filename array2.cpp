#include <iostream>
using namespace std;
int main() {
    int array [10], n;

    for (int i = 0; i < 10; i++){
        cout << "inserisci un numero" << i + 1 << endl;
        cin >> array [i];
    }

    for (int i = 0; i < 10; i++){
    cout << "inserisci un numero da cercare" << endl;
    cin >> n;

    if (array [i] == n){
    cout << "numero trovato alla posizione " << i << endl;
    }

    }
}