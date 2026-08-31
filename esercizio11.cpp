#include <iostream>
using namespace std;
int main() {
    int n, somma = 0;
    cout << "Inserisci un numero " << endl;
    cin >> n;
if (n > 0 ){
    for (int num = 1; num <= n; num++) {
       
        for (int i = 1; i<=num % 2; i++){
            if (num % i == 0){
                somma+=i;
            }
        }
    if (somma == num && num =!0){
    cout << num << " numero perfetto" << endl;
            }
        }
    }
}
