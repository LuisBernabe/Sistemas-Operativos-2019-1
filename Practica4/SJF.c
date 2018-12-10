#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(int n, char **args) {
	printf("SJF: Shortest Job First\n");
    int num_procesos;
    double promedio_espera, promedio_ejecucion;
    int llegada = 0;
	int interrupcion = 0, prioridad = 0;

    printf("Cantidad de procesos: ");
    scanf("%d", &num_procesos);

    int tiempo_ejecucion[num_procesos], tiempo_llegada[num_procesos], tiempo_espera[num_procesos], interrupciones[num_procesos];
    int tiempo_final[num_procesos], prioridades[num_procesos], procesos[num_procesos]; 
    
    //Solicitamos los valores para cada proceso.
    printf("Ingresa el tiempo de ejecución para cada proceso: \n");
    for (int i = 0; i < num_procesos; ++i)
    {
        printf("Proceso %d\n", i+1);
        tiempo_llegada[i] = llegada;
        llegada += 3;
        printf("Tiempo ejecución:");
        scanf("%d", &tiempo_ejecucion[i]);//ingresamos el tiempo de ejecución del proceso 'i'
        procesos[i] = i+1;
    }

    //Ordenamos de menor a mayor con selection sort
    for(int i = 0, pos = 0, temp = 0, temp_llegada; i < num_procesos; i++)
    {
        pos=i;
        for(int j=i+1;j < num_procesos;j++)
        {
            if(tiempo_ejecucion[j]<tiempo_ejecucion[pos])
                pos=j;
        }
		//Ordemanos los procesos por tiempo de ejecución 
        temp = tiempo_ejecucion[i];
        tiempo_ejecucion[i] = tiempo_ejecucion[pos];
        tiempo_ejecucion[pos] = temp;

        //Ordenamos los tiempos de los procesos que llegaron.
        temp_llegada = tiempo_llegada[i];
        tiempo_llegada[i] = tiempo_llegada[pos];
        tiempo_llegada[pos] = temp_llegada;
 
        temp=procesos[i];
        procesos[i]=procesos[pos];
        procesos[pos]=temp;
    }



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

    //calculamos el tiempo de espera de los procesos
    tiempo_espera[0] = 0;//el primer proceso que llego no espera.
	for(int i = 1;i < num_procesos; i++)
    {
    	tiempo_espera[i] = 0;
    	for (int j = 0; j < i; ++j)
    	{
    		tiempo_espera[i] += tiempo_ejecucion[j] + interrupciones[j]; 
    	}
    	tiempo_espera[i] -= tiempo_llegada[i]; //calculamos el valor del timepo de espera.
    	if(tiempo_espera[i] < 0 ){
    		tiempo_espera[i] = 0;
    	}
    }

    //Mostramos la información de cada proceso
    printf("\nProceso\t\t|Llegada\t|Ejecución\t|Interrupciones\t|Prioridad\n");
    for (int i = 0; i < num_procesos; ++i)
    {
    	tiempo_final[i] = tiempo_espera[i] + tiempo_ejecucion[i];//tiempo en el que termina un proceso 
    	promedio_espera += tiempo_espera[i];//sumamos los valores de espera
    	promedio_ejecucion += tiempo_final[i];//sumamos los valores en que terminan
    	printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", i+1,tiempo_llegada[i], tiempo_ejecucion[i], interrupciones[i], prioridades[i]);
    }

    //Mostramos la información en que termino de ejecutar y el tiempo de espera de los procesos
    printf("\n\nProceso\t\t|Ejecución|Espera\n");
    for (int i = 0; i < num_procesos; ++i)
    {
    	//promedio_espera += tiempo_espera[i];
    	//promedio_ejecucion += tiempo_final[i];
    	printf("\n P[%d]\t\t%d\t\t%d", i+1, tiempo_final[i],tiempo_espera[i]);
    }

    //Calculamos el promedio de espera y de ejecución.
    promedio_espera /= num_procesos;
    promedio_ejecucion /= num_procesos;
    printf("\n\n Promedio de espera: %f", promedio_espera);
    printf("\n Promedio de ejecución: %f\n", promedio_ejecucion);
	return 0;}