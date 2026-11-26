#include <iostream>
#include "Tripla.hpp"
using namespace std;

int main(){
	Tripla t;
	float x;
	int scelta;

	cout<<"Inserisci il primo valore: ";
	cin>>x;
	t.setA(x);
	cout<<"Inserisci il secondo valore: ";
	cin>>x;
	t.setB(x);
	cout<<"Inserisci il terzo valore: ";
	cin>>x;
	t.setC(x);

	do{
		cout<<endl<<"1) Somma"<<endl;
		cout<<"2) Prodotto"<<endl;
		cout<<"3) Media"<<endl;
		cout<<"4) Esci"<<endl;
		cout<<"Scelta: ";
		cin>>scelta;

		switch(scelta){
			case 1:
				cout<<"Somma: "<<t.somma()<<endl;
				break;
			case 2:
				cout<<"Prodotto: "<<t.prodotto()<<endl;
				break;
			case 3:
				cout<<"Media: "<<t.media()<<endl;
				break;
			case 4:
				cout<<"Arrivederci"<<endl;
				break;
			default:
				cout<<"Scelta non presente"<<endl;
		}
	}while(scelta!=4);
}