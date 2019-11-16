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
        if(fd != -1) //Verificação se existiu algum erro na abertura do ficherio
        {
            stat(argv[i], &file); //Estado do ficherio
            int size = file.st_size; //Guardar o tamanho do ficheiro
            char str[size]; //Criar um buffer do tamanho do ficehiro
            read(fd,str,size); //Ler o ficherio para a str
            write(1,str,size); //Escrever no ecrã a Str
        }
        else write(2,"Erro ficherio não existe!!!\n", 30); //Mensagem de erro
    }
    return 0;
}