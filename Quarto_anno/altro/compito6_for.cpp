// Preso in input un array di N reali, calcolare la media dei suoi elementi
// e creare due nuovi array: uno con i valori minori della media e uno con i
// valori maggiori.
#include <iostream>
using namespace std;

const int dim = 100;
// Costante globale: dim.

// inputn: nessun parametro formale o attuale; locale: n.
// Passaggio dei parametri: non applicabile.
int inputn();
// inputnumeri: formali arr, n; attuali nel main k, n. Entrambi per valore
// (arr è un puntatore); locale: i.
void inputnumeri(double[], int);
// media: formali arr, n; attuali nel main k, n. Entrambi per valore
// (arr è un puntatore); locali: somma, i.
double media(double[], int);
// separa: formali arr, n, m, minori, maggiori; attuali nel main
// k, n, m, minori, maggiori. Tutti per valore (gli array sono puntatori);
// locali: nMinori, nMaggiori, i. Gli array puntati vengono modificati.
int separa(double[], int, double, double[], double[]);
// output: formali m, minori, nMinori, maggiori, nMaggiori; attuali nel main
// gli omonimi. Tutti per valore (gli array sono puntatori); locale: i.
void output(double, double[], int, double[], int);

// main: nessun parametro formale o attuale. Variabili locali: k, minori,
// maggiori, n, m, nMinori, nMaggiori. Nessun passaggio di parametri.
int main()
{
	double k[dim], minori[dim], maggiori[dim];
	int n = inputn();
	inputnumeri(k, n);
	double m = media(k, n);
	int nMinori = separa(k, n, m, minori, maggiori);
	int nMaggiori = n - nMinori;
	output(m, minori, nMinori, maggiori, nMaggiori);
}

int inputn()
{
	// Variabile locale: n; nessun parametro.
	int n = 0;
	do
	{
		cout << "Inserisci la dimensione" << endl;
		cin >> n;
	} while (n <= 0 || n > dim);
	return n;
}

void inputnumeri(double arr[], int n)
{
	// Parametri formali arr, n (attuali k, n dal main), passati per valore;
	// arr è un puntatore. Variabile locale: i.
	for (int i = 0; i < n; i++)
	{
		cout << "Inserisci elemento array" << endl;
		cin >> arr[i];
	}
}

double media(double arr[], int n)
{
	// Parametri formali arr, n (attuali k, n dal main), passati per valore;
	// arr è un puntatore. Variabili locali: somma, i.
	double somma = 0;
	for (int i = 0; i < n; i++)
		somma += arr[i];
	return somma / n;
}

int separa(double arr[], int n, double m, double minori[], double maggiori[])
{
	// Parametri formali arr, n, m, minori, maggiori (attuali k, n, m,
	// minori, maggiori dal main): tutti per valore; gli array sono puntatori.
	// Variabili locali: nMinori, nMaggiori, i. Scrive negli array puntati.
	int nMinori = 0, nMaggiori = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < m)
			minori[nMinori++] = arr[i];
		else if (arr[i] > m)
			maggiori[nMaggiori++] = arr[i];
	}
	return nMinori;
}

void output(double m, double minori[], int nMinori, double maggiori[], int nMaggiori)
{
	// Parametri formali m, minori, nMinori, maggiori, nMaggiori (attuali
	// omonimi dal main), tutti per valore; gli array sono puntatori.
	// Variabile locale: i.
	cout << "Media: " << m << endl;
	cout << "Valori minori della media: ";
	for (int i = 0; i < nMinori; i++)
		cout << minori[i] << " ";
	cout << endl << "Valori maggiori della media: ";
	for (int i = 0; i < nMaggiori; i++)
		cout << maggiori[i] << " ";
	cout << endl;
}
