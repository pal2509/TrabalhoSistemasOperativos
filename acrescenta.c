#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char* argv[]){    
    
    int fd1, fd2;

    fd1 = open (argv[1], O_APPEND);

    for (int i = 2 ; i < argc ; i++)
    {
        fd2 = open (argv[i], O_RDONLY);   

        if (fd1 >= 0)
        {
            struct stat file;
            stat(argv[i], &file); //Estado do ficheiro
            int size = file.st_size; //Guardar o tamanho do ficheiro
            char str[size]; //Criar um buffer do tamanho do ficheiro
            read(fd2,str,size); //Ler o ficheiro para a str
            write(fd1,str,size); //Escrever no ecrã a Str        
            
        }
        else write(1,"Erro: Ficheiro não existe.",30);
        close(fd2);
    }
       
    close(fd1);
    

    return 0;   

}