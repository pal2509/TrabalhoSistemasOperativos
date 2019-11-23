#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>



void lista(char path[200], char cmd[20], char file[200])
{
    int p = fork();
    if(p)
    {
        if(execl(path, cmd, file ,(char *)NULL) == -1)perror("Erro");
    }
}