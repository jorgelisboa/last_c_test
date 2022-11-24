#include <stdio.h>

#define PROJETOS 15

struct DespesasProjeto
{
    char salarioDesenvolvedores[9];
    char horasExtras[10];
    char salarioDeslocamento[10];
    char outrosGastos[10];
};

struct Projeto // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    char codigoDoProjeto[10];
    char gerente[60];
    char dataDeEntregaPrevistaParaProjeto[10];
    char cliente[60];
    struct DespesasProjeto despesasProjeto;
    char receitaProjeto[100];
}; // Define o nome do novo tipo criado

int getLucroTotal() {
    return 0;
}

int getUserOption() {
    unsigned int option;
    
    printf("Digite uma opção abaixo");
    scanf("%d", &option);

    return option;
}
void showAvaiableOptions() {
    printf("1 - Lucro Total dos projetos em andamento \n");
    printf("2 - Quantos projetos estão atrasados \n");
    printf("3 - Projeto com maior gasto com horas extras \n");
    printf("4 - Projeto com maior gasto total \n");
    printf("5 - Informação do projeto (gerente) \n");
    printf("6 - Informação do projeto (cliente) \n");
    printf("0 - Sair \n");
}
int main() {
    int option = 0;
    while (option == 1)
    {
        showAvaiableOptions();
        int userOption = getUserOption();
        switch (userOption)
        {
        case 1:
            printf("CASO UM");
            break;
        case 2:
            printf("CASO DOIS");
            break;
        case 3:
            printf("CASO TRÊS");
            break;
        case 4:
            printf("CASO QUATRO");
            break;
        case 5:
            printf("CASO CINCO");
            break;
        case 6:
            printf("CASO SEIS");
            break;
        default:
            break;
        }
    }
    
    

    return 0;
}