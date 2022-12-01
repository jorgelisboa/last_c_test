#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#define nome 50
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

typedef struct
{
    int codigo;
    char gerente[nome];
    char cliente[nome];
    float receitaProjeto;
    Despesas despesas;
    Data dataEntrega;
}Projeto;



void getLucroTotal(Projeto* listaDeProjetos, unsigned int avaiableProjects) {
    float gastos;
    for (unsigned int i = 0; i < avaiableProjects; i++) {
        gastos = 
                (listaDeProjetos[i].despesas.deslocamento) + 
                (listaDeProjetos[i].despesas.horasExtras) + 
                (listaDeProjetos[i].despesas.salarioDesenvolvedor) + 
                (listaDeProjetos[i].despesas.outros);
        printf("\n TOTAL: %f", listaDeProjetos[i].receitaProjeto);
        printf("\n GASTOS: %f", gastos);
        printf("\nO projeto %d tem o lucro atual de R$: %.2f", listaDeProjetos[i].codigo, listaDeProjetos[i].receitaProjeto - gastos);
    }
}
void getProjetosAtrasados(Projeto* listaDeProjetos, unsigned int avaiableProjects) {
    for (unsigned int i = 0; i < avaiableProjects; i++) {
        printf("\n%s", listaDeProjetos[i].cliente);
        fflush(stdout);
    }
}
void getProjetoComMaisHorasExtras(Projeto* listaDeProjetos, unsigned int avaiableProjects) {
    float projetoComMaisHorasExtras = 0;
    unsigned int indiceProjetoComMaisHorasExtras = 0;
    for (unsigned int i = 0; i < avaiableProjects; i++) {
        if (projetoComMaisHorasExtras < listaDeProjetos[i].despesas.horasExtras)
        {
            indiceProjetoComMaisHorasExtras = i;
        }
    }
    printf("O projeto com mais horas extras é o projeto %d com R$:%.2f", listaDeProjetos[indiceProjetoComMaisHorasExtras].codigo, listaDeProjetos[indiceProjetoComMaisHorasExtras].despesas.horasExtras);

}
void getProjetoComMaiorGasto(Projeto* listaDeProjetos, unsigned int avaiableProjects) {
    float projetoComMaiorGasto = 0;
    unsigned int indiceProjetoComMaiorGasto = 0;
    for (unsigned int i = 0; i < avaiableProjects; i++) {
        
        if (projetoComMaiorGasto < ((listaDeProjetos[i].despesas.deslocamento) + 
            (listaDeProjetos[i].despesas.horasExtras) + 
            (listaDeProjetos[i].despesas.salarioDesenvolvedor) + 
            (listaDeProjetos[i].despesas.outros)))
        {
            indiceProjetoComMaiorGasto = i;
        }
    }
    
    printf(
        "O projeto com maior gasto é o projeto %d com R$:%.2f", 
        listaDeProjetos[indiceProjetoComMaiorGasto].codigo, 
        ((listaDeProjetos[indiceProjetoComMaiorGasto].despesas.deslocamento) + 
        (listaDeProjetos[indiceProjetoComMaiorGasto].despesas.horasExtras) + 
        (listaDeProjetos[indiceProjetoComMaiorGasto].despesas.salarioDesenvolvedor) + 
        (listaDeProjetos[indiceProjetoComMaiorGasto].despesas.outros))
    );

}
void getProjectsInfoByGerente(Projeto* listaDeProjetos, unsigned int avaiableProjects, char name[nome]) {
    unsigned int achouGerente = 0;
    for (unsigned int i = 0; i < avaiableProjects; i++) {
        if(strcmp((listaDeProjetos[i].gerente), name) == 0) {
            achouGerente = 1;
            printf("\nPROJETO %d - %s", listaDeProjetos[i].codigo, listaDeProjetos[i].gerente);
            printf("\n - Data de entrega:  %d/0%d/%d", listaDeProjetos[i].dataEntrega.dia, listaDeProjetos[i].dataEntrega.mes, listaDeProjetos[i].dataEntrega.ano);
            // printf("\n - PROJETO %d", listaDeProjetos[i].);
            // printf("\nPROJETO %d", listaDeProjetos[i].codigo);
            // printf("\nPROJETO %d", listaDeProjetos[i].codigo);
        }
    }

    if (achouGerente == 0)
    {
        printf("GERENTE '%s' NÃO ENCONTRADO", name);
    }
    
}
void getProjectInfoByCliente(Projeto* listaDeProjetos, unsigned int avaiableProjects, char name[nome]) {
    unsigned int achouCliente = 0;
    for (unsigned int i = 0; i < avaiableProjects; i++) {
        if(strcmp((listaDeProjetos[i].cliente), name) == 0) {
            achouCliente = 1;
            printf("\nPROJETO %d - %s", listaDeProjetos[i].codigo, listaDeProjetos[i].cliente);
            printf("\n - Data de entrega:  %d/0%d/%d", listaDeProjetos[i].dataEntrega.dia, listaDeProjetos[i].dataEntrega.mes, listaDeProjetos[i].dataEntrega.ano);
            // printf("\n - PROJETO %d", listaDeProjetos[i].);
            // printf("\nPROJETO %d", listaDeProjetos[i].codigo);
            // printf("\nPROJETO %d", listaDeProjetos[i].codigo);
        }
    }

    if (achouCliente == 0)
    {
        printf("CLIENTE '%s' NÃO ENCONTRADO", name);
    }
}

int getUserOption() {
    unsigned int option;

    printf("Digite uma das opções acima: ");
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
    printf("0 - Sair");
}

void divisor() {
    printf("\n-------------------\n");
}

void clearTerminal() {
    system("clear");
}
int main() {
    char nomeCliente[nome];
    char nomeGerente[nome];

    Projeto projeto[] = {
        {
            1,
            "Jorge",
            "jorgin",
            100000.00,
            {
                50000.00,
                10000.00,
                100.00,
                500.00
            },
            {
            	27,
            	12,
            	2022
            }
        },
        {
            2,
            "Miguel",
            "Miguelzinho",
            100000.00,
            {
                10000.00,
                40000.00,
                6000.00,
                9000.00
            },
            {
            	20,
            	2,
            	2010
            }
        }
    };

    unsigned int arrayLength = sizeof(projeto)/sizeof(projeto[0]);
    Projeto* listaProjetos = (Projeto*) malloc(arrayLength * sizeof(Projeto));

    // Coloca os projetos na memória alocada
    for (unsigned int i = 0; i < arrayLength; i++)
    {
        // Base do projeto
        strcpy(listaProjetos[i].cliente, projeto[i].cliente);
        strcpy(listaProjetos[i].gerente, projeto[i].gerente);
        listaProjetos[i].codigo = projeto[i].codigo;
        listaProjetos[i].receitaProjeto = projeto[i].receitaProjeto;
        listaProjetos[i].dataEntrega = projeto[i].dataEntrega;

        // Despesas
        listaProjetos[i].despesas.deslocamento = projeto[i].despesas.deslocamento;
        listaProjetos[i].despesas.horasExtras = projeto[i].despesas.horasExtras;
        listaProjetos[i].despesas.salarioDesenvolvedor = projeto[i].despesas.salarioDesenvolvedor;
        listaProjetos[i].despesas.outros = projeto[i].despesas.outros;

        // Datas
        listaProjetos[i].dataEntrega.ano = projeto[i].dataEntrega.ano;
        listaProjetos[i].dataEntrega.mes = projeto[i].dataEntrega.mes;
        listaProjetos[i].dataEntrega.dia = projeto[i].dataEntrega.dia;

    }

    int option = 1;
    while (option == 1)
    {
        divisor();
        showAvaiableOptions();
        divisor();
        int userOption = getUserOption();
        divisor();
        clearTerminal();

        switch (userOption)
        {
        case 1:
            getLucroTotal(listaProjetos, arrayLength);
            break;
        case 2:
            getProjetosAtrasados(listaProjetos, arrayLength);
            break;
        case 3:
            getProjetoComMaisHorasExtras(listaProjetos, arrayLength);
            break;
        case 4:
            getProjetoComMaiorGasto(listaProjetos, arrayLength);
            break;
        case 5:
            printf("\nDigite o nome do gerente desejado: ");
            scanf("%s", nomeGerente);
            getProjectsInfoByGerente(listaProjetos, arrayLength, nomeGerente);
            break;
        case 6:
            printf("\nDigite o nome do cliente desejado: ");
            scanf("%s", nomeCliente);
            getProjectInfoByCliente(listaProjetos, arrayLength, nomeCliente);
            break;
        case 0:
            divisor();
            printf("MUITO OBRIGADO POR UTILIZAR O SISTEMA");
            option = 0;
            break;
        default:
            divisor();
            printf("DIGITE UMA OPÇÃO VÁLIDA");
            break;
        }
    }
    free(listaProjetos);
    return 0;
}
