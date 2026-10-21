#include <iostream>
#include <string>
using namespace std;
 
// ============================================================
// RIFERIMENTO: tutte le dichiarazioni base di una classe in C++
// ============================================================
 
class Esempio {
 
// ---------------------------------------------------------
// 1. LIVELLI DI ACCESSO
// ---------------------------------------------------------
private:
    // I membri private sono accessibili SOLO dai metodi della classe stessa.
    // Questo e' il principio di incapsulamento: nasconde i dati dall'esterno
    // e obbliga chi usa la classe a passare da metodi pubblici controllati.
    string datoPrivato;
 
protected:
    // I membri protected si comportano come private verso l'esterno,
    // MA sono visibili anche alle classi che ereditano da questa
    // (vedi ereditarieta', un concetto successivo).
    int datoProtetto;
 
public:
    // I membri public sono accessibili da chiunque, anche da fuori la classe
    // (es. dal main, o da altre funzioni che ricevono l'oggetto).
    int datoPubblico;
 
    // Nota: si puo' ripetere private/protected/public piu' volte nella stessa
    // classe, per raggruppare membri logicamente vicini.
 
 
// ---------------------------------------------------------
// 2. COSTRUTTORI
// ---------------------------------------------------------
 
    // --- 2a. Costruttore di default (nessun parametro) ---
    // Chiamato automaticamente quando crei un oggetto senza argomenti,
    // es. "Esempio e;" oppure quando dichiari un array di oggetti "Esempio arr[10];"
    // Serve SEMPRE se hai gia' definito un altro costruttore con parametri,
    // altrimenti il compilatore smette di generarlo automaticamente.
    Esempio();
 
    // --- 2b. Costruttore con parametri ---
    // Permette di creare un oggetto gia' inizializzato con valori specifici,
    // es. "Esempio e(5, "ciao");"
    Esempio(int d, string s);
 
    // --- 2c. Costruttore con lista di inizializzazione ---
    // Forma alternativa e piu' efficiente per inizializzare i campi:
    // i valori vengono assegnati PRIMA che il corpo {} venga eseguito.
    // Sintassi: NomeClasse(parametri) : campo1(valore1), campo2(valore2) {}
    // (la dichiarazione e' identica a un costruttore normale, cambia solo
    // come lo definisci fuori dalla classe - vedi piu' sotto)
    Esempio(int d);
 
    // --- 2d. Costruttore di copia ---
    // Chiamato quando crei un nuovo oggetto copiando un oggetto esistente,
    // es. "Esempio e2 = e1;" oppure quando passi un oggetto per valore a una funzione.
    // Se non lo scrivi tu, il compilatore ne genera uno automatico che copia
    // campo per campo (va bene per dati semplici, va scritto a mano se la
    // classe gestisce memoria dinamica con "new").
    Esempio(const Esempio& altro);
 
    // --- 2e. Overload del costruttore ---
    // Puoi avere piu' costruttori con parametri diversi (numero o tipo):
    // il compilatore sceglie automaticamente quello giusto in base a come
    // crei l'oggetto. Qui sopra Esempio(), Esempio(int,string) ed Esempio(int)
    // sono gia' un esempio di overload del costruttore.
 
 
// ---------------------------------------------------------
// 3. DISTRUTTORE
// ---------------------------------------------------------
 
    // Chiamato automaticamente quando l'oggetto viene distrutto
    // (fine dello scope in cui e' stato creato, o "delete" se creato con "new").
    // Nome: ~NomeClasse(). Nessun parametro, nessun tipo di ritorno, non si
    // puo' fare overload (ce n'e' sempre e solo UNO per classe).
    // Utile per liberare risorse allocate dinamicamente.
    ~Esempio();
 
 
// ---------------------------------------------------------
// 4. GETTER E SETTER
// ---------------------------------------------------------
 
    // --- 4a. Getter ---
    // Restituisce il valore di un campo privato. Non modifica l'oggetto,
    // quindi e' buona pratica marcarlo "const" (vedi punto 6b).
    string getDatoPrivato();
 
    // --- 4b. Setter ---
    // Modifica un campo privato. Puo' contenere validazioni: qui, ad esempio,
    // potresti rifiutare valori non validi invece di accettarli ciecamente.
    void setDatoPrivato(string valore);
 
 
// ---------------------------------------------------------
// 5. METODI (FUNZIONI MEMBRO) NORMALI
// ---------------------------------------------------------
 
    // Un metodo qualsiasi, che non e' ne' un getter ne' un setter,
    // rappresenta un COMPORTAMENTO dell'oggetto (cosa "sa fare").
    void stampa();
 
    // Un metodo puo' anche essere definito DIRETTAMENTE dentro la classe
    // (inline), invece che dichiarato qui e definito fuori con "::".
    // Va bene per metodi molto brevi:
    int quadrato(int x){
        return x * x;
    }
 
 
// ---------------------------------------------------------
// 6. VARIANTI IMPORTANTI DI METODI
// ---------------------------------------------------------
 
    // --- 6a. Metodo che usa "this" ---
    // "this" e' un puntatore implicito all'oggetto corrente. Serve soprattutto
    // quando un parametro ha lo stesso nome di un campo della classe, per
    // distinguere "il campo dell'oggetto" dal "parametro appena ricevuto".
    void setDatoPubblico(int datoPubblico){
        this->datoPubblico = datoPubblico; // this->datoPubblico e' il CAMPO
                                            // datoPubblico (senza this->) e' il PARAMETRO
    }
 
    // --- 6b. Metodo const ---
    // La parola "const" DOPO le parentesi promette che il metodo non
    // modifichera' nessun campo dell'oggetto. Va sempre messa sui getter.
    int getDatoProtetto() const {
        return datoProtetto;
    }
 
 
// ---------------------------------------------------------
// 7. MEMBRI STATICI
// ---------------------------------------------------------
 
    // Un campo "static" NON appartiene al singolo oggetto, ma e' condiviso
    // da TUTTE le istanze della classe (es. un contatore di quanti oggetti
    // sono stati creati finora).
    static int contatoreOggetti;
 
    // Un metodo "static" puo' essere chiamato senza creare nessun oggetto,
    // scrivendo NomeClasse::metodo() invece di oggetto.metodo().
    static int getContatore();
};
 
 
// ============================================================
// DEFINIZIONI FUORI DALLA CLASSE (con l'operatore ::)
// ============================================================
// Tutto cio' che sopra e' stato solo DICHIARATO (una promessa al compilatore)
// va DEFINITO qui sotto, dicendo davvero cosa fa ogni metodo/costruttore.
 
// Costruttore di default: valori "neutri" di partenza.
Esempio::Esempio(){
    datoPrivato = "";
    datoProtetto = 0;
    datoPubblico = 0;
}
 
// Costruttore con parametri: assegnazione classica nel corpo {}.
Esempio::Esempio(int d, string s){
    datoProtetto = d;
    datoPrivato = s;
}
 
// Costruttore con LISTA DI INIZIALIZZAZIONE: i due punti ":" dopo la
// parentesi indicano i valori iniziali dei campi, PRIMA di entrare nel {}.
// Equivalente a "datoProtetto = d;" scritto dentro il corpo, ma piu' efficiente
// (soprattutto per oggetti complessi, o campi const/riferimenti che si
// possono inizializzare SOLO cosi').
Esempio::Esempio(int d) : datoProtetto(d) {
    // corpo vuoto: l'inizializzazione e' gia' avvenuta nella lista sopra
}
 
// Costruttore di copia: "const Esempio& altro" e' l'oggetto sorgente da
// copiare, passato per riferimento costante (non lo modifico, non lo copio
// di nuovo inutilmente).
Esempio::Esempio(const Esempio& altro){
    datoPrivato = altro.datoPrivato;
    datoProtetto = altro.datoProtetto;
    datoPubblico = altro.datoPubblico;
}
 
// Distruttore: qui potresti liberare memoria allocata con "new" (in questo
// esempio non ce n'e' bisogno, quindi il corpo resta vuoto).
Esempio::~Esempio(){
    // eventuale pulizia di risorse
}
 
// Getter: restituisce semplicemente il valore del campo privato.
string Esempio::getDatoPrivato(){
    return datoPrivato;
}
 
// Setter: assegna il nuovo valore al campo privato.
void Esempio::setDatoPrivato(string valore){
    datoPrivato = valore;
}
 
// Metodo normale: usa i campi dell'oggetto per fare qualcosa (qui, stampare).
void Esempio::stampa(){
    cout << datoPrivato << " " << datoProtetto << " " << datoPubblico << endl;
}
 
// Membro static: va inizializzato UNA VOLTA SOLA fuori dalla classe,
// altrimenti il linker da' errore ("undefined reference").
int Esempio::contatoreOggetti = 0;
 
// Metodo static: puo' accedere solo ad altri membri static (non ha un
// oggetto specifico su cui lavorare, quindi non puo' leggere datoPrivato
// di un singolo oggetto).
int Esempio::getContatore(){
    return contatoreOggetti;
}
 
 
// ============================================================
// USO PRATICO NEL MAIN
// ============================================================
int main(){
 
    Esempio e1;                    // costruttore di default
    Esempio e2(5, "ciao");         // costruttore con parametri
    Esempio e3(10);                // costruttore con lista di inizializzazione
    Esempio e4 = e2;                // costruttore di copia (copia e2 dentro e4)
 
    e1.setDatoPrivato("prova");    // chiamata a un setter: oggetto.metodo(valore)
    cout << e1.getDatoPrivato() << endl;  // chiamata a un getter
 
    e1.setDatoPubblico(99);        // datoPubblico e' public, ma uso comunque il setter
                                    // per mostrare l'uso di "this"
 
    e1.stampa();                   // chiamata a un metodo normale
 
    cout << "Quadrato di 4: " << e1.quadrato(4) << endl;  // metodo definito inline
 
    cout << "Contatore statico: " << Esempio::getContatore() << endl;
    // notare: NomeClasse::metodo(), non oggetto.metodo(), perche' e' static
 
}