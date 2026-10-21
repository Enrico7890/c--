/* VOTI: un array bidimensionale (matrice) di interi, di dimensione N x M, dove le N righe rappresentano gli alunni e le M colonne
rappresentano le valutazioni nelle singole discipline.
ALUNNI: un array monodimensionale di stringhe, di dimensione N, che memorizza i nomi degli studenti. L'indice i dell'array individua
la riga i della matrice dei voti.
DISCIPLINE: Un array monodimensionale di stringhe, di dimensione M, che memorizza i nomi delle materie scolastiche.
L'indice j dell'array individua la colonna j della matrice dei voti.
Data la matrice VOTI e gli array paralleli ALUNNI e DISCIPLINE, implementare i seguenti punti:
Calcolo della media individuale con prospetto discipline: Chiesto in input il nome di un alunno,
effettuare la ricerca nell'array ALUNNI. Se lo studente è presente, stampare per ogni disciplina (recuperata dall'array DISCIPLINE)
il relativo voto memorizzato nella matrice, e infine calcolare e visualizzare la media aritmetica complessiva dell'alunno.
Se lo studente non viene trovato, mostrare un messaggio di errore.
Individuazione dello studente con la media più alta: Determinare la media aritmetica per ciascuna riga della matrice e
individuare lo studente con la media voti più alta dell'intera classe. Stampare a schermo il nome dell'alunno e il valore della sua media.
Analisi per disciplina (ricerca materia e punteggio minimo): Chiesto in input il nome di una disciplina,
effettuare la ricerca all'interno dell'array DISCIPLINE per ricavarne l'indice di colonna j.
Calcolare la media aritmetica dei voti della classe per quella specifica materia e mostrare il nome dello studente (o degli studenti) che ha ottenuto il voto più basso.
Conteggio insufficienze e dettaglio per materia: Scorrere l'intera matrice per individuare gli studenti che presentano (voto < 6).
Per ogni studente individuato, stampare il nome dell'alunno,
il numero totale di insufficienze e l'elenco delle discipline in cui è insufficiente (recuperando i nomi dall'array DISCIPLINE).*/

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

// MAIN
// Parametri attuali: nessuno.
// Parametri formali: nessuno (main non riceve argomenti).
// Variabili locali: voti, alunni, materie, ins, u, nome, materia, n, m,
//                   indalunno, indicemax, indicemat, minimo,
//                   mediaal, mediamax, mediamat.
// Parametri attuali nelle chiamate: inputdim(u); inputarray(voti, alunni, materie, n, m);
// inputnome(u); ricercaindice(alunni, n, nome); mediariga(voti, m, indalunno);
// medialta(voti, n, m, indicemax, mediamax); inputnome(u);
// ricercaindice(materie, m, materia); mediacolonna(voti, n, indicemat);
// votominimo(voti, n, indicemat); containsufficienze(voti, n, m, ins);
// outputalunno(voti, alunni, materie, n, m, indalunno, mediaal);
// outputmediaalta(alunni, indicemax, mediamax);
// outputmateria(voti, alunni, materie, n, m, indicemat, mediamat, minimo);
// outputinsufficienze(voti, alunni, materie, n, m, ins).
// main non ha parametri da passare per valore o per riferimento.
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


// INPUTDIM
// Parametri attuali (chiamate da main): u, sia per il numero di alunni sia per le discipline.
// Parametro formale: z, passato per valore.
// Variabili locali: num.
int inputdim(string z)
{
    int num = 0;
    do
    {
        cout << z;
        cin >> num;
    } while (num <= 0 || num > dim);
    return num;
}

// INPUTARRAY
// Parametri attuali (chiamata da main): voti, alunni, materie, n, m.
// Parametri formali: mat, nomi, disc, r, c.
// Variabili locali: i, j (indici dei cicli).
// Passaggio parametri: mat, nomi e disc sono array, quindi sono modificati
// tramite i rispettivi parametri array (in C++ questi parametri sono adattati
// a puntatori); r e c sono passati per valore.
void inputarray(int mat[][dim], string nomi[], string disc[], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        cout << "Inserisci il nome dell'alunno " << i << endl;
        cin >> nomi[i];
    }
    for (int j = 0; j < c; j++)
    {
        cout << "Inserisci il nome della disciplina " << j << endl;
        cin >> disc[j];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Inserisci il voto di " << nomi[i] << " in " << disc[j] << endl;
            cin >> mat[i][j];
        }
    }
}

// INPUTNOME
// Parametri attuali (chiamate da main): u per la richiesta dell'alunno e u
// per quella della disciplina.
// Parametro formale: z, passato per valore.
// Variabili locali: s.
string inputnome(string z)
{
    string s;
    cout << z << endl;
    cin >> s;
    return s;
}

// Restituisce dim se l'elemento non viene trovato.
// Parametri attuali (chiamate da main): (alunni, n, nome) e
// (materie, m, materia).
// Parametri formali: v, len, x.
// Passaggio parametri: v è un array, consultato tramite il parametro array
// (adattato a puntatore in C++); len e x sono passati per valore.
// Variabili locali: i.
int ricercaindice(string v[], int len, string x)
{
    for (int i = 0; i < len; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return dim;
}

// Calcola la media dei voti di una riga.
// Parametri attuali: da main (voti, m, indalunno); da medialta (mat, c, i).
// Parametri formali: mat, c, riga.
// Passaggio parametri: mat è un array, consultato tramite il parametro array
// (adattato a puntatore in C++); c e riga sono passati per valore.
// Variabili locali: somma, j.
double mediariga(int mat[][dim], int c, int riga)
{
    double somma = 0;
    for (int j = 0; j < c; j++)
    {
        somma += mat[riga][j];
    }
    return somma / c;
}

// Trova l'alunno con la media piu' alta.
// Parametri attuali (chiamata da main): voti, n, m, indicemax, mediamax.
// Parametri formali: mat, r, c, indice, massima.
// Passaggio parametri: mat è un array, consultato tramite il parametro array
// (adattato a puntatore in C++); r e c sono passati per valore; indice e
// massima sono passati per riferimento e ricevono i risultati.
// Variabili locali: i, media.
void medialta(int mat[][dim], int r, int c, int &indice, double &massima)
{
    massima = 0;
    indice = 0;
    for (int i = 0; i < r; i++)
    {
        double media = mediariga(mat, c, i);
        if (media > massima)
        {
            massima = media;
            indice = i;
        }
    }
}

// Calcola la media dei voti di una colonna.
// Parametri attuali (chiamata da main): voti, n, indicemat.
// Parametri formali: mat, r, col.
// Passaggio parametri: mat è un array, consultato tramite il parametro array
// (adattato a puntatore in C++); r e col sono passati per valore.
// Variabili locali: somma, i.
double mediacolonna(int mat[][dim], int r, int col)
{
    double somma = 0;
    for (int i = 0; i < r; i++)
    {
        somma += mat[i][col];
    }
    return somma / r;
}

// Trova il voto minimo di una colonna.
// Parametri attuali (chiamata da main): voti, n, indicemat.
// Parametri formali: mat, r, col.
// Passaggio parametri: mat è un array, consultato tramite il parametro array
// (adattato a puntatore in C++); r e col sono passati per valore.
// Variabili locali: minimo, i.
int votominimo(int mat[][dim], int r, int col)
{
    int minimo;
    minimo = mat[0][col];
    for (int i = 1; i < r; i++)
    {
        if (mat[i][col] < minimo)
        {
            minimo = mat[i][col];
        }
    }
    return minimo;
}

// CONTAINSUFFICIENZE (punto 4)
// Parametri attuali (chiamata da main): voti, n, m, ins.
// Parametri formali: mat, r, c, conta.
// Variabili locali: i, j (indici dei cicli).
// Passaggio parametri: mat e conta sono array; conta è modificato tramite
// il parametro array (in C++ adattato a puntatore); r e c sono passati per valore.
void containsufficienze(int mat[][dim], int r, int c, int conta[])
{
    for (int i = 0; i < r; i++)
    {
        conta[i] = 0;
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] < 6)
            {
                conta[i]++;
            }
        }
    }
}

// Parametri attuali (chiamata da main): voti, alunni, materie, n, m,
// indalunno, mediaal.
// Parametri formali: mat, nomi, disc, r, c, indal, medal.
// Passaggio parametri: mat, nomi e disc sono array, consultati tramite i
// parametri array (adattati a puntatori in C++); gli altri parametri sono
// passati per valore.
// Variabili locali: j.
void outputalunno(int mat[][dim], string nomi[], string disc[], int r, int c, int indal, double medal)
{
    if (indal >= r)
        cout << "Errore: alunno non trovato" << endl;
    else
    {
        for (int j = 0; j < c; j++)
        {
            cout << disc[j] << ": " << mat[indal][j] << endl;
        }
        cout << "Media di " << nomi[indal] << ": " << medal << endl;
    }
}

// Parametri attuali (chiamata da main): alunni, indicemax, mediamax.
// Parametri formali: nomi, indmax, medmax.
// Passaggio parametri: nomi è un array, consultato tramite il parametro array
// (adattato a puntatore in C++); indmax e medmax sono passati per valore.
// Variabili locali: nessuna.
void outputmediaalta(string nomi[], int indmax, double medmax)
{
    cout << "Alunno con la media piu' alta: " << nomi[indmax] << " (media " << medmax << ")" << endl;
}

// Parametri attuali (chiamata da main): voti, alunni, materie, n, m,
// indicemat, mediamat, minimo.
// Parametri formali: mat, nomi, disc, r, c, indmat, medmat, minimo.
// Passaggio parametri: mat, nomi e disc sono array, consultati tramite i
// parametri array (adattati a puntatori in C++); gli altri parametri sono
// passati per valore.
// Variabili locali: i.
void outputmateria(int mat[][dim], string nomi[], string disc[], int r, int c, int indmat, double medmat, int minimo)
{
    if (indmat >= c)
        cout << "Errore: disciplina non trovata" << endl;
    else
    {
        cout << "Media della classe in " << disc[indmat] << ": " << medmat << endl;
        cout << "Voto piu' basso: " << minimo << ", ottenuto da:" << endl;
        for (int i = 0; i < r; i++)
        {
            if (mat[i][indmat] == minimo)
            {
                cout << nomi[i] << endl;
            }
        }
    }
}

// Parametri attuali (chiamata da main): voti, alunni, materie, n, m, ins.
// Parametri formali: mat, nomi, disc, r, c, conta.
// Passaggio parametri: mat, nomi, disc e conta sono array, consultati tramite
// i parametri array (adattati a puntatori in C++); r e c sono passati per valore.
// Variabili locali: i, j (indici dei cicli).
void outputinsufficienze(int mat[][dim], string nomi[], string disc[], int r, int c, int conta[])
{
    for (int i = 0; i < r; i++)
    {
        if (conta[i] > 0)
        {
            cout << nomi[i] << ": " << conta[i] << " insufficienze in:" << endl;
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] < 6)
                {
                    cout << "- " << disc[j] << endl;
                }
            }
        }

    }
}