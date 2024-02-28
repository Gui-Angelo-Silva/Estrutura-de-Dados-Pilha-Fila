#include <stdlib.h>
#include <stdio.h>
#define N 5

typedef struct Fila
{
    int id;
    char nome[20];
} Fila;

int estavazia(int IL, int FL)
{
    if (IL == -1 && FL == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int estacheia(int IL, int FL, int IA, int FA)
{
    if (IL == IA && FL == FA)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inserir(Fila LL[], int *IL, int *FL, int IA, int FA)
{
    Fila NovoNodo;
    printf("Informe o id e o nome: ");
    scanf("%d %s", &NovoNodo.id, NovoNodo.nome);

    if (estacheia(*IL, *FL, IA, FA) == 1)
    { // O ponteiro adicionado ao IL e FL, está pegando oq está na memória e não o endereço
        printf("\nA fila está cheia, verifica dá próxima vez!\n");
    }
    else
    {
        if (estavazia(*IL, *FL) == 1)
        {
            *IL = (*FL = FA);
        }
        else if (*FL < FA)
        {
            *FL = *FL + 1; // Verificar se tem espaço à direita
        }
        else
        {
            for (int i = *IL; i <= *FL; i++)
            {
                LL[i - 1] = LL[i];
            }
            *IL = *IL - 1;
        }
        LL[*FL] = NovoNodo;
    }
}

void remover(Fila LL[], int *IL, int *FL)
{
    if (estavazia(*IL, *FL) == 1)
    {
        printf("A lista está vazia!\n\n");
    }
    else
    {
        Fila vazio;
        LL[*IL] = vazio;

        if (*IL == *FL)
        {
            *IL = (*FL = -1);
        }
        else
        {
            *IL = *IL + 1;
        }
    }
}

int mostrar(Fila LL[], int IL, int FL, int IA, int FA)
{
    for (int i = IA; i <= FA; i++)
    {

        if (i >= IL && i <= FL)
        {
            printf("%d\n", LL[i].id);
            printf("%s\n\n", LL[i].nome);
        }
        else
        {
            printf("-----------\n");
            printf("-----------\n\n");
        }
    }
}

int mostrarUltimo(Fila LL[], int IL, int FL)
{
    if (estavazia(IL, FL) == 1)
    {
        printf("A lista está vazia!\n\n");
    }
    else
    {
        printf("%d\n", LL[IL].id);
        printf("%s\n\n", LL[IL].nome);
    }
}

int mostrarPrimeiro(Fila LL[], int IL, int FL)
{
    if (estavazia(IL, FL) == 1)
    {
        printf("A lista está vazia!\n\n");
    }
    else
    {
        printf("%d\n", LL[FL].id);
        printf("%s\n\n", LL[FL].nome);
    }
}

int quantidade(int IL, int FL)
{
    if (estavazia(IL, FL) == 1)
    {
        printf("A lista está vazia!\n\n");
    }
    else
    {
        printf("Quantidade de elementos: %d\n\n", (FL - IL) + 1);
    }
}

int main()
{
    struct Fila LL[N];
    int opcao, IA = 0, FA = N - 1, IL = -1, FL = -1;

    while (1)
    {
        printf("\n-------------MENU------------");
        printf("\n[1] - Inserir");
        printf("\n[2] - Remover");
        printf("\n[3] - Quantidade de elementos");
        printf("\n[4] - Mostrar primeiro");
        printf("\n[5] - Mostrar último");
        printf("\n[6] - Mostrar fila");
        printf("\n[0] - Sair");
        printf("\nInforme a opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("\n<Programa encerrado!>");
            return 0;
        case 1:
            inserir(LL, &IL, &FL, IA, FA);
            break;
        case 2:
            remover(LL, &IL, &FL);
            break;
        case 3:
            quantidade(IL, FL);
            break;
        case 4: 
            mostrarPrimeiro(LL, IL, FL);
            break;
        case 5:
            mostrarUltimo(LL, IL, FL);
            break;
        case 6:
            mostrar(LL, IL, FL, IA, FA);
            break;
        default:
            printf("\nOpção Inválida!\n");
        }
    }
}
