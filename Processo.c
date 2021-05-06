// Simulador de Processamentos
// Trabalho para a materia de Estrutura de Dados
// Universidade Positivo
// Professor Felipe Przysiada
// Alunos: Renata Costa - Engenharia da Computacao
         //Diego de Oliveira - Engenharia Elétrica
         
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

<<<<<<< HEAD
//Constantes para o Menu 
=======
//Constantes para o Menu //Diego: reorganizei os numeros // OK Renata
>>>>>>> c4cc24b8fd7fd6decfb38619786f72565302cd21
#define SAIR 0
#define ADICIONAR 1
#define ATUAL 2
#define LISTAR 3
#define RESET 4
#define CICLO 5

int EmExecucao = 0;

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

int AdProcesso(TPilha *pilha, TProcesso* atual) 
{
    TProcesso *novo;
    char* auxNome;
    int auxPrioridade, auxTempo;
    // static int EmExecucao = 0; 

    if((auxNome=(char*)malloc(sizeof(char))) == NULL)
    {
        return -1;
    }
    printf("Informe o nome: ");
    scanf("%s", auxNome);
    printf("Informe a prioridade: ");
    scanf("%i", &auxPrioridade);
    printf("Informe o tempo de execucao: ");
    scanf("%i", &auxTempo);

    
    
    if(EmExecucao == 0 ){
        strcpy(atual->nome, auxNome);
        atual->prioridade = auxPrioridade;
        atual->tempoExecucao = auxTempo;
        atual->seguinte = pilha->inicio;
        EmExecucao = 1;
    }
    else 
    {
        if((novo =(TProcesso*) malloc(sizeof(TProcesso))) == NULL)
        {
            return -1;
        }
        if((novo->nome=(char*)malloc(sizeof(char))) == NULL)
        {
            return -1;
        }
        if(atual->prioridade >= auxPrioridade || atual->prioridade < 3)
        {
            novo->nome = auxNome;
            novo->prioridade = auxPrioridade;
            novo->tempoExecucao = auxTempo;
            novo->seguinte = pilha->inicio;
            pilha->inicio = novo;
            pilha->tamanho++;
        }
        else
        {
            novo->nome = atual->nome;
            novo->prioridade = atual->prioridade;
            novo->tempoExecucao = atual->tempoExecucao;
            atual->nome = auxNome;
            atual->prioridade = auxPrioridade;
            atual->tempoExecucao = auxTempo;

            novo->seguinte = pilha->inicio;
            pilha->inicio = novo;
            pilha->tamanho++;
        }
    }
    return 0;

}

<<<<<<< HEAD
int printAtual(TProcesso* atual) 
=======
int printAtual(TProcesso* atual) //Diego: Criei a funcao atual TODO n imprimir quando vazio // Ok Renata
>>>>>>> c4cc24b8fd7fd6decfb38619786f72565302cd21
{
    if (EmExecucao != 0)
    {
        printf("\n\nProcesso atual\n");
        printf("\tNome                   %s\n", atual->nome);
        printf("\tPrioridade             %d\n", atual->prioridade);
        printf("\tTempo de execucao      %d\n", atual->tempoExecucao);
        printf("\n");
    }
    else
    {
        printf("\nProcesso atual ainda n%co inicializado\n", 198);
    }
    
}

void List_Pilha(TPilha* pilha)
{
    TProcesso *atual;
    int i;
    atual = pilha->inicio;

    printf("\n\nA pilha tem %i processos\n\n", pilha->tamanho);
    if(pilha->tamanho > 0)
    { 
        printf("--------TOPO DA PILHA--------\n");
        for (i = 0; i <pilha->tamanho; i++)
        {
            printf("Processo\n");
            printf("\tNome                   %s\n", atual->nome);
            printf("\tPrioridade             %i\n", atual->prioridade);
            printf("\tTempo de execucao      %i\n", atual->tempoExecucao);
            atual = atual->seguinte;
        }
        printf("-------- FUNDO DA PILHA--------\n");
    }
<<<<<<< HEAD
=======
    printf("-------- FUNDO DA PILHA--------\n");
>>>>>>> c4cc24b8fd7fd6decfb38619786f72565302cd21
}

int Reset(TPilha* pilha )
{
    TProcesso* limpar;

    if(pilha->tamanho == 0)
    {
        return -1;
    }
    do
    {
        limpar = pilha->inicio;
        pilha->inicio = pilha->inicio->seguinte;
        free(limpar->nome);
        free(limpar);
        pilha->tamanho--;
    }while(pilha->tamanho > 0);

    return 0;
}

int Passar_Ciclo(TProcesso* atual, TPilha* pilha)
{
    if(atual->tempoExecucao <= 0)
    {
        printf("Erro 0x004"); //
    }
    atual->tempoExecucao--;
    if(atual->tempoExecucao == 0)
    {
        printf("\nProcesso finalizado\nInicializando novo processo . . .\n");

        if(pilha->tamanho > 0)
        {
            strcpy(atual->nome, pilha->inicio->nome);
            atual->prioridade = pilha->inicio->prioridade;
            atual->tempoExecucao = pilha->inicio->tempoExecucao;
            pilha->inicio = pilha->inicio->seguinte;
            pilha->tamanho--;
        }
        else
        {
            printf("\nPilha vazia\nCrie novos processos para continuar . . .\n");
        }
    }
    return 0;
}

<<<<<<< HEAD
void ExibeMenu()
=======
void ExibeMenu() //Diego: Realinhei o menu //OK
>>>>>>> c4cc24b8fd7fd6decfb38619786f72565302cd21
{
    printf("\nSelecione uma op%c%co:\n", 135,198);
    printf("\t%d - Adicionar processo\n", ADICIONAR);
    printf("\t%d - Visualizar processo atual\n", ATUAL);
    printf("\t%d - Listar processos\n", LISTAR);
    printf("\t%d - Resetar pilha\n", RESET);
    printf("\t%d - Avan%car ciclo\n", CICLO, 135);
    printf("\t%d - Sair\n", SAIR);
}


int main()
{
    TPilha *execucao;
    TProcesso* atual;
    int opcao;
    
    if((execucao = (TPilha*) malloc(sizeof(TPilha))) == NULL)
    {
        printf("Erro 0x001\n\t...Encerrando...");// o nome do erro eh so para fazer graca
        return -1;
    }
    if((atual =(TProcesso*) malloc(sizeof(TProcesso))) == NULL)
    {
        return -1;
        printf("Erro 0x001\n\t...Encerrando...");
    }
    if((atual->nome=(char*)malloc(sizeof(char))) == NULL)
    {
        return -1;
        printf("Erro 0x001\n\t...Encerrando...");
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
        case ADICIONAR:
            if(AdProcesso(execucao, atual) < 0)
            {
                printf("Erro 0x002\n\tO processo n%co pode ser criado", 198);
            }
            break;
        case ATUAL:
            printAtual(atual);
<<<<<<< HEAD
            // break; //Professor, para facilitar a vizualizacao, deixamos sem esse break para que sempre que sempre q ele imprima o atual ele imprima tambem a lista
=======
            //break; //Diego: Deixei sem o break para ele tambem imprimir a pilha, imprimindo assim "o estado atual de forma geral", achei mais facil para debugar e gostei assim, oq acha? // Concordo
>>>>>>> c4cc24b8fd7fd6decfb38619786f72565302cd21
        case LISTAR:
            List_Pilha(execucao);
            break;
        case RESET:
            if(Reset(execucao) < 0)
            {
                printf("Erro 0x003: Pilha vazia\n");
            }
            break;
        case CICLO:
            Passar_Ciclo(atual, execucao);
            break;
        
        default:
            printf("\aOpcao invalida\n");
            break;
        }
    } while (opcao != SAIR);
}