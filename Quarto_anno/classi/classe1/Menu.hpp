#include <string>
#include "Tabella.hpp"
using namespace std;

class Menu{

	private:
		Tabella T;
		int exit;
		void scelta1();
		void scelta2();
		void scelta3();
		void scelta4();
		void scelta5();
		int inputInt(string );
		float inputFlt(string );
		string inputStr(string );
		void stampaPersona(Persona );

	public:
		Menu();
		int getExit();
		void stampa();
		void seleziona(int );
};
