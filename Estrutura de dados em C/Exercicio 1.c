// Algoritmo que transforma decimal para hexadecimal. Se o resto for 10, 11, 12, 13, 14 ou 15, imprime, respectivamente, A, B, C, D, E ou F
#include <stdio.h>

int main() {
    int decimal;
    char hexadecimal[20];
    int i = 0;

    // Ler número decimal do usuário
    printf("Digite um número decimal: ");
    scanf("%d", &decimal);

    int temp = decimal; // variável temporária para manipular o número decimal

    // Verifica se o número é zero
    if (temp == 0) {
        hexadecimal[i++] = '0';
    }

    // Converter decimal para hexadecimal
    while (temp != 0) {
        int resto = temp % 16;

        // Converter resto para o caractere hexadecimal apropriado
        if (resto < 10) {
            hexadecimal[i] = resto + '0';  // Converte número para caractere '0'-'9'
        } else {
            // Converter resto para o caractere hexadecimal apropriado usando switch-case
            switch (resto) {
                case 10: hexadecimal[i] = 'A'; break;
                case 11: hexadecimal[i] = 'B'; break;
                case 12: hexadecimal[i] = 'C'; break;
                case 13: hexadecimal[i] = 'D'; break;
                case 14: hexadecimal[i] = 'E'; break;
                case 15: hexadecimal[i] = 'F'; break;
            }
        }

        temp = temp / 16;
        i++;
    }
    
    // Exibir o array hexadecimal de trás para frente
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");

    return 0;
}
