#include "matrice11.hpp"

int main()
{
    int voti[dim][dim];
    string alunni[dim];
    string materie[dim];
    int ins[dim];
    string u, nome, materia;
    int n, m;
    int indalunno, indicemax, indicemat, minimo;
    double mediaal, mediamax, mediamat;

    u = "Inserisci il numero di alunni ";
    n = inputdim(u);
    u = "Inserisci il numero di discipline ";
    m = inputdim(u);
    inputarray(voti, alunni, materie, n, m);

    u = "Inserisci il nome dell'alunno da cercare ";
    nome = inputnome(u);
    indalunno = ricercaindice(alunni, n, nome);
    mediaal = mediariga(voti, m, indalunno);

    medialta(voti, n, m, indicemax, mediamax);

    u = "Inserisci il nome della disciplina da analizzare ";
    materia = inputnome(u);
    indicemat = ricercaindice(materie, m, materia);
    mediamat = mediacolonna(voti, n, indicemat);
    minimo = votominimo(voti, n, indicemat);

    containsufficienze(voti, n, m, ins);

    outputalunno(voti, alunni, materie, n, m, indalunno, mediaal);
    outputmediaalta(alunni, indicemax, mediamax);
    outputmateria(voti, alunni, materie, n, m, indicemat, mediamat, minimo);
    outputinsufficienze(voti, alunni, materie, n, m, ins);
}