/*Presi in input una successione di numeri interi che termina quando viene inserito -1,
determinare per ciascuno di essi il suo quadrato se il numero stesso è pari altrimenti il suo cubo*/

#include <iostream>
using namespace std;

int main (){
int N;

while (true){
    cout << "inserisci il numero"<< endl;   
    cin >> N;
if (N==-1){
    cout<<"Hai inserito il numero corretto"<< endl;
    break; 
    }
if (N % 2 == 0){
    cout <<"il quadrato e'" << N*N<< endl;
    }
else{
    cout<< "il cubo e'"<< N*N*N<< endl;
        }
    }
}