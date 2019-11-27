#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{ 
    for(int i = 1 ; i < argc ; i++) //Percorrer os argumentos todos
    {
        if(unlink(argv[i]) == 0) //Agaga o ficheiro no argv[i] usando
            // a função unlink() que retorna 0 se for eliminado com sucesso 
            //ou -1 se existir algum erro
        {
            write(1, "Ficherio apagado com sucesso.\n",31);
        }
        else perror("Erro"); //Em caso de erro imprimir o erro
    }
    return 0;
}