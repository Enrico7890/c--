#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int dim = 100;

int inputdim(string);
void inputmatrice(int[][dim], int, int);
void minmax(int[][dim], int&, int&, int, int);
int casuale(int, int);
void nuovoarr(int[][dim], int[][dim], int, int, int);
void output(int[][dim], int[][dim], int, int, int);
