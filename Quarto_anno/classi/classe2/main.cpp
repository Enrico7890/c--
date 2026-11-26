#include <iostream>
#include "Rettangolo.hpp"
using namespace std;

int main(){
	Rettangolo r;
	float b, h;

	cout<<"Inserisci la base: ";
	cin>>b;
	cout<<"Inserisci l'altezza: ";
	cin>>h;

	r.setBase(b);
	r.setAltezza(h);

	cout<<"Area: "<<r.area()<<endl;
	cout<<"Perimetro: "<<r.perimetro()<<endl;
}