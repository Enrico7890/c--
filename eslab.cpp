#include <iostream>
using namespace std;
 
const int MAX = 100;
 
void menu();
void registra(double arr[], int &n);
void estremi(double arr[], int n);
void statistiche(double arr[], int n);
void irrigazione(double arr[], int n);
void stato(double arr[], int n);
 
int main() {
    double umidita[MAX];
    int n = 0;
    int scelta;
    
    do {
        menu();
        cin >> scelta;
        
        switch(scelta) {
            case 1:
                registra(umidita, n);
                break;
            case 2:
                if(n == 0) cout << "Errore: registra prima dati" << endl;
                else estremi(umidita, n);
                break;
            case 3:
                if(n == 0) cout << "Errore: registra prima dati" << endl;
                else statistiche(umidita, n);
                break;
            case 4:
                if(n == 0) cout << "Errore: registra prima dati" << endl;
                else irrigazione(umidita, n);
                break;
            case 5:
                if(n == 0) cout << "Errore: registra prima dati" << endl;
                else stato(umidita, n);
                break;
            case 6:
                cout << "Arrivederci" << endl;
                break;
            default:
                cout << "Scelta non valida" << endl;
        }
        cout << endl;
    } while(scelta != 6);
}
 
void menu() {
    cout << "MENU PRINCIPALE" << endl;
    cout << "1. Registrazione Umidita" << endl;
    cout << "2. Analisi Estremi" << endl;
    cout << "3. Riepilogo Statistico" << endl;
    cout << "4. Controllo Irrigazione" << endl;
    cout << "5. Stato Terreno" << endl;
    cout << "6. Esci" << endl;
    cout << "Scelta: ";
}
 
void registra(double arr[], int &n) {
    cout << "Inserisci almeno 6 misurazioni (0-100):" << endl;
    n = 0;
    double val;
    
    while(n < 6) {
        cout << "Misurazione ";
        cin >> val;
        if(val >= 0 && val <= 100) {
            arr[n] = val;
            n++;
        } else {
            cout << "Errore: 0-100" << endl;
        }
    }
    
    char cont;
    cout << "Altre misurazioni? (S/N): ";
    cin >> cont;
    while(cont == 'S' || cont == 's') {
        cout << "Misurazione " << (n + 1) << ": ";
        cin >> val;
        if(val >= 0 && val <= 100) {
            arr[n] = val;
            n++;
        } else {
            cout << "Errore: 0-100" << endl;
            continue;
        }
        cout << "Altre? (S/N): ";
        cin >> cont;
    }
    
    cout << "Registrate " << n << " misurazioni" << endl;
}
 
void estremi(double arr[], int n) {
    cout << "ANALISI ESTREMI" << endl;
    
    double max_val = arr[0];
    int idx_max = 0;
    double min_val = arr[0];
    int idx_min = 0;
    
    for(int i = 1; i < n; i++) {
        if(arr[i] > max_val) {
            max_val = arr[i];
            idx_max = i;
        }
        if(arr[i] < min_val) {
            min_val = arr[i];
            idx_min = i;
        }
    }
    
    cout << "Max: " << max_val << "% (misurazione " << (idx_max + 1) << ")" << endl;
    cout << "Min: " << min_val << "% (misurazione " << (idx_min + 1) << ")" << endl;
}
 
void statistiche(double arr[], int n) {
    cout << "RIEPILOGO STATISTICO" << endl;
    
    double somma = 0;
    for(int i = 0; i < n; i++) {
        somma += arr[i];
    }
    double media = somma / n;
    
    double max_val = arr[0];
    double min_val = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max_val) max_val = arr[i];
        if(arr[i] < min_val) min_val = arr[i];
    }
    
    double range = max_val - min_val;
    
    cout << "Media: " << media << "%" << endl;
    cout << "Range: " << range << "%" << endl;
    cout << "Max: " << max_val << "%, Min: " << min_val << "%" << endl;
}
 
void irrigazione(double arr[], int n) {
    cout << "CONTROLLO IRRIGAZIONE" << endl;
    
    double soglia;
    cout << "Soglia di secchezza (%): ";
    cin >> soglia;
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] < soglia) count++;
    }
    
    cout << "Volte sotto soglia: " << count << endl;
    if(count > 0) {
        cout << "ATTENZIONE: attivare irrigatori" << endl;
        cout << "Misurazioni critiche: ";
        for(int i = 0; i < n; i++) {
            if(arr[i] < soglia) cout << (i + 1) << " ";
        }
        cout << endl;
    } else {
        cout << "OK: umidita sempre sopra soglia" << endl;
    }
}
 
void stato(double arr[], int n) {
    cout << "STATO DEL TERRENO" << endl;
    
    double somma = 0;
    for(int i = 0; i < n; i++) {
        somma += arr[i];
    }
    double media = somma / n;
    
    cout << "Media: " << media << "%" << endl;
    
    if(media > 70) {
        cout << "RISCHIO MUFFE" << endl;
    } else if(media >= 40 && media <= 70) {
        cout << "CONDIZIONI OTTIMALI" << endl;
    } else {
        cout << "TERRENO CRITICO" << endl;
    }
}