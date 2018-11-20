#include <stdlib.h>
#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <unistd.h>

int main(){
  pid_t pid;

  int f=fork();
  pid=getpid();
  char buf[100];
  if(f==0){

    //Procesp Hijo
    printf("Yo soy el proceso hijo con PID: %d\n",pid );
    printf("\tMi padre es PID :%d\n",getppid() );

  }else{
    //Proceso padre
    printf("Yo soy el proceso padre con PID: %d\n",pid );
    printf("\tMi padre es PID :%d\n",getppid() );
  }

}
