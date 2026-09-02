#include <iostream>
#include <string>
using namespace std;
 
const int dim = 100;
 
int inputn();
void inputarr(string [], int [], int);
void giovaneanziano(string [], int [], int, int&, int&, int&, int&);
void output(string [], int [], int, int, int, int, int);
 
int main() {
    int n, etanziano, etagiovane, indicegiovane, indiceanziano;
    string nomi[dim];
    int eta[dim];
 
    n = inputn();
    inputarr(nomi, eta, n);
    giovaneanziano(nomi, eta, n, indicegiovane, indiceanziano, etagiovane, etanziano);
    output(nomi, eta, n, indicegiovane, indiceanziano, etagiovane, etanziano);
}
 
int inputn() {
    int n = 0;
    do {
        cout << "Inserisci la dimensione del tuo array: ";
        cin >> n;
    } while (n <= 0 || n >= dim);
    return n;
}
 
void inputarr(string nomi[], int eta[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: ";
        cin >> nomi[i];
        cout << "Eta: ";
        cin >> eta[i];
    }
}
 
void giovaneanziano(string nomi[], int eta[], int n, int& indicegiovane, int& indiceanziano, int& etagiovane, int& etanziano) {
    indicegiovane = 0;
    etagiovane = eta[0];
    indiceanziano = 0;
    etanziano = eta[0];
 
    for (int i = 1; i < n; i++) {
        if (eta[i] < etagiovane) {
            etagiovane = eta[i];
            indicegiovane = i;
        }
        if (eta[i] > etanziano) {
            etanziano = eta[i];
            indiceanziano = i;
        }
    }
}
 
void output(string nomi[], int eta[], int n, int indicegiovane, int indiceanziano, int etagiovane, int etanziano) {
    cout << "Persona piu giovane: " << nomi[indicegiovane] << etagiovane << " anni" << endl;
    cout << "Persona piu anziana: " << nomi[indiceanziano]  << etanziano << " anni" << endl;
}