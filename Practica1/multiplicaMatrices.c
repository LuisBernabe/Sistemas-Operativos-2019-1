#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int ** makeMatriz(int a, int b,int c);
int * getColumna(int noCol, int ** matriz, int filas,int columas);
int * getFila(int noFil, int ** matriz, int filas,int columas);
int multilpica(int * fila, int * columna);


int main(){
  int filasA=2;
  int columnasA=3;

  int filasB=3;
  int columnasB=3;

  int filasC=filasA;
  int columnasC=columnasB;

  int **matrizA;
  int ** matrizB;
  int ** matrizC;

  printf("Matriz A\n\n");
  matrizA= makeMatriz(filasA,columnasA,1);
  printf("\nMatrizB \n\n" );
  matrizB=makeMatriz(filasB,columnasB,1);
  printf("\nRsultado A*B\n\n");
  matrizC=makeMatriz(filasC,columnasB,0);


  for(int i=0;i<filasC;i++){
    for(int j=0;j<columnasC;j++){
      matrizC[i][j]=multilpica(getFila(i,matrizA,filasA,columnasA),getColumna(j,matrizB,filasB,columnasB));
    }

  }

  for(int i=0;i<filasC;i++){
    for(int j=0;j<columnasC;j++){
      //printf("i=%d j=%d,",i,j);
      printf("%d,",matrizC[i][j] );
    }
    printf("\n" );
  }

  return 0;
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
   }
     return matriz;

}

int * getColumna(int noCol, int ** matriz, int filas,int columas){
  int * res=(int *)calloc(filas,sizeof(int));

  for(int i=0;i<filas;i++){
    res[i]=matriz[i][noCol];
    //printf("%d\n",res[i] );
  }

  return res;
}

int * getFila(int noFil, int ** matriz, int filas,int columas){
  int * res=(int *)calloc(columas,sizeof(int));
  for(int i=0;i<columas;i++){
    res[i]=matriz[noFil][i];
    //printf("%d\n",res[i] );

  }
  return res;
}


int multilpica(int * fila, int * columna){
  int length=sizeof(fila)/sizeof(int);
  int res=0;
  for(int i=0;i<=length;i++){
    res+=fila[i]*columna[i];

  }

  return res;
}
