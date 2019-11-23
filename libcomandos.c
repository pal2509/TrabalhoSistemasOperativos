#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


//Transforma o comando dado para um path, sendo esse path a pasta atual (./)
char *getpath(char cmd[])
{
    char *path = malloc(strlen(cmd) + 2);
    //printf("Path Size: %ld\n",sizeof(path));
    path[0] = '.';
    path[1] = '/';
    for(int i = 0; i < strlen(cmd) + 2 ; i++)
    {
        path[i + 2] = cmd[i];
    }
    //printf("Path:%s::%ld\n",path,sizeof(path));
    return path;
}


void showargs(char *args[])
{
    int i = 0;
    while(args[i] != NULL)
    {
        printf("args:%d %s\n", i, args[i]);
        i++;
    }
}