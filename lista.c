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
                while((read = readdir(dir)) != NULL )
                {                                        
                    switch(read->d_type)
                    {
                        case DT_BLK: printf("B ");     break;
                        case DT_CHR: printf("C ");     break;
                        case DT_DIR: printf("D ");     break;
                        case DT_FIFO: printf("P ");     break;
                        case DT_LNK: printf("L ");     break;
                        case DT_REG: printf("N ");    break;
                        case DT_SOCK: printf("S ");     break;
                        default: printf("? ");            break;
                    }    
                    printf("%s\n", read->d_name);
                }
            }
            else perror("Erro");
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
                
                while((read = readdir(dir)) != NULL )
                {                                        
                    switch(read->d_type)
                    {
                        case DT_BLK: printf("B ");     break;
                        case DT_CHR: printf("C ");     break;
                        case DT_DIR: printf("D ");     break;
                        case DT_FIFO: printf("P ");     break;
                        case DT_LNK: printf("L ");     break;
                        case DT_REG: printf("N ");    break;
                        case DT_SOCK: printf("S ");     break;
                        default: printf("? ");            break;
                    }
                    printf("%s\n", read->d_name);
                }
            }
            else perror("Erro"); //Mensagem de erro
            closedir(dir); //Fechar o fiheiro
        }
    }    
    
    return 0;
}