    // 4 Gewinnt.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
    //
     
    
    #include <stdlib.h>
    #include "spiel.h"
     
    char spielfeld [MAX][MAX]; // 1. Dim: Zeile, 2. Dim: Spalte
    
     
    int main(void)
    {
    	int runde = 49; //42 ergibt sich aus der maximal Anzahl Felder die das Spielfeld hat. 7*6=42.
    	int spieler=1; //Diese Variabel gibt den aktuellen Spieler an. 1 steht für Spieler B (=Spieler 2) und -1 steht für Spieler A (=Spieler 1).
    	InitSpielfeld();
     
    	printf("4 Gewinnt\n"); //Titel
    	printf("---------\n\n");
    	printf("Info:\n Spieler1 hat den Spielstein A und Spieler 2 hat den Spielstein B.\n Spieler 1 beginnt.\n\n");
     
    	printf("Spielfeldaufbau:\n\n"); //Aufbau des Spielfeldes und wie die Zeilen und Spalten beziefert sind.
     
    	printf ("      S p a l t e n\n");
    	printf ("      0 1 2 3 4 5 6 \n");
    	printf ("      | | | | | | |\n");
    	printf (" Z 0- 0 0 0 0 0 0 0\n");
    	printf (" e 1- 0 0 0 0 0 0 0\n");
    	printf (" i 2- 0 0 0 0 0 0 0\n");
    	printf (" l 3- 0 0 0 0 0 0 0\n");
    	printf (" e 4- 0 0 0 0 0 0 0\n");
    	printf (" n 5- 0 0 0 0 0 0 0\n");
        printf ("   6- 0 0 0 0 0 0 0\n\n");
        
        int spalte;
     
    	while(runde > 0)
    	{
           
    		spalte = SpaltenAbfragen(spieler);

            if (spalte == -1) continue;
            int zeile = ZugSpielen(spalte, spieler);
                		
    		SpielfeldAusgabe();
            if (zeile !=1){
                if (CheckWinner(spalte,zeile)){
                    printf("\nSpieler%d  is the Winner !!!!!\n\n",
                     (spieler == 1) ? 1: 2);
                    break;

                } 
            }
                          
            spieler *= -1;
    		printf("\n");
    		runde--;
    	}
    	
    	return 0;
    }