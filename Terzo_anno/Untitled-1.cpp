#include <iostream>
using namespace std; 

int main (){
int numero;
cout << "inserisci un numero da 1 a 3"<< endl;
cin >> numero;

switch (numero){

case 1: 
 
cout<< "colore verde" << endl;
break;

case 2:

cout<< "colore rosso" << endl;
break;
case 3:

cout << "colore blu"<< endl;
break;
default: 

cout<< "errore"<< endl;
}

}