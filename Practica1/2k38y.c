#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>


/*
* Función que imprime los segundos restantes para el 2038
*/
void segundosRestantes2038(void)
{
  time_t actual = time(NULL);
  printf("Segundos Restantes para la fecha: %.0f s\n",difftime(INT_MAX, actual));    
}

/*
* Función que imprime la fecha exacta del 2038.
*/
void fechaExacta2038(void)
{
  time_t final = INT_MAX; 
  printf("Local Time\t%s", asctime(localtime(&final)));
  printf("Coordinated Universal Time (UTC)\t%s", asctime(gmtime(&final)));
}



int main()
{
  
  segundosRestantes2038();
  fechaExacta2038();
  return 0;
}
