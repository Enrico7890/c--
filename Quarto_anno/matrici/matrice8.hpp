#include <iostream>
#include <string>
using namespace std;

const int dim = 100;

int inputn(string);
void inputmatrice(char [][dim], int, int);
char minuscola(char);
void minmax(char [][dim], int, int, char &, char &);
void output(char [][dim], int, int, string);