#include <iostream>
using namespace std;

int main() {
    int array [10], somma = 0;

    for (int i = 0; i < 10; i++){
        cout << "inserisci un numero" << endl;
        cin >> array [i];
        somma+=array [i];
    }
    
    cout << "la somma e' "<< somma << endl;

}