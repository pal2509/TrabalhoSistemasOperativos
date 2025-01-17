
    #include <unistd.h>
    #include <sys/wait.h>
    char cmd[20];
    char c = '%';
    char *arg[200];
    int i = 1;

%x Files

%%

lista      {   
                strcpy(cmd,"./lista");
                arg[0] = strdup("lista");
                BEGIN(Files);
            }

mostra      {   
                strcpy(cmd,"./mostra");
                arg[0] = strdup("mostra");
                BEGIN(Files);
            }


informa     {   
                strcpy(cmd,"./informa");
                arg[0] = strdup("informa");
                BEGIN(Files);
            }

apaga       {
                strcpy(cmd,"./apaga");
                arg[0] = strdup("apaga");
                BEGIN(Files);
            }

acrescenta  {   
               strcpy(cmd,"./acrescenta");
                arg[0] = strdup("acrescenta");
                BEGIN(Files);
            }

conta       {   
                strcpy(cmd,"./conta");
                arg[0] = strdup("conta");
                BEGIN(Files);
            }

termina     { return 0;}

\n {printf("%c ",c);}

<Files>[^\t \n]+   { arg[i] = strdup(yytext);
                i++;   }

<Files>\n  {       
        arg[i] = NULL;
        int p = fork();
        int r;
        if(p == 0)
        {
            execv(cmd, arg);
        }
        else    r = wait(NULL);
        printf("\nTerminou o comando %s com codigo %d\n", arg[0], r);
        i = 1;
        printf("%c ", c);
        BEGIN(INITIAL);
    }

<INITIAL,Files>[ \t\n\r] {}

%%
