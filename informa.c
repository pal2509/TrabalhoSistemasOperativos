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
                printf("Nome: %s\n", argv[i]);
                printf("Tipo de ficheiro: ");
                switch (file.st_mode & __S_IFMT) {
                case __S_IFBLK:  printf("Orientado ao bloco\n");      break;
                case __S_IFCHR:  printf("Orientado ao caracter\n");   break;
                case __S_IFIFO:  printf("FIFO/pipe\n");               break;
                case __S_IFLNK:  printf("symlink\n");                 break;
                case __S_IFREG:  printf("Normal\n");                  break;
                case __S_IFSOCK: printf("Socket\n");                  break;
                default:       printf("Desconhecido?\n");             break;
                }
            }
            printf("Tamanho: %lld bytes\n",(long long)file.st_size);
            printf("I-node: %ld\n",(long)file.st_ino);
            printf("UID: %ld \n",(long)file.st_uid);
            printf("Criação: \n");
            printf("Última modificação: %s\n",ctime(&file.st_mtime));

        }
        else perror("Erro"); //Mensagem de erro
        close(fd); //Fechar o fiheiro
    }
    return 0;
}