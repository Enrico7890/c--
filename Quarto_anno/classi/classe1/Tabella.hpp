#include "Persona.hpp"

const int dim = 10;

class Tabella{

	private:
		Persona tab[dim];
		int pos;	//pos indica nell'array l'ultima posizione libera

	public:
		Tabella();
		int getPos();
		Persona getPersona(int );
		bool addPersona(Persona );
		float mediaStipendi();
		int indiceStipendioMax();
		int indiceStipendioMin();
		int indiceAnzianitaMax();
		int indiceAnzianitaMin();
};
