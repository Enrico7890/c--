#include <iostream>
#include <string>
using namespace std;

const int dim = 100;
 
int inputn();
void inputdati(string nome[], int assenze[], int n);
void maggioreminore(string nome[], int assenze[], int n, string &piuass, string &menoass, int &indicepiuass, int &indicemenoass);
void assenzeclasse(string nome[], int assenze[], int n, int &assclasse);
void assenzemedie(string nome[], int assenze[], int n, float &assmedie);
void nomeassenzeminoremedia(string nome[], int assenze[], int n, float assmedie);
 
int main()
{
    int n = inputn();
    
    string nome[dim];
    int assenze[dim];
    
    inputdati(nome, assenze, n);
    
    string piuass, menoass;
    int indicepiuass, indicemenoass;
    maggioreminore(nome, assenze, n, piuass, menoass, indicepiuass, indicemenoass);
    
    int assclasse;
    assenzeclasse(nome, assenze, n, assclasse);
    
    float assmedie;
    assenzemedie(nome, assenze, n, assmedie);
    
    nomeassenzeminoremedia(nome, assenze, n, assmedie);
}
 
int inputn()
{
    int n;
    do{
    cout << "Inserisci il numero di studenti: ";
    cin >> n;
  } while (n < 0|| n > dim);
    return n;
}
 
void inputdati(string nome[], int assenze[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nome " << (i + 1) << ": ";
        cout << "Assenze: ";
        cin >> assenze[i];
    }
}
 
void maggioreminore(string nome[], int assenze[], int n, string &piuass, string &menoass, int &indicepiuass, int &indicemenoass)
{
    indicepiuass = 0;
    indicemenoass = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (assenze[i] > assenze[indicepiuass])
            indicepiuass = i;
        if (assenze[i] < assenze[indicemenoass])
            indicemenoass = i;
    }
    
    piuass = nome[indicepiuass];
    menoass = nome[indicemenoass];
    
    cout << "Max assenze: " << piuass << " (" << assenze[indicepiuass] << endl;
    cout << "Min assenze: " << menoass << " (" << assenze[indicemenoass]  << endl;
}
 
void assenzeclasse(string nome[], int assenze[], int n, int &assclasse)
{
    assclasse = 0;
    for (int i = 0; i < n; i++)
        assclasse += assenze[i];
    
    cout << "Totale assenze: " << assclasse << "\n";
}
 
void assenzemedie(string nome[], int assenze[], int n, float &assmedie)
{
    int tot = 0;
    for (int i = 0; i < n; i++)
        tot += assenze[i];
    
    assmedie = (float)tot / n;
    cout << "Media assenze: " << assmedie << "\n";
}
 
void nomeassenzeminoremedia(string nome[], int assenze[], int n, float assmedie)
{
    cout << "\nStudenti sotto media:\n";
    for (int i = 0; i < n; i++)
    {
        if (assenze[i] < assmedie)
            cout << "- " << nome[i] << " (" << assenze[i] << ")\n";
    }
}