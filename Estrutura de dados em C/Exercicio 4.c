/* algoritmo que empilha uma seqüência de valores numéricos inteiros positivos até o momento em que o valor 999 for digitado. 
Neste momento, o conteúdo da pilha é distribuído em outras duas pilhas. Um delas conterá apenas os valores ímpares, e a outra conterá apenas os valores pares. */  
#include <stdio.h>

#define TAMANHO_MAX 100 // Tamanho máximo para as pilhas

// Estrutura da pilha
typedef struct {
    int itens[TAMANHO_MAX]; // Array para armazenar os itens da pilha
    int topo;               // Índice do topo da pilha (-1 quando vazia)
} Pilha;

// Função para inicializar uma pilha
void inicializar(Pilha *pilha) {
    pilha->topo = -1; // Inicializa o topo como vazio
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para verificar se a pilha está cheia
int estaCheia(Pilha *pilha) {
    return pilha->topo == TAMANHO_MAX - 1;
}

// Função para empilhar um elemento na pilha
void empilhar(Pilha *pilha, int valor) {
    if (estaCheia(pilha)) {
        printf("Erro: pilha cheia\n");
    } else {
        pilha->topo++;
        pilha->itens[pilha->topo] = valor;
    }
}

// Função para desempilhar um elemento da pilha
int desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: pilha vazia\n");
        return -1; // Valor inválido, se a pilha estiver vazia
    } else {
        int valor = pilha->itens[pilha->topo];
        pilha->topo--;
        return valor;
    }
}

int main() {
    Pilha original, impares, pares;
    int valor;

    // Inicializa as pilhas
    inicializar(&original);
    inicializar(&impares);
    inicializar(&pares);

    printf("Digite os valores (999 para terminar):\n");

    do {
        scanf("%d", &valor);
        if (valor != 999) {
            // Empilha na pilha original
            if (estaCheia(&original)) {
                printf("Erro: pilha original cheia\n");
                break;
            }
            original.topo++;
            original.itens[original.topo] = valor;
        }
    } while (valor != 999);

    // Distribui os valores da pilha original nas pilhas de ímpares e pares
    while (!estaVazia(&original)) {
        int valor = desempilhar(&original);
        if (valor % 2 == 0) {
            // Empilha em 'pares' se for par
            if (estaCheia(&pares)) {
                printf("Erro: pilha de pares cheia\n");
                break;
            }
            pares.topo++;
            pares.itens[pares.topo] = valor;
        } else {
            // Empilha em 'impares' se for ímpar
            if (estaCheia(&impares)) {
                printf("Erro: pilha de ímpares cheia\n");
                break;
            }
            impares.topo++;
            impares.itens[impares.topo] = valor;
        }
    }

    // Imprime os valores na pilha de ímpares
    printf("Valores na pilha de ímpares:\n");
    while (!estaVazia(&impares)) {
        printf("%d\n", desempilhar(&impares));
    }

    // Imprime os valores na pilha de pares
    printf("Valores na pilha de pares:\n");
    while (!estaVazia(&pares)) {
        printf("%d\n", desempilhar(&pares));
    }

    return 0;
}
