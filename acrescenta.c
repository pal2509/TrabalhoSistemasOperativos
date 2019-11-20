#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char* argv[]){    
    
    int fd1 = open (argv[1], O_WRONLY | O_APPEND); //Abrir o ficherio para escever no fim dele
    if(fd1 >= 0)
    {
        for (int i = 2 ; i < argc ; i++)
        {
            int fd2;
            fd2 = open (argv[i], O_RDONLY);   
            if (fd1 >= 0)
            {
                struct stat file;
                if(stat(argv[i], &file) == -1)perror("Erro"); //Estado do ficheiro
                int size = file.st_size; //Guardar o tamanho do ficheiro
                char str[size]; //Criar um buffer do tamanho do ficheiro
                if(read(fd2,str,size) == -1)perror("Erro"); //Ler o ficheiro para a str
                if(write(fd1,str,size) == -1) perror("Erro");      
                
            }
            else perror("Erro");//Erro caso não consiga abrir o ficherio
            close(fd2);
        }
    }
    else perror("Erro");  //Erro caso não consiga abrir o ficherio
    close(fd1);
    
    return 0;   
}