#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de testo por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int resgistro() // fun��o responsavel por cadastrar os usuarios no sistema 
{
	//inicio da cria��o de variaveis/strings
	setlocale(LC_ALL, "portuguese"); //Definindo linguagem
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf); //%S REFERE-SE A STRING
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel 
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser encontrado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{  
   char cpf[40];
   setlocale(LC_ALL,"portuguese");
    

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);


    FILE *file;

    file = fopen(cpf, "r"); // Tenta abrir o arquivo para leitura

    if (file == NULL) 

  {

    printf("O usu�rio n�o existe!\n");

    system("pause");

  } 

    else 

  {

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora voc� pode remover o arquivo

    printf("Usu�rio deletado!\n");

    system("pause");

  }

}


int main()
{
	int opcao=0; //Definindo vari�veis 
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de Adminstrador!\n\n Digite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	    system("cls");
     	for(laco=1;laco=1;)
	{
    	    system("cls");
	
            setlocale(LC_ALL, "portuguese"); //Definindo linguagem
	
	        printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	        printf("Escolha a op��o desejada do menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
  	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n\n");
	        printf("\t4 - Sair do sistema\n");
	        printf("opc�o:"); //fim do menu
	
	        scanf("%d", &opcao); //armazenando a escolha do usuario 
	
	        system("cls"); //responsavel por limpar a tela
	    
	    
      	    switch(opcao)
	    {
	        	case 1:
	            resgistro();//chamada de fun��es 
	            break;
	        
	            case 2:
                consulta();
	 	        break;
	 	    
	     	    case 3:
	     	    deletar();
	            break;
	        
	            case 4:
	            printf("Obrigado por utilizar o sistema!");
	            return 0;
	            break;
	        
	        
	            default:
	            printf("A op��o desejada n�o existe\n");
   		        system("pause");
   		        break;
       	    }
	    
        }
    }
    
    else
        printf("Senha incorreta!");
} 

