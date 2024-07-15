/* algoritmo que localiza um determinado elemento em uma pilha. Em seguida, faz a 
remoção do mesmo. Para tanto, se o elemento não estiver no topo, os elementos anteriores ao elemento 
procurado são desempilhados e, após a remoção, empilhado novamente. O algoritmo  
preve a possibilidade de o elemento que esta sendo procurado não existir na pilha. */  
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

// Função para localizar e remover um elemento da pilha
int localizarERemover(Pilha *pilha, int valor) {
    Pilha pilhaAux; // Pilha auxiliar para armazenar os elementos temporariamente
    inicializar(&pilhaAux);
    int encontrado = 0;
    
    // Desempilha até encontrar o elemento ou esvaziar a pilha
    while (!estaVazia(pilha)) {
        int topo = desempilhar(pilha);
        if (topo == valor) {
            encontrado = 1;
            break; // Elemento encontrado e removido
        } else {
            empilhar(&pilhaAux, topo); // Empilha na pilha auxiliar
        }
    }
    
    // Restaura os elementos na pilha original, se o elemento foi encontrado
    while (!estaVazia(&pilhaAux)) {
        empilhar(pilha, desempilhar(&pilhaAux));
    }
    
    if (!encontrado) {
        printf("Erro: elemento %d não encontrado na pilha\n", valor);
    }
    
    return encontrado;
}

int main() {
    Pilha pilha;
    inicializar(&pilha);
    int valor;
    
    printf("Digite os valores (0 para terminar):\n");
    do {
        scanf("%d", &valor);
        if (valor != 0) {
            // Empilha na pilha original
            if (estaCheia(&pilha)) {
                printf("Erro: pilha original cheia\n");
                break;
            }
            empilhar(&pilha, valor);
        }
    } while (valor != 0);
    
    printf("Digite o valor a ser remonido: \n");
    scanf("%d", &valor);
    if (localizarERemover(&pilha, valor)) {
        printf("Elemento %d removido com sucesso\n", valor);
    } else {
        printf("Elemento %d não encontrado na pilha\n", valor);
    }
    // Mostrar o conteúdo da pilha após remoção
    printf("Conteúdo da pilha após remoção:\n");
    while (!estaVazia(&pilha)) {
        printf("%d\n", desempilhar(&pilha));
    }

    return 0;
}
