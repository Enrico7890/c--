#include <iostream>
using namespace std;
int main (){
int n, array [50], min = 0, max = 0, pari = 0, dispari = 0;

cout << "quanti numeri vuoi inserire" << endl;
cin >> n;

for (int i = 0; i < n; i++){

cout << "Inserisci un numero" << endl;
cin >> array[i];

                if (i == 0 || array [i] > max ){
        max=array [i];
    }
        if (i == 0 || array [i] < min){
    min= array [i];
    }
        if (array [i] % 2 == 0){
    pari++;
    }

    if (array [i] % 2 != 0){

    dispari++;    

    }

}
cout << "i numeri pari sono " << pari << endl;
cout << "i numeri dispari sono " << dispari << endl;
cout << "il minimo e'" << min << endl;
cout << "il max e'" << max << endl;


}