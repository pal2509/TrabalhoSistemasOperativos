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
    if(argv[1] == NULL)//Caso não seja dado o directório assume-se o atual
    {
        char cwd[256];
        getcwd(cwd, sizeof(cwd));//Encontrar qual é o directório atual
        printf("%s\n", cwd);
        DIR *dir = opendir (cwd);//Abrir o directorio atual
            if(dir != NULL)//Verificar se é diferente de NULL
            {
                struct dirent *read;//Estrutura de dados para fazer a leitura do directório
                while((read = readdir(dir)) != NULL )//Ler o directorio
                {                                      
                    switch(read->d_type)//Determinar se é um ficheiro ou um diretório o ficheiro, o que foi lido 
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
                    printf("%s\n", read->d_name);//Escreve o ficheiro ou diretorio lido
                }
            }
            else perror("Erro");//Caso exista erro na abertura da diretoria imprime o erro
        closedir(dir);  //Fecha a diretoria
    }
    else    //Caso seja dado diretorias para ler
    {
        for(int i = 1 ; i < argc ; i++)//Percorrer o argv
        {
            DIR *dir = opendir (argv[i]);//Abrir a diretoria
            if(dir != NULL)//Verificar se é diferente de NULL
            {
                struct dirent *read;//Estrutura de dados para fazer a leitura do directório
                
                while((read = readdir(dir)) != NULL )//Ler o directorio
                {                                        
                    switch(read->d_type)//Determinar se é um ficheiro ou um diretório, o que foi lido
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
                    printf("%s\n", read->d_name);//Escreve o ficheiro ou diretorio lido
                }
            }
            else perror("Erro"); //Mensagem de erro
            closedir(dir); //Fechar o fiheiro
        }
    }    
    
    return 0;
}