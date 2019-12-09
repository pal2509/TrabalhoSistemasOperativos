#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[])
{
    struct stat file; 
    int fd; 
    for(int i = 1 ; i < argc ; i++)
    {
        fd = open (argv[i], O_RDONLY); //Abrir os ficherios passados com argumento
        if(fd >= 0) //Verificação se existiu algum erro na abertura do ficherio
        {
            if(stat(argv[i], &file) == -1)perror("Erro"); //Estado do ficheiro
            else {   
                printf("Nome: %s\n", argv[i]); //Nome do ficheiro
                printf("Tipo de ficheiro: "); //Tipo de ficheiro
                switch (file.st_mode & __S_IFMT) {//Switch para determinar qual é o tipo de ficherio
                //Fazendo uma operação com o valor do st_mode com __S_IFMT que é um valor que pertence 
                //á libraria stats.h que permite comparar com outros valores dessa mesma libraria
                case __S_IFBLK:  printf("Orientado ao bloco\n");      break;
                case __S_IFCHR:  printf("Orientado ao caracter\n");   break;
                case __S_IFIFO:  printf("FIFO/pipe\n");               break;
                case __S_IFLNK:  printf("symlink\n");                 break;
                case __S_IFREG:  printf("Normal\n");                  break;
                case __S_IFSOCK: printf("Socket\n");                  break;
                default:       printf("Desconhecido?\n");             break;
                }
            }
            printf("Tamanho: %lld bytes\n",(long long)file.st_size);//Tamanho em bytes do ficheiro
            printf("I-node: %ld\n",(long)file.st_ino);//Numero de I-node
            printf("UID: %ld \n",(long)file.st_uid);//User ID do ficheiro
            
            printf("Criação: \n");
            printf("Última modificação: %s\n",ctime(&file.st_mtime));//Data da ultima modificação
            
        }
        else perror("Erro"); //Mensagem de erro
        close(fd); //Fechar o fiheiro
    }
    return 0;
}