#include <iostream>
using namespace std;

int main (){
int mese;

cout<< "Inserisci un mese per ottenere la stagione (1-12)" << endl;
cin>> mese;

if (mese== 12 || mese ==1 || mese==2){

cout << "siamo in inverno"<< endl;
}

else if (mese >=3 && mese<=5){
cout<< "siamo in primavera"<< endl;
    }
    else if (mese >=6 && mese<=8){
cout << "siamo in estate"<< endl;
}
else if (mese>=9 && mese<=11){

cout<< "siamo in autunno"<< endl;}

else{

    cout<< "errore" << endl;

}
}

