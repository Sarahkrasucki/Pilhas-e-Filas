// Algoritmo para ler uma frase e imprimi-la com palavras invertidas. Exemplo: A frase “um por todos e todos por um”, deverá ficar “mu rop sodot e sodot rop mu”. 
#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    char palavra[20];
    int i = 0, j = 0, k;

    // Ler a frase do usuário
    printf("Digite uma frase: ");
    // Armazena cada palavra dentro de um array. Estrutura: (fgets(variavel que será lida, numero de espaços no array, onde os caracteres serão lidos);)
    fgets(frase, sizeof(frase), stdin);

    // Remover o caractere de nova linha no final da string. ***Não obrigatório
    frase[strcspn(frase, "\n")] = 0;

    printf("Frase com palavras invertidas: ");

    while (frase[i] != '\0') {
        // Se o caractere não for espaço, adiciona à palavra atual
        if (frase[i] != ' ') {
            palavra[j++] = frase[i];
        } else {
            // Termina a palavra atual
            palavra[j] = '\0';
            // Inverte a palavra e imprime
            for (k = j - 1; k >= 0; k--) {
                printf("%c", palavra[k]);
            }
            printf(" ");
            j = 0;  // zera o índice da palavra
        }
        i++;
    }
    
    // Para a última palavra que não tem um espaço no final
    palavra[j] = '\0';
    for (k = j - 1; k >= 0; k--) {
        printf("%c", palavra[k]);
    }

    printf("\n");

    return 0;
}

