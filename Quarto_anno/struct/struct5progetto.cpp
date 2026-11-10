#include "struct5.cpp"
int main(){
    Lista nozze[dim];
    int n = inputn();
    inputlista(nozze, n);
    menu(nozze, n);
}

int inputn(){
    int n = 0;
    do {
        cout << "inserisci la dimensione dell'elenco: ";
        cin >> n;
    } while (n <= 0 || n > dim);
    return n;
}

void inputlista(Lista nozze[], int n){
    for (int i = 0; i < n; i++){
        cout << "articolo: ";
        cin >> nozze[i].articolo;
        cout << "descrizione: ";
        cin >> nozze[i].descrizione;
        cout << "prezzo: ";
        cin >> nozze[i].prezzo;
    }
}

void menu(Lista nozze[], int n){
    int scelta = 0;
    do {
        cout << "1 - articoli piu' costosi di una soglia" << endl;
        cout << "2 - descrizione di un articolo" << endl;
        cout << "3 - prezzo di un articolo" << endl;
        cout << "4 - prezzo medio" << endl;
        cout << "5 - termina" << endl;
        cin >> scelta;
        switch (scelta) {
            case 1: articolocostoso(nozze, n); 
            break;
            case 2: detdescrizione(nozze, n); 
            break;
            case 3: detprezzo(nozze, n); 
            break;
            case 4: prezzomedio(nozze, n); 
            break;
            case 5: cout << "fine programma" << endl; 
            break;
            default: cout << "scelta non valida" << endl;
        }
    } while (scelta != 5);
}

void articolocostoso(Lista nozze[], int n){
    double soglia = 0;
    cout << "inserisci la soglia ";
    cin >> soglia;
    for (int i = 0; i < n; i++)
        if (nozze[i].prezzo > soglia)
            cout << nozze[i].articolo << " " << nozze[i].prezzo << endl;
}

void detdescrizione(Lista nozze[], int n){
    string nomedesc;
    cout << "inserisci l'articolo: ";
    cin >> nomedesc;
    for (int i = 0; i < n; i++)
        if (nozze[i].articolo == nomedesc){
            cout << nozze[i].descrizione << endl;
        }
    cout << "articolo non trovato" << endl;
}

void detprezzo(Lista nozze[], int n){
    string nome;
    cout << "inserisci l'articolo: ";
    cin >> nome;
    for (int i = 0; i < n; i++)
        if (nozze[i].articolo == nome){
            cout << nozze[i].prezzo << endl;
        }
    cout << "articolo non trovato" << endl;
}

void prezzomedio(Lista nozze[], int n){
    double somma = 0;
    for (int i = 0; i < n; i++)
        somma += nozze[i].prezzo;
    cout << "prezzo medio: " << somma / n << endl;
}