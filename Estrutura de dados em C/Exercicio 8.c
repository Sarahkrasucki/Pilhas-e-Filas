/* Há duas filas chamadas qpar e qimpar e uma pilha s. As três estruturas são representadas por vetores com, no máximo, 30 elementos. 
O algoritmo lê uma seqüência determinada de valores inteiros. O valor zero finaliza a entrada de dados. 
Em seguida, é determinado se um certo número é par ou ímpar. 
Se o número for par, ´mesmo é colocado na fila qpar, caso contrário, na fila qimpar. 
Logo após a entrada do valor zero, alternadamente (começando-se pela fila qimpar), é retirado um elemento de cada fila até o momento em que ambas tornam-se vazias. 
Se o elemento de uma das filas for um valor positivo, ele é colocado na pilha s, caso contrário, é removido um elemento da pilha s. 
Ao finalizar o processo, é exibido todo o conteúdo da pilha s. */  
#include <stdio.h>
#define TAMANHO_MAX 30 // Tamanho máximo para as filas e pilha

// Estrutura da fila
typedef struct {
    int itens[TAMANHO_MAX]; // Array para armazenar os itens da fila
    int frente;             // Índice do primeiro elemento da fila
    int tras;               // Índice do último elemento da fila
} Fila;

// Estrutura da pilha
typedef struct {
    int itens[TAMANHO_MAX]; // Array para armazenar os itens da pilha
    int topo;               // Índice do topo da pilha
} Pilha;

// Função para inicializar uma fila
void inicializarFila(Fila *fila) {
    fila->frente = -1;
    fila->tras = -1;
}

// Função para inicializar uma pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *fila) {
    return fila->frente == -1;
}

// Função para verificar se a fila está cheia
int filaCheia(Fila *fila) {
    return fila->tras == TAMANHO_MAX - 1;
}

// Função para enfileirar (inserir) um elemento na fila
void enfileirar(Fila *fila, int valor) {
    if (filaCheia(fila)) {
        printf("Erro: fila cheia\n");
    } else {
        if (filaVazia(fila)) {
            fila->frente = 0;
        }
        fila->tras++;
        fila->itens[fila->tras] = valor;
    }
}

// Função para desenfileirar (remover) um elemento da fila
int desenfileirar(Fila *fila) {
    if (filaVazia(fila)) {
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

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para verificar se a pilha está cheia
int pilhaCheia(Pilha *pilha) {
    return pilha->topo == TAMANHO_MAX - 1;
}

// Função para empilhar (inserir) um elemento na pilha
void empilhar(Pilha *pilha, int valor) {
    if (pilhaCheia(pilha)) {
        printf("Erro: pilha cheia\n");
    } else {
        pilha->topo++;
        pilha->itens[pilha->topo] = valor;
    }
}

// Função para desempilhar (remover) um elemento da pilha
int desempilhar(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: pilha vazia\n");
        return -1; // Valor inválido, se a pilha estiver vazia
    } else {
        int valor = pilha->itens[pilha->topo];
        pilha->topo--;
        return valor;
    }
}

int main() {
    Fila qpar, qimpar;
    Pilha s;
    inicializarFila(&qpar);
    inicializarFila(&qimpar);
    inicializarPilha(&s);

    int valor;
    
    // Leitura dos valores até encontrar 0
    printf("Digite uma sequência de valores inteiros (0 para finalizar):\n");
    while (1) {
        scanf("%d", &valor);
        if (valor == 0) {
            break;
        }
        if (valor % 2 == 0) {
            enfileirar(&qpar, valor);
        } else {
            enfileirar(&qimpar, valor);
        }
    }

    // Processamento alternado das filas
    int alternar = 1; // Começa com 1 para alternar, 0 para mudar para a outra fila
    while (!filaVazia(&qpar) || !filaVazia(&qimpar)) {
        if (alternar) {
            if (!filaVazia(&qimpar)) {
                valor = desenfileirar(&qimpar);
                if (valor > 0) {
                    empilhar(&s, valor);
                } else {
                    desempilhar(&s);
                }
            }
        } else {
            if (!filaVazia(&qpar)) {
                valor = desenfileirar(&qpar);
                if (valor > 0) {
                    empilhar(&s, valor);
                } else {
                    desempilhar(&s);
                }
            }
        }
        alternar = !alternar;
    }

    // Mostrar o conteúdo da pilha s
    printf("Conteúdo da pilha após o processamento:\n");
    while (!pilhaVazia(&s)) {
        printf("%d\n", desempilhar(&s));
    }

    return 0;
}

