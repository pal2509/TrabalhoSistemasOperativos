#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    struct stat file; 
    int fd; 
    for(int i = 1 ; i < argc ; i++)
    {
        fd = open (argv[i], O_RDONLY); //Abrir os ficherios passados com argumento
        if(fd >= 0) //Verificação se existiu algum erro na abertura do ficherio
        {
            stat(argv[i], &file); //Estado do ficherio
            printf("Nome: %s\n", argv[i]);
            printf("Tipo: %s\n",file.st_mode);
            printf("Tamanho: %s\n",file.st_size);
            printf("I-node: %s\n",file.st_ino);
            printf("Dono: %s\n",file.st_uid);
            printf("Criação: %s\n");
            printf("Última modificação: %s\n",file.st_mtime);

        }
        else write(2,"Erro ficherio não existe!!!\n", 30); //Mensagem de erro
        close(fd); //Fechar o fiheiro
    }
    return 0;
}