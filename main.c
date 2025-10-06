#include <stdio.h>
#include <math.h> // Essencial para quase todas as funções científicas

// Constante para a conversão de radianos, caso M_PI não seja definido por padrão
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Protótipo da nossa função customizada de fatorial
long double factorial(int n);

int main() {
    int escolha;
    double num1, num2, resultado;

    // Menu principal com as 24 funções
    printf("===== Calculadora Cientifica em C =====\n");
    printf("--- Basicas ---\n");
    printf("1. Adicao (+)\t\t2. Subtracao (-)\n");
    printf("3. Multiplicacao (*)\t4. Divisao (/)\n");
    printf("--- Potencia e Raizes ---\n");
    printf("5. Potencia (x^y)\t6. Raiz Quadrada (sqrt)\n");
    printf("7. Raiz Cubica (cbrt)\n");
    printf("--- Trigonometricas (Entrada em Graus) ---\n");
    printf("8. Seno (sin)\t\t9. Cosseno (cos)\n");
    printf("10. Tangente (tan)\n");
    printf("--- Trigonometricas Inversas ---\n");
    printf("11. Arco Seno (asin)\t12. Arco Cosseno (acos)\n");
    printf("13. Arco Tangente (atan)\n");
    printf("--- Logaritmicas e Exponenciais ---\n");
    printf("14. Logaritmo Natural (ln)\t15. Logaritmo Base 10 (log10)\n");
    printf("16. Exponencial (e^x)\n");
    printf("--- Outras Funcoes ---\n");
    printf("17. Valor Absoluto (|x|)\t18. Fatorial (x!)\n");
    printf("19. Inverso (1/x)\t20. Percentagem (%%)\n");
    printf("--- Arredondamento ---\n");
    printf("21. Arredondar para Cima (ceil)\t22. Arredondar para Baixo (floor)\n");
    printf("--- Conversoes de Angulo ---\n");
    printf("23. Graus para Radianos\t24. Radianos para Graus\n");

    printf("\nDigite o numero da sua escolha: ");
    scanf("%d", &escolha);

    // O switch decide a ação baseada na escolha do usuário
    switch (escolha) {
        // --- Casos com DOIS números de entrada ---
        case 1: // Adição
        case 2: // Subtração
        case 3: // Multiplicação
        case 4: // Divisão
        case 5: // Potência
        case 20: // Percentagem
            printf("Digite o primeiro numero: ");
            scanf("%lf", &num1);
            printf("Digite o segundo numero: ");
            scanf("%lf", &num2);

            if (escolha == 1) printf("%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            if (escolha == 2) printf("%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            if (escolha == 3) printf("%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            if (escolha == 4) {
                if (num2 != 0) printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
                else printf("Erro: Divisao por zero!\n");
            }
            if (escolha == 5) printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, pow(num1, num2));
            if (escolha == 20) printf("%.2lf%% de %.2lf = %.2lf\n", num1, num2, (num1 / 100.0) * num2);
            break;

        // --- Casos com UM número de entrada ---
        default:
            printf("Digite o numero: ");
            scanf("%lf", &num1);
            
            switch(escolha) {
                case 6: // Raiz Quadrada
                    if (num1 >= 0) printf("A raiz quadrada de %.2lf e %.2lf\n", num1, sqrt(num1));
                    else printf("Erro: Nao existe raiz real de numero negativo.\n");
                    break;
                case 7: // Raiz Cúbica
                    printf("A raiz cubica de %.2lf e %.2lf\n", num1, cbrt(num1));
                    break;
                case 8: // Seno
                    resultado = sin(num1 * M_PI / 180.0); // Converte graus para radianos ANTES de calcular
                    printf("O seno de %.2lf graus e %.4lf\n", num1, resultado);
                    break;
                case 9: // Cosseno
                    resultado = cos(num1 * M_PI / 180.0); // Converte graus para radianos
                    printf("O cosseno de %.2lf graus e %.4lf\n", num1, resultado);
                    break;
                case 10: // Tangente
                    resultado = tan(num1 * M_PI / 180.0); // Converte graus para radianos
                    printf("A tangente de %.2lf graus e %.4lf\n", num1, resultado);
                    break;
                case 11: // Arco Seno
                    if (num1 >= -1.0 && num1 <= 1.0) {
                        resultado = asin(num1) * 180.0 / M_PI; // Converte o resultado para graus
                        printf("O arco seno de %.2lf e %.2lf graus\n", num1, resultado);
                    } else printf("Erro: A entrada para arco seno deve estar entre -1 e 1.\n");
                    break;
                case 12: // Arco Cosseno
                     if (num1 >= -1.0 && num1 <= 1.0) {
                        resultado = acos(num1) * 180.0 / M_PI; // Converte o resultado para graus
                        printf("O arco cosseno de %.2lf e %.2lf graus\n", num1, resultado);
                    } else printf("Erro: A entrada para arco cosseno deve estar entre -1 e 1.\n");
                    break;
                case 13: // Arco Tangente
                    resultado = atan(num1) * 180.0 / M_PI; // Converte o resultado para graus
                    printf("O arco tangente de %.2lf e %.2lf graus\n", num1, resultado);
                    break;
                case 14: // Logaritmo Natural
                    if (num1 > 0) printf("O logaritmo natural de %.2lf e %.4lf\n", num1, log(num1));
                    else printf("Erro: Logaritmo so e definido para numeros positivos.\n");
                    break;
                case 15: // Logaritmo Base 10
                    if (num1 > 0) printf("O logaritmo base 10 de %.2lf e %.4lf\n", num1, log10(num1));
                    else printf("Erro: Logaritmo so e definido para numeros positivos.\n");
                    break;
                case 16: // Exponencial
                    printf("e elevado a %.2lf e %Lf\n", num1, expl((long double)num1));
                    break;
                case 17: // Valor Absoluto
                    printf("O valor absoluto de %.2lf e %.2lf\n", num1, fabs(num1));
                    break;
                case 18: // Fatorial
                    if (num1 < 0 || floor(num1) != num1) {
                         printf("Erro: Fatorial so e definido para inteiros nao negativos.\n");
                    } else {
                        printf("O fatorial de %d e %Lf\n", (int)num1, factorial((int)num1));
                    }
                    break;
                case 19: // Inverso
                    if (num1 != 0) printf("O inverso de %.2lf e %.4lf\n", num1, 1.0 / num1);
                    else printf("Erro: Nao se pode dividir por zero.\n");
                    break;
                case 21: // Arredondar para Cima
                    printf("%.2lf arredondado para cima e %.2lf\n", num1, ceil(num1));
                    break;
                case 22: // Arredondar para Baixo
                    printf("%.2lf arredondado para baixo e %.2lf\n", num1, floor(num1));
                    break;
                case 23: // Graus para Radianos
                    printf("%.2lf graus equivale a %.4lf radianos\n", num1, num1 * M_PI / 180.0);
                    break;
                case 24: // Radianos para Graus
                    printf("%.4lf radianos equivale a %.2lf graus\n", num1, num1 * 180.0 / M_PI);
                    break;
                default:
                    printf("Erro! Opcao invalida.\n");
            }
    }

    return 0;
}

/**
 * @brief Calcula o fatorial de um número inteiro não negativo.
 * @param n O número para o qual calcular o fatorial.
 * @return O valor do fatorial como um long double. Retorna 0 para entradas negativas.
 */
long double factorial(int n) {
    if (n < 0) return 0; // Fatorial não definido para negativos
    if (n == 0) return 1; // 0! = 1
    long double fact = 1.0;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
} 