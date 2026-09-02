#include <iostream>
using namespace std;

int main() {
    int N, somma;

    cout << "Inserisci un numero ";
    cin >> N;

    for (int num = 1; num <= N; num++) {

        somma = 0;

        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                somma += i;
            }
        }

        if (somma == num && num != 0) {
            cout << num << " numero perfetto" << endl;
        }
    }
}
