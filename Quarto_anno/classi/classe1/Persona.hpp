#include <string>
using namespace std;

class Persona{

	private:
		string cognome;
		string nome;
		string ruolo;
		float stipendio;
		int anzianita;

	public:
		Persona();
		void setCognome(string);
		void setNome(string);
		void setRuolo(string);
		void setStipendio(float);
		void setAnzianita(int);
		string getCognome();
		string getNome();
		string getRuolo();
		float getStipendio();
		int getAnzianita();
};