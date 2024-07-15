/* Dado uma fila de inteiros, o algoritmo que exclui todos os inteiros negativos sem alterar a 
posição dos outros elementos na fila q.*/  
#include <stdio.h>
#define TAMANHO_MAX 100 // Tamanho máximo para as filas

// Estrutura da fila
typedef struct {
    int itens[TAMANHO_MAX]; // Array para armazenar os itens da fila
    int frente;             // Índice do primeiro elemento da fila
    int tras;               // Índice do último elemento da fila
} Fila;

// Função para inicializar uma fila
void inicializar(Fila *fila) {
    fila->frente = -1;
    fila->tras = -1;
}

// Função para verificar se a fila está vazia
int estaVazia(Fila *fila) {
    return fila->frente == -1;
}

// Função para verificar se a fila está cheia
int estaCheia(Fila *fila) {
    return fila->tras == TAMANHO_MAX - 1;
}

// Função para enfileirar (inserir) um elemento na fila
void enfileirar(Fila *fila, int valor) {
    if (estaCheia(fila)) {
        printf("Erro: fila cheia\n");
    } else {
        if (estaVazia(fila)) {
            fila->frente = 0;
        }
        fila->tras++;
        fila->itens[fila->tras] = valor;
    }
}

// Função para desenfileirar (remover) um elemento da fila
int desenfileirar(Fila *fila) {
    if (estaVazia(fila)) {
        printf("Erro: fila vazia\n");
        return -1; // Valor inválido, se a fila estiver vazia
    } else {
        int valor = fila->itens[fila->frente];
        if (fila->frente == fila->tras) {
            // Fila se tornará vazia
            fila->frente = -1;
            fila->tras = -1;
        } else {
            fila->frente++;
        }
        return valor;
    }
}

// Função para excluir todos os inteiros negativos da fila
void excluirNegativos(Fila *fila) {
    Fila aux; // Fila auxiliar para armazenar os elementos não negativos
    inicializar(&aux);
    
    // Processa a fila original
    while (!estaVazia(fila)) {
        int valor = desenfileirar(fila);
        if (valor >= 0) {
            enfileirar(&aux, valor); // Apenas enfileira valores não negativos
        }
    }
    
    // Copia os elementos da fila auxiliar de volta para a fila original
    while (!estaVazia(&aux)) {
        enfileirar(fila, desenfileirar(&aux));
    }
}

int main() {
    Fila fila;
    inicializar(&fila);
    int n, valor;

    // Solicitar ao usuário que insira a quantidade de valores a serem enfileirados
    printf("Digite a quantidade de valores a serem inseridos na fila: ");
    scanf("%d", &n);

    // Ler os valores do usuário e enfileirar
    printf("Digite os valores a serem inseridos na fila:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &valor);
        enfileirar(&fila, valor);
    }

    // Excluir elementos negativos da fila
    printf("Excluindo numeros negativos da fila...\n");
    excluirNegativos(&fila);

    // Mostrar o conteúdo da fila após a exclusão dos negativos
    printf("Conteúdo da fila depois de excluir os numeros negativos:\n");
    while (!estaVazia(&fila)) {
        printf("%d\n", desenfileirar(&fila));
    }

    return 0;
}
