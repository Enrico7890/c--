#include "matrice13.hpp"
int main(){
    int mat[dim][dim];
    int mat2[dim][dim];
    int rarrmat[dim];
    int carrmat[dim];
    string u = "inserisci righe ";
    int n = inputdim(u);
    u = "inserisci colonne ";
    int m = inputdim(u);
    u = "prima matrice";
    inputmatrice(mat, n, m, u);
    u = "seconda matrice ";
    inputmatrice(mat2, n, m, u);
    popolazioner(mat, mat2, rarrmat, n, m);
    popolazionec(mat, mat2, carrmat, n, m);
    u = "output primo array r ";
    output(rarrmat, n, u);
    u = "output secondo array c";
    output(carrmat, m, u);
}
