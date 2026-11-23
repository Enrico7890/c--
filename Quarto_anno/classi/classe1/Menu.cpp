#include <iostream>
#include "Menu.hpp"
using namespace std;

Menu::Menu(){
	exit = 6;
}

int Menu::inputInt(string s){
	int x;
	do{
		cout<< s;
		cin>>x;
	}while (x<0);
	return x;
}

float Menu::inputFlt(string s){
	float x;
	do{
		cout<< s;
		cin>>x;
	}while (x<0);
	return x;
}

string Menu::inputStr(string s){
	string x;
	cout<< s;
	cin>>x;
	return x;
}

void Menu::stampaPersona(Persona p){
	cout<<"Cognome: "<<p.getCognome()<<endl;
	cout<<"Nome: "<<p.getNome()<<endl;
	cout<<"Ruolo: "<<p.getRuolo()<<endl;
	cout<<"Stipendio: "<<p.getStipendio()<<endl;
	cout<<"Anzianita': "<<p.getAnzianita()<<endl<<endl;
}

int Menu::getExit(){
	return exit;
}

void Menu::stampa(){
	system("cls");
	cout<<"Gestione Stipendi"<<endl<<endl<<endl;
	cout<<"1) Inserimento di una nuova persona"<<endl;
	cout<<"2) Persone con stipendio superiore a una soglia"<<endl;
	cout<<"3) Stipendio medio di tutte le persone"<<endl;
	cout<<"4) Persona con stipendio piu' alto e piu' basso"<<endl;
	cout<<"5) Persona con anzianita' minore e maggiore"<<endl;
	cout<<"6) Esci"<<endl;
}

void Menu::seleziona(int n){
	cout<<endl;
	switch(n){
		case 1:
			scelta1();
			break;

		case 2:
			scelta2();
			break;

		case 3:
			scelta3();
			break;

		case 4:
			scelta4();
			break;

		case 5:
			scelta5();
			break;

		case 6:
			cout<<"Arrivederci"<<endl;
			break;

		default:
			cout<<"Scelta indicata non presente!"<<endl;
			break;
	}

	cout<<endl;
	system("pause");
}

void Menu::scelta1(){
	string cognome, nome, ruolo;
	float stipendio;
	int anzianita;

	cout<<"Inserimento di una nuova persona"<<endl<<endl;
	cognome = inputStr("Inserisci il cognome: ");
	nome = inputStr("Inserisci il nome: ");
	ruolo = inputStr("Inserisci il ruolo: ");
	stipendio = inputFlt("Inserisci lo stipendio: ");
	anzianita = inputInt("Inserisci l'anzianita': ");

	Persona p;
	p.setCognome(cognome);
	p.setNome(nome);
	p.setRuolo(ruolo);
	p.setStipendio(stipendio);
	p.setAnzianita(anzianita);

	if (T.addPersona(p))
		cout<<"Persona inserita in tabella"<<endl;
	else
		cout<<"Tabella piena: impossibile inserire altre persone"<<endl;
}

void Menu::scelta2(){
	float soglia;
	int trovati=0;

	cout<<"Persone con stipendio superiore a una soglia"<<endl<<endl;
	soglia = inputFlt("Inserisci la soglia: ");
	for(int i=0; i<T.getPos(); i++){
		if (T.getPersona(i).getStipendio() > soglia){
			stampaPersona(T.getPersona(i));
			trovati++;
		}
	}
	if (trovati==0)
		cout<<"Nessuna persona ha uno stipendio superiore a "<<soglia<<endl;
}

void Menu::scelta3(){
	cout<<"Stipendio medio di tutte le persone"<<endl<<endl;
	if (T.getPos()>0)
		cout<<"Lo stipendio medio e': "<<T.mediaStipendi()<<endl;
	else
		cout<<"Impossibile calcolare la media: tabella vuota"<<endl;
}

void Menu::scelta4(){
	cout<<"Persona con stipendio piu' alto e piu' basso"<<endl<<endl;
	if (T.getPos()>0){
		cout<<"Stipendio piu' alto:"<<endl;
		stampaPersona(T.getPersona(T.indiceStipendioMax()));
		cout<<"Stipendio piu' basso:"<<endl;
		stampaPersona(T.getPersona(T.indiceStipendioMin()));
	}
	else
		cout<<"Tabella vuota"<<endl;
}

void Menu::scelta5(){
	cout<<"Persona con anzianita' minore e maggiore"<<endl<<endl;
	if (T.getPos()>0){
		cout<<"Anzianita' maggiore:"<<endl;
		stampaPersona(T.getPersona(T.indiceAnzianitaMax()));
		cout<<"Anzianita' minore:"<<endl;
		stampaPersona(T.getPersona(T.indiceAnzianitaMin()));
	}
	else
		cout<<"Tabella vuota"<<endl;
}