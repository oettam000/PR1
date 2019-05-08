#include "docente.h"

//This global constant variable contains the adjacencies of the territories (true if a territory is adjacent with another).
const _Bool t[N_TERRITORI][N_TERRITORI] = {//matrice dei terreni fornita dal docente //nota per me da non cambiare in alcun modo matrice gia completa di tutto
        {false, false, true,  false, false, false, false, false, false, false, false, false, true,  false, false, false, false, true,  false, false, false, false, false, false, false, false},
        {false, false, true,  true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {true,  true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, true,  false, false, true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  false, false, false, false, false, false},
        {false, false, false, true,  false, true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, true,  false, false, true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, true,  true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, true,  true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, true,  false, false, false, true,  false, false, false, false, false, true,  false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, true,  false, false, false, false, false, false, false, false, false, true,  false, false, false, false, false},
        {false, false, false, false, false, false, false, false, true,  true,  false, true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
        {true,  false, false, false, false, false, false, false, false, false, false, false, false, true,  true,  false, false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, true,  false, true,  false, true,  false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, true,  true,  false, true,  false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  false, false, true,  false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, true,  false, false, false, false, true,  false, false, false, false, false, false, false, false, false, false, false, false},
        {true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  false, false, true,  false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  false, true,  false, true,  false, false, false, false},
        {false, false, false, true,  false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  false, true,  true,  true,  false, false, false},
        {false, false, false, false, false, false, false, false, false, true,  false, false, false, false, false, false, false, false, false, true,  false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  true,  false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  false, false, false, true,  false, true},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  false, true,  false},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  false, true},
        {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,  false, true,  false}
};//fine matrice di controllo dei terreni

/**
 * This function checks if two territories are adjacent (reachable from each other).
 * @param idFirst  the id of the first territory
 * @param idSecond the id of the second territory
 * @return it returns true if they are adjacent, false otherwise
 */
_Bool isAdjacent(int idFirst,
                 int idSecond) {//questa semplice funzione controlla se si possono attaccare i terreni da dove si trova il giocatore
    return t[idFirst][idSecond];
}

//******************inizio parte del codice con le relative strutture ed enumerazioni**********************//
enum colore {
    ROSSO, NERO, VIOLA, VERDE, GIALLO, BLU
};//questa enumerazione contiene tutti i colori delle armate che useranno i giocatori
enum simbolo {
    caffe, birra, vino, jolly
};


enum coloreD {
    rosso, blu
};//questa enumerazione è per i dadi che mi dice i dadi di attaccoed i dadi di difesa


enum facolta {
    studi_umanistici,
    biologia_e_farmacia,
    ingegneria_e_architettura,
    scienze_merendine,
    medicina_chirurgia,
    scienze,
    nullo
};//questa enumerazione ci serve per capire a quale dipartimento fanno capo le singole facolta


typedef struct {//struttura che definisce il giocatore in tutte le sue parti
    enum colore Colore;//questo mi serve per dare il valore del colore al singolo giocatore
    int ID;//valore identificativo del giocatore
    int Ncarte;//questo valore sta ad indicare il numero di carte che il giocatore ha in mano
    int numero_truppe;//questo valore ci fornisce il numero massimo di truppe che puo avere il giocatore quindi ogni volta che il giocatore prendera una truppa andremo a scalare il valore da questo numero
    int territori;//numero di territori appartenente al giocatore
    char Nome[DIM]; //nome corrispondente al giocatore stando al linguaggio del c 89/90 devono stare alla fine della struttura
} giocatore;//fine struttura giocatore

giocatore G[6] = {{ROSSO,  0, 0, 0, 0,"GENOVEFFA"},
                  {NERO,   1, 0, 0, 0,"DAVIDE"},
                  {VIOLA,  2, 0, 0, 0,"FABIOLA"},
                  {VERDE,  3, 0, 0, 0,"SOCRATE"},
                  {GIALLO, 4, 0, 0, 0,"FRANCESCA"},
                  {BLU,    5, 0, 0, 0,"FRANCESCO"}};//definisco un vettore di strutture statico e lo inizzializzo

typedef struct{//quetsa struttura mi servve per il salvataggio delle carte al interno del file salvataggio.rsk
    int ID;//id relativo al giocatore
    int NCARTA;//valore della carta
}carte;
carte DECK[27];
struct tabellone {//inizio struttura terreno
    int Vterritorio;//puo prendere valori che vanno da 0 a 25
    int Proprietario;//puo prendere valori che vanno da 0 a 5
    int Armate;//questo indica il numero di armate che ci sono al interno di quel terreno che possono andare da '0 a 100
    char nome[DIM + 1];
};//fine struttura terreno


typedef struct {//inizio della struttura del mazzo
    int Numero;
    int id;
    enum simbolo Simbolo;//simbolo riportato nella carta
    enum facolta F;//enumerazione di ragruppamento per il dipartimento
    char Testo[DIM];//do la stezsa dimensione del nome da mettere nelle carte
} mazzo;//fine della struttura del mazzo

mazzo M[28] = {{0,0,  vino,  studi_umanistici,          "Psicologia"},
               {1,0,  birra, studi_umanistici,          "filosofia"},
               {2,0,  vino,  studi_umanistici,          "pedagogia"},
               {3,0,  birra, studi_umanistici,          "lettere"},
               {4,0,  caffe, studi_umanistici,          "lingue"},
               {5,0,  vino,  scienze_merendine,         "economia"},
               {6,0,  birra, scienze_merendine,         "Scienze politiche"},
               {7,0,  caffe, scienze_merendine,         "Giurisprudenza"},
               {8,0,  vino,  medicina_chirurgia,        "Odontoiatra"},
               {9,0,  caffe, medicina_chirurgia,        "Infermieristica"},
               {10,0, caffe, medicina_chirurgia,        "Medicina"},
               {11,0, birra, medicina_chirurgia,        "Scienze motorie"},
               {12,0, vino,  biologia_e_farmacia,       "CTF"},
               {13,0, caffe, biologia_e_farmacia,       "tossicologia"},
               {14,0, birra, biologia_e_farmacia,       "Biologia"},
               {15,0, caffe, biologia_e_farmacia,       "Scienze della natura"},
               {16,0, vino,  biologia_e_farmacia,       "farmacia"},
               {17,0, caffe, ingegneria_e_architettura, "Ing,Chimica"},
               {18,0, birra, ingegneria_e_architettura, "Ing,Meccanica"},
               {19,0, caffe, ingegneria_e_architettura, "Ing,Elettronica"},
               {20,0, caffe, ingegneria_e_architettura, "Architettura"},
               {21,0, birra, ingegneria_e_architettura, "Ing,Civile"},
               {22,0, caffe, scienze,                   "Chimica"},
               {23,0, caffe, scienze,                   "Fisica"},
               {24,0, birra, scienze,                   "Informatica"},
               {25,0, caffe, scienze,                   "Matematica"},
               {26,0, jolly, nullo,                     "jolly"},
               {27,0, jolly, nullo,                     "jolly"}};





struct Lista {//creazione della struttura lista
    mazzo m;//dichiaro un vettore della struttura mazzo di 26 spazzi
    struct Lista *pnext;//puntatore al prossimo elemento della lista
};
struct Smaz{
    int nCarte;
    int vet[27];
};
typedef struct{
    char Nome[DIM+1];
    int Carmate;
    int Ncarte;
}GSAV;

struct savtab{
    int id;
    int idp;
    int armate;
};
struct savT{
    struct savtab tab[26];
};
typedef struct {
    int nGiocatore;
    int IDGiocatore;
    GSAV Giocatore[GIOCATORI];//un blocco per ogni giocatore
    int vat[28];
    struct savT Ta;
    struct Smaz maz;
}Salvataggio;

//********************fine parte del codice relativo a strutture e enumerazioni*************************************//
/******porzione di codice relativa al lancio dei dadi*******/
int Adadi() {//inizio funzione per la generazione dei numeri casuali tramite i dadi
    srand(time(NULL));//inizializzazione del seed a zero
    int Adado;//variabili dei dadi per l'attacco
    Adado = 1 + rand() % 6 - 1 + 1;//generazione del numero random per il dado con gli estremi compresi
    return Adado;
}//fine della funzione dei dadi di attacco
//devo generare un altra funzione che mi permette di vreare un lista o per qualcosa di simile per la il controllo delle infoemazioni sul terreno di gioco altrimenti non posso controllare le informazioni relative a i terreni


int Bdadi() {//dovro assegnare unn vettore per i dadi in modo che non mi creino problemi altrimenti non so come passare i dati
    srand(time(NULL));//inizializzazione del seed a zero
    int Bdado;
    Bdado = 1 + rand() % 6 - 1 + 1;//generazione del numero random per il dado con gli estremi compresi
    return Bdado;
}//fine della funzione dei dadi in difesa
/***************fine porzione relativa al lancio dei dadi******************/


void gioca() {//semplice funzione di controllo che mi permette di capire quali sono i giocatori giocanti e la loro struttura
    int i;//valore di i che mi serve per scorrere i giocatori
    for (i = 0;i < GIOCATORI; i++) {//semplice costrutto for che funziona da contatore e mi fa scorrere tutti i giocatori
        printf("%s\n", G[i].Nome);//stampo il nome del giocatore
        printf("%d\n",G[i].ID);//stampo l'id del giocatore che poi verra dato a i terreni per capire se siano loro o meno
        printf("%d\n", G[i].numero_truppe);//il numero delle truppe che ha il giocatore
    }
}

void generazione_giocatori() {//questa funzione mi permette di definire il numero massimo assegnate al inizio del gioco a i giocatori che cambiera al variare degli stessi
    switch (GIOCATORI) {
        case 3:
            G[0].numero_truppe = 35;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[1].numero_truppe = 35;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[2].numero_truppe = 35;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            break;
        case 4:
            G[0].numero_truppe = 30;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[1].numero_truppe = 30;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[2].numero_truppe = 30;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[3].numero_truppe = 30;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            break;
        case 5:
            G[0].numero_truppe = 25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[1].numero_truppe = 25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[2].numero_truppe = 25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[3].numero_truppe = 25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[4].numero_truppe = 25;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            break;
        case 6:
            G[0].numero_truppe = 20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[1].numero_truppe = 20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[2].numero_truppe = 20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[3].numero_truppe = 20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[4].numero_truppe = 20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            G[5].numero_truppe = 20;//cambio il valore delle truppe al inizio in modo che ogni volta non si abbia bisogno di vambiare il valore nel vettore statico
            break;
        default:
            printf("hai sbagliato cambiando la variabile macro\n");//questo messaggio viene visualizzato solo quando si sbaglia a cambiare il valore macro delle impostazioni nel file docente.h
    }
    //adesso provero a fare una parte di codice che mi permette di assegnare il valore contenuto nella lista delle carte ad il valore id del giocatore
    //mi da un altro errore che consiste nella richiamata come valore di ritorno di una valore che è contenuto solo nella variabile locale
    //devo sempre controllare il valore di ritorno di questa funzione perche potrebbe crearmi problemi in compilazione o a run-time

}

struct Lista *generazione_mazzo() {//generazione della lista del mazzo e prima mandata a i giocatori
    struct Lista *MAZZO = NULL, *paus = NULL;//dichiarazione dei puntatori e dei puntatori ausiliari
    int i = 0, j = 0;//variabile che mi serve nel vor come contatore
    ///parte della creazione della lista
    MAZZO = (struct Lista *) malloc(sizeof(struct Lista));//allocazione dinamica della struttura lista
    MAZZO->m = M[i];//assegnazione del primo elemento della lista
    paus = MAZZO;//assegnazione al puntatore ausiliario l'allocazione di memoria del puntatore mazzo
    for (i = 1; i < 26; i++) {//for per l'assegnazione dei prossimi elementi della lista
        paus->pnext = (struct Lista *) malloc(sizeof(struct Lista));//allocazione dei prossimi n elementi
        paus = paus->pnext;//passaggio del valore della prossima cella di memoria
        paus->m = M[i];//assegnazione del dato da mettere nella lista
    }//fine for per l'assegnazione della lista
    paus->pnext = NULL;//una volta finita l'allocazione dinamica della lista devo chiuderla
    ////parte che cambia l'ordine delle carte al interno della lista devo ancora terminarla
    //devo ancora modificare questa porzione di code in modo che mescoli le carte
    return (MAZZO);//il valore di ritorno che mi rende la lista del mazzo senza mischiare al inizio
    //devo capire perche qua mi da un warning altrimenti potrebbe esserci un problema con il codice in fatto di compilazione
}//fine della funzione


struct Lista *mescola(struct Lista *MAZZO) {
    int i = 0, j = 0;
    int random = 1;
    struct Lista *PrimaCarta = NULL, *pNext = NULL, *pLnext = NULL;
    srand(time(NULL));
    for (i = 0; i < 6; i++) {//mescolate che vengono date al mazzo
        random = rand() % 25 + 1;
        if (random == 0)random = 1;
        PrimaCarta = MAZZO;
        pLnext = MAZZO;
        MAZZO = pLnext->pnext;
        for (j = 0; j < random && pLnext != NULL; j++) {
            pLnext = pLnext->pnext;
        }
        pNext = pLnext->pnext;
        pLnext->pnext = PrimaCarta;
        pLnext->pnext->pnext = pNext;
    }
    return MAZZO;
}
struct Lista *Pesca(int b,int i,struct Lista *MAZZO){//questa funzione permette di pescare una carta a turno per il giocatore
    struct Lista *primaCarta=NULL, *Pnext=NULL, *pLnext=NULL;
    if(MAZZO==NULL){//controlla se il puntatore al mazzo è arrivata alla fine se e cosi stampa il messaggio eltrimenti esegue quello dopo
        printf("sono finite le carte");//stampa il messaggio al giocatore
    }else {
        DECK[b].NCARTA = MAZZO->m.Numero;//assegno il numero della carta alla struttura carta
        DECK[b].ID = G[i].ID;//assegno il valore del id del giocatore che pesca la carta alla struttura carta
        primaCarta = MAZZO;//passo a primaCarta il primo elemento della lista
        Pnext = MAZZO;//passo la testa della lista al puntatore pNxt per essere incrementato e permettermi di cancellare il primo elemento della lista corrente
        MAZZO = Pnext->pnext;//passo avanti al prossimo elemento della lista
        free(primaCarta);//elimino il primo elemento della lista
    }
    return MAZZO; //ritorno al puntatore a struttura
};

void truppe(int b) {//questa funzione serve per vedere se il giocatore è arrivato al limite massimo delle sue truppe ossia 100
    int aggiunta;//questo valore mi da la possibilita di icrementare il numero di truppe ad ogni turno
    if (G[b].numero_truppe < 100) {//controllo per l'aggiunta delle truppe del giocatore
        aggiunta = G[b].territori / 3;//
        G[b].numero_truppe=G[b].numero_truppe+aggiunta;//con questa operazione incremento il numero delle truppe del giocatore
    printf("%d",G[b].territori);
    } else {
        printf("hai raggiunto il limite massimo delle truppe dora devi giostrartela bene\n ");//messaggio di ritorno al giocatore
    }
}//fine funzione truppe



struct tabellone *fase_pre_gioco(int random, struct Lista *MAZZO) {
    struct tabellone *T = NULL;//creo il puntatore alla struttura e lo inizializzo a null
    T = (struct tabellone *) malloc(26 * sizeof(struct tabellone));//alloco lo spazio per ogni spazio sul tabellone
    int i, j = 0;//variabile che mi serve per passare il valore del giocatore iniziale
    for (i = random; i <= GIOCATORI; i++) {//con questo for asseggno ad ogni giocatore un tot di carte
        if (i <= GIOCATORI) {//questo controllo lo fa ritornare sempre alla prima posizione del giocatore
            //ritorna sempre alla prima posizione
            T[j].Vterritorio = M[j].Numero;//assegno il valore del territorio in base al valore delle carte che sto distribuendo
            T[j].Armate = 0;//assegno alle armate presenti al interno del terreno il valore zero
            strcpy(T[j].nome, M[j].Testo);//copio il testo della carta al interno del valore del tabellone
            j++;//incremento la variabile altrimenti controllo solo la stessa parte di territorio e la stessa carta continuamente
            i = 0;//questo succede solo se il valore del for arriva alla fine del ciclo in modo che ritorni sempre a zero e rincominci
        } else {//fine del controllo
            T[j].Vterritorio = M[j].Numero;//assegno il valore del territorio in base al valore delle carte che sto distribuendo
            T[j].Armate = 0;//assegno alle armate presenti al interno del terreno il valore zero
            strcpy(T[j].nome, M[j].Testo);//copio il testo della carta al interno del valore del tabellone
            j++;//incremento il valore di j per andare avanti con il mazzo
        }//fine else
        if (j == 25) {
            break;
        }
    }
    return T;
}

struct tabellone *Proprietario(struct tabellone *T, int random) {
    int i = 0;
    int j = random;
    do {
        T[i].Proprietario = j;
        G[j].territori++;
        i++;
        j++;
        if (j >= GIOCATORI) {
            j = 0;
        }
    } while (i != 26);
    return T;
};

void tabelloneVIS(struct tabellone *a) {//questa funzione mi serve per visualizzare tutti i territori del campo di gioco
    int i;
    for (i = 0; i < 25; i++) {
        printf("\n%s\n", a[i].nome);
        printf("\n%d\n", a[i].Proprietario);
        printf("\n%d\n", a[i].Armate);
        printf("\n%d\n", a[i].Vterritorio);
    }
}
void schieramento(struct tabellone *T, int random) {
    int i, j, a,b,c,d;//variabili che mi servono per i cicli e contenitori vari
    int scelta;//variabile che mi serve per la scelta del giocatore
    int valoreT[GIOCATORI];//arrai per le truppe di ogni giocatore
    int flag=0;//variabile di supporto che mi serve per uscire dal ciclo do-while per farla funzionare in modo decente la sto inizializzando a 0
    for(a=0;a<GIOCATORI;a++){//mi serve solo per settare a zero il valore delle truppe per poi iniziare ad incrementare
        valoreT[a]=0;
    }
    a=35;
    b=30;
    c=25;
    d=20;
    i = random;//assegno al valore i il valore di random generato al interno del main
    j = 0;//assegno al valore j il valore zero//faccio partire il ciclo
    if (GIOCATORI == 3) {
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 25) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<a)&&(valoreT[1]<a)&&(valoreT[2]<a));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<a)&&(valoreT[1]<a)&&(valoreT[2]<a));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<a)&&(valoreT[1]<a)&&(valoreT[2]<a));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
    } else if (GIOCATORI == 4) {
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<b)&&(valoreT[1]<b)&&(valoreT[2]<b)&&(valoreT[3]<b));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<b)&&(valoreT[1]<b)&&(valoreT[2]<b)&&(valoreT[3]<b));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<b)&&(valoreT[1]<b)&&(valoreT[2]<b)&&(valoreT[3]<b));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<b)&&(valoreT[1]<b)&&(valoreT[2]<b)&&(valoreT[3]<b));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
} else if (GIOCATORI == 5) {
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<c)&&(valoreT[1]<c)&&(valoreT[2]<c)&&(valoreT[3]<c)&&(valoreT[4]<c));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<c)&&(valoreT[1]<c)&&(valoreT[2]<c)&&(valoreT[3]<c)&&(valoreT[4]<c));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<c)&&(valoreT[1]<c)&&(valoreT[2]<c)&&(valoreT[3]<c)&&(valoreT[4]<c));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<c)&&(valoreT[1]<c)&&(valoreT[2]<c)&&(valoreT[3]<c)&&(valoreT[4]<c));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<c)&&(valoreT[1]<c)&&(valoreT[2]<c)&&(valoreT[3]<c)&&(valoreT[4]<c));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato

} else if (GIOCATORI == 6) {
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<d)&&(valoreT[1]<d)&&(valoreT[2]<d)&&(valoreT[3]<d)&&(valoreT[4]<d)&&(valoreT[5]<d));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<d)&&(valoreT[1]<d)&&(valoreT[2]<d)&&(valoreT[3]<d)&&(valoreT[4]<d)&&(valoreT[5]<d));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<d)&&(valoreT[1]<d)&&(valoreT[2]<d)&&(valoreT[3]<d)&&(valoreT[4]<d)&&(valoreT[5]<d));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<d)&&(valoreT[1]<d)&&(valoreT[2]<d)&&(valoreT[3]<d)&&(valoreT[4]<d)&&(valoreT[5]<d));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<d)&&(valoreT[1]<d)&&(valoreT[2]<d)&&(valoreT[3]<d)&&(valoreT[4]<d)&&(valoreT[5]<d));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato
        do {//mi permette di eseguire il ciclo almeno una volta

            if (T[j].Proprietario==G[i].ID) {//in teoria questo dovrebbe farmi vedere quale terreno appartiene ad oggni proprietario
                printf("\nil terreno dove devi mettere le truppe e' :%s\n",T[j].nome);//mi stampa il nome del territorio in questione
                printf("%s\n",G[i].Nome);
                printf("hai ancora a disposizione :%d",G[i].numero_truppe-valoreT[i]);
                printf("\ndecidi quante truppe da piazzare al interrno del territorio ti ricordo che ne puoi mettere solo 3 alla volta\n ");//ricorda al utente che puo mettere solo da 1 a 4 truppe sul terreno
                printf("\nil numero di armate presenti al interno del territorio  e' :%d",T[j].Armate);
                scanf("%d", &scelta);//mi serve per liberare il buffer daleventuale presa del tasto di invio
                if ((G[i].numero_truppe>0)){//il numero va a crescere cosiche quando arriva al numero massimo delle armate si ferma
                    switch (scelta) {//inizio costrutto di scelta
                        case 1://se la scelta equivale a 1
                            T[j].Armate=T[j].Armate+1;//incremento il valore delle armate di uno
                            valoreT[i]=valoreT[i]+1;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di j
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 2://se la scelta ecquivale a 2
                            T[j].Armate = T[j].Armate + 2;//incremento il valore delle armate di due
                            valoreT[i] = valoreT[i] + 2;//incremento il valore della impostazione di controllo
                            j++;//incrementa il valore di j
                            i++;//incrementa il valore di i
                            if(j==25){
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        case 3:// se la scelta ecquivale a 3
                            T[j].Armate = T[j].Armate + 3;//incremento il valore delle armate di tre
                            valoreT[i] = valoreT[i] + 3;//incremento il valore della impostazione di controllo
                            j++;//incremento il valore di j
                            i++;//incremento il valore di i
                            if(j==25){//non mi ricordo per quale motivo ho cambiatoquesto valore l'ultima volta pero sicuramente aveva a che fare con i territori
                                j=0;
                            }
                            if(i==GIOCATORI){
                                i=0;
                            }
                            break;//istruzione che serve per terminare il costrutto switch
                        default ://se la scelta non è contemplata con le impostazioni che ho dato al programma
                            printf("hai inserito un valore non supportato riprova\n");//stampa a video il messaggio di errore
                    }//fine costrutto di scelta

                }else{printf("hai finito il numero di truppe mi dispiace ma tu non puoi metterne altre");
                    i++;
                    if(i==GIOCATORI-1){
                        i=0;
                    }
                }
            }else {//questo succede se non trova delle corrispondenze
                j++;
                if (j == 24) {
                    j = 0;
                }
            }

        }while ((valoreT[0]<d)&&(valoreT[1]<d)&&(valoreT[2]<d)&&(valoreT[3]<d)&&(valoreT[4]<d)&&(valoreT[5]<d));//questa condizione mi permette di rifar ciclare il codice al interno del do perche si ha inserito un valore diverso da quello che deve essere
//qua metto un altro if else perche qua finisce appena arriva al valore designato

    }
}


int Fase_principale(int random,struct tabellone *T,struct Lista *MAZZO) {//questa e la fase principale del progetto prende in ingresso la struttura giocatore e il valore generato random
    //fase iniziale del turno //
    int scelta;//questa e la scelta che esegue l'utente
    int i,k,b=0;//variabile indice del for

    for (i = random; i <GIOCATORI; i++) {//questo for cicla al infinito in modo che il programma continui a girare a meno che non si utilizza la funzione apposta per uscire
        //truppe(G,i);//assegno delle truppe al giocatore
        truppe(i);//incrementa il numero delle truppe del giocatore corrente
        if(b<27) {
            Pesca(b,i,MAZZO);//faccio pescare al giocatore una carta
            b++;//incremento il valore di b
        }
        do {
        if (i == (GIOCATORI-1)) {//mi serve per azzerare il valore di controllo del for
            printf("\nE' il turno del giocatore %s\n", G[i].Nome);
            truppe(i);// aumenta le truppe relative al giocatore
            printf("\nche cosa vuoi fare??\n");//stampa a video il messaggio
            printf("\n1)ATTACCARE\n");//stampa a video il messaggio
            printf("\n2)SPOSTARE TRUPPE\n");//stampa a video il messaggio
            printf("\n3)SALVARE\n");//stampa a video il messaggio
            printf("\n4)TERMINARE IL TURNO\n");//stampa a video il messaggio
            scanf("%d", &scelta);//faccio prendere un valore in ingresso da tastiera
            //getchar();//svuoto il buffer ed evito che venga preso il valore di enter come prossimo paramentro in ingresso
            k=i;//assegno il valore di i a k
            i=0;
            //i = i%GIOCATORI;//viene riportato a zero quando arriva al massimo dei giocatori
        } else {//questo deve avvenire quasi sempre ammeno che non si verifichi la situazione del if
            printf("\nE' il turno del giocatore %s\n", G[i].Nome);
            printf("\nche cosa vuoi fare??\n");//stampa a video il messaggio
            printf("\n1)ATTACCARE\n");//stampa a video il messaggio
            printf("\n2)SPOSTARE TRUPPE\n");//stampa a video il messaggio
            printf("\n3)SALVARE\n");//stampa a video il messaggio
            printf("\n4)TERMINARE IL TURNO\n");//stampa a video il messaggio
            scanf("%d", &scelta);//prende in ingresso un valore da tastiera
            //getchar();//svuoto il buffer e evito che venga preso il valore di enter come prossimo carattere in ingresso
            k=i;//assegno il valore di i a k

        }
            switch (scelta) {//in base al numero che viene digitato fa succedere le diverse funzioni
                case 1://se la scelta è uguale uno
                    gioca();
                    attacco(k, T);//situazione in cui si digita il numero 1
                    //qua prendo in ingresso delle funzioni in modo da non dilungare il codice oltremodo
                    break;//interrompe la questa parte di codice e la fa uscire dal flusso
                case 2://se la scelta è uguale a due
                    gioca();
                    spostamento_truppe(k, T);//situazione in cui si digita il numero 2
                    break;//interrompe la questa parte di codice e la fa uscire dal flusso
                case 3://situazione in cui si digita il numero 3
                    salvataggio(i,T);
                    break;//interrompe la questa parte di codice e la fa uscire dal flusso
                case 4://situazione in cui si digita il numero 4
                    printf("hai deciso di terminare il turno");
                    break;//interrompe la questa parte di codice e la fa uscire dal flusso
                default ://situazione in cui si digita il valore sbagliato
                    printf("hai inserito un numero sbagliato riprova");
            }
        } while (scelta >4);//viene fatto riciclare la parte al interno del do while perche si ha inserito un numero diverso da quelli elencati
        //devo controllare quali territori sono vicini ai terreni confinanti dei giocatore in questione e quale puo attaccare
        //devo prima dare le carte a tutti i giocatori altrimenti non posso andare avanti con il funzionamento del gioco
        //i =i%GIOCATORI;
    }//fine for
}//fine funzione principale

void attacco(int a,struct tabellone *T) {//questo è la funzione per l'attacco prende in ingresso il vettore giocatori piu il numero del attaccante e del difensore
    int scelta, sceltaD, sceltaT=0, sceltaT1=0, i=0, j=0,k;//variabili che mi  servono al interno della
    int D1[3], D2[3], D3; //dadi attacco, difesa ausiliari
    int alfa,vettore[25];
    printf("\n%s\n",G[a].Nome);//stampa il nome a video
    printf("\nscegli da quale dei tuoi terreni attaccare\n");
    //sto provando a cambiare la selezione dei territori da attaccare al posto di un for sto mettendo un do-while in modo che mi faccia vedere tutti i terreni
    for(alfa=0;alfa<25;alfa++){
        vettore[alfa]=0;//sto inizializzando il valore al interno del vettore a zero
    }
    i=0;
    do{
        if(T[j].Proprietario == G[a].ID){//
            printf("\n%d)%s\n", j, T[j].nome);//stampo tutti i nomi dei territori che hanno in comune l'id con il proprietario
            vettore[i]=j;
            i++;
        }
        j++;//aumento la variabile j per arrivare alla fine del array dei terreni
    }while(j<25);//controlla se j è diverso da 25 quando arriva a 25 si ferma

   /* for (i = 0; i < 25; i++) {
        if (T[i].Proprietario == G[i].ID) {
            printf("%d)%s", i, T[i].nome);
        }
    }*/
    i=0;
    do {
        scanf("%d", &sceltaT);
        do {
            if(vettore[i]!=sceltaT){
                if(i==25){
                    printf("hai inserito un valore sbagliato riprova");
                    attacco(a,T);//richiamo la funzione per poter reinserire il valore da zero con tutti i terreni che lo compongono
                    break;//sto mettendo questa interruzione per levarmi un sospetto
                }
                i++;
            }else{
                break;
            }

        }while(-1);
        if (T[sceltaT].Armate == 1) {//questo controlla se ci sono abbastanza truppe per poter attaccare il teritorio altrimenti viene visualizzato un messaggio di errore e che non possiamo attaccare da quel terreno
            printf("\nnon puoi attaccare da questo territorio");
        } else {
            break;
        }
    } while (-1);
    printf("\npuoi attaccare i seguenti terreni dal territorio che hai scelto\n");
    printf("\nquale terreno vuoi attaccare\n??");
    for (i = 0; i < 25; i++) {
        if(isAdjacent(sceltaT, i) == true){
            if(T[i].Proprietario!=G[a].ID){
                printf("\n%d)%s\n", i,T[i].nome);
            }
        }
    }
    //io qua sto ancora

    do {
        scanf("%d", &sceltaT1);
        if (isAdjacent(sceltaT, sceltaT1) == true) {
            printf("\nstai attaccando %s\n", T[sceltaT1].nome);
            break;//termina il flusso uscendo dal do in modo che il while messo a -1 non continui a ciclare al infinito
        } else {

            printf("\nhai sbagliato inserendo il numero del territorio da attaccare\n");
            printf("\nil terreno che hai selto non e' nelle vicinanze del tuo\n");
            for (i = 0; i < 25; i++) {
                if(isAdjacent(sceltaT, i) == true){
                    if(T[i].Proprietario!=G[a].ID){
                        printf("\n%d)%s\n", i,T[i].nome);
                    }
                }
            }
        }
    } while (-1);
    printf("scelgli con quante truppe attaccare il massimo e tre");
    scanf("%d", &scelta);
    getchar();
    for (i = 0; i < scelta; i++) {
        D1[i] = Adadi();
    }
    for(i=0;i<GIOCATORI;i++){//ciclo for che mi fa scorrere tutti i giocatori
        if(T[sceltaT1].Proprietario==G[i].ID){//controlla che l'id al interno del terreno sia uguale a quello del giocatore che sto scorrendo
            k=i;
            printf("\n%s\n",G[k].Nome);//siccome il numero del id e univoco non ci possono essere due persone con lo stesso id quindi blocco il ciclo appena trova una corrispondenza
            break;//istruzione che blocca il ciclo for appena trova una corrispondenza
        }
    }
    printf("\nscegli con quante truppe difendere\n");
    scanf("%d", &sceltaD);
    getchar();
    for (i = 0; i < sceltaD; i++) {
        D2[i] = Bdadi();
    }
    //queesta parte controlla i quali dadi sono quelli piu grand3
    //questi due for mi servono per avere il numero piu alto al inizio e cosi via cioe dobbiamo mettere i dadi in ordine
    //questi sono due funzioni bublesort per avere il dado piu grande al inizio e non in mezzo al gruppo dei dadi
    for (i = 0; i < scelta; i++) {//cicla in base al numero dei dadi
        for (j = 0; j < scelta; j++) {//seconda passata per trovare il numero piu  grande dei dadi
            if (D1[i] > D1[i + 1]) {
                D3 = D1[i];
                D1[i] = D1[i + 1];
                D1[i + 1] = D3;
            }
        }
    }
    for (i = 0; i< sceltaD; i++) {//cicla in base al numero dei dadi
        for (j = 0; j < sceltaD; j++) {//seconda passata per trovare il numero piu  grande dei dadi
            if (D2[i] > D2[i + 1]) {
                D3 = D2[i];
                D2[i] = D2[i + 1];
                D2[i + 1] = D3;
            }
        }
    }


    switch (scelta) {//questo primo switch mi permette di decidere quanti dadi verranno lanciati dal attaccante
        case 1:
            switch (sceltaD) {//questo mi permettere di scegliere con quanti dadi dovra difendere
                case 1:
                    if (D1[0] > D2[0]) {//controllo se e maggiore
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if (D1[0] < D2[0]) {//se e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if (D1[0] == D2[0]) {//se è uguale
                        printf("non succede niente");//questo messaggio avviene quando i dadi sono pari
                    }
                    break;//istruzione di blocco
                case 2:
                    if (D1[0] > D2[0]) {//controllo se e maggiore
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if (D1[0] < D2[0]) {//se e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if (D1[0] == D2[0]) {//se è uguale
                        printf("non succede niente");//questo messaggio avviene quando i dadi sono pari
                    }
                    break;//istruzione di blocco
                case 3:
                    if (D1[0] > D2[0]) {//controllo se e maggiore
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if (D1[0] < D2[0]) {//se e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if (D1[0] == D2[0]) {//se è uguale
                        printf("non succede niente");//questo messaggio avviene quando i dadi sono pari
                    }
                    break;//istruzione di blocco
            }
            break;//istruzione di blocco del prico caso del case principale
        case 2://secondo caso del case principale ossia andiamo a controllare i due dadi
            switch (sceltaD) {//questo mi permettere di scegliere con quanti dadi dovra difendere
                case 1://se decide di difendere con un dado
                    if ((D1[0] > D2[0])) {//se e maggiore
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] < D2[0])) {//se e minore
                        T[sceltaT].Armate = T[sceltaT1].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if (D1[0] == D2[0]) {//se e uguale
                        printf("non succede niente");
                    }
                    break;//istruzione di blocco
                case 2://se decide di difendere con due dadi
                    if ((D1[0] > D2[0]) && (D1[1] > D2[1])) {//se e maggiore
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 2;
                        printf("\nil giocatore %s perde due truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                    } else if ((D1[0] < D2[0]) && (D1[1] < D2[1])) {//se e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=2;
                    } else if ((D1[0] < D2[0]) && (D1[1] > D2[1])) {//se un solo dado e minore
                        T[sceltaT].Armate =T[sceltaT].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] < D2[1])) {//seconda variabile che il dado sia minore
                        T[sceltaT].Armate =T[sceltaT].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] == D2[1])) {//se i dadi sono uguale
                        printf("non succede niente");
                    } else if ((D1[0] == D2[0]) && (D1[1] < D2[1])) {//se un dado e minore e uno uguale
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] < D2[0]) && (D1[1] == D2[1])) {//se un dado e minore e uno uguale variante
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] > D2[1])) {//se un dado e maggiore e uno uguale
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] == D2[1])) {//se un dado e maggiore e uno uguale variante
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    }
                    break;//istruzzione per la fine del blocco
                case 3://caso con tre dadi in difesa
                    if ((D1[0] > D2[0]) && (D1[1] > D2[1])) {//se e maggiore
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 2;
                        printf("\nil giocatore %s perde due truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                    } else if ((D1[0] < D2[0]) && (D1[1] < D2[1])) {//se e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=2;
                    } else if ((D1[0] < D2[0]) && (D1[1] > D2[1])) {//se un solo dado e minore
                        T[sceltaT].Armate =T[sceltaT].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] < D2[1])) {//seconda variabile che il dado sia minore
                        T[sceltaT].Armate =T[sceltaT].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] == D2[1])) {//se i dadi sono uguale
                        printf("non succede niente");
                    } else if ((D1[0] == D2[0]) && (D1[1] < D2[1])) {//se un dado e minore e uno uguale
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] < D2[0]) && (D1[1] == D2[1])) {//se un dado e minore e uno uguale variante
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] > D2[1])) {//se un dado e maggiore e uno uguale
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] == D2[1])) {//se un dado e maggiore e uno uguale variante
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    }
                    break;//istruzzione per la fine del blocco
            }
            break;//istruzione di fine blocco dello switch principale
        case 3://caso in cui ci sono tre dadi in attacco
            switch (sceltaD) {//questo mi permettere di scegliere con quanti dadi dovra difendere
                case 1:
                    if ((D1[0] > D2[0])) {//se e maggiore
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] < D2[0])) {//se e minore
                        T[sceltaT].Armate = T[sceltaT1].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if (D1[0] == D2[0]) {//se e uguale
                        printf("non succede niente");
                    }
                    break;//istruzione di blocco
                case 2://se decide di difendere con due dadi
                    if ((D1[0] > D2[0]) && (D1[1] > D2[1])) {//se e maggiore
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 2;
                        printf("\nil giocatore %s perde due truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                    } else if ((D1[0] < D2[0]) && (D1[1] < D2[1])) {//se e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=2;
                    } else if ((D1[0] < D2[0]) && (D1[1] > D2[1])) {//se un solo dado e minore
                        T[sceltaT].Armate =T[sceltaT].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] < D2[1])) {//seconda variabile che il dado sia minore
                        T[sceltaT].Armate =T[sceltaT].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] == D2[1])) {//se i dadi sono uguale
                        printf("non succede niente");
                    } else if ((D1[0] == D2[0]) && (D1[1] < D2[1])) {//se un dado e minore e uno uguale
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] < D2[0]) && (D1[1] == D2[1])) {//se un dado e minore e uno uguale variante
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;//elimino un armata dal territorio che sta attaccando
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] > D2[1])) {//se un dado e maggiore e uno uguale
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] == D2[1])) {//se un dado e maggiore e uno uguale variante
                        T[sceltaT1].Armate =T[sceltaT1].Armate - 1;//elimino un armata dal territorio che è stato attaccato
                        printf("\nil giocatore %s perde una truppa\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    }
                    break;//istruzzione per la fine del blocco
                case 3://se ci sono tre dadi in difesa
                    if ((D1[0] > D2[0]) && (D1[1] > D2[1]) && (D1[2] > D2[2])) {//se sono tutti maggiori
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 3;
                        printf("\nil giocatore %s perde tre truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=3;
                    } else if ((D1[0] < D2[0]) && (D1[1] > D2[1]) && (D1[2] > D2[2])) {//se solo uno e minore
                        T[sceltaT1].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                        T[sceltaT].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] < D2[1]) && (D1[2] > D2[2])) {//se solo uno e minore variante 1
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 2;
                        printf("\nil giocatore %s perde due truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] > D2[1]) && (D1[2] < D2[2])) {//se solo uno e minore variante 2
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 2;
                        printf("\nil giocatore %s perde due truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] < D2[0]) && (D1[1] < D2[1]) && (D1[2] > D2[2])) {// se sono due minori
                        T[sceltaT].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=2;
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] < D2[0]) && (D1[1] > D2[1]) && (D1[2] < D2[2])) {// se sono due minori variante 1
                        T[sceltaT].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=2;
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] < D2[1]) && (D1[2] < D2[2])) {// se sono due minori variante 2
                        T[sceltaT].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=2;
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                    } else if ((D1[0] < D2[0]) && (D1[1] < D2[1]) && (D1[2] < D2[2])) {//se sono tutti minori
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 3;
                        printf("\nil giocatore %s perde tre truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=3;
                    } else if ((D1[0] == D2[0]) && (D1[1] == D2[1]) && (D1[2] == D2[2])) {// se sono tutti uguali
                        printf("non succede niente");
                    } else if ((D1[0] < D2[0]) && (D1[1] == D2[1]) && (D1[2] == D2[2])) {//se solo uno e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] < D2[1]) && (D1[2] == D2[2])) {//se solo uno e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] == D2[1]) && (D1[2] < D2[2])) {//se solo uno e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] == D2[1]) && (D1[2] == D2[2])) {//se solo uno e maggiore
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] > D2[1]) && (D1[2] == D2[2])) {//se solo uno e maggiore
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] == D2[1]) && (D1[2] > D2[2])) {//se solo uno e maggiore
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] < D2[0]) && (D1[1] < D2[1]) && (D1[2] == D2[2])) {//se sono due minori
                        T[sceltaT].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=2;
                    } else if ((D1[0] == D2[0]) && (D1[1] < D2[1]) && (D1[2] < D2[2])) {//se sono due minori variante 1
                        T[sceltaT].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=2;
                    } else if ((D1[0] < D2[0]) && (D1[1] == D2[1]) && (D1[2] < D2[2])) {//se sono due minori variante 2
                        T[sceltaT].Armate = T[sceltaT].Armate - 2;
                        printf("\nil giocatore %s perde due truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=2;
                    } else if ((D1[0] > D2[0]) && (D1[1] > D2[1]) && (D1[2] == D2[2])) {//se sono due maggiori
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 2;
                        printf("\nil giocatore %s perde due truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                    } else if ((D1[0] == D2[0]) && (D1[1] > D2[1]) &&(D1[2] > D2[2])) {//se sono due maggiori variante 1
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 2;
                        printf("\nil giocatore %s perde due truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                    } else if ((D1[0] > D2[0]) && (D1[1] == D2[1]) &&(D1[2] > D2[2])) {//se sono due maggiori variante 2
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 2;
                        printf("\nil giocatore %s perde due truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=2;
                    } else if ((D1[0] < D2[0]) && (D1[1] == D2[1]) &&(D1[2] > D2[2])) {//se uno e maggiore e uno e minore
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] < D2[0]) && (D1[1] > D2[1]) &&(D1[2] == D2[2])) {//se uno e maggiore e uno e minore variante 1
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] == D2[1]) &&(D1[2] < D2[2])) {//se uno e maggiore e uno e minore variante 2
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] > D2[0]) && (D1[1] < D2[1])&&(D1[2] == D2[2])) {//se uno e maggiore e uno e minore variante 3
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] < D2[1]) &&(D1[2] > D2[2])) {//se uno e maggiore e uno e minore variante 4
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    } else if ((D1[0] == D2[0]) && (D1[1] > D2[1]) &&(D1[2] < D2[2])) {//se uno e maggiore e uno e minore variante 5
                        T[sceltaT].Armate = T[sceltaT].Armate - 1;
                        printf("\nil giocatore %s perde una truppa\n",G[a].Nome);//stampo il messaggio a i giocatori
                        G[a].numero_truppe-=1;
                        T[sceltaT1].Armate = T[sceltaT1].Armate - 1;
                        printf("\nil giocatore %s perde una truppe\n",G[k].Nome);//stampo il messaggio a i giocatori
                        G[k].numero_truppe-=1;
                    }
                    break;//istruzione di fine blocco
            }
            break;//istruzione di fine blocco dello switch principale
    }//fine switch case
    if (T[sceltaT1].Armate < 1) {//controllo il territorio è rimasto scoperto per le truppe
        printf("il territorio e stato conquistato dal giocatore");//stampo a schermo il messaggio
        T[sceltaT1].Armate = 1;//sto assegnando un armata dal territorio che ha attaccato
        T[sceltaT1].Proprietario = G[a].ID;//sto passando l'id del nuovo propretario
        T[sceltaT].Armate = T[sceltaT].Armate - 1;//levo un armata per assegnarla al territorio
    }
}//fine della funzione di attacco


void spostamento_truppe(int a, struct tabellone *T) {
    int i, b;//variabile che mi serve per il for
    int scelta, sceltaB, sceltaC;
    char let;

    //devo stampare tutti i territori che ha il giocatore per poi spostare le truppe
    for (i = 0; i < 25; i++) {//dovrebbe permettere di stampare tutti i terreni relativi al utente con lo stesso id
        if (T[i].Proprietario == G[a].ID) {
            printf("\n%d)%s\n", i, T[i].nome);//stampa in sucessione tutti i terreni appartenenti alla stessa persona
            printf("\n armate presenti al interno %d\n", T[i].Armate);
        }
    }//fine for
    printf("seleziona in base al numero il terreno dove vuoi che le truppe siano levate");
    scanf("%d", &scelta);//prendo in ingresso da tastiera
    getchar();//mi serve per evitare che prenda il valore del invio e mi vada a riempire le prossime variabili a scelta
    for (i = 0; i < 26; i++) {
        if(T[i].Proprietario==G[a].ID) {//scorre i terreni e controlla se il proprietario li possiede
            if (isAdjacent(scelta, i) == true) {//controlla se ci sono dei terreni vicini
                printf("puoi spostarle nei seguenti territori adicenti");//stampa il messaggio
                printf("\n%d)%s\n", i, T[i].nome);//stampa il nome del terreno
                printf("\ntruppe presenti al interno del territorio:%d\n",T[i].Armate);
            }
        }
    }

    do {//mi permette di rimandare la scelta del terreno se il gioccatore la scelgie sbagliata
        scanf("%d", &sceltaB);//prendo in ingresso da tastiera
        getchar();//mi serve per evitare che prenda il valore del invio e mi vada a riempire le prossime variabili a scelta
        if (isAdjacent(scelta, sceltaB) == true) {
            printf("nel terreno a tua scelta ci sono %d truppe", T[sceltaB].Armate);
            printf("quante truppe vuoi spostare dal altro terreno ");
            scanf("%d", &sceltaC);
            do {//questo do mi permette di rimandare dinuovo la scelta delle truppe se risulta sbagliata
                if (sceltaC < T[scelta].Armate) {
                    T[scelta].Armate = T[scelta].Armate - sceltaC;
                    T[sceltaB].Armate = T[sceltaB].Armate + sceltaC;
                    break;
                } else {
                    printf("hai sbagliato inserendo il numero delle truppe da spostare riprova");
                    printf("vuoi annullare??");
                    printf("Y/N");
                    scanf("%s",&let);
                    if((scelta=='Y')||(scelta=='y')) {
                        break;
                    }else{
                        printf("riprova;");
                    }
                }
            } while (1);
            break;
        } else {
            printf("hai sbagliato iserendo il numero del territorio ");
        }
    } while (-1);
}//fine funzione



void visualizza(struct Lista *a) {//mi serve solo in progettazione
    printf("\npuntalista----->");
    while (a != NULL) {
        printf("%d\n", a->m.Numero);
        printf("%s\n", a->m.Testo);
        printf("%d\n", a->m.F);
        printf("%d\n", a->m.Simbolo);
        printf("--->");
        a = a->pnext;
    }
    printf("NULL\n\n");

}//fine funzione di visualizzazione
//per adesso come ho sistemato questa funzione va molto bene pero devo ancora spenderci ancora un po di tempo perche nondevo ancora andare a prendere tutti i nomi dei terreni ed i loro rispettivi proprietari

void salvataggio(int i,struct tabellone *T) {//funzione per il salvataggio
    Salvataggio salva;
    int a, k,j;//variabile che mi serve per prendere in considerazione il giocatore
    FILE *fp = NULL;//assegno al puntatore il valore null per evitare che venga utilizzato da altri
    fp = fopen("salvataggio.rsk", "wb");//nome del file che uso per il salvataggio e anche come deve essere salvato
    fwrite(&salva, sizeof(Salvataggio),1, fp);
    fclose(fp);//chiudo il file in scrittura
        //devo creare la funzione perscacarte per salvare le carte in un array

}//fine della funzione di salvataggio


struct Lista *aggiungi_elementi(struct Lista *MAZZO){
    struct Lista *pxt=NULL;
    pxt=(struct Lista *)malloc(sizeof(struct Lista));
    pxt->m=M[26];
    pxt->pnext=MAZZO;
    MAZZO=pxt;
    pxt=(struct Lista *)malloc(sizeof(struct Lista));
    pxt->m=M[27];
    pxt->pnext=MAZZO;
    MAZZO=pxt;
    return MAZZO;
}
void carica(){//mi serve per capire se alla fine mi va a buon fine
    Salvataggio salva;
    int a;
    FILE*fp=NULL;//creo il puntatore del file da zero
    fp=fopen("salvataggio.rsk","r+b");
            fread(&salva, sizeof(Salvataggio), 1, fp);
            printf("%d",salva);
            printf("%s %d %d ",salva.Giocatore);

    fclose(fp);
        }
