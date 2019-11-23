#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libcomandos.c"

int main()
{   
    int c = fork();
    if(c == 0)
    {
        char *args[5];
        char a[] = "teste.c";

        args[0] = "mostra";
        args[1] = a;

        

        execv("./mostra", args);
        perror("Erro");
    }
	return 0;
}