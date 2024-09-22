#include <stdio.h>  // biblioteca para intera��o com o usu�rio
#include <stdlib.h> // biblioteca para aloca��o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca de string

int registro() // fun��o para registrar um novo aluno
{
    // inicia as vari�veis utilizadas nesta fun��o
    char arquivo[11];
    char cpf[11];
    char nome[15];
    char sobrenome[15];
    char cargo[40];
    int loop = 1;

    while (loop == 1)
    {
        system("cls");
        setlocale(LC_ALL, "portuguese"); // definindo a linguagem do texto a ser mostrado (portugu�s)

        printf("\t<<<<<Cadastro>>>>>\n\n\n"); // t�tulo da tela

        printf("Digite o CPF: ");
        scanf("%s", cpf); // espera a entrada do cpf a ser inserido

        strcpy(arquivo, cpf); // copia o cpf para o arquivo, ou seja, o cpf ser� o localizador deste arquivo

        FILE *file;                // cria um arquivo
        file = fopen(arquivo, "r"); // tenta abrir um arquivo com o cpf inserido

        if (file == NULL) // verifica se o cpf j� foi registrado
        {
            fclose(file);           // fecha o arquivo anterior para n�o existir a possibilidade de erro
            file = fopen(arquivo, "w"); // cria um arquivo com o cpf dado
            fprintf(file, cpf);         // salva a vari�vel cpf no arquivo.
            fclose(file);               // fecha o arquivo.

            file = fopen(arquivo, "a");
            fprintf(file, ","); // adiciona uma separa��o entre as informa��es
            fclose(file);

            printf("\n\nDigite o Primeiro nome: ");
            scanf("%s", nome); // espera o nome
            file = fopen(arquivo, "a");
            fprintf(file, nome); // adiciona o nome ao arquivo
            fclose(file);

            file = fopen(arquivo, "a");
            fprintf(file, ",");
            fclose(file);

            printf("\n\nDigite o sobrenome: ");
            scanf("%s", sobrenome); // espera o sobrenome
            file = fopen(arquivo, "a");
            fprintf(file, sobrenome); // adiciona o sobrenome
            fclose(file);

            file = fopen(arquivo, "a");
            fprintf(file, ",");
            fclose(file);

            printf("\n\nDigite o cargo: ");
            scanf("%s", cargo); // espera o cargo deste nome
            file = fopen(arquivo, "a");
            fprintf(file, cargo); // adiciona o cargo ao arquivo
            fclose(file);
            printf("Cadastrado com sucesso!\n\n"); // mensagem de sucesso
            system("pause"); // pausa para leitura das mensagens
        }
        else
        {
            fclose(file);
            printf("CPF j� foi cadastrado!\n\n"); // mostra caso o cpf j� tenha cadastro
            system("pause"); // deixa a aplica��o em pausa para leitura das mensagens
        }
        system("cls");
        loop = decisao();
    }
}

int decisao()
{
    char escolha; // vari�vel que armazena a escolha do usu�rio
    int loop = 1; // vari�vel que mant�m o loop caso a escolha do usu�rio seja inv�lida

    setlocale(LC_ALL, "portuguese");

    while (loop == 1) // in�cio do loop
    {
        printf("Deseja voltar ao menu? y/n\n");
        scanf(" %c", &escolha); // aguarda a decis�o do usu�rio

        switch (escolha) // manipula a escolha
        {
        case 'y':
            return 0; // se o usu�rio escolher y, ele retorna 0 para encerrar o loop da fun��o que essa fun��o dar� suporte
            break;

        case 'n':
            return 1; // retorna 1 para manter o loop intacto
            break;

        default:
            system("cls");
            printf("Escolha inv�lida. Digite y para sim ou n para n�o\n"); // mensagem se a escolha for inv�lida
        }
    }
}

int consulta() // fun��o para consultar as informa��es de um cpf
{
    char cpf[11];
    char conteudo[200];
    char *token; // ponteiro para a fun��o strtok()
    int loop = 1;

    while (loop == 1)
    {
        system("cls");
        setlocale(LC_ALL, "portuguese"); // define a l�ngua

        printf("\t<<<<Consultar informa��es>>>>\n\n\n"); // t�tulo
        printf("Digite o CPF: ");
        scanf("%s", cpf); // espera o cpf a ser consultado

        printf("\n\n\n");

        FILE *file;
        file = fopen(cpf, "r"); // tenta abrir o arquivo deste cpf

        if (file == NULL)
        {
            printf("CPF n�o foi encontrado.\n\n"); // caso n�o encontre este arquivo
        }
        else
        {
            printf("Informa��es: \n\n");

            while (fgets(conteudo, 200, file) != NULL)
            { // coloca todas as informa��es do arquivo na string conteudo
            }
            token = strtok(conteudo, ","); // separa a string pela <,> que foi o que usamos no registro para separar informa��es
            printf("\tCPF: ");
            printf("%s\n", token); // mostra a primeira informa��o
            token = strtok(NULL, ","); // usando NULL aqui o ponteiro token passa a conter a pr�xima informa��o, neste caso o nome
            printf("\tNome: ");
            printf("%s", token);
            token = strtok(NULL, ","); // mesma l�gica do anterior
            printf(" %s\n", token);
            token = strtok(NULL, ","); // mesma l�gica do anterior
            printf("\tCargo: ");
            printf("%s\n\n", token);
        }

        fclose(file);
        system("pause");
        loop = decisao();
    }
}

int deletar() // fun��o para deletar
{
    char cpf[11];
    char confirmar;
    int loop = 1;

    while (loop == 1)
    {
        system("cls");
        setlocale(LC_ALL, "portuguese"); // define a l�ngua

        printf("\t<<<<Deletar cadastro>>>>\n\n\n"); // t�tulo

        printf("Digite o CPF a ser deletado: ");
        scanf("%s", cpf); // espera o cpf a ser deletado

        FILE *file;
        file = fopen(cpf, "r"); // tenta abrir o arquivo deste cpf
        fclose(file);

        if (file == NULL) // verifica se o arquivo existe ou n�o
        {
            printf("\n\nCPF n�o encontrado!\n\n"); // mensagem caso n�o encontre o cpf
            system("pause");
        }
        else
        {
            printf("\n\nTem certeza que quer deletar o CPF %s?", cpf); // pede a confirma��o para deletar o cpf
            scanf(" %c", &confirmar);

            if (confirmar == 'y')
            {
                remove(cpf); // remove o cpf
                printf("\n\nCPF deletado com sucesso!\n");
                system("pause");
            }
            else
            {
                printf("\n\nExclus�o cancelada!\n"); // mensagem se a exclus�o for cancelada
                system("pause");
            }
        }
        system("cls");
        loop = decisao();
    }
}

int main()
{
    int escolha = 0;
    char sair[3];
    int loop = 1;

    for (loop = 1; loop = 1;)
    {
        system("cls"); // limpa a tela

        setlocale(LC_ALL, "portuguese");

        printf("########  Registro de Nomes EBAC  ########\n\n"); // t�tulo da aplica��o

        // tela de menu
        printf("Digite o n�mero da op��o desejada:\n\n");

        printf("\tDigite 1 para cadastrar novo Nome.\n\n\tDigite 2 para consultar os dados.\n\n\tDigite 3 para excluir um cadastro.\n\n\tDigite 4 para sair do sistema.\n\n\n\n"); // op��es a serem escolhidas

        printf("Op��o: ");
        scanf("%d", &escolha); // espera a escolha do usu�rio

        system("cls"); // limpa a tela

        switch (escolha) // in�cio da escolha
        {

        case 1:
            registro(); // chamada da fun��o registro
            break;

        case 2:
            consulta(); // chamada da fun��o consulta
            break;

        case 3:
            deletar(); // chamada da fun��o deletar
            break;

        case 4:
            printf("Obrigado por usar este sistema!!");
            return 0;
            break;

        default:
            printf("\tOp��o n�o est� dispon�vel no menu.\n\n\n"); // fim da escolha
            system("pause");
            break;
        }
    }
}

