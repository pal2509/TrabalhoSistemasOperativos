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


<B>[^ \n]+  {    
                int p = fork();
                if(p == 0)
                {
                    if(execl(getpath(cmd), cmd, yytext, (char *) NULL) == -1)perror("Erro");
                    else printf("Terminou com sucesso\n");
                }
                else
                {
                    wait(NULL);
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
                strcpy(arg2,yytext);
                int c = fork();
                if(c == 0)
                {
                    if(execl(getpath(cmd), cmd, arg1, arg2, (char *) NULL) == -1)perror("Erro");
                    else printf("Terminou com sucesso\n");
                }
                else
                {
                   wait(NULL);
                   BEGIN(INITIAL);
                } 
            }

%%
