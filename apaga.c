#include <unistd.h>

int main(int argc, char* argv[])
{ 
    for(int i = 1 ; i < argc ; i++)
    {
        if(unlink(argv[i]) == 0) 
        {
            write(1, "Ficherio apagado com sucesso.\n",31);
        }
        else perror("Erro"); 
    }
    return 0;
}