#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função por cadastrar usuário
{
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf(" Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	FILE*file;// cria o arquivo
	file = fopen(arquivo,"w");//cria o arquivo
	fprintf(file,cpf);//salvo o valor da váriavel 
	fclose(file);//fecha o arquivo
	
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado:  ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL )
    {
    	printf("Não foi possível abrir o arquivo, não localizado!. \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL )
    {
    	printf("\nEssas são as informações do usuário");
    	printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deleta()
{
	char cpf[40];
	setlocale(LC_ALL,"portuguese");
	
	printf("Digite o CPF a ser deletado:  ");
	scanf("%s",cpf);
	
	FILE *file;
    file = fopen(cpf, "r"); // Tenta abrir o arquivo para leitura

if (file == NULL) 
    {
        printf("O usuário não existe!\n");
        system("pause");
    } 

else 

    {
        fclose(file); // Fecha o arquivo, pois ele existe
        remove(cpf);  // Agora você pode remover o arquivo
        printf("Usuário deletado!\n");
        system("pause");
    }


}

int main()
{
    int opcao = 0; //Definindo variáveis

    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem 

    while (1) // Loop infinito
    {
        system("cls");
        
		printf("### cartório da EBAC ###\n\n"); // Início do menu
        printf("Escolha a opção desejada do menu:\n\n ");
        printf("\t1  - Registrar nomes\n");
        printf("\t2  - Consultar nomes\n");
        printf("\t3  - Deletar nomes\n\n\n"); // Fim do menu
        printf("Opção:");

        scanf("%d", &opcao); //armazenamento do usuário
    
        system("cls"); // Limpa a tela (só funciona no Windows)
        
        
        
        switch(opcao)//Chamada da função
        {
        	case 1:
        	    registro();
        	    break;
        	    
        	case 2:
				consulta();
                break;
                
            case 3:
		   	    deleta();
                break;
                
            default:
				printf("Opção inválida\n");
				system("pause");
				break;
		}
    
    }

    return 0;
}

