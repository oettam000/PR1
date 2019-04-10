#include "docente.h"//ho definito dove il programma deve andare a riprendere tutte le funzioni di libreria

int main() {
    //qua inserisco il numero che verra generato random e lo faro prendere in ingresso alle funzioni in modo da non incasinarmi in futuro
    srand(time(NULL));//inizializzo il seed per la generazione random
    int random=1+rand()%GIOCATORI;//valore random che utilizzo per far partire il gioco
    struct Lista *MAZZO;//struttura che richiama il mazzo
    struct tabellone *A;//struttura che richiama il tabellone
    MAZZO=generazione_mazzo();//funziona
    MAZZO=mescola(MAZZO);//mescola il mazzo per darlo ad i proprietari
    gioca();//mi restituisce il nome del giocatore
    A=fase_pre_gioco(random,MAZZO);//mi da un nome sbagliato all secondo inserimento della truppa
    A=Proprietario(A,random);//stampa il proprietario dei singoli terreni
    generazione_giocatori();//assegna il numero delle truppe a i rispettivi giocatori
    schieramento(A,random);//mi fa schierare tutte le truppe che ho al inizio
    MAZZO=aggiungi_elementi(MAZZO);//aggiunge le ultime due carte jollu al interno del mazzo
    MAZZO=mescola(MAZZO);//funzione per ri mescolare il mazzo completo dopo aver inserito tutte le carte
    visualizza(MAZZO);//mi serve solo in fase di progettazione
    Fase_principale(random,A,MAZZO);//la fase principale del gioco
    tabelloneVIS(A);//mi stampa tutto il tabellone per intero
    return 0;
}