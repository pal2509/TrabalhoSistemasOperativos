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
                }
                else
                {
                    wait(NULL);
                    BEGIN(INITIAL);

                } 
            }
<INITIAL,A>\n  {  printf("%c ", c); BEGIN(INITIAL);}

terminar       { return 0;}

<C>" "          {  puts("First space");BEGIN(D);}

<E>[^\n]+    { 
                printf("%sawwad\n",yytext);
                //char a[strlen(yytext) - 1];
                //for(int k = 0 ; k < sizeof(a); k++)a[k]=yytext[k];
                arg[i] = yytext;
                i++; 
                BEGIN(F);
            }

<D>[^\n]+" "   {
                printf("%sawwad\n",yytext);
                char a[strlen(yytext) - 1];
                for(int k = 0 ; k < sizeof(a); k++)a[k]=yytext[k];
                arg[i] = a;
                printf("arg:%s",arg[i]);
                i++;
                BEGIN(E);
            }


<F>\n       {
                arg[0] = cmd;
                printf("%s\n", arg[0]);
                printf("%s\n", arg[1]);
                printf("%s\n", arg[2]);
                
                arg[i] = NULL;
                int p = fork();
                if(p == 0)
                {
                    showargs(arg);
                    if(execv(getpath(cmd), arg) == -1)perror("Erro");
                }
                else
                {
                   wait(NULL);
                   BEGIN(INITIAL);
                }  
            }

%%
