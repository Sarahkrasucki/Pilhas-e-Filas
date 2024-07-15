// algoritmo que determine se uma expressão é palíndroma ou não
#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para usar isalpha()

#define TAM_MAX 1000

int main() {
    char frase[TAM_MAX];
    char fraseSemEspacos[TAM_MAX];
    char fraseSemEspacosInvertida[TAM_MAX];
    int i, j, tamanho;

    // Lê a frase do usuário
    printf("Digite uma frase: ");
    fgets(frase, TAM_MAX, stdin);

    // Remover o enter (\n) no final da string lida com fgets
    frase[strcspn(frase, "\n")] = '\0';

    // Remove espaços da frase e copia para fraseSemEspacos
    for (i = 0, j = 0; frase[i] != '\0'; i++) {
        if (isalpha(frase[i])) { // Verifica se é uma letra
            fraseSemEspacos[j++] = tolower(frase[i]); // Converte para minúscula
        }
    }
    fraseSemEspacos[j] = '\0'; // Adicionar o caractere nulo ao final da string. Serve para informar que a frase acabou

    // Inverte a fraseSemEspacos
    tamanho = strlen(fraseSemEspacos);
    for (i = 0, j = tamanho - 1; i < tamanho; i++, j--) {
        fraseSemEspacosInvertida[i] = fraseSemEspacos[j];
    }
    fraseSemEspacosInvertida[tamanho] = '\0'; // Adicionar o caractere nulo ao final da string invertida

    // Compara a frase original sem espaços com a frase invertida sem espaços
    int palindromo = 1; // Assumimos que é um palíndromo
    for (i = 0; i < tamanho; i++) {
        if (fraseSemEspacos[i] != fraseSemEspacosInvertida[i]) {
            palindromo = 0; // Não é um palíndromo
            break;
        }
    }
    // Impressão do resultado
    if (palindromo) {
        printf("%s (sem espaços) é um palíndromo!\n", fraseSemEspacos);
    } else {
        printf("%s (sem espaços) não é um palíndromo.\n", fraseSemEspacos);
    }

    return 0;
}
