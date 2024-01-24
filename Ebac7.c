#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca resposável por cuidar das strings

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif


void clearScreen(void)
{
    system(CLEAR_SCREEN);
}

int registro(void) //Função responsável por cadastrar os usuários no sistema
{
    //início da criação das variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da criação das variáveis/string

    printf(" Digite o CPF a ser cadastrado: ");//Coletando informações do usuário
    scanf("%s", cpf);//%s refere-se às strings
    
    strcpy(arquivo, cpf);//Responsável por copiar os valores das strings
           
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o "w"
    fprintf(file,"%s", cpf); // salvo o valor da variável
    fclose(file); // fecha o arquivo
           
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,"%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,"%s", sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,"%s", cargo);
    fclose(file);
    
    clearScreen();
    
    return 0;
}

int consulta(void)
{
    setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado!\n");
    }
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\Essas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
        
    system("read");
    return 0;
}

int deletar(void)
{
    char cpf[40];
    
    printf("Digitar o cpf a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("O usuário não se encontra na sistema!\n");
        system("read");
        
    }
    
    return 0;
}
int main(void)
    
{
    putenv("TERM=xterm-256color");
    
    int opcao=0; //Definindo as variáveis
    int laco=1;
    
    for(laco=1;laco==1;)
    {
        
        clearScreen();
        
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
        
        printf("### Cartório da EBAC ###\n\n"); //Início do menu
        printf("Escolha desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n\n");
        printf("\t2 - Consultar nomes\n\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: ");//fim do menu
        
        scanf("%d", &opcao); //Armazenando a escolha do usuário
        
        clearScreen();//Responsável por limpar a tela
        
        
        switch(opcao)//Início da seleção do menu
        {
            case 1:
                registro();//Chamada de funções
                system("read");
                break;
                
            case 2:
                
                consulta();
                system("read");
                break;
                
            case 3:
                deletar();
                system("read");
                break;
            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0;
                break;
                
            default:
                printf("Essa opção não está disponível!");
                system("read");
                break;
                
        }//Fim da seleção1
        
        
       
    }
    return 0;
}

