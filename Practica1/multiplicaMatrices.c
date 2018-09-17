#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int ** makeMatriz(int a, int b,int c);

int main(){
  int filasA=2;
  int columnasA=3;

  int filasB=3;
  int columnasB=3;

  int **arregloA;
  int ** arregloB;
  int ** arregloC;

  arregloA= makeMatriz(filasA,columnasA,1);
  printf("\n" );
  arregloB=makeMatriz(filasB,columnasB,1);
  printf("\n");
  arregloC=makeMatriz(columnasA,filasB,0);







}


 int ** makeMatriz(int filas, int columnas, int contenido){
   srand(time(NULL));

   int **matriz;
   matriz=(int **)calloc(filas,sizeof(int *));

   for(int i=0;i<filas;i++ ){
     matriz[i]=(int *)calloc(columnas,sizeof(int));
   }


   if(contenido != 0){
     for(int i=0;i<filas;i++){
         for(int j=0;j<columnas;j++){

           matriz[i][j]=rand()%10;
           printf("%d,",matriz[i][j]);
         }
         printf("\n");
       }
   }else{
     for(int i=0;i<filas;i++){
         for(int j=0;j<columnas;j++){

           //matriz[i][j]=0;
           printf("%d,",matriz[i][j]);
         }
         printf("\n");
       }

   }
     return matriz;

}
