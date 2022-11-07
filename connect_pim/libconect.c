#include "libconect.h"
#include <stdio.h>
#include<string.h>
#include <time.h>

//Menu Principal
void Menu_Principal()
{
    //limpar o console
    system("cls");

    //variaveis
    char opcao;

        printf("\n\n+---MENU PRINCIPAL-----------+---------+\n");
        printf("|         Opcoes             |  Numero |\n");
        printf("+----------------------------+---------+\n");
        printf("|        Cadastros           |    1    |\n");
        printf("+----------------------------+---------+\n");
        printf("|        Relatorio           |    2    |\n");
        printf("+----------------------------+---------|\n");
        printf("|      Consultar dados       |    3    |\n");
        printf("+----------------------------+---------|\n");
        printf("|      Sair do sistema       |    4    |\n");
        printf("+----------------------------+---------|\n");

        printf("Escolha o numero da opcao.....: ");
        fflush(stdin);
        scanf("%c", &opcao);

        switch(opcao)
        {
            case '1':
            //limpar o console
            system("cls");
            Menu_Cadastros();
            break;

            case '2':
            //limpar o console
            system("cls");
            printf("\n\n");
            Relatorio();
            break;

            case '3':
            //limpar o console
            system("cls");
            printf("\n\n");
            Menu_Consultar();
            break;

            case '4':
            printf("\n\n");
            printf("Voce saiu do sistema!");
            getch();
            exit(1);
            break;

        }


        if(opcao > 4)
        {
            printf("opcao invalida!");
            getch();
            Menu_Principal();
        }


}

//------------------------------------------------------------------------------------------------------------------

//Menu Cadastros
void Menu_Cadastros()
{
    //variaveis
    char opcao;

        printf("\n\n+---MENU CADASTROS-----------+---------+\n");
        printf("|         Opcoes             |  Numero |\n");
        printf("+----------------------------+---------+\n");
        printf("| Cadastros de Funcionarios  |    1    |\n");
        printf("+----------------------------+---------+\n");
        printf("|  Cadastros de Clientes     |    2    |\n");
        printf("+----------------------------+---------|\n");
        printf("|        Menu principal      |    3    |\n");
        printf("+----------------------------+---------|\n");

        printf("Escolha o numero da opcao.....: ");
        fflush(stdin);
        scanf("%c", &opcao);

        switch(opcao)
        {
            case '1':
            //limpar o console
            system("cls");
            User_Autorizado();
            break;

            case '2':
            //limpar o console
            system("cls");
            printf("\n\n");
            Cadastro_Cliente();
            break;

            case '3':
            //limpar o console
            system("cls");
            printf("\n\n");
            Menu_Principal();
            break;
        }


        if(opcao > 3)
        {
            printf("opcao invalida!");
            Menu_Cadastros();
        }

}

//------------------------------------------------------------------------------------------------------------------

//Cadastrar funcionarios
void Cadastro_Funcionario()
{


    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);

    data_hora_atual = localtime(&segundos);


    //variaveis
    int comparador;
    int tamanho_nome, tamanho_data, tamanho_idade, tamanho_area;
    char opcao;
    char nome[50], idade[20], area[200];

    FILE *Funcionarios = fopen("C:\\Users\\fabio\\OneDrive\\Área de Trabalho\\connect_pim\\dataBase\\Funcionarios.txt", "a");
    if(Funcionarios == NULL)
    {
        printf("ERRO! o arquivo não foi criado");
    }

    printf("\n\n+---CADASTRAR FUNCIONARIOS---+---------+\n");
    printf("|         Opcoes             |  Numero |\n");
    printf("+----------------------------+---------+\n");
    printf("|     Novo Funcionarios      |    1    |\n");
    printf("+----------------------------+---------+\n");
    printf("|          VOLTAR            |    2    |\n");
    printf("+----------------------------+---------|\n");

    printf("Escolha o numero da opcao.....: ");
    fflush(stdin);
    scanf("%c", &opcao);

    if(opcao == '1')
    {
    //limpar o console
    system("cls");

        do
        {
            printf("\n\n====# DIGITE OS DADOS DO FUNCIONARIOS #====\n");
            printf("Nome......: ");
            fflush(stdin);
            fgets(nome, 50, stdin);
            tamanho_nome = strlen(nome) - 1;


            printf("Idade......: ");
            fflush(stdin);
            fgets(idade, 20, stdin);
            tamanho_idade = strlen(idade) - 1;


            printf("Area de atuacao.........: ");
            fflush(stdin);
            fgets(area, 200, stdin);
            tamanho_area = strlen(area) - 1;

            if(tamanho_nome == 0 || tamanho_idade == 0 || tamanho_area == 0)
            {
                printf("\n====# CAMPOS VAZIOS, NAO FOI POSSIVEL EFETUAR O CADASTRO #====\n");
            }
            if(tamanho_nome > 0 && tamanho_idade > 0 && tamanho_area > 0)
            {
                comparador++;
            }
        }while(!comparador);


        fprintf(Funcionarios , "====# FUNCIONARIO #===============================================");
        fprintf(Funcionarios ,"# Hora: %d:",data_hora_atual->tm_hour);//hora
        fprintf(Funcionarios ,"%d:",data_hora_atual->tm_min);//minuto
        fprintf(Funcionarios ,"%d\n",data_hora_atual->tm_sec);//segundo

        fprintf(Funcionarios ,"\n\n Nome: %s ", nome );
        fprintf(Funcionarios ,"Idade: %s ", idade);

        fprintf(Funcionarios,"Data: %d/", data_hora_atual->tm_mday);//dia
        fprintf(Funcionarios,"%d/",data_hora_atual->tm_mon+1); //mês
        fprintf(Funcionarios,"%d\n",data_hora_atual->tm_year+1900); //ano


        fprintf(Funcionarios , " Area de atuacao: %s \n===================================================================================\n\n", area );

        printf("\n====# CADASTRO EFETUADO COM SUCESSO! #====\n");
        fclose(Funcionarios);
        getch();
        //limpar o console
        system("cls");
        Cadastro_Funcionario();


    }else if(opcao == '2')
    {
        fclose(Funcionarios);
        //limpar o console
        system("cls");
        Menu_Cadastros();
    }else{

        printf("opcao invalida!");
        Cadastro_Funcionario();
    }

}

//------------------------------------------------------------------------------------------------------------------

//Cadastrar cliente
void Cadastro_Cliente()
{
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);

    data_hora_atual = localtime(&segundos);

    //variaveis
    int comparador;
    int tamanho_nome, tamanho_idade, tamanho_pedido;
    char opcao;
    char nome[50], idade[20], pedido[200];

    FILE *Cliente = fopen("C:\\Users\\fabio\\OneDrive\\Área de Trabalho\\connect_pim\\dataBase\\Clientes.txt", "a");
    if(Cliente == NULL)
    {
        printf("ERRO! o arquivo não foi criado");
    }

    printf("\n\n+---CADASTRAR CLIENTES-------+---------+\n");
    printf("|         Opcoes             |  Numero |\n");
    printf("+----------------------------+---------+\n");
    printf("|       Novo Cliente         |    1    |\n");
    printf("+----------------------------+---------+\n");
    printf("|          VOLTAR            |    2    |\n");
    printf("+----------------------------+---------|\n");

    printf("Escolha o numero da opcao.....: ");
    fflush(stdin);
    scanf("%c", &opcao);

    if(opcao == '1')
    {
    //limpar o console
    system("cls");
        do
        {
            printf("\n\n====# DIGITE OS DADOS DO CLIENTE #====\n");
            printf("Nome......: ");
            fflush(stdin);
            fgets(nome, 50, stdin);
            tamanho_nome = strlen(nome) - 1;

            printf("Idade......: ");
            fflush(stdin);
            fgets(idade, 20, stdin);
            tamanho_idade = strlen(idade) - 1;


            printf("Pedido.........: ");
            fflush(stdin);
            fgets(pedido, 200, stdin);
            tamanho_pedido = strlen(pedido) - 1;

            if(tamanho_nome == 0 || tamanho_idade == 0 || tamanho_pedido == 0)
            {
                printf("\n====# CAMPOS VAZIOS, NAO FOI POSSIVEL EFETUAR O CADASTRO #====\n");
            }
            if(tamanho_nome > 0 && tamanho_idade > 0 && tamanho_pedido > 0)
            {
                comparador++;
            }


        }while(!comparador);

        fprintf(Cliente , "====# CLIENTE #========================================================");

        fprintf(Cliente ,"# Hora: %d:",data_hora_atual->tm_hour);//hora
        fprintf(Cliente ,"%d:",data_hora_atual->tm_min);//minuto
        fprintf(Cliente ,"%d\n",data_hora_atual->tm_sec);//segundo

        fprintf(Cliente,"\n\n Nome: %s ", nome );
        fprintf(Cliente ,"Idade: %s ", idade);

        fprintf(Cliente,"Data: %d/", data_hora_atual->tm_mday);//dia
        fprintf(Cliente,"%d/",data_hora_atual->tm_mon+1); //mês
        fprintf(Cliente,"%d\n",data_hora_atual->tm_year+1900); //ano


        fprintf(Cliente , " Pedido: %s \n================================================================================\n\n", pedido );

        printf("\n====# CADASTRO EFETUADO COM SUCESSO! #====\n");
        fclose(Cliente);
        getch();
        //limpar o console
        system("cls");
        Cadastro_Cliente();


    }else if(opcao == '2')
    {
        fclose(Cliente);
        //limpar o console
        system("cls");
        Menu_Cadastros();
    }else{
        printf("opcao invalida!");
        Cadastro_Cliente();
    }
}

//------------------------------------------------------------------------------------------------------------------

//Relatorio
void Relatorio()
{
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);

    data_hora_atual = localtime(&segundos);

     //variaveis
    int comparador;
    int tamanho_nome, tamanho_assunto, tamanho_texto;
    char opcao;
    char nome[50], assunto[20], texto[200];

    FILE *Relatoriotxt = fopen("C:\\Users\\fabio\\OneDrive\\Área de Trabalho\\connect_pim\\dataBase\\Relatorio.txt", "a");
    if(Relatoriotxt == NULL)
    {
        printf("ERRO! o arquivo não foi criado");
    }

    printf("+---RELATORIO----------------+---------+\n");
    printf("|         Opcoes             |  Numero |\n");
    printf("+----------------------------+---------+\n");
    printf("|       Novo Relatorio       |    1    |\n");
    printf("+----------------------------+---------+\n");
    printf("|       Menu Principal       |    2    |\n");
    printf("+----------------------------+---------|\n");

    printf("Escolha o numero da opcao.....: ");
    fflush(stdin);
    scanf("%c", &opcao);

    if(opcao == '1')
    {
        //limpar o console
        system("cls");
        do
        {
            printf("\n\n====# PREENCHA O RELATORIO #====\n");
            printf("Autor do Relatorio......: ");
            fflush(stdin);
            fgets(nome, 50, stdin);
            tamanho_nome = strlen(nome) - 1;

            printf("Assunto......: ");
            fflush(stdin);
            fgets(assunto, 20, stdin);
            tamanho_assunto = strlen(assunto) - 1;

            printf("Descricao.........: ");
            fflush(stdin);
            fgets(texto, 200, stdin);
            tamanho_texto = strlen(texto) - 1;

            if(tamanho_nome == 0 || tamanho_assunto == 0 || tamanho_texto == 0)
            {
                printf("\n====# CAMPOS VAZIOS, NAO FOI POSSIVEL EFETUAR O CADASTRO #====\n");
            }
            if(tamanho_nome > 0 && tamanho_assunto > 0 && tamanho_texto > 0)
            {

                comparador++;
            }


        }while(!comparador);



        fprintf(Relatoriotxt , "====# RELATORIO #========================================================");

        fprintf(Relatoriotxt ,"# Hora: %d:",data_hora_atual->tm_hour);//hora
        fprintf(Relatoriotxt ,"%d:",data_hora_atual->tm_min);//minuto
        fprintf(Relatoriotxt ,"%d\n",data_hora_atual->tm_sec);//segundo

        fprintf(Relatoriotxt,"\n\n Nome: %s ", nome );
        fprintf(Relatoriotxt ,"Assunto: %s ", assunto);

        fprintf(Relatoriotxt,"Data: %d/", data_hora_atual->tm_mday);//dia
        fprintf(Relatoriotxt,"%d/",data_hora_atual->tm_mon+1); //mês
        fprintf(Relatoriotxt,"%d\n",data_hora_atual->tm_year+1900); //ano


        fprintf(Relatoriotxt , " Pedido: %s \n================================================================================\n\n", texto );

        printf("\n====# CADASTRO EFETUADO COM SUCESSO! #====\n");
        fclose(Relatoriotxt);
        getch();
        //limpar o console
        system("cls");
        Relatorio();


    }else if(opcao == '2')
    {
        fclose(Relatoriotxt);
        Menu_Principal();
    }else{
        printf("\n\nopcao invalida!\n\n");
        Relatorio();
    }


}

//------------------------------------------------------------------------------------------------------------------

//Menu de Consulta
void Menu_Consultar()
{
    //limpar o console
    system("cls");
    //variaveis
    char opcao;

    printf("\n\n+---MENU CONSULTAS-----------+---------+\n");
    printf("|         Opcoes             |  Numero |\n");
    printf("+----------------------------+---------+\n");
    printf("|       BD_Cadastros         |    1    |\n");
    printf("+----------------------------+---------+\n");
    printf("|       READ Relatorio       |    2    |\n");
    printf("+----------------------------+---------|\n");
    printf("|      Menu Principal        |    3    |\n");
    printf("+----------------------------+---------|\n");

    printf("Escolha o numero da opcao.....: ");
    fflush(stdin);
    scanf("%c", &opcao);

     switch(opcao)
        {
        case '1':
        //limpar o console
        system("cls");
        Menu_Colsutar_Cadastros();
        break;

        case '2':
        //limpar o console
        system("cls");
        Consultar_Relatorio();
        break;

        case '3':
        printf("\n\n");
        Menu_Principal();
        break;

        }


        if(opcao > 3)
        {
            printf("opcao invalida!");
            getch();
            Menu_Consultar();
        }


}

//------------------------------------------------------------------------------------------------------------------

//Menu de Consulta de Cadastros
void Menu_Colsutar_Cadastros()
{
    //variaveis
    char opcao;
    char consulta;

    //arq.txt Funcionarios
    FILE *Funcionarios = fopen("C:\\Users\\fabio\\OneDrive\\Área de Trabalho\\connect_pim\\dataBase\\Funcionarios.txt", "rt");
    if(Funcionarios == NULL)
    {
        printf("ERRO! o arquivo não foi criado");
    }

    //arq.txt Clientes
    FILE *Cliente = fopen("C:\\Users\\fabio\\OneDrive\\Área de Trabalho\\connect_pim\\dataBase\\Clientes.txt", "rt");
    if(Cliente == NULL)
    {
        printf("ERRO! o arquivo não foi criado");
    }


    printf("\n\n+---CONSULTAS CADASTROS------+---------+\n");
    printf("|         Opcoes             |  Numero |\n");
    printf("+----------------------------+---------+\n");
    printf("|       READ Funcionarios    |    1    |\n");
    printf("+----------------------------+---------+\n");
    printf("|       READ Clientes        |    2    |\n");
    printf("+----------------------------+---------|\n");
    printf("|          VOLTAR            |    3    |\n");
    printf("+----------------------------+---------|\n");

    printf("Escolha o numero da opcao.....: ");
    fflush(stdin);
    scanf("%c", &opcao);


    switch(opcao)
        {
        case '1':
            //limpar o console
            system("cls");

            printf("\n\n====# Consutando o Banco de Dados de Funcionarios..... #====\n");

            /*Consultando*/
            do{
            //faz a leitura do caracter no arquivo apontado por banco_dados
            consulta = fgetc(Funcionarios);

            //exibe o caracter lido na tela
            printf("%c" , consulta);

        }while (consulta != EOF);

            printf("\n====# CONSULTA COMCLUIDA #====\n\n");
            printf("===# APERTE QUALQUER TECLA PARA CONTINUAR #===\n\n");
            getch();
            fclose(Funcionarios);
            //limpar o console
            system("cls");
            Menu_Consultar();
        break;

        case '2':
            //limpar o console
            system("cls");
            printf("\n\n====# Consutando o Banco de Dados de Clientes..... #====\n");


            do{

                consulta = fgetc(Cliente);
                printf("%c" , consulta);

            }while (consulta != EOF);

            printf("\n====# CONSULTA COMCLUIDA #====\n\n");
            printf("===# APERTE QUALQUER TECLA PARA CONTINUAR #===\n\n");
            getch();
            fclose(Cliente);
            //limpar o console
            system("cls");
            Menu_Consultar();
        break;



        case '3':
        printf("\n\n");
        Menu_Consultar();
        break;
        }


        if(opcao > 3)
        {
            printf("opcao invalida!");
            Menu_Colsutar_Cadastros();
        }
}

//------------------------------------------------------------------------------------------------------------------

//Consulta de Relatorio
Consultar_Relatorio()
{
    char consulta;

    //arq.txt Relatorio
    FILE *Relatoriotxt = fopen("C:\\Users\\fabio\\OneDrive\\Área de Trabalho\\connect_pim\\dataBase\\Relatorio.txt", "rt");
    if(Relatoriotxt == NULL)
    {
        printf("ERRO! o arquivo não foi criado");
    }

    printf("\n\n====# Consutando o Banco de Dados de Relatorio..... #====\n");

            /*Consultando*/
            do{
                //faz a leitura do caracter no arquivo apontado por banco_dados
                consulta = fgetc(Relatoriotxt);

                //exibe o caracter lido na tela
                printf("%c" , consulta);

            }while (consulta != EOF);

            printf("\n====# CONSULTA COMCLUIDA #====\n\n");
            printf("===# APERTE QUALQUER TECLA PARA CONTINUAR #===\n\n");
            getch();
            fclose(Relatoriotxt);
            Menu_Consultar();
}

//------------------------------------------------------------------------------------------------------------------

typedef struct{
    char senha[20];
}Usuario;

//Autorização para cadastrar usuarios.
void User_Autorizado()
{
    //variaveis
    int comparador;
    char senha[20];

    Usuario usuario1;
    strcpy(usuario1.senha, "123");

    do
    {
        printf("\n\n Para ter acesso a esta opcao e nescessario digitar a senha.\n");
        printf("     Password......:  ");
        fflush(stdin);
        scanf("%s", senha);

        if (strcmp(senha,usuario1.senha)==0){
            printf("\n      Acesso Permitido!");
            comparador++;
        }else{
            printf("\n      Acesso Negado!\n\n");
            Menu_Cadastros();
        }

    }while(!comparador);

    Cadastro_Funcionario();
}

//------------------------------------------------------------------------------------------------------------------

//Mostrar data e hora.

void Data_Hora()
{
  struct tm *data_hora_atual;

  time_t segundos;

  time(&segundos);

  data_hora_atual = localtime(&segundos);

  printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora
  printf("%d:",data_hora_atual->tm_min);//minuto
  printf("%d\n",data_hora_atual->tm_sec);//segundo





}















