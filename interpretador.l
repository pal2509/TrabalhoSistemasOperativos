%{    
    #include "libcomandos.c"

    char cmd[20];
    char c = '%';
    char arg1[500];
    char arg2[500];
    char *arg[20];
    int i = 1;
%}

%x A
%x B
%x C
%x D
%x E
%x F

%%

lista      {   
                strcpy(cmd,yytext);
                BEGIN(A);
            }

mostra      {   
                strcpy(cmd,yytext);
                BEGIN(A);
            }


informa     {   
                strcpy(cmd,yytext);
                BEGIN(A);
            }

apaga       {
                strcpy(cmd,yytext);
                BEGIN(A);
            }

acrescenta  {   
                strcpy(cmd,yytext);
                printf("cmd: %s\n", cmd);
                BEGIN(C);
            }

conta       {   
                strcpy(cmd,yytext);
                BEGIN(A);
            }

<A>[ ]      {BEGIN(B);}


<B>[^ \n]+  {   int cod;
                int p = fork();  //Criar um novo processo
                if(p == 0) //Verificar se é o processo filho 
                {   

                    cod = execl(getpath(cmd), cmd, yytext, (char *) NULL);  //Executar o progama nesse processo filho
                }
                else
                {
                    wait(NULL); //Wait() para o processo pai esperar
                    printf("\nTerminou comando %s com codigo %d\n",cmd,cod); //Codigo de fim de execução
                    BEGIN(INITIAL);

                } 
            }
<INITIAL,A>\n  {  printf("%c ", c); BEGIN(INITIAL);}

terminar       { return 0;}

<C>[ ]          {  BEGIN(D);}

<D>[^ \t\n]+  {
                
                strcpy(arg1,yytext);
                BEGIN(E);
            }

<E>" "      {   }

<E>[^ \t\n]+  { 
                int cod;
                strcpy(arg2,yytext);
                int c = fork();  //Criar um novo processo
                if(c == 0) //Verificar se é o processo filho
                {
                    cod = execl(getpath(cmd), cmd, arg1, arg2, (char *) NULL);  //Executar o progama nesse processo filho
                }
                else
                {
                    wait(NULL);  //Wait() para o processo pai esperar
                    printf("\nTerminou comando %s com codigo %d\n",cmd,cod);  //Codigo de fim de execução
                    BEGIN(INITIAL);
                } 
            }

%%
