#include <stdio.h>  // biblioteca para interação com o usuário
#include <stdlib.h> // biblioteca para alocação de memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca de string

int registro() // função para registrar um novo aluno
{
    // inicia as variáveis utilizadas nesta função
    char arquivo[11];
    char cpf[11];
    char nome[15];
    char sobrenome[15];
    char cargo[40];
    int loop = 1;

    while (loop == 1)
    {
        system("cls");
        setlocale(LC_ALL, "portuguese"); // definindo a linguagem do texto a ser mostrado (português)

        printf("\t<<<<<Cadastro>>>>>\n\n\n"); // título da tela

        printf("Digite o CPF: ");
        scanf("%s", cpf); // espera a entrada do cpf a ser inserido

        strcpy(arquivo, cpf); // copia o cpf para o arquivo, ou seja, o cpf será o localizador deste arquivo

        FILE *file;                // cria um arquivo
        file = fopen(arquivo, "r"); // tenta abrir um arquivo com o cpf inserido

        if (file == NULL) // verifica se o cpf já foi registrado
        {
            fclose(file);           // fecha o arquivo anterior para não existir a possibilidade de erro
            file = fopen(arquivo, "w"); // cria um arquivo com o cpf dado
            fprintf(file, cpf);         // salva a variável cpf no arquivo.
            fclose(file);               // fecha o arquivo.

            file = fopen(arquivo, "a");
            fprintf(file, ","); // adiciona uma separação entre as informações
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
            printf("CPF já foi cadastrado!\n\n"); // mostra caso o cpf já tenha cadastro
            system("pause"); // deixa a aplicação em pausa para leitura das mensagens
        }
        system("cls");
        loop = decisao();
    }
}

int decisao()
{
    char escolha; // variável que armazena a escolha do usuário
    int loop = 1; // variável que mantém o loop caso a escolha do usuário seja inválida

    setlocale(LC_ALL, "portuguese");

    while (loop == 1) // início do loop
    {
        printf("Deseja voltar ao menu? y/n\n");
        scanf(" %c", &escolha); // aguarda a decisão do usuário

        switch (escolha) // manipula a escolha
        {
        case 'y':
            return 0; // se o usuário escolher y, ele retorna 0 para encerrar o loop da função que essa função dará suporte
            break;

        case 'n':
            return 1; // retorna 1 para manter o loop intacto
            break;

        default:
            system("cls");
            printf("Escolha inválida. Digite y para sim ou n para não\n"); // mensagem se a escolha for inválida
        }
    }
}

int consulta() // função para consultar as informações de um cpf
{
    char cpf[11];
    char conteudo[200];
    char *token; // ponteiro para a função strtok()
    int loop = 1;

    while (loop == 1)
    {
        system("cls");
        setlocale(LC_ALL, "portuguese"); // define a língua

        printf("\t<<<<Consultar informações>>>>\n\n\n"); // título
        printf("Digite o CPF: ");
        scanf("%s", cpf); // espera o cpf a ser consultado

        printf("\n\n\n");

        FILE *file;
        file = fopen(cpf, "r"); // tenta abrir o arquivo deste cpf

        if (file == NULL)
        {
            printf("CPF não foi encontrado.\n\n"); // caso não encontre este arquivo
        }
        else
        {
            printf("Informações: \n\n");

            while (fgets(conteudo, 200, file) != NULL)
            { // coloca todas as informações do arquivo na string conteudo
            }
            token = strtok(conteudo, ","); // separa a string pela <,> que foi o que usamos no registro para separar informações
            printf("\tCPF: ");
            printf("%s\n", token); // mostra a primeira informação
            token = strtok(NULL, ","); // usando NULL aqui o ponteiro token passa a conter a próxima informação, neste caso o nome
            printf("\tNome: ");
            printf("%s", token);
            token = strtok(NULL, ","); // mesma lógica do anterior
            printf(" %s\n", token);
            token = strtok(NULL, ","); // mesma lógica do anterior
            printf("\tCargo: ");
            printf("%s\n\n", token);
        }

        fclose(file);
        system("pause");
        loop = decisao();
    }
}

int deletar() // função para deletar
{
    char cpf[11];
    char confirmar;
    int loop = 1;

    while (loop == 1)
    {
        system("cls");
        setlocale(LC_ALL, "portuguese"); // define a língua

        printf("\t<<<<Deletar cadastro>>>>\n\n\n"); // título

        printf("Digite o CPF a ser deletado: ");
        scanf("%s", cpf); // espera o cpf a ser deletado

        FILE *file;
        file = fopen(cpf, "r"); // tenta abrir o arquivo deste cpf
        fclose(file);

        if (file == NULL) // verifica se o arquivo existe ou não
        {
            printf("\n\nCPF não encontrado!\n\n"); // mensagem caso não encontre o cpf
            system("pause");
        }
        else
        {
            printf("\n\nTem certeza que quer deletar o CPF %s?", cpf); // pede a confirmação para deletar o cpf
            scanf(" %c", &confirmar);

            if (confirmar == 'y')
            {
                remove(cpf); // remove o cpf
                printf("\n\nCPF deletado com sucesso!\n");
                system("pause");
            }
            else
            {
                printf("\n\nExclusão cancelada!\n"); // mensagem se a exclusão for cancelada
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

        printf("########  Registro de Nomes EBAC  ########\n\n"); // título da aplicação

        // tela de menu
        printf("Digite o número da opção desejada:\n\n");

        printf("\tDigite 1 para cadastrar novo Nome.\n\n\tDigite 2 para consultar os dados.\n\n\tDigite 3 para excluir um cadastro.\n\n\tDigite 4 para sair do sistema.\n\n\n\n"); // opções a serem escolhidas

        printf("Opção: ");
        scanf("%d", &escolha); // espera a escolha do usuário

        system("cls"); // limpa a tela

        switch (escolha) // início da escolha
        {

        case 1:
            registro(); // chamada da função registro
            break;

        case 2:
            consulta(); // chamada da função consulta
            break;

        case 3:
            deletar(); // chamada da função deletar
            break;

        case 4:
            printf("Obrigado por usar este sistema!!");
            return 0;
            break;

        default:
            printf("\tOpção não está disponível no menu.\n\n\n"); // fim da escolha
            system("pause");
            break;
        }
    }
}

