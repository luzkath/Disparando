/*moviendo muñequitos =)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define T 15

 void imprimir(int mapa[T][T],int d);
 void color(int letra, int fondo);
 
int main() 
{
	 
	int mapa[T][T]={{42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42,42},
                    {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},	
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
	                {42,255,255,255,255,255,255,255,255,255,255,255,255,255,42},
                    {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42,42}	
	               };
	 char tecla;
	 int band, dir,fp,cp,tiempo,fa,ca, disparo,Xd,Cd,bloq;             
	fp=12;cp=12; // pertenece al que se mueve solo
	fa=13;ca=13; // peretenece al que se mueve con el cursor
	bloq=2;
   //mapa[fp][cp]=221; 
	mapa[fa][ca]=2; //figura de la carita
	band=1;

	srand(time(0));
	//dir=rand()%4 + 1;
	
	tiempo=0;
       mapa[fa][ca]=219;
         mapa[fp][cp]=221; 
	   imprimir(mapa,dir);
	disparo=0;
	while(band)
	{
	 //para el cursor	
	 
	   tecla=0;
		if(kbhit())//FUNCION DE LA TECLA PRESIONAR
			tecla=getch();
    	 
		mapa[fa][ca]=255;  //rastro.
		switch(tecla)
        {
            case 'd': 
              	//derecha
			   if(mapa[fa][ca+1]==255)
			   {
				ca++;
			   }
			   
            break;
            case 'a': 
               
		        //izquierda
			   if(mapa[fa][ca-1]==255)
			   {
				ca--;
			   }
  
            break;
            case 'f': 
              if(disparo==0){
			   
		       disparo=1;
		       fp=fa-1;
		       cp=ca;
               mapa[fp][cp]=64;
		   }
            break;
    }
    //	printf("%c",2);
    
		mapa[fa][ca]=2;       
        //OJO QUITAR LA MANCHITA
			
	     if(disparo==1)
	     {
	       //para el tiempo
		   //printf("Hola");
		    mapa[fp][cp]=255;
	
		      if(mapa[fp-1][cp]==255)
		       { //arriba
				   fp--;
			     mapa[fp][cp]=221;
		       }
		       else{
		       	disparo=0;
		       	mapa[fp][cp]=0;
			   } 	       	
	     }//corre el tiempo
		    
         imprimir(mapa,dir);
	      Sleep(200);	
	}//while	   	

	return 1;
}
 void imprimir(int mapa[T][T], int d)
 {
	int i,j;
	system("CLS");
	for(i=0;i<T;i++)
	{
		printf("\n\t\t");
		for(j=0;j<T;j++)
		{
			color(20,0);
			printf("%c",mapa[i][j]);
		}
	}
	

}
void color(int letra, int fondo) {
     int x = fondo*16 + letra; 
     SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),x); 
} //color
