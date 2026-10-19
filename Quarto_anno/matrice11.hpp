#include "matrice11main.cpp"

#include <iostream>
#include <string>

using namespace std;

const int dim = 100;

int inputdim(string);
void inputarray(int[][dim], string[], string[], int, int);
string inputnome(string);
int ricercaindice(string[], int, string);
double mediariga(int[][dim], int, int);
void medialta(int[][dim], int, int, int &, double &);
double mediacolonna(int[][dim], int, int);
int votominimo(int[][dim], int, int);
void containsufficienze(int[][dim], int, int, int[]);
void outputalunno(int[][dim], string[], string[], int, int, int, double);
void outputmediaalta(string[], int, double);
void outputmateria(int[][dim], string[], string[], int, int, int, double, int);
void outputinsufficienze(int[][dim], string[], string[], int, int, int[]);