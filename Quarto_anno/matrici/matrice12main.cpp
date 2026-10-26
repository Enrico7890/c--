#include "matrice12.hpp"

int main(){
    double mat [dim][dim];
    double vmain [dim];
    int zmain[dim];
    string u = "Inserisci righe ";
    int n = inputdim(u);
    u = "inserisci colonne";
    int m = inputdim(u);
    inputmatrice(mat, n, m);
    popolazionev(mat, vmain, n, m);
    popolazionez(mat, vmain, zmain, n, m);
    output(vmain, zmain, n);
}