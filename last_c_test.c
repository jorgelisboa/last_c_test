#include <stdio.h>
#include <stdlib.h>
#define PROJETOS 15

typedef struct
{
    char salarioDesenvolvedores[9];
    char horasExtras[10];
    char salarioDeslocamento[10];
    char outrosGastos[10];
}DespesasProjeto;
typedef struct  // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    char codigoDoProjeto[10];
    char gerente[60];
    char dataDeEntregaPrevistaParaProjeto[10];
    char cliente[60];
    DespesasProjeto despesasProjeto;
    char receitaProjeto[100];
}Projeto; // Define o nome do novo tipo criado

void getLucroTotal(Projeto** listaDeProjetos, unsigned int avaiableProjects) {
    printf("getLucroTotal\n");
    for (unsigned int i = 0; i < avaiableProjects; i++)
    {
        printf("\n%d", i);
        printf("%s", listaDeProjetos[i]->cliente);
    }
}
void getProjetosAtrasados() {
    
}
void getProjetoComMaisHorasExtras() {
    
}
void getProjetoComMaiorGasto() {
    
}
void getProjectsInfoByGerente() {
    
}
void getProjectInfoByCliente() {
    
}

int getUserOption() {
    unsigned int option;
    
    printf("Digite uma das opções acima: ");
    scanf("%d", &option);

    return option;
}
void showAvaiableOptions() {
    printf("\n1 - Lucro Total dos projetos em andamento \n");
    printf("2 - Quantos projetos estão atrasados \n");
    printf("3 - Projeto com maior gasto com horas extras \n");
    printf("4 - Projeto com maior gasto total \n");
    printf("5 - Informação do projeto (gerente) \n");
    printf("6 - Informação do projeto (cliente) \n");
    printf("0 - Sair \n");
}
int main() {
    Projeto projeto[] = {
        {
            "1",
            "Jorge",
            "27/02/2030",
            "joji",
            {
                "1.000",
                "5",
                "200.00",
                "5.000"
            },
            "100.000.00"
        },
        {
            "2",
            "Miguel",
            "27/02/2003",
            "Miguel",
            {
                "10.000",
                "5",
                "2.000.00",
                "5.000"
            },
            "100.000.00"
        },
    };
    unsigned int arraySize = sizeof(projeto)/sizeof(projeto[0]);
    
    Projeto* listaProjetos = (Projeto*) malloc(arraySize * sizeof(Projeto));
    // Coloca os projetos na memória alocada
    printf("%d", arraySize);
    for (unsigned int i = 0; i < arraySize; i++)
    {
        printf("%s", projeto[i].cliente);
        listaProjetos[i] = projeto[i];
    }
    
    int option = 1;
    while (option == 1)
    {
        showAvaiableOptions();
        int userOption = getUserOption();
        switch (userOption)
        {
        case 1:
            getLucroTotal(&listaProjetos, arraySize);
            printf("\nCASO UM");
            break;
        case 2:
            getProjetosAtrasados();
            printf("\nCASO DOIS");
            break;
        case 3:
            getProjetoComMaisHorasExtras();
            printf("\nCASO TRÊS");
            break;
        case 4:
            getProjetoComMaiorGasto();
            printf("\nCASO QUATRO");
            break;
        case 5:
            getProjectsInfoByGerente();
            printf("\nCASO CINCO");
            break;
        case 6:
            getProjectInfoByCliente();
            printf("\nCASO SEIS");
            break;
        default:
            option = 0;
            break;
        }
    }
    free(listaProjetos);
    return 0;
}
