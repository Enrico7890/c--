#include <iostream>
using namespace std;
int main() {
int N, N1, max;
max = 0;

cout << "quanti numeri vuoi inserire" << endl;
cin >> N;

if (N<0){
    cout << "errore";
}

for (int i=0; N>i; i++){
    cout << "Inserisci un numero" << endl;
    cin >> N1;
if (N1>max){
    max = N1;
        }
    }
cout << max;
}