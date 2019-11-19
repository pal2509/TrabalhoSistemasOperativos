#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif

int main(int argc, char* argv[])
{
    if(argv[1] == NULL)
    {
        char cwd[256];
        getcwd(cwd, sizeof(cwd));
        printf("%s\n", cwd);
        DIR *dir = opendir (cwd);
            if(dir != NULL)
            {
                struct dirent *read;
                printf("Name\tTipo\n");
                while((read = readdir(dir)) != NULL )
                {                                        
                    printf("%s\t", read->d_name);
                    switch(read->d_type)
                    {
                        case DT_BLK: printf("B\n");     break;
                        case DT_CHR: printf("C\n");     break;
                        case DT_DIR: printf("D\n");     break;
                        case DT_FIFO: printf("P\n");     break;
                        case DT_LNK: printf("L\n");     break;
                        case DT_REG: printf("N\n");    break;
                        case DT_SOCK: printf("S\n");     break;
                        default: printf("?\n");            break;
                    }    
                }
            }
            else write(2,"Erro ao abrir directoria!!!",28);
        closedir(dir);               
    }
    else
    {
        for(int i = 1 ; i < argc ; i++)
        {
            DIR *dir = opendir (argv[i]);
            if(dir != NULL)
            {
                struct dirent *read;
                printf("Name\tTipo\n");
                while((read = readdir(dir)) != NULL )
                {                                        
                    printf("%s\t", read->d_name);
                    switch(read->d_type)
                    {
                        case DT_BLK: printf("B\n");     break;
                        case DT_CHR: printf("C\n");     break;
                        case DT_DIR: printf("D\n");     break;
                        case DT_FIFO: printf("P\n");     break;
                        case DT_LNK: printf("L\n");     break;
                        case DT_REG: printf("N\n");    break;
                        case DT_SOCK: printf("S\n");     break;
                        default: printf("?\n");            break;
                    }    
                }
                
            }
            else write(2,"Erro directoria não existe!!!\n", 30); //Mensagem de erro
            closedir(dir); //Fechar o fiheiro
        }
    }    
    
    return 0;
}