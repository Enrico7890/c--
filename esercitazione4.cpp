#include <iostream>
#include <string>
using namespace std;

/* Una scuola gestisce i dati degli studenti in tre array paralleli:

nomi[] — nomi degli studenti
voti[] — media dei voti (0-10)
assenze[] — numero di assenze

Determinare:

Lo studente con la media più alta e quello con la media più bassa, stampando nome e media
La media generale della classe e quanti studenti sono sopra e quanti sotto questa media
Gli studenti "a rischio": media < 6 E assenze > 5 (stampa nome, media e assenze)
La classifica dei primi 3 studenti per media (dal più alto al più basso con posizione)
Studenti "promossi": media ≥ 6 E assenze ≤ 5
Calcolare il numero di assenze medie e individuare lo studente con il maggior numero di assenze ingiustificate (assenze > media assenze della classe)
Bonus: trovare la coppia di studenti con la differenza di media più piccola (stampa entrambi i nomi e la differenza) */

int inputn();
void inputdati(string [], float[], int [], int n);
void media(string [], float[], int [], float &media, int &studsottomedia, int &studsopramedia,  int n)
void studentirischio (string [], float[], int [], float media )