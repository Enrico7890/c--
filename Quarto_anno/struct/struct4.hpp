#include <iostream>
#include <string>
using namespace std; 

const int dim = 100;

struct Alunno {
    string nome;
    string cognome;
    double voto;
};

int inputn(string);
void inputarray(Alunno alunni[], int);
void votoaltobasso(Alunno alunni[], int);
void determinatovoto(Alunno alunni[], int);
void votomedio(Alunno alunni[], int);