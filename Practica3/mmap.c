#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc,char *argv[]){

  int fd;
  struct stat mystat;
  unsigned char *pmap;

  fd= open("test.txt", O_RDWR);

  printf("File Descriptor de mi archivo es: %d\n",fd );

  if(fd== -1){
    perror("open");
    exit(1);
  }

  if(fstat(fd,&mystat) <0){

    perror("fstat");
    close(fd);
    exit(1);

  }


  printf("********Abriendo archivo y mostrandolo con mmap******* \n" );
  pmap=(char *)mmap(0,mystat.st_size,PROT_READ,
            MAP_SHARED,fd,0);

  for(int i=0;i<mystat.st_size;i++){
    char c;
    c=pmap[i];
    putchar(c);

  }

  if(pmap == MAP_FAILED){
    perror("mmap");
    close(fd);
    exit(1);
  }

  return 0;
}
