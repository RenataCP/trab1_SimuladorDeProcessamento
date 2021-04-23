// Simulador de Processamentos
// Alunos: Renata Costa - Engenharia da Computacao
         //Diego de Oliveira - Engenharia Elétrica
#include <stdio.h>
#include <stdlib.h> //incluido biblioteca

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
    char *nome;
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
        printf("Elemento\n");
        printf("\tNome                   %c\n", atual->nome);
        printf("\tPrioridade             %i\n", atual->prioridade);
        printf("\tTempo de execucao      %i\n", atual->tempoExecucao);
        atual = atual->seguinte;
    }
    printf("-------- FUNDO DA PILHA--------\n");
}

void Tamanho_Pilha(TPilha *pilha)
{
    printf("\n\tA pilha tem elementos : %i\n\n", pilha->tamanho);
}

/*int Pop_Pilha(TPilha *pilha)
{
    TProcesso *remove_elemento;
    if(pilha->tamanho == 0)
        return -1;
    remove_elemento = pilha->inicio;
    pilha->inicio = pilha->inicio->seguinte;
    free(remove_elemento->nome);
    free(remove_elemento);
    pilha->tamanho--;
    return 0;
}*/

int AdProcesso(TPilha *pilha)
{
    TProcesso *novo;
    if((novo =(TProcesso*) malloc(sizeof(TProcesso))) == NULL)
    {
        return -1;
    }
    if((novo->nome=(char*)malloc(sizeof(char))) == NULL)
    {
        return -1;
    }
    printf("Informe o nome: ");
    scanf("%s", &novo->nome);
    printf("Informe a prioridade: ");
    scanf("%i", &novo->prioridade);
    printf("Informe o tempo de execucao: ");
    scanf("%i", &novo->tempoExecucao);
    novo->seguinte = pilha->inicio;
    pilha->inicio = novo;
    pilha->tamanho++;
    return 0;

}

void ExibeMenu()
{
    printf("\nSelecione uma op%c%co:\n", 135,198);
    printf("\t%d - Listar processos\n", LISTAR);
    printf("\t%d - Listar processos detalhadamente\n", DETALHES);
    printf("\t%d - Visualizar processo atual\n", ATUAL);
    printf("\t%d - Adicionar processo\n", ADICIONAR);
    printf("\t%d - Resetar pilha\n", RESET);
    printf("\t%d - Avan%car ciclo\n", CICLO, 135);
    printf("\t%d - Sair\n", SAIR);
}


int main()
{
    TPilha *execucao;
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
            List_Pilha(execucao);
            break;
        case DETALHES:
            // printf("\nDETALHES");
            break;
        case ATUAL:
            Tamanho_Pilha(execucao);
            break;
        case ADICIONAR:
            AdProcesso(execucao);
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