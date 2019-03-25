#include "docente.h"//ho definito dove il programma deve andare a riprendere tutte le funzioni di libreria

int main() {
    //qua inserisco il numero che verra generato random e lo faro prendere in ingresso alle funzioni in modo da non incasinarmi in futuro
    srand(time(NULL));
    int random=1+rand()%GIOCATORI;
    struct Lista *MAZZO;
    struct tabellone *A;
    MAZZO=generazione_mazzo();//funziona
    MAZZO=mescola(MAZZO);
    //visualizza(MAZZO);
    generazione_giocatori();//assegna il numero delle truppe a i rispettivi giocatori
    //gioca();//mi restituisce il nome del giocatore
    A=fase_pre_gioco(random,MAZZO);//mi da un nome sbagliato all secondo inserimento della truppa
    A=Proprietario(A,random);
    //tabelloneVIS(A);

    schieramento(A,random);
    return 0;
}