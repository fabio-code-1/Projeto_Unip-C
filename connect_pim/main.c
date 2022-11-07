#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include "libconect.h"


typedef struct{
    char login[20]; // vetor login da struct cliente
    char senha[20]; // vetor senha da struct cliente
}Usuario;


int main()
{
    system("color f0");
    //variaveis
    int comparador;

    Usuario usuario1;
    strcpy(usuario1.login, "user");
    strcpy(usuario1.senha, "123");

     char login[20];
     char senha[20];

     printf("   ____________________ \n");
     printf("  |                    |\n");
     printf("  | CONNECT TECHNOLOGY |\n");
     printf("  |____________________|\n\n\n\n");

    do
    {
        printf("  ===# LOGIN #===\n");

        printf("     Username.....: ");
        scanf("%s", login); // armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função main


        printf("     Password......:  ");
        fflush(stdin);
        scanf("%s", senha); // armazenando os dados inseridos pelo usuário para o vetor senha que está dentro da função main



        if ((strcmp(login,usuario1.login)==0) && (strcmp(senha,usuario1.senha)==0)){ // A função strcmp é responsável por comparar string com string
            printf("\n      Bem vindo ao sistema");
            comparador++;
        }else{
            printf("\n      Login e/ou senha incorretos\n\n"); // senão, login ou senha incorreta.
        }

    }while(!comparador);

    Menu_Principal();

    return 0;
}
