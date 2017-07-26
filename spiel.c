
#include "spiel.h"

int zeileFrei(int spalte);
int IsClunValid(int colun);
int IsColunFull(int colun);
int checkVertikal(int spalte, int zeile);
int checkHorizontal(int spalte,int zeile);
int checkDiagonal(int spalte, int zeile);





extern int InitSpielfeld (void) // initialisieren des Spielfeldes
{
	int z; 
	int s; 
	for (z = 0; z < MAX; z++)
		for (s = 0; s < MAX; s++)
			spielfeld [z][s] ='0'; //Spielfeld wird mit dem Zeichen 0 erstellt.
	return 0;
}

    
     
    
// return -1 --> if culum is not valid or culum is full
// return culum -->   if culum is valid and not full  
extern int SpaltenAbfragen (int sp) //abfragen der Spaltennummer vom Spieler.
{
	int spalte;

	printf ("Spieler %d Spalte Bitte eingeben: ",(sp == 1) ? 1: 2);
	scanf ("%d", &spalte);
    if( IsClunValid(spalte) && ( !IsColunFull(spalte)) ) return spalte;
    else return -1;
   
}
     
   
    
extern int ZugSpielen(int spalte, int sp)
{
    int zeile = zeileFrei(spalte);
    if(zeile != -1) 
        {
            if(sp == 1) spielfeld [zeile][spalte] = 'A';
            else if(sp == -1) spielfeld [zeile][spalte] = 'B';
        }
    return zeile;    
}
     
extern void SpielfeldAusgabe(void)
{
	int i;
	int j;
    
	printf("\n");
	for (i = 0; i < MAX; i++)
	{
		printf("\n");
		for (j = 0; j < MAX; j++)
			printf(" %c", spielfeld [i][j]);
	}
	
}
extern int CheckWinner(int spalte, int zeile)
{
    int vertical = checkVertikal(spalte, zeile);
    if(vertical)  return 1;
    int horizontal = checkHorizontal(spalte, zeile);
    if(horizontal) return 1;
    int diagonal = checkDiagonal(spalte, zeile);
    if(diagonal) return 1;
    return 0;
}

int checkDiagonal(int spalte, int zeile)
{
    int count = 0;
    char character = spielfeld[zeile][spalte];
    int i,j;

    for (i=zeile, j=spalte ; (spielfeld[i][j]==character)&& (i >= 0) &&(j<= (MAX-1)); i--,j++)
    {
        count++;
        //printf("\ncounter = %d, zeile = %d, spalte= %d\n",count, i, j);
        if (count == 4) return 1;
    }
    for (i=zeile+1, j=spalte-1 ; (spielfeld[i][j]==character)&& (i <= (MAX-1)) &&(j>= 0); i++,j--)
    {
        count++;
        //printf("\ncounter = %d, zeile = %d, spalte= %d\n",count, i, j);
        if (count == 4) return 1;
    }



    return 0;
}

int checkVertikal(int spalte, int zeile)
{
    
    int count = 0;
    char character = spielfeld[zeile][spalte];
    for ( ; (spielfeld[zeile][spalte]==character)&& (zeile <= (MAX-1)); zeile++)
    {
        count++;
        //printf("\ncounter = %d, zeile = %d\n",count, zeile);
        if (count == 4) return 1;
    }
    return 0;
}


int checkHorizontal(int spalte,int zeile)
{

    int count = 0;
    char character = spielfeld[zeile][spalte];
    int j = spalte;
    for(;(spielfeld[zeile][j]==character) && j <= (MAX-1);j++)
    {
        count++;
        //printf("\ncounter = %d, spalte = %d\n",count, j);
        if (count == 4) return 1;
    }
    j =spalte-1;
    for(;(spielfeld[zeile][j]==character) && j >= 0;j--)
    {
        count++;
        //printf("\ncounter = %d, spalte = %d\n",count, j);
        if (count == 4) return 1;
    }

    return 0;
}
int zeileFrei(int spalte)
{
    int zeile;
    for ( zeile = (MAX-1); zeile >=0; zeile--)
    {
        if(spielfeld[zeile][spalte] == '0') return zeile;
          
    }
    return -1;
}

int IsClunValid(int colun)
{  
    int isValid = ((colun >=0) && (colun <= (MAX-1))); 
    if(!isValid) printf("\033[35m""\n spalte %d isNotValid\n""\033[0m ", colun);
    return isValid;
}

int IsColunFull(int colun)
{
    char character = spielfeld[0][colun];
    
    int isFull = (character !='0');
    if(isFull) printf("\033[34m""\nspalte %d  isFull\n""\033[0m ", colun);
    return isFull ;
}