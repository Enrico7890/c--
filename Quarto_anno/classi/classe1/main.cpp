#include <iostream>
#include "Menu.hpp"
using namespace std;

int main(){
	Menu opzioni;

	int scelta;

	do{

		opzioni.stampa();
		cout<<endl<<"Indicare il numero della scelta:   ";
		cin>>scelta;
		opzioni.seleziona(scelta);

	}while(scelta!=opzioni.getExit());
}