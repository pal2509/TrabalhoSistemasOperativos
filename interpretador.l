    #include "libcomandos.c"

    char cmd[20];
    char c = '%';



%%

lista      {   
                strcpy(cmd,yytext);
                printf("cmd: %s\n", cmd);
                
            }

mostra      {   
                strcpy(cmd,yytext);
                printf("cmd: %s\n", cmd);
            }


informa     {   
                strcpy(cmd,yytext);
                printf("cmd: %s\n", cmd);
                
            }

apaga       {
                strcpy(cmd,yytext);
                printf("cmd: %s\n", cmd);
                
            }

acrescenta  {   
                strcpy(cmd,yytext);
                printf("cmd: %s\n", cmd);
                
            }

[^/]+\/|?+  {
                printf("File:%s\n", yytext);
                char path[strlen(cmd) + 2];
                path[0] = '.';
                path[1] = '/';
                for(int i = 0; i < sizeof(cmd); i++)
                {
                        path[i + 2] = cmd[i];
                }
                printf("Path:%s\n",path);
                char file[strlen(yytext)];
                for(int i = 0 ; i < sizeof(file) ; i++)
                {
                    file[i] = yytext[i];
                }
                
                int p = fork();
                if(p == 0)
                {
                    printf("antes exec\n");
                    
                    if(execl(path, cmd, file ,(char *)NULL) == -1)perror("Erro");
                    printf("depois exec\n");
                }
                else
                {
                    printf("teste antes\n");
                    wait(NULL);
                    printf("teste depois\n");
                } 
            }

\n  {   }



%%
