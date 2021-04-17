// Simulador de Processamentos
// Alunos: Renata Costa - Engenharia da Computacao
#include <stdio.h>

//Constantes para o Menu
#define SAIR 0
#define LISTAR 1
#define DETALHES 2
#define ATUAL 3
#define ADICIONAR 4
#define RESET 5
#define CICLO 6

//Dado tipo Processo
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
}TPilha;

void Init(TPilha* pilha)
{
    pilha->inicio = NULL;
    pilha->tamanho = 0;
}

void List_Pilha(TPilha* pilha) //Adicionado List_Pilha
{
    TProcesso *atual;
    int i;
    atual = pilha->inicio;

    printf("\n\nA pilha tem elementos: %i\n\n", pilha->tamanho);
    printf("--------TOPO DA PILHA--------\n");
    for (i = 0; i <pilha->tamanho; i++)
    {
        printf(" %s\n", atual->nome);
        atual = pilha->inicio;
    }

}

void ExibeMenu()
{
    printf("\nSelecione uma op%c%co:\n", 135,198);
    printf("\t%d - Listar processos\n", LISTAR);
    printf("\t%d - Listar processos detalahadamente\n", DETALHES);
    printf("\t%d - Visualizar processo atual\n", ATUAL);
    printf("\t%d - Adicionar processo\n", ADICIONAR);
    printf("\t%d - Resetar pilha\n", RESET);
    printf("\t%d - Avan%car ciclo\n", CICLO, 135);
    printf("\t%d - Sair\n", SAIR);
}


int main()
{
    TPilha* execucao;
    int opcao;

    if((execucao = (TPilha*) malloc(sizeof(TPilha))) == NULL)
    {
        printf("Erro 0x001\n\t...Encerrando...");// o nome do erro eh so para fazer graca
        return -1;
    }
    Init(execucao);
    do
    {
        ExibeMenu(); 
        scanf("%d", &opcao);

        switch (opcao)
        {
        case SAIR:
            // printf("\nSAIR");
            break;
        case LISTAR:
            // printf("\nLISTAR");
            break;
        case DETALHES:
            // printf("\nDETALHES");
            break;
        case ATUAL:
            // printf("\nATUAL");
            break;
        case ADICIONAR:
            // printf("\nADICIONAR");
            break;
        case RESET:
            // printf("\nRESET");
            break;
        case CICLO:
            // printf("\nCICLO");
            break;
        
        default:
            printf("\aOpcao invalida\n");
            break;
        }
    } while (opcao != SAIR);
}