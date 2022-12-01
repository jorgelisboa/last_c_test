#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <string.h> //necessário para strcpy
#define nome 50

typedef struct
{
    int codigo;
    char gerente[nome];
    char cliente[nome];
    float receitaProjeto;
    Despesas despesas;
    Data dataEntrega;
}Projeto;

typedef struct
{
    float salarioDesenvolvedor;
    float horasExtras;
    float deslocamento;
    float outros;
}Despesas;

typedef struct
{
    int dia;
    int mes;
    int ano;
}Data;

void getLucroTotal(Projeto** listaDeProjetos, unsigned int avaiableProjects) {
    printf("\nAVAIABLE PROJECTS: %d", avaiableProjects);
    for (unsigned int i = 0; i < avaiableProjects; i++)
    {
        printf("\n%s", listaDeProjetos[i]->cliente);
        fflush(stdout);
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
            "jorgin",
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
        },        {
            "4",
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
            "3",
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
        }
    };
    unsigned int arraySize = sizeof(projeto)/sizeof(projeto[0]);

    Projeto* listaProjetos = (Projeto*) malloc(arraySize * sizeof(Projeto));
    // Coloca os projetos na memória alocada
    printf("%d", arraySize);
    for (unsigned int i = 0; i < arraySize; i++)
    {
        // Base do projeto
        strcpy(listaProjetos[i].cliente, projeto[i].cliente);
        strcpy(listaProjetos[i].codigoDoProjeto, projeto[i].codigoDoProjeto);
        strcpy(listaProjetos[i].dataDeEntregaPrevistaParaProjeto, projeto[i].dataDeEntregaPrevistaParaProjeto);
        strcpy(listaProjetos[i].gerente, projeto[i].gerente);

        // Despesas do projeto
        strcpy(listaProjetos[i].despesasProjeto.horasExtras, projeto[i].despesasProjeto.horasExtras);
        strcpy(listaProjetos[i].despesasProjeto.outrosGastos, projeto[i].despesasProjeto.outrosGastos);
        strcpy(listaProjetos[i].despesasProjeto.salarioDesenvolvedores, projeto[i].despesasProjeto.horasExtras);
        strcpy(listaProjetos[i].despesasProjeto.horasExtras, projeto[i].despesasProjeto.horasExtras);
        strcpy(listaProjetos[i].despesasProjeto.salarioDeslocamento, projeto[i].despesasProjeto.salarioDeslocamento);
        printf("%s", projeto[i].cliente);
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
