#include<stdio.h>
#include<string.h>
// Function to allocate memory to  
// blocks as per First fit algorithm 
void firstFit(int blockSize[], int m, int ocupados[], 
              int processSize[], int n) 
{ 
    // Stores block id of the  
    // block allocated to a process 
    int allocation[n]; 
  
    // Initially no block is assigned to any process 
    memset(allocation, -1, sizeof(allocation)); 
  
    // pick each process and find suitable blocks 
    // according to its size ad assign to it 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < m; j++) 
        { 
            if (blockSize[j] >= processSize[i] && ocupados[j] != 1) 
            { 
                // allocate block j to p[i] process 
                allocation[i] = j; 
  
                // Reduce available memory in this block. 
                //blockSize[j] -= processSize[i]; 
  				ocupados[j] = 1;
                break; 
            } 
        } 
    } 
  
    printf("\nProcess No.\tProcess Size\tBlock Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf("%d \t\t", i+1); 
   	 	printf("%d \t\t", processSize[i]); 
		if(i >= m)
            printf("%d \t\t", 0);
        else
            printf("%d \t\t", blockSize[i]);

        if (allocation[i] != -1) 
            printf("%d\n", allocation[i] + 1); 
        else
            printf("Not Allocated\n"); 
        //cout << endl; 
    } 
} 

int main(int argc, char const *argv[])
{
	printf("First Fit Algotithm\n");
	int num_bloque = 0, num_segmentos = 0;
	printf("\nCantidad de bloques: ");
	scanf("%d", &num_bloque);

	int blockSize[num_bloque], ocupados[num_bloque];//= {100, 500, 200, 300, 600};
	for (int i = 0; i < num_bloque; ++i)
	{
		printf("\nTamaño de bloque b[%d]: ", i+1);
		scanf("%d", &blockSize[i]);
		ocupados[i] = 0;
	}

	printf("\n\nCantidad de segmentos: ");
	scanf("%d", &num_segmentos);

	int processSize[num_segmentos];//= {100, 500, 200, 300, 600};
	for (int i = 0; i < num_segmentos; ++i)
	{
		printf("\nTamaño de segmento s[%d]: ", i+1);
		scanf("%d", &processSize[i]);
	}


    //int processSize[] = {212, 417, 112, 426}; 
    int m = sizeof(blockSize) / sizeof(blockSize[0]); 
    int n = sizeof(processSize) / sizeof(processSize[0]); 
  
    firstFit(blockSize, m, ocupados, processSize, n); 
	return 0;
}