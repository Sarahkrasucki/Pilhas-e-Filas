/* algoritmo que remova todos os múltiplos de 3 de uma pilha.*/  
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
    Pilha original, temp;
    int valor;

    // Inicializa as pilhas
    inicializar(&original);
    inicializar(&temp);

    printf("Digite os valores (0 para terminar):\n");

    do {
        scanf("%d", &valor);
        if (valor != 0) {
            // Empilha na pilha original
            if (estaCheia(&original)) {
                printf("Erro: pilha original cheia\n");
                break;
            }
            empilhar(&original, valor);
        }
    } while (valor != 0);

    // Remove todos os múltiplos de 3 da pilha original
    while (!estaVazia(&original)) {
        valor = desempilhar(&original);
        if (valor % 3 != 0) {
            empilhar(&temp, valor);
        }
    }

    // Retorna os valores da pilha temporária para a pilha original
    while (!estaVazia(&temp)) {
        valor = desempilhar(&temp);
        empilhar(&original, valor);
    }

    // Imprime os valores restantes na pilha original
    printf("Valores na pilha que não são múltiplos de 3:\n");
    while (!estaVazia(&original)) {
        printf("%d\n", desempilhar(&original));
    }
    
    return 0;
}
