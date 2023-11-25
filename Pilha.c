#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *topo;
    int contador;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->contador = 0;
}

int vazia(Pilha *pilha) {
    return pilha -> topo == NULL;
}

void empilhar(Pilha *pilha, int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
    pilha->contador++;
}

void desemplihar(Pilha *pilha) {
    if (vazia(pilha)) {
        printf("Erro: a pilha está vazia\n");
        return;
    }

    No *memoria = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(memoria);
    pilha->contador--;
}

void quantidadeElementos(Pilha *pilha) {
    printf("Total de elementos na pilha: %d\n", pilha->contador);
}

void exibirTopo(Pilha *pilha) {
    if (vazia(pilha)) {
        printf("Erro: a pilha está vazia\n");
        return;
    }
    printf("Elemento do topo da pilha: %d\n", pilha->topo->dado);
}

void mostrar(Pilha *pilha) {
    if (vazia(pilha)) {
        printf("Erro: a pilha está vazia\n");
        return;
    }
    //printf("Elementos da pilha: ");
    No *noAtual = pilha->topo;
    while (noAtual != NULL) {
        printf("Elementos da pilha: %d\n", noAtual->dado);
        noAtual = noAtual->prox;
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    int opcao, valor;

    while (1) {
        printf("\n----------------Menu--------------\n");
        printf("[1] Empilhar elemento\n");
        printf("[2] Desempilhar elemento\n");
        printf("[3] Exibir quantidade de elementos\n");
        printf("[4] Exibir o topo da pilha\n");
        printf("[5] Mostrar pilha\n");
        printf("[0] Sair\n");
        printf("Informe a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("\n<Programa encerrado!>");
                return 0;
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilhar(&pilha, valor);
                printf("Empilhado com sucesso!\n");
                break;
            case 2:
                desemplihar(&pilha);
                printf("Desempilhado com sucesso!\n");
                mostrar(&pilha);
                break;
            case 3:
                quantidadeElementos(&pilha);
                break;
            case 4:
                exibirTopo(&pilha);
                break;
            case 5:
                mostrar(&pilha);
        }
    }
}