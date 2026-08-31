#include <iostream>
using namespace std;

const int dim=100;

int inputDim();
void inputVett(int arr[], int d);
int contaPositivi(int arr[], int d);
int contaNegativi(int arr[], int d);
int sommaPari(int arr[], int d);
int sommaDispari(int arr[], int d);
void output(int pos, int neg, int spar, int sdisp);



int main(){
    int n;
    int Vett[dim];
    int positivi, negativi;
    int somma_Pari, somma_Dispari;
    
    cout<<"Inserisci la diemnsione dell'array: "<<endl;
    n= inputDim();
    
    cout<<"Inserisci il primo numero dell'array: "<<endl;
    inputVett(Vett,n);
    
    positivi=contaPositivi(Vett,n);
    negativi=contaNegativi(Vett,n);
    somma_Pari=sommaPari(Vett,n);
    somma_Dispari=sommaDispari(Vett,n);
    output(positivi, negativi, somma_Pari, somma_Dispari);
}
    
    int inputDim(){
        int d;
        do{
            cout<<"Inserisci la dimensione dell'array: ";
            cin>>d;
        } while (d<0||d>dim);
        	return d;
}
    void inputVett(int arr[], int d){
        for (int i=0;i<d;i++){
        cout<<"Inserisci un numero: ";
        cin>>arr[i];
    }
}
    int contaPositivi(int arr[], int d){
        int contatore=0;
        for (int i=0;i<d;i++){
            if (arr[i]>0){
                contatore++;
            }
                
        }
        return contatore;
    }
    
    int contaNegativi(int arr[], int d){
        int contatore=0;
        for (int i=0;i<d;i++){
            if (arr[i]<0){
                contatore++;
            }
        }
        return contatore;
    }
    
    int sommaPari(int arr[], int d){
        int somma=0;
        for (int i=0;i<d;i++){
            if (i % 2 != 0){
                somma=somma+arr[i];
            }
        }
        
        return somma;
    }
    
    int sommaDispari(int arr[], int d){
        int somma=0;
        for (int i=0;i<d;i++){
            if(i % 2 != 0){
                somma=somma+arr[i];
            }
        }
        return somma;
    }
    
    void output (int pos, int neg, int sommaPari, int sommaDispari){
        cout<<"Numero di elementi positivi: "<<pos<<endl;
        cout<<"Numero di elementi negativi: "<<neg<<endl;
        cout<<"Somma dei numeri pari: "<<sommaPari<<endl;
        cout<<"Somma dei numeri disapri: "<<sommaDispari<<endl;
        
    }