/*
Scrivere un programma in C++, utilizzando la OOP, che gestisca una tabella di Persone
contenente, per ogni riga, le seguenti informazioni:
 - cognome (si tratta di una stringa che rappresenta il cognome dello studente)
 - nome (si tratta di una stringa che rappresenta il nome dello studente)
 - età (si tratta di un valore numerico che indica l'età della persona)
 - altezza (si tratta di un valore numerico che indica l'altezza della persona)
Si prevedano:
 - una classe che implementi la singola riga della tabella,
 - un'altra che implementi l'array di tutte le righe della tabella
 - un'ultima classe che permetta le operazioni di I/O
Il programma dovrà eseguire le seguenti operazioni:
 - inserimento di N persone nella tabella;
 - visualizzazione di tutte le persone contenute nella tabella;
 - calcolo della media delle età di tutte le persone;
 - calcolo della media delle altezze di tutte le persone.
*/


#include <iostream>
#include <string>
using namespace std;

const int dim=10;

//****************DICHIARAZIONE CLASSE PERSONA**************//
class Persona{

	private:	
		string cognome;
		string nome;
		int eta;
		float altezza;
	
	public:	
		Persona();
		void setCognome(string );
		void setNome(string );
		void setEta(int );
		void setAltezza(float );
		string getCognome();
		string getNome();
		int getEta();
		float getAltezza();
};

//****************DICHIARAZIONE CLASSE TABELLA**************//
class Tabella{
	
	private:
		Persona tab[dim];		
		int pos; 				//pos indica nell'array l'ultima posizione libera 

	public:	
		Tabella();
		void setCognome(int , string );
		void setNome(int , string );
		void setEta(int , int );
		void setAltezza(int , float );
		string getCognome(int );
		string getNome(int );
		int getEta(int );
		float getAltezza(int );
		int getPos();
		bool addPersona(string, string, int, float);
		float mediaEta();
		float mediaAltezza();
		
		
};

//****************DICHIARAZIONE CLASSE MENU**************//
class menu{
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
	
	public:
		menu();
		int getExit();
		void stampa();
		void seleziona(int );	
};


//**********DEFINIZIONE PROGRAMMA PRINCIPALE**********//

int main(){
	menu opzioni;
	
	int scelta;
	
	do{
		
		opzioni.stampa();
		cout<<endl<<"Indicare il numero della scelta:   ";
		cin>>scelta;
		opzioni.seleziona(scelta);
		
	}while(scelta!=opzioni.getExit());
	
	system("pause");
	
}

//**********DEFINIZIONE METODI CLASSE PERSONA**********//
Persona::Persona(){
	cognome="";
	nome="";
	eta=0;
	altezza=0;
}

void Persona::setCognome(string c){
	cognome=c;
}

void Persona::setNome(string n){
	nome=n;
}

void Persona::setEta(int e){
	eta=e;
}

void Persona::setAltezza(float a){
	altezza=a;
}

string Persona::getCognome(){
	return cognome;
}

string Persona::getNome(){
	return nome;
}

int Persona::getEta(){
	return eta;
}

float Persona::getAltezza(){
	return altezza;
}


//**********DEFINIZIONE METODI CLASSE TABELLA**********//
Tabella::Tabella(){
	pos=0;
}

void Tabella::setCognome(int x, string c){
	tab[x].setCognome(c);
}

void Tabella::setNome(int x, string n){
	tab[x].setNome(n);
}

void Tabella::setEta(int x, int e){
	tab[x].setEta(e);
}

void Tabella::setAltezza(int x, float a){
	tab[x].setAltezza(a);
}

string Tabella::getCognome(int x){
	return tab[x].getCognome();	
}

string Tabella::getNome(int x){
	return tab[x].getNome();
}

int Tabella::getEta(int x){
	return tab[x].getEta();
}

float Tabella::getAltezza(int x){
	return tab[x].getAltezza();
}

int Tabella::getPos(){
	return pos;
}

bool Tabella::addPersona(string c, string n, int e, float a){
	bool flag=false;
	if (pos<dim){
		tab[pos].setCognome(c);
		tab[pos].setNome(n);
		tab[pos].setEta(e);
		tab[pos].setAltezza(a);
		pos++;
		flag=true;
	}
	return flag;
}

float Tabella::mediaEta(){
	float med;
	int s=0;
	for(int i=0; i<pos; i++)		
		s += tab[i].getEta();
	if (pos>0)
		med = (float) s/pos;
	else
		med = 0;
	return med;
}

float Tabella::mediaAltezza(){
	float med;
	float s=0.0;
	for(int i=0; i<pos; i++)		
		s += tab[i].getAltezza();
	if (pos>0)
		med = s/pos;
	else
		med = 0;
	return med;
}


//**********DEFINIZIONE METODI CLASSE MENU**********//
menu::menu(){
	exit = 6;
}

int menu::inputInt(string s){
	int x;
	do{
		cout<< s;
		cin>>x;
	}while (x<0);
	return x;
}
	
float menu::inputFlt(string s){
	float x;
	do{
		cout<< s;
		cin>>x;
	}while (x<0);
	return x;
}

string menu::inputStr(string s){
	string x;
	cout<< s;
	cin>>x;
	return x;
}

int menu::getExit(){
	return exit;
}

void menu::stampa(){
	system("cls");
	cout<<"Elenco di Persone"<<endl<<endl<<endl;
	cout<<"1) Inserimento di nuove persone nell'Elenco"<<endl;
	cout<<"2) Informazioni delle persone in Elenco"<<endl;
	cout<<"3) Media delle Età di tutte le persone"<<endl;
	cout<<"4) Media delle Altezze di tutte le persone"<<endl;
	cout<<"5) Numero di persone presenti in elenco"<<endl;
	cout<<"6) Esci"<<endl;
	//cout<<endl<<"Inserire il numero corrispondente alla scelta:   ";
}

void menu::seleziona(int n){
//	system("cls");
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

void menu::scelta1(){
	string surname, name;
	int age;
	float height;
	int n, i=0;
	bool flag = true;
	
	cout<<"Inserimento di nuove persone nell'Elenco"<<endl<<endl;
	n = inputInt("Inserisci il numero di persone da aggiungere all'elenco\n");
	do {
		cout<<"Inserisci Persona nr."<<i+1<<endl;
		cout<<"----------"<<endl;
		surname = inputStr("Inserisci il cognome: ");
		name = inputStr("Inserisci il nome: ");
		age = inputInt("Inserisci l'eta'': ");
		height = inputFlt("Inserisci l'altezza: ");
		if (T.addPersona(surname, name, age, height)){
			cout << "Persona inserita in elenco" << endl;
			i++;
		} 
		else {
			cout << "Tabella piena: impossibile inserire altre persone" << endl;
			flag=false;
		}	
	}
	while((i<n)&&(flag));
}

void menu::scelta2(){
	string surname, name;
	int age;
	float height;
	int n, i=0;
	bool flag = true;
	
	cout<<"Informazioni delle persone in Elenco"<<endl<<endl;
	n = T.getPos();
	if (n!=0){
		for(i=0;i<n;i++)
		{
			cout<<"Persona nr."<<i+1<<endl;
			cout<<"----------"<<endl;
			cout<<"Cognome: "<<T.getCognome(i)<<endl;
			cout<<"Nome: "<<T.getNome(i)<<endl;
			cout<<"Eta': "<<T.getEta(i)<<endl;
			cout<<"Altezza: "<<T.getAltezza(i)<<endl<<endl;
		}	
	}
	else
		cout<<"Elenco vuoto: non ci sono persone!"<<endl<<endl;
}

void menu::scelta3(){
	
	cout<<"Media delle Età di tutte le persone"<<endl<<endl;
	float m = T.mediaEta();
	if (m>0)
		cout<<"La media delle eta' di tutte le persone è': "<<m<<endl<<endl;
	else
		cout<<"Impossibile calcolare la media: elenco vuoto"<<endl<<endl;
}

void menu::scelta4(){
	
	cout<<"Media delle Altezze di tutte le persone"<<endl<<endl;
	float m = T.mediaAltezza();
	if (m>0)
		cout<<"La media delle altezze di tutte le persone è': "<<m<<endl<<endl;
	else
		cout<<"Impossibile calcolare la media: elenco vuoto"<<endl<<endl;
}

void menu::scelta5(){
	cout<<"Numero di persone presenti in Elenco"<<endl;
	cout<<T.getPos()<<endl<<endl;
}

