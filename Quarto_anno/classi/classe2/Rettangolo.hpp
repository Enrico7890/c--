//Utilizzando l'approccio OOP, scrivere il codice nel linguaggio C++ che risolva il seguente problema:
//Prese in input la base e l'altezza di un RETTANGOLO calcolare la sua Area e il suo perimetro.

class Rettangolo{

	private:
		float base;
		float altezza;

	public:
		Rettangolo();
		void setBase(float);
		void setAltezza(float);
		float getBase();
		float getAltezza();
		float area();
		float perimetro();
};