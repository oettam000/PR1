#include "docente.h"//ho definito dove il programma deve andare a riprendere tutte le funzioni di libreria

int main() {
    //qua inserisco il numero che verra generato random e lo faro prendere in ingresso alle funzioni in modo da non incasinarmi in futuro

    int random=1-rand()%6-1;
    struct giocatore *G;//creazione della lista giocatori
    struct Lista *MAZZO;
    struct tabellone *T;
    G=generazione_giocatori();//funziona
    MAZZO=generazione_mazzo();//funziona
    T=fase_pre_gioco(G,random,MAZZO);
    //T=fase_pre_gioco(G,random,MAZZO);//non mi ritorna zero
    return 0;
}