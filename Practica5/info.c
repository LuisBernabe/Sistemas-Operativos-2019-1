#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char **argv)
{
    if(argc != 2)
        return 1;

    struct stat fileStat;
    if(stat(argv[1],&fileStat) < 0)
        return 1;

    printf("Archivo %s\n",argv[1]);
    printf("---------------------------\n");
    printf("Tamaño: \t\t%d bytes\n",fileStat.st_size);
    printf("ID Usuario: \t\t%d\n",fileStat.st_uid );
    printf("inodo: \t\t%d\n",fileStat.st_ino);
    printf("Ultima modificacion:\t");
    struct tm *fechaMod;
    time(&fileStat.st_ctime);
    fechaMod=localtime(&fileStat.st_ctime);
    printf("%d/%d/%d \t %d:%d\n",fechaMod->tm_mday,fechaMod->tm_mon,fechaMod->tm_year,fechaMod->tm_hour,fechaMod->tm_min);

    printf("Permisos del archivo: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");



    return 0;
}
