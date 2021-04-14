// Simulador de Processamentos
// Alunos: Renata Costa - Engenharia da Computacao

#include <stdio.h>

#define LISTAR 1
#define DETALHES 2
#define ATUAL 3
#define ADICIONAR 4
#define RESET 5
#define CICLO 6

typedef struct 
{
    char* nome;
    int prioridade;
    int tempoExecucao;

    struct TProcesso* seguinte;
}TProcesso;

typedef struct
{
    TProcesso* inicio;
    int tamanho;    
} Pilha;

void ExibeMenu()
{
    printf("\nSelecione uma op%c%co:\n", 135,198);
    printf("\t%d - Listar processos", LISTAR);
    printf("\t%d - Listar processos detalahadamente", DETALHES);
    printf("\t%d - Visualizar processo atual", ATUAL);
    printf("\t%d - Adicionar processo", ADICIONAR);
    printf("\t%d - Resetar pilha", RESET);
    printf("\t%d - Avan%car ciclo", CICLO, 135);
}

void main()
{
    ExibeMenu();
}