#ifndef FP_BASE_DOCENTE_H//incluseione delle librerie
#define FP_BASE_DOCENTE_H
//inizio funzioni di libreria
#include <stdbool.h>//librerie inserite dal docente per la definizione della
#include <stdlib.h>//librerie standard del c
#include <stdio.h>//librerie standard del c
#include <time.h>//questa libreria mi serve per la generazione casuale
#include <string.h>//libreria che mi permette di usare tutte le funzioni con le stringhe
//fine funzioni di libreria
//inizio definizioni
#define N_TERRITORI 26 //Number of territories
#define DIM 26//questa ci definisce la grandezza massima che possiamo dare a i nomi
#define GIOCATORI 3 //come chiesto nell progetto base creare una macro con il valore dei giocatori
//fine definizioni
//inizio prototipi di funzione
_Bool isAdjacent(int idFirst, int idSecond);
struct giocatore;//dichiaro il prototipo della struttura
struct tabellone;//definizione della struttura tabellone
struct mazzo;//definizione della struttura del mazzo di carte
struct dadi;//definizione della struttura dei dadi
struct salvataggio;//questa definisce la struttura del salvataggio in tutte le sue parti
struct Lista;//definizione della struttura lista per la
enum colore;//sto creando un prototipo di un enumerazione per i giocatori
enum coloreD;//enumerazione che mi permette di capire quali sono i dadi di attacco o di difesa
enum simbolo;//prototipo del enumerazione che ci definisce il simbolo al interno della carta
enum facolta;//prototipo di enumerazione che ci dice a quale dipartimento fanno capo le facolta
int Adadi();//questa funzione ci da come valore di ritorno il valore di ogni dado e questo dipende dal numero di armate con qui decidiamo di attaccare o difendere
int Bdadi();//questa funzione ci da come valore di ritorno il valore di ogni dado e questo dipende dal numero di armate con qui decidiamo di attaccare o difendere
int generazione_giocatori();//questa funzione mi deve restituire solo i giocatori
int generazione_mazzo();//questa funzione genera il mazzo e lo distribuisce a i giocatori giocanti
int fase_pre_gioco(struct giocatore *,int ,struct Lista *);//questo prototipo di funzione mi fa mettere le truppe al interno dei territori prima della partita edeve farmeli mettere massimo 3 alla volta
int Fase_principale(struct giocatore *,int ,struct tabellone *);//questa e la fase principale del gioco
int attacco(struct giocatore *,int,struct tabellone*);
void truppe(struct giocatore *, int );//questa funzione aumenta il numero delle truppe del giocatore fino ad arrivare al numero massimo consentito
void spostamento_truppe(struct giocatore *, int ,struct tabellone *);
void visualizza(struct Lista *);//visualizza le carte
void vis(struct giocatore *);//visualizza le informazioni relative a i giocatori
//fine prototipi di funzione
#endif