#include "Tabella.hpp"

Tabella::Tabella(){
	pos=0;
}

int Tabella::getPos(){
	return pos;
}

Persona Tabella::getPersona(int x){
	return tab[x];
}

bool Tabella::addPersona(Persona p){
	bool flag=false;
	if (pos<dim){
		tab[pos]=p;
		pos++;
		flag=true;
	}
	return flag;
}

// Chiamare solo con pos>0: altrimenti divisione per zero.
float Tabella::mediaStipendi(){
	float s=0;
	for(int i=0; i<pos; i++)
		s += tab[i].getStipendio();
	return s/pos;
}

int Tabella::indiceStipendioMax(){
	int imax=0;
	for(int i=1; i<pos; i++)
		if (tab[i].getStipendio() > tab[imax].getStipendio())
			imax=i;
	return imax;
}

int Tabella::indiceStipendioMin(){
	int imin=0;
	for(int i=1; i<pos; i++)
		if (tab[i].getStipendio() < tab[imin].getStipendio())
			imin=i;
	return imin;
}

int Tabella::indiceAnzianitaMax(){
	int imax=0;
	for(int i=1; i<pos; i++)
		if (tab[i].getAnzianita() > tab[imax].getAnzianita())
			imax=i;
	return imax;
}

int Tabella::indiceAnzianitaMin(){
	int imin=0;
	for(int i=1; i<pos; i++)
		if (tab[i].getAnzianita() < tab[imin].getAnzianita())
			imin=i;
	return imin;
}