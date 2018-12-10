#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int n, char **args) {
	printf("Round Robin\n");
    int num_procesos;
    int quantum = 0;
    double promedio_espera, promedio_ejecucion;
    int llegada = 0;
	int interrupcion = 0, prioridad = 0;

    printf("Cantidad de procesos: ");
    scanf("%d", &num_procesos);

    int tiempo_ejecucion[num_procesos], tiempo_llegada[num_procesos], tiempo_espera[num_procesos], interrupciones[num_procesos];
    int tiempo_final[num_procesos], prioridades[num_procesos], tiempo_restante[num_procesos]; 
    int tiempo_ejecutado[num_procesos];
    //Solicitamos los valores para cada proceso.
    printf("Ingresa el tiempo de ejecución para cada proceso: \n");
    for (int i = 0; i < num_procesos; ++i)
    {
        printf("Proceso %d\n", i+1);
        tiempo_llegada[i] = llegada;
        llegada += 3;
        //Asignamos valores aleatorios para el tiempo de interrupción y la prioridad.
        for (int x = 0; x < 2; x++)
        {
			time_t t;
        	if(x == 0){

		    	srand(time(&t));
		    	interrupcion = rand()%5;
		    	interrupciones[i] = interrupcion;
        	}else{

		    	srand((unsigned) time(&t));
		    	prioridad += rand()%5;
		    	prioridades[i] = prioridad;
        	}
        }

        printf("Tiempo ejecución:");
        scanf("%d", &tiempo_ejecucion[i]);//ingresamos el tiempo de ejecución del proceso 'i'        
        tiempo_restante[i] = tiempo_ejecucion[i];
        tiempo_ejecutado[i] = 0;
        tiempo_espera[i] = 0;
    }
    printf("Tamaño del Quantum: ");
    scanf("%d", &quantum);

	//Asignamos valores aleatorios para el tiempo de interrupción y la prioridad.
	for (int i = 0; i < num_procesos; ++i)
	{
        for (int x = 0; x < 2; x++)
        {
			time_t t;
        	if(x == 0){

		    	srand(time(&t));
		    	interrupcion = rand()%5;
		    	interrupciones[i] = interrupcion;
        	}else{

		    	srand((unsigned) time(&t));
		    	prioridad += rand()%5;
		    	prioridades[i] = prioridad;
        	}
        }
	}


    //Mostramos la información de cada proceso
    printf("\nProceso\t\t|Llegada\t|Ejecución\t|Interrupciones\t|Prioridad\n");
    for (int i = 0; i < num_procesos; ++i)
    {
    	printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", i+1,tiempo_llegada[i], tiempo_ejecucion[i], interrupciones[i], prioridades[i]);
    }


    printf("\n\nProceso\t\t|Ejecución|Espera\n");
	int tiempo_transcurrido = 0, flag = 0;

	//Revisamos sobre todos los procesos hasta que todos esten terminados.
	for (int i = 0, restantes = num_procesos; restantes != 0;)
	{
		//Si es el último quantum para el proceso lo terminamos.
		if (tiempo_restante[i] > 0 && tiempo_restante[i] <= quantum)
		{		
			tiempo_espera[i] += tiempo_transcurrido - tiempo_ejecutado[i];
			if(tiempo_espera[i] < 0)
				tiempo_espera[i] = 0;
			tiempo_transcurrido += tiempo_restante[i];
			tiempo_ejecutado[i] += tiempo_restante[i];
			tiempo_restante[i] = 0;
			flag = 1;
		}else if(tiempo_restante[i] > 0){
			tiempo_espera[i] += tiempo_transcurrido - tiempo_ejecutado[i];
			tiempo_transcurrido += quantum + interrupciones[i];
			tiempo_ejecutado[i] += quantum;
			tiempo_restante[i] -= quantum;
		}
		//imprimimos la información del proceso terminado
		if (tiempo_restante[i] == 0 && flag == 1)
		{
			restantes --;
			printf("\nP[%d]\t\t%d\t\t%d", i, tiempo_ejecutado[i], tiempo_espera[i] - tiempo_llegada[i]);
			promedio_espera += tiempo_espera[i] - tiempo_llegada[i];
			promedio_ejecucion += tiempo_ejecutado[i] + (tiempo_ejecucion[i]/quantum)*interrupciones[i];
			flag = 0;
		}
		//Aumentamos la variable para contienuar revisando los procesos.
		if (i == num_procesos-1)
			i = 0;//regresamos la variable para atender de nuevo a todos.
		else if(tiempo_llegada[i+1] <= tiempo_transcurrido)
			i++;
		else
			i++;
	}




    //Calculamos el promedio de espera y de ejecución.
    promedio_espera /= num_procesos;
    promedio_ejecucion /= num_procesos;
    printf("\n\n Promedio de espera: %f", promedio_espera);
    printf("\n Promedio de ejecución: %f\n", promedio_ejecucion);
	return 0;
}