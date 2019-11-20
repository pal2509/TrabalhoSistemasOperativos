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
            if(stat(argv[i], &file) == -1)perror("Erro"); //Estado do ficherio
            int size = file.st_size; //Guardar o tamanho do ficheiro
            char str[size]; //Criar um buffer do tamanho do ficheiro
            if(read(fd,str,size) == -1)perror("Erro"); //Ler o ficherio para a str
            
            int lines = 0; //Contador do numero de linhas
            for(int k = 0 ; k < size ; k++) //Percorrer a string
            {
                if(str[k] == '\n') lines++; //Contar os \n na string
            }
            printf("Número de linhas de %s => %d\n", argv[i], lines); //Escrever o numero de linhas
        }
        else perror("Erro"); //Mensagem de erro
        close(fd); //Fechar o fiheiro
    }
    return 0;
}