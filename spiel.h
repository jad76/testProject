#ifndef SPIEL_H
#define SPIEL_H


#include <stdio.h>

#define MAX 7
extern char spielfeld [MAX][MAX];
extern int InitSpielfeld (void);
extern int SpaltenAbfragen (int sp);
extern int ZugSpielen(int spalte, int sp);
extern void SpielfeldAusgabe(void);
extern int CheckWinner(int spieler, int Zeile);


#endif