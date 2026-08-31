#include <iostream>
using namespace std;

int main() {
    int N, array[100], x;

    cout << "Quanti numeri";
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> array[i];
    }

    cout << "Inserisci x ";
    cin >> x;

    for(int i = 0; i < N; i++){
        array[i] = array[i] + x;
    }

    for(int i = 0; i < N; i++){
        cout << array[i];
    }
}