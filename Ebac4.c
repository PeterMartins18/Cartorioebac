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

int registro(void)
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf(" Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf);//Responsável por copiar os valores das strings
           
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo
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
    clearScreen();
    printf("Você escolheu deletar os nomes!\n");
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
        printf("\t1 Registrar nomes\n");
        printf("\t2 Consultar nomes\n");
        printf("\t3 Deletar nomes\n\n");
        printf("Opção: ");//fim do menu
        
        scanf("%d", &opcao); //Armazenando a escolha do usuário
        
        clearScreen();
        
        
        switch(opcao)
        {
            case 1:
                registro();
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
                
            
            default:
                printf("Essa opção não está disponível!");
                system("read");
                
        }
        
        
       
    }
    return 0;
}

