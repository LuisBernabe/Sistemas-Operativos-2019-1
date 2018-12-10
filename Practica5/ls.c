#include <stdio.h>
#include <dirent.h>

int main(void)
{
    struct dirent *de;

    // opendir() regresa un apuntador de tipo directorio
    DIR *dr = opendir(".");

    if (dr == NULL)  // opendir regresara NULL si no puede abrir el directorio
    {
        printf("No se puede abrir el directrorio actual" );
        return 0;
    }


    while ((de = readdir(dr)) != NULL)
            printf("%s\n", de->d_name);

    closedir(dr);
    return 0;
}
