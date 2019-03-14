#include "docente.h"

//This global constant variable contains the adjacencies of the territories (true if a territory is adjacent with another).
const _Bool t[N_TERRITORI][N_TERRITORI] = {//matrice dei terreni fornita dal docente //nota per me da non cambiare in alcun modo matrice gia completa di tutto
        { false, false,  true, false, false, false, false, false, false, false, false, false,  true, false, false, false, false,  true, false, false, false, false, false, false, false, false},
        { false, false,  true,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {  true,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        { false,  true, false, false,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false, false, false, false, false, false},
        { false, false, false,  true, false,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        { false, false, false, false,  true, false, false,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        { false, false, false, false, false, false, false,  true,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        { false, false, false, false, false,  true,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        { false, false, false, false, false, false,  true, false, false, false,  true, false, false, false, false, false,  true, false, false, false, false, false, false, false, false, false},
        { false, false, false, false, false, false, false, false, false, false,  true, false, false, false, false, false, false, false, false, false,  true, false, false, false, false, false},
        { false, false, false, false, false, false, false, false,  true,  true, false,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        { false, false, false, false, false, false, false, false, false, false,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {  true, false, false, false, false, false, false, false, false, false, false, false, false,  true,  true, false, false, false, false, false, false, false, false, false, false, false},
        { false, false, false, false, false, false, false, false, false, false, false, false,  true, false,  true, false,  true, false, false, false, false, false, false, false, false, false},
        { false, false, false, false, false, false, false, false, false, false, false, false,  true,  true, false,  true, false, false, false, false, false, false, false, false, false, false},
        { false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false, false,  true, false, false, false, false, false, false, false, false},
        { false, false, false, false, false, false, false, false,  true, false, false, false, false,  true, false, false, false, false, false, false, false, false, false, false, false, false},
        {  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false, false,  true, false, false, false, false, false, false, false},
        { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false,  true, false,  true, false, false, false, false},
        { false, false, false,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false,  true,  true,  true, false, false, false},
        { false, false, false, false, false, false, false, false, false,  true, false, false, false, false, false, false, false, false, false,  true, false, false, false, false, false, false},
        { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true,  true, false, false, false, false, false, false},
        { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false, false, false,  true, false,  true},
        { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false,  true, false},
        { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false,  true},
        { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,  true, false,  true, false}
};//fine matrice di controllo dei terreni

/**
 * This function checks if two territories are adjacent (reachable from each other).
 * @param idFirst  the id of the first territory
 * @param idSecond the id of the second territory
 * @return it returns true if they are adjacent, false otherwise
 */
_Bool isAdjacent(int idFirst, int idSecond){//questa semplice funzione controlla se si possono attaccare i terreni da dove si trova il giocatore
    return t[idFirst][idSecond];
}
//******************inizio parte del codice con le relative strutture ed enumerazioni**********************//
enum colore{ROSSO,NERO,VIOLA,VERDE,GIALLO,BLU};//questa enumerazione contiene tutti i colori delle armate che useranno i giocatori
enum simbolo{caffe,birra,vino,jolly};


enum coloreD{rosso,blu};//questa enumerazione è per i dadi che mi dice i dadi di attaccoed i dadi di difesa


enum facolta{studi_umanistici,biologia_e_farmacia,ingegneria_e_architettura,scienze_merendine,medicina_chirurgia,scienze,nullo};//questa enumerazione ci serve per capire a quale dipartimento fanno capo le singole facolta


typedef struct {//struttura che definisce il giocatore in tutte le sue parti
    enum colore Colore;//questo mi serve per dare il valore del colore al singolo giocatore
    int ID;//valore identificativo del giocatore
    int Ncarte;//questo valore sta ad indicare il numero di carte che il giocatore ha in mano
    int numero_truppe;//questo valore ci fornisce il numero massimo di truppe che puo avere il giocatore quindi ogni volta che il giocatore prendera una truppa andremo a scalare il valore da questo numero
    int territori;//numero di territori appartenente al giocatore
    char Nome[DIM]; //nome corrispondente al giocatore stando al linguaggio del c 89/90 devono stare alla fine della struttura
}giocatore;//fine struttura giocatore
giocatore G[6]={{ROSSO,0,0,0,0,"GENOVEFFA"},{NERO,1,0,0,0,"DAVIDE"},{VIOLA,2,0,0,0,"FABIOLA"},
                {VERDE,3,0,0,0,"SOCRATE"},{GIALLO,4,0,0,0,"FRANCESCA"},{BLU,5,0,0,0,"FRANCESCO"}};//definisco un vettore di strutture statico e lo inizzializzo


struct tabellone{//inizio struttura terreno
    int Vterritorio;//puo prendere valori che vanno da 0 a 25
    int Proprietario;//puo prendere valori che vanno da 0 a 5
    int Armate;//questo indica il numero di armate che ci sono al interno di quel terreno che possono andare da '0 a 100
    char nome[DIM+1];
};//fine struttura terreno


typedef struct {//inizio della struttura del mazzo
    int Numero;
    enum simbolo Simbolo;//simbolo riportato nella carta
    enum facolta F;//enumerazione di ragruppamento per il dipartimento
    char Testo[DIM];//do la stezsa dimensione del nome da mettere nelle carte
}mazzo;//fine della struttura del mazzo

mazzo M[28]={{0,vino,studi_umanistici,"Psicologia"},{1,birra,studi_umanistici,"filosofia"},{2,vino,studi_umanistici,"pedagogia"},{3,birra,studi_umanistici,"lettere"},{4,caffe,studi_umanistici,"lingue"},{5,vino,scienze_merendine,"economia"},{6,birra,scienze_merendine,"Scienze politiche"},{7,caffe,scienze_merendine,"Giurisprudenza"},
            {8,vino,medicina_chirurgia,"Odontoiatra"},{9,caffe,medicina_chirurgia,"Infermieristica"},{10,caffe,medicina_chirurgia,"Medicina"},{11,birra,medicina_chirurgia,"Scienze motorie"},{12,vino,biologia_e_farmacia,"CTF"},{13,caffe,biologia_e_farmacia,"tossicologia"},{14,birra,biologia_e_farmacia,"Biologia"},
            {15,caffe,biologia_e_farmacia,"Scienze della natura"},{16,vino,biologia_e_farmacia,"farmacia"},{17,caffe,ingegneria_e_architettura,"Ing,Chimica"},{18,birra,ingegneria_e_architettura,"Ing,Meccanica"},{19,caffe,ingegneria_e_architettura,"Ing,Elettronica"},{20,caffe,ingegneria_e_architettura,"Architettura"},
            {21,birra,ingegneria_e_architettura,"Ing,Civile"},{22,caffe,scienze,"Chimica"},{23,caffe,scienze,"Fisica"},{24,birra,scienze,"Informatica"},{25,caffe,scienze,"Matematica"},{26,jolly,nullo,"jolly"},{27,jolly,nullo,"jolly"}};

struct salvataggio{//questa struttura serve solo per il salvataggio
    int nGiocatori;//numero dei giocatori al momento del salvataggio
    int IDgiocatoreGiocante;//numero identificativo del giocatore
    giocatore GIOCATORE;//richiamo alla struttura giocatore
    int Vcarte[27];//vettore carte
    struct tabellone TABELLONE;//richiamo alla struttura tabellone
    mazzo MAZZO;//richiamo alla struttura mazzo
};//fine struttura salvataggio


struct Lista{//creazione della struttura lista
    mazzo m;//dichiaro un vettore della struttura mazzo di 26 spazzi
    struct Lista *pnext;//puntatore al prossimo elemento della lista
};

//********************fine parte del codice relativo a strutture e enumerazioni*************************************//
/******porzione di codice relativa al lancio dei dadi*******/
int Adadi() {//inizio funzione per la generazione dei numeri casuali tramite i dadi
    srand(time(NULL));//inizializzazione del seed a zero
    int Adado;//variabili dei dadi per l'attacco
            Adado = 1 + rand() % 6 - 1 + 1;//generazione del numero random per il dado con gli estremi compresi
    return Adado;
}//fine della funzione dei dadi di attacco
//devo generare un altra funzione che mi permette di vreare un lista o per qualcosa di simile per la il controllo delle infoemazioni sul terreno di gioco altrimenti non posso controllare le informazioni relative a i terreni
int Bdadi(){//dovro assegnare unn vettore per i dadi in modo che non mi creino problemi altrimenti non so come passare i dati
    srand(time(NULL));//inizializzazione del seed a zero
    int Bdado;
            Bdado=1+rand()%6-1+1;//generazione del numero random per il dado con gli estremi compresi
    return Bdado;
}//fine della funzione dei dadi in difesa
/***************fine porzione relativa al lancio dei dadi******************/
void gioca(){
    int i;
    for(i=0;i<GIOCATORI;i++) {
        printf("%s\n", G[i].Nome);
        printf("%d\n", G[i].ID);
        printf("%d\n", G[i].numero_truppe);
    }
}

void generazione_giocatori(){
    switch(GIOCATORI){
        case 3:
            G[0].numero_truppe=35;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[1].numero_truppe=35;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[2].numero_truppe=35;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            break;
        case 4:
            G[0].numero_truppe=30;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[1].numero_truppe=30;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[2].numero_truppe=30;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[3].numero_truppe=30;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            break;
        case 5:
            G[0].numero_truppe=25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[1].numero_truppe=25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[2].numero_truppe=25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[3].numero_truppe=25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[4].numero_truppe=25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            break;
        case 6:
            G[0].numero_truppe=20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[1].numero_truppe=20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[2].numero_truppe=20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[3].numero_truppe=20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[4].numero_truppe=20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[5].numero_truppe=20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            break;
        default:printf("hai sbagliato cambiando la variabile macro\n");//questo messaggio viene visualizzato solo quando si sbaglia a cambiare il valore macro delle impostazioni nel file docente.h
    }
    //adesso provero a fare una parte di codice che mi permette di assegnare il valore contenuto nella lista delle carte ad il valore id del giocatore
    //mi da un altro errore che consiste nella richiamata come valore di ritorno di una valore che è contenuto solo nella variabile locale
    //devo sempre controllare il valore di ritorno di questa funzione perche potrebbe crearmi problemi in compilazione o a run-time

}

struct Lista *generazione_mazzo(){//generazione della lista del mazzo
    struct Lista *MAZZO=NULL, *paus=NULL, *pausM=NULL,*primoM=NULL;//dichiarazione dei puntatori e dei puntatori ausiliari
    int i=0;//variabile che mi serve nel vor come contatore
    ///parte della creazione della lista
    MAZZO=(struct Lista *)malloc(sizeof(struct Lista));//allocazione dinamica della struttura lista
    MAZZO->m=M[i];//assegnazione del primo elemento della lista
    paus=MAZZO;//assegnazione al puntatore ausiliario l'allocazione di memoria del puntatore mazzo
    for(i=1;i<26;i++){//for per l'assegnazione dei prossimi elementi della lista
        paus->pnext=(struct Lista *)malloc(sizeof(struct Lista));//allocazione dei prossimi n elementi
        paus=paus->pnext;//passaggio del valore della prossima cella di memoria
        paus->m=M[i];//assegnazione del dato da mettere nella lista
    }//fine for per l'assegnazione della lista
    paus->pnext=NULL;//una volta finita l'allocazione dinamica della lista devo chiuderla
    ////parte che cambia l'ordine delle carte al interno della lista devo ancora terminarla
    //devo ancora modificare questa porzione di code in modo che mescoli le carte
    return (MAZZO);//il valore di ritorno che mi rende la lista del mazzo senza mischiare al inizio
    //devo capire perche qua mi da un warning altrimenti potrebbe esserci un problema con il codice in fatto di compilazione
}//fine della funzione

void truppe(int b){//questa funzione serve per vedere se il giocatore è arrivato al limite massimo delle sue truppe ossia 100
    int aggiunta;//questo valore mi da la possibilita di icrementare il numero di truppe ad ogni turno
    if(G[b].numero_truppe<100){//controllo per l'aggiunta delle truppe del giocatore
        aggiunta=G[b].territori/3;//
        G[b].territori=G[b].territori+aggiunta;//con questa operazione incremento il numero delle truppe del giocatore
    }else{
        printf("hai raggiunto il limite massimo delle truppe dora devi giostrartela bene\n ");//messaggio di ritorno al giocatore
    }
}//fine funzione truppe



struct tabellone *fase_pre_gioco( int random,struct Lista *MAZZO) {
    struct tabellone *T;//sto inizializzando la struttura tabellone con il valore relativo ad ogni giocatore
    T = (struct tabellone *) malloc(sizeof(struct tabellone));//alloco lo spazio per ogni spazio sul tabellone
    int i, j = 0;//variabile che mi serve per passare il valore del giocatore iniziale
    int valoreT[GIOCATORI +
                1];//mi serve per eseguire un calcolo al indietro per il controllo delle truppe del giocatore durante l'assegnazione dei terreni
    int scelta;
    for (i = random; i < GIOCATORI; i++) {//con questo for asseggno ad ogni giocatore un tot di carte
        if (i == GIOCATORI - 1) {//questo controllo lo fa ritornare sempre alla prima posizione del giocatore
            //ritorna sempre alla prima posizione
            T[j].Proprietario = i;//assegno il valore del proprietario al terreno
            T[j].Vterritorio = MAZZO[j].m.Numero;//assegno il valore del territorio in base al valore delle carte che sto distribuendo
            T[j].Armate = 0;//assegno alle armate presenti al interno del terreno il valore zero
            strcpy(T[j].nome, MAZZO[j].m.Testo);//copio il testo della carta al interno del valore del tabellone
            valoreT[i] = 0;
            j++;//incremento la variabile altrimenti controllo solo la stessa parte di territorio e la stessa carta continuamente
            i = 0;//questo succede solo se il valore del for arriva alla fine del ciclo in modo che ritorni sempre a zero e rincominci
        } else {//fine del controllo
            T[j].Proprietario = i;//assegno il valore del proprietario al terreno
            T[j].Vterritorio = MAZZO[j].m.Numero;//assegno il valore del territorio in base al valore delle carte che sto distribuendo
            T[j].Armate = 0;//assegno alle armate presenti al interno del terreno il valore zero
            strcpy(T[j].nome, MAZZO[j].m.Testo);//copio il testo della carta al interno del valore del tabellone
            j++;//incremento il valore di j per andare avanti con il mazzo
            valoreT[i] = 0;
        }
        if (j ==
            26) {//controllo se j è uguale a il massimo valore del vettore del mazzo posso interrompere la compèutazxione di questo for
            break;//forzo l'uscita dal ciclo
        }//fine istruzione per uscire dal ciclo
    }//fine else
    //fine primo ciclo for
    return T;
}
void schieramento(struct tabellone *T,int random ) {
    int i, j;
    int scelta;
    int valoreT[GIOCATORI];
    for (j = 0; j < 26; j++) {
        for (i = random; i <GIOCATORI; i++){//questo lo devo fare fino a quando non hanno posizionato al interno del tabellone tutte le truppo
            do {//mi permette di eseguire il ciclo almeno una volta
                if (T[j].Proprietario == G[i].ID) {
                    if (valoreT[i] !=G[i].numero_truppe) {//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                        printf("il terreno dove devi mettere le truppe e' :%s\n",T[j].nome);
                        printf("puoi ancora posizionare %d truppe sul tabellone prima del inizio del gioco\n ",
                               G[i].numero_truppe-valoreT[i]);//messaggio per vedere il numero delle truppe prima del inizio vero del gioco
                        printf("decidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");
                        scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                        switch (scelta) {//inizio costrutto di scelta
                            case 1://se la scelta equivale a 1
                                T[j].Armate++;//incremento il valore delle armate di uno
                                valoreT[i]++;//incremento il valore della impostazione di controllo
                                break;//istruzione che serve per terminare il costrutto switch
                            case 2://se la scelta ecquivale a 2
                                T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                                valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                                break;//istruzione che serve per terminare il costrutto switch
                            case 3:// se la scelta ecquivale a 3
                                T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                                valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                                break;//istruzione che serve per terminare il costrutto switch
                            default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                                printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                        }//fine costrutto di scelta
                    } else {
                        printf("hai inserito tutte le truppe di cui disponevi\n ");//questo avviene solo quando si sono posizionate tutte le truppe al interno del tabellone
                    }

                }
            } while (scelta ==3||scelta==2||scelta==1);//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//questo valore di ritorno mi serve per tutto il gioco perche mi indica quale è il giocatore iniziale

            if(i==GIOCATORI-1){//fa tornare il valore della conta dei giocatori a zero
                i=0;//assegno il valore a zero
            }
            if(i==25){//fa tornare il valore della conta dei terreni a zero
                j=0;
            }switch(GIOCATORI) {
    case 3:
        if ((valoreT[0] == G[j].numero_truppe) && (valoreT[1] == G[j].numero_truppe) &&
            (valoreT[2] == G[j].numero_truppe)) {
            i = 26;
            j = 6;
        }
        break;
    case 4:
        if ((valoreT[0] == G[j].numero_truppe) && (valoreT[1] == G[j].numero_truppe) &&
            (valoreT[2] == G[j].numero_truppe) && (valoreT[3] == G[j].numero_truppe)) {
            i = 26;
            j = 6;
        }
        break;
    case 5:
        if ((valoreT[0] == G[j].numero_truppe) && (valoreT[1] == G[j].numero_truppe) &&
            (valoreT[2] == G[j].numero_truppe) && (valoreT[3] == G[j].numero_truppe) &&
            (valoreT[4] == G[j].numero_truppe)) {
            i = 26;
            j = 6;
        }
        break;
    case 6:
        if ((valoreT[0] == G[j].numero_truppe) && (valoreT[1] == G[j].numero_truppe) &&
            (valoreT[2] == G[j].numero_truppe) && (valoreT[3] == G[j].numero_truppe) &&
            (valoreT[4] == G[j].numero_truppe) && (valoreT[5] == G[j].numero_truppe)) {
            i = 26;
            j = 6;
        }
        break;
}

        }//fine del for


    }
}


int Fase_principale(struct giocatore *G, int random,struct tabellone *T){//questa e la fase principale del progetto prende in ingresso la struttura giocatore e il valore generato random
    //fase iniziale del turno //
    int scelta;
    int i;//variabile indice del for

    for (i = random; i <GIOCATORI ; i++) {//questo for cicla al infinito in modo che il programma continui a girare a meno che non si utilizza la funzione apposta per uscire
        //truppe(G,i);//assegno delle truppe al giocatore
        if(i==GIOCATORI-1){//mi serve per azzerare il valore di controllo del for
            printf("è il turno del giocatore %d",i);
            truppe(i);
            printf("che cosa vuoi fare??");//stampa a video il messaggio
            printf("1)ATTACCARE");//stampa a video il messaggio
            printf("2)SPOSTARE TRUPPE");//stampa a video il messaggio
            printf("3)SALVARE");//stampa a video il messaggio
            printf("4)TERMINARE IL TURNO");//stampa a video il messaggio
            scanf("%d",&scelta);//faccio prendere un valore in ingresso da tastiera
            getchar();//svuoto il buffer ed evito che venga preso il valore di enter come prossimo paramentro in ingresso
            i=0;//viene riportato a zero quando arriva al massimo dei giocatori
        }else{//questo deve avvenire quasi sempre ammeno che non si verifichi la situazione del if
            truppe(i);
            printf("che cosa vuoi fare??");//stampa a video il messaggio
            printf("1)ATTACCARE");//stampa a video il messaggio
            printf("2)SPOSTARE TRUPPE");//stampa a video il messaggio
            printf("3)SALVARE");//stampa a video il messaggio
            printf("4)TERMINARE IL TURNO");//stampa a video il messaggio
            scanf("%d",&scelta);//prende in ingresso un valore da tastiera
            getchar();//svuoto il buffer e evito che venga preso il valore di enter come prossimo carattere in ingresso
        }
        do {
            switch (scelta) {//in base al numero che viene digitato fa succedere le diverse funzioni
                case 1:attacco(i,T);//situazione in cui si digita il numero 1
                //qua prendo in ingresso delle funzioni in modo da non dilungare il codice oltremodo
                    break;//interrompe la questa parte di codice e la fa uscire dal flusso
                case 2:spostamento_truppe(i,T);//situazione in cui si digita il numero 2
                    break;//interrompe la questa parte di codice e la fa uscire dal flusso
                case 3://situazione in cui si digita il numero 3
                    break;//interrompe la questa parte di codice e la fa uscire dal flusso
                case 4://situazione in cui si digita il numero 4
                    printf("hai deciso di terminare il turno");
                    break;//interrompe la questa parte di codice e la fa uscire dal flusso
                default ://situazione in cui si digita il valore sbagliato
                    printf("hai inserito un numero sbagliato riprova");
            }
        }while(scelta>4);//viene fatto riciclare la parte al interno del do while perche si ha inserito un numero diverso da quelli elencati
        //devo controllare quali territori sono vicini ai terreni confinanti dei giocatore in questione e quale puo attaccare
        //devo prima dare le carte a tutti i giocatori altrimenti non posso andare avanti con il funzionamento del gioco
    }//fine for
}//fine funzione principale

int attacco(int a,struct tabellone *T) {//questo è la funzione per l'attacco prende in ingresso il vettore giocatori piu il numero del attaccante e del difensore
    giocatore *G;
    int scelta,sceltaD,sceltaT,sceltaT1, i,j;//variabili che mi  servono al interno della
    int D1[3], D2[3],D3; //dadi attacco, difesa ausiliari
    printf("scegli da quale dei tuoi terreni attaccare");
    for(i=0;i<26;i++){
        if(T[i].Proprietario==G[i].ID){
            printf("%d)%s",i,T[i].nome);
        }
    }

        do {
            scanf("%d", &sceltaT);
            if(T[sceltaT].Armate==1){
                printf("non puoi attaccare da questo territorio");
            }else{
                break;
            }
        }while(-1);
        printf("puoi attaccare i seguenti terreni dal territorio che hai scelto");
        printf("quale terreno vuoi attaccare??");
        for (i = 0; i < 26; i++) {
            if (isAdjacent(sceltaT, i) == true) {
                printf("%d)%s", T[i].nome);
            }
        }

        do{
            scanf("%d",&sceltaT1);
            if(isAdjacent(sceltaT,sceltaT1)==true){
                printf("stai attaccando %s",T[sceltaT1].nome);
                break;//termina il flusso uscendo dal do in modo che il while messo a -1 non continui a ciclare al infinito
            }else{
                printf("hai sbagliato inserendo il numero del territorio da attaccare");
                printf("il terreno che hai selto non è nelle vicinanze del tuo");
            }

        }while(-1);
    printf("scelgli con quante truppe attaccare il massimo e tre");
    scanf("%d", &scelta);
    getchar();
    for (i = 0; i < scelta; i++);
    {
        D1[i] = Adadi();
    }
    printf("scegli con quante truppe difendere");
    scanf("%d", &sceltaD);
    getchar();
    for (i = 0; i < sceltaD; i++) {
        D2[i] = Bdadi();
    }
    //queesta parte controlla i quali dadi sono quelli piu grand3
    //questi due for mi servono per avere il numero piu alto al inizio e cosi via cioe dobbiamo mettere i dadi in ordine
    for(i=0;i<scelta;i++){//cicla in base al numero dei dadi
        for(j=0;j<scelta;j++){//seconda passata per trovare il numero piu  grande dei dadi
            if(D1[i]>D1[i+1]){
                D3=D1[i];
                D1[i]=D1[i+1];
                D1[i+1]=D3;
            }
        }
    }
    for(i=0;sceltaD<3;i++){//cicla in base al numero dei dadi
        for(j=0;sceltaD<3;j++){//seconda passata per trovare il numero piu  grande dei dadi
            if(D2[i]>D2[i+1]){
                D3=D2[i];
                D2[i]=D2[i+1];
                D2[i+1]=D3;
            }
        }
    }


    switch(scelta){//questo primo switch mi permette di decidere quanti dadi verranno lanciati dal attaccante
        case 1:
            switch(sceltaD){//questo mi permettere di scegliere con quanti dadi dovra difendere
                case 1://caso uno con un dado di attatto e un dado di difesa
                    if(D1[0]>D2[0]){//controllo se e maggiore
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che è stato attaccato
                    }else if(D1[0]<D2[0]){//se e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if(D1[0]==D2[0]){//se è uguale
                        printf("non succede niente");//questo messaggio avviene quando i dadi sono pari
                    }
                    break;//istruzione di blocco
                case 2://con due dadi da attacco ma siccome dobbiamo controllare sempre quello maggiore
                    if((D1[0]>D2[0])){//se e maggiore
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che è stato attaccato
                    }else if((D1[0]<D2[0])){//se e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if(D1[0]==D2[0]){//Se e uguale
                        printf("non succede niente");
                    }
                    break;//istruzione di blocco
                case 3://con tre dadi sempre controllando il maggiore tra i dadi
                    if((D1[0]>D2[0])){//se e maggiore
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che è stato attaccato
                    }else if((D1[0]<D2[0])){//Se e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if(D1[0]==D2[0]){//se e uguale
                        printf("non succede niente");
                    }
                    break;//istruzione di blocco
            }
            break;//istruzione di blocco del prico caso del case principale
        case 2://secondo caso del case principale ossia andiamo a controllare i due dadi
            switch(sceltaD){//questo mi permettere di scegliere con quanti dadi dovra difendere
                case 1://se decide di difendere con un dado
                    if((D1[0]>D2[0])){//se e maggiore
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che è stato attaccato
                    }else if((D1[0]<D2[0])){//se e minore
                        T[sceltaT].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if(D1[0]==D2[0]){//se e uguale
                        printf("non succede niente");
                    }
                    break;//istruzione di blocco
                case 2://se decide di difendere con due dadi
                    if((D1[0]>D2[0])&&(D1[1]>D2[1])){//se e maggiore
                        T[sceltaT1].Armate=T[sceltaT1].Armate-2;
                    }else if((D1[0]<D2[0])&&(D1[1]<D2[1])){//se e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                    }else if((D1[0]<D2[0])&&(D1[1]>D2[1])){//se un solo dado e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che è stato attaccato
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]>D2[0])&&(D1[1]<D2[1])){//seconda variabile che il dado sia minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che è stato attaccato
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]==D2[0])&&(D1[1]==D2[1])){//se i dadi sono uguale
                        printf("non succede niente");
                    }else if((D1[0]==D2[0])&&(D1[1]<D2[1])){//se un dado e minore e uno uguale
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]<D2[0])&&(D1[1]==D2[1])){//se un dado e minore e uno uguale variante
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]==D2[0])&&(D1[1]>D2[1])){//se un dado e maggiore e uno uguale
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che è stato attaccato
                    }else if((D1[0]>D2[0])&&(D1[1]==D2[1])){//se un dado e maggiore e uno uguale variante
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che è stato attaccato
                    }
                    break;//istruzzione per la fine del blocco
                case 3://caso con tre dadi in difesa
                    if((D1[0]>D2[0])&&(D1[1]>D2[1])){//se sono tutti maggiori
                        T[sceltaT1].Armate=T[sceltaT1].Armate-2;
                    }else if((D1[0]<D2[0])&&(D1[1]<D2[1])){//se sono tutti minori
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                    }else if((D1[0]<D2[0])&&(D1[1]>D2[1])){//se uno e maggiore e l'altro e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che è stato attaccato
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]>D2[0])&&(D1[1]<D2[1])){//se uno e maggiore e l'altro e minore variante
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che è stato attaccato
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]==D2[0])&&(D1[1]==D2[1])){//se sono tutti uguali
                        printf("non succede niente");
                    }else if((D1[0]==D2[0])&&(D1[1]<D2[1])){//se un dado e minore e uno uguale
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]<D2[0])&&(D1[1]==D2[1])){//se un dado e minore e uno uguale variante
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]==D2[0])&&(D1[1]>D2[1])){//se un dado e maggiore e uno uguale
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]>D2[0])&&(D1[1]==D2[1])){//se un dado e maggiore e uno uguale variante
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }
                    break;//istruzione di fine blocco
            }
            break;//istruzione di fine blocco dello switch principale
        case 3://caso in cui ci sono tre dadi in attacco
            switch(sceltaD){//questo mi permettere di scegliere con quanti dadi dovra difendere
                case 1://solo un dado in difesa
                    if((D1[0]>D2[0])){//se e maggiore
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che è stato attaccato
                    }else if((D1[0]<D2[0])){//se e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if(D1[0]==D2[0]){//se e uguale
                        printf("non succede niente");
                    }
                    break;//istruzione fine blocco

                case 2://se in difesa abbiamo due dadi
                    if((D1[0]>D2[0])&&(D1[1]>D2[1])){//se sono tutti maggiori
                        T[sceltaT1].Armate=T[sceltaT1].Armate-2;
                    }else if((D1[0]<D2[0])&&(D1[1]<D2[1])){//se sono tutti minori
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                    }else if((D1[0]<D2[0])&&(D1[1]>D2[1])){//se uno e maggiore e l'altro e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che è stato attaccato
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]>D2[0])&&(D1[1]<D2[1])){//se uno e maggiore e l'altro e minore variante
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che è stato attaccato
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]==D2[0])&&(D1[1]==D2[1])){//se sono tutti uguali
                        printf("non succede niente");
                    }else if((D1[0]==D2[0])&&(D1[1]<D2[1])){//se un dado e minore e uno uguale
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]<D2[0])&&(D1[1]==D2[1])){//se un dado e minore e uno uguale variante
                        T[sceltaT].Armate=T[sceltaT].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]==D2[0])&&(D1[1]>D2[1])){//se un dado e maggiore e uno uguale
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }else if((D1[0]>D2[0])&&(D1[1]==D2[1])){//se un dado e maggiore e uno uguale variante
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;//elimino un armata dal territorio che sta attaccando
                    }
                    break;//istruzione di fine blocco
                case 3://se ci sono tre dadi in difesa
                    if((D1[0]>D2[0])&&(D1[1]>D2[1])&&(D1[2]>D2[2])){//se sono tutti maggiori
                        T[sceltaT1].Armate=T[sceltaT1].Armate-3;
                    }else if((D1[0]<D2[0])&&(D1[1]>D2[1])&&(D1[2]>D2[2])){//se solo uno e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]>D2[0])&&(D1[1]<D2[1])&&(D1[2]>D2[2])){//se solo uno e minore variante 1
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]>D2[0])&&(D1[1]>D2[1])&&(D1[2]<D2[2])){//se solo uno e minore variante 2
                        T[sceltaT1].Armate=T[sceltaT1].Armate-2;
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                    }else if((D1[0]<D2[0])&&(D1[1]<D2[1])&&(D1[2]>D2[2])){// se sono due minori
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]<D2[0])&&(D1[1]>D2[1])&&(D1[2]<D2[2])){// se sono due minori variante 1
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]>D2[0])&&(D1[1]<D2[1])&&(D1[2]<D2[2])){// se sono due minori variante 2
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]<D2[0])&&(D1[1]<D2[1])&&(D1[2]<D2[2])){//se sono tutti minori
                        T[sceltaT1].Armate=T[sceltaT1].Armate-3;
                    }else if((D1[0]==D2[0])&&(D1[1]==D2[1])&&(D1[2]==D2[2])){// se sono tutti uguali
                        printf("non succede niente");
                    }else if((D1[0]<D2[0])&&(D1[1]==D2[1])&&(D1[2]==D2[2])){//se solo uno e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                    }else if((D1[0]==D2[0])&&(D1[1]<D2[1])&&(D1[2]==D2[2])){//se solo uno e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                    }else if((D1[0]==D2[0])&&(D1[1]==D2[1])&&(D1[2]<D2[2])){//se solo uno e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                    }else if((D1[0]>D2[0])&&(D1[1]==D2[1])&&(D1[2]==D2[2])){//se solo uno e maggiore
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]==D2[0])&&(D1[1]>D2[1])&&(D1[2]==D2[2])){//se solo uno e maggiore
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]==D2[0])&&(D1[1]==D2[1])&&(D1[2]>D2[2])){//se solo uno e maggiore
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]<D2[0])&&(D1[1]<D2[1])&&(D1[2]==D2[2])){//se sono due minori
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                    }else if((D1[0]==D2[0])&&(D1[1]<D2[1])&&(D1[2]<D2[2])){//se sono due minori variante 1
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                    }else if((D1[0]<D2[0])&&(D1[1]==D2[1])&&(D1[2]<D2[2])){//se sono due minori variante 2
                        T[sceltaT].Armate=T[sceltaT].Armate-2;
                    }else if((D1[0]>D2[0])&&(D1[1]>D2[1])&&(D1[2]==D2[2])){//se sono due maggiori
                        T[sceltaT1].Armate=T[sceltaT1].Armate-2;
                    }else if((D1[0]==D2[0])&&(D1[1]>D2[1])&&(D1[2]>D2[2])){//se sono due maggiori variante 1
                        T[sceltaT1].Armate=T[sceltaT1].Armate-2;
                    }else if((D1[0]>D2[0])&&(D1[1]==D2[1])&&(D1[2]>D2[2])){//se sono due maggiori variante 2
                        T[sceltaT1].Armate=T[sceltaT1].Armate-2;
                    }else if((D1[0]<D2[0])&&(D1[1]==D2[1])&&(D1[2]>D2[2])){//se uno e maggiore e uno e minore
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]<D2[0])&&(D1[1]>D2[1])&&(D1[2]==D2[2])){//se uno e maggiore e uno e minore variante 1
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]>D2[0])&&(D1[1]==D2[1])&&(D1[2]<D2[2])){//se uno e maggiore e uno e minore variante 2
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]>D2[0])&&(D1[1]<D2[1])&&(D1[2]==D2[2])){//se uno e maggiore e uno e minore variante 3
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]==D2[0])&&(D1[1]<D2[1])&&(D1[2]>D2[2])){//se uno e maggiore e uno e minore variante 4
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }else if((D1[0]==D2[0])&&(D1[1]>D2[1])&&(D1[2]<D2[2])){//se uno e maggiore e uno e minore variante 5
                        T[sceltaT].Armate=T[sceltaT].Armate-1;
                        T[sceltaT1].Armate=T[sceltaT1].Armate-1;
                    }
                    break;//istruzione di fine blocco
            }
            break;//istruzione di fine blocco dello switch principale
    }//fine switch case
    if(T[sceltaT1].Armate<1){//controllo il territorio è rimasto scoperto per le truppe
        printf("il territorio e stato conquistato dal giocatore");//stampo a schermo il messaggio
        T[sceltaT1].Armate=1;//sto assegnando un armata dal territorio che ha attaccato
        T[sceltaT1].Proprietario=G[a].ID;//sto passando l'id del nuovo propretario
        T[sceltaT].Armate=T[sceltaT].Armate-1;//levo un armata per assegnarla al territorio
    }
}//fine della funzione di attacco


void spostamento_truppe(int a,struct tabellone *T){
    giocatore *G;
    int i,b;//variabile che mi serve per il for
    int scelta,sceltaB,sceltaC;
    //devo stampare tutti i territori che ha il giocatore per poi spostare le truppe
    for(i=0;i<28;i++){//dovrebbe permettere di stampare tutti i terreni relativi al utente con lo stesso id
        if(T[i].Proprietario==G[a].ID){
            printf("%d)%s",i,T[i].nome);//stampa in sucessione tutti i terreni appartenenti alla stessa persona
            printf("%d",T[i].Armate);
        }
    }//fine for
    printf("seleziona in base al numero il terreno dove vuoi che le truppe siano levate");
    scanf("%d",&scelta);//prendo in ingresso da tastiera
    getchar();//mi serve per evitare che prenda il valore del invio e mi vada a riempire le prossime variabili a scelta
    for(i=0;i<26;i++){
        if(isAdjacent(scelta,i)==true){
            printf("puoi spostarle nei seguenti territori adicenti");
            printf("%d)%s",i,T[i].nome);

        }
    }
    printf("scelgli dove spostare le tue truppe");
    scanf("%d",&sceltaB);//prendo in ingresso da tastiera
    getchar();//mi serve per evitare che prenda il valore del invio e mi vada a riempire le prossime variabili a scelta
    do {//mi permette di rimandare la scelta del terreno se il gioccatore la scelgie sbagliata
        if (isAdjacent(scelta, sceltaB) == true) {
            printf("nel terreno a tua scelta ci sono %d truppe",T[i].Armate);
            printf("quante truppe vuoi spostare dal altro terreno ");
            scanf("%d",&sceltaC);
            do{//questo do mi permette di rimandare dinuovo la scelta delle truppe se risulta sbagliata
                if(T[scelta].Armate>sceltaC) {
                    T[scelta].Armate=T[scelta].Armate-sceltaC;
                    T[sceltaB].Armate=T[sceltaB].Armate+sceltaC;
                    break;
                }else{
                    printf("hai sbagliato inserendo il numero delle truppe da spostare riprova");
                }
            }while(-1);
            break;
        }else{
            printf("hai sbagliato iserendo il numero del territorio ");
        }
    }while(-1);
}//fine funzione

void visualizza(struct Lista *a){
    printf("\npuntalista----->");
    while(a != NULL){
        printf("%d\n",a->m.Numero);
        printf("%s\n",a->m.Testo);
        printf("%d\n",a->m.F);
        printf("%d\n",a->m.Simbolo);
        printf("--->");
        a=a->pnext;
    }
    printf("NULL\n\n");

}
