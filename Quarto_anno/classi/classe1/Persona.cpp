#include "Persona.hpp"

Persona::Persona(){
	cognome="";
	nome="";
	ruolo="";
	stipendio=0;
	anzianita=0;
}

void Persona::setCognome(string c){
	cognome=c;
}

void Persona::setNome(string n){
	nome=n;
}

void Persona::setRuolo(string r){
	ruolo=r;
}

void Persona::setStipendio(float s){
	stipendio=s;
}

void Persona::setAnzianita(int a){
	anzianita=a;
}

string Persona::getCognome(){
	return cognome;
}

string Persona::getNome(){
	return nome;
}

string Persona::getRuolo(){
	return ruolo;
}

float Persona::getStipendio(){
	return stipendio;
}

int Persona::getAnzianita(){
	return anzianita;
}