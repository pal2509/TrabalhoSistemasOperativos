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
            int size = file.st_size; //Guardar o tamanho do ficheiro
            char str[size]; //Criar um buffer do tamanho do ficheiro
            read(fd,str,size); //Ler o ficherio para a str
            
            int lines = 0; //Contador do numero de linhas
            for(int k = 0 ; k < size ; k++) //Percorrer a string
            {
                if(str[k] == '\n') lines++; //Contar os \n na string
            }
            printf("Número de linhas de %s => %d\n", argv[i], lines); //Escrever o numero de linhas
        }
        else write(2,"Erro ficherio não existe!!!\n", 30); //Mensagem de erro
        close(fd); //Fechar o fiheiro
    }
    return 0;
}