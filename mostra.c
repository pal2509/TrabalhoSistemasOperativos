#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    struct stat file; 
    int fd; 
    for(int i = 1 ; i < argc ; i++)
    {
        fd = open (argv[i], O_RDONLY); //Abrir os ficherios passados com argumento
        if(fd >= 0) //Verificação se existiu algum erro na abertura do ficherio
        {
            if(stat(argv[i], &file) == -1)perror("Erro"); //Estado do ficherio
            int size = file.st_size; //Guardar o tamanho do ficheiro
            char str[size]; //Criar um buffer do tamanho do ficheiro
            if(read(fd,str,size) == -1)perror("Erro"); //Ler o ficherio para a str
            if(write(1,str,size) == -1)perror("Erro"); //Escrever no ecrã a Str
        }
        else perror("Erro"); //Mensagem de erro
        close(fd); //Fechar o fiheiro
    }
    return 0;
}