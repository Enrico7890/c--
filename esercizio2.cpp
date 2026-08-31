#include <iostream>
using namespace std;
int main (){
int N, N2;
cout << "inserisci quanti numeri vuoi inserire"<< endl;   
cin >> N;

for (int i=0; i<=N;i++){
    cout << "inserisci un numero intero"<< endl;
    cin >> N2;
 if (N2 % 2==0){
    cout << "il numero " << N2 << " e' pari" << endl;
   } 
 else {
    cout << "il numero " << N2 << " e' dispari" << endl;
      }
   }
}