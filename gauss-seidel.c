#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define PULA_LINHAS printf("\n\n");
#define n 3
#define erro 0.01

double max(double v[]) {
    double maiorNumero = 0;

    for(int i = 0; i < n; i++){
        if(fabs(v[i]) > maiorNumero) {
            maiorNumero = fabs(v[i]);
        }
    }

    return maiorNumero;
}

int main(){
    PULA_LINHAS
    printf("Vai Corinthians!");
    PULA_LINHAS

    double matrizA[n][n];
    double vetorX1[n] = {0, 0, 0};
    double vetorX2[n] = {0, 0, 0};
    double vetorB[n];
    double vetorBeta[n];
    unsigned short int k = 1;

    printf("Digite a matriz A: ");
    PULA_LINHAS

    printf("Informe a matriz A \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("a%i%i: ", i+1, j+1);
            scanf("%lf", &matrizA[i][j]);
        }
    }

    PULA_LINHAS

    printf("Informe o vetor B: ");
    for(int i = 0; i < n; i++) {
        scanf("%lf", &vetorB[i]);
    }

    PULA_LINHAS

    printf("Matriz A\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%lf ", matrizA[i][j]);
        }
        printf("\n");
    }

    PULA_LINHAS

    printf("Vetor B: ");
    for(int i = 0; i < n; i++) {
        printf("%lf ", vetorB[i]);
    }

    PULA_LINHAS

    //Loop para verificar a condição de convergência
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < i; j++) {
            vetorBeta[i] += fabs(matrizA[i][j] / matrizA[i][i]) * vetorBeta[j];
        }

        for(int j = i+1; j < n; j++) {
            vetorBeta[i] += fabs(matrizA[i][j] / matrizA[i][i]);
        }        

        if(vetorBeta[i] >= 1) {
            printf("O sistema informado NÃO atende à condição de convergência (Critério de Sassenfeld). Beta: %lf", vetorBeta[i]);

            return 0;
        }
    }

    printf("O sistema informado atende à condição de convergência (Critério de Sassenfeld).");
    
    PULA_LINHAS

    printf("Vetor Beta: ");
    for(int i = 0; i < n; i++) {
        printf("%lf ", vetorBeta[i]);
    }

    PULA_LINHAS

    while(true) {
        for(int i = 0; i < n; i++) {
            double somatorio1 = 0, somatorio2 = 0;

            for(int j = 0; j < i; j++) {
                somatorio1 += matrizA[i][j] * vetorX2[j];
            }

            for(int j = i+1; j < n; j++) {
                somatorio2 += matrizA[i][j] * vetorX1[j];
            }

            vetorX2[i] = (vetorB[i] - (somatorio1 + somatorio2)) / matrizA[i][i];
        } 

        printf("Vetor X%i: ", k);
        for(int i = 0; i < n; i++) {
            printf("%lf ", vetorX2[i]);
        }

        PULA_LINHAS
        
        double vetorDiferenca[n];

        for(int i = 0; i < n; i++) {
            vetorDiferenca[i] = vetorX2[i] - vetorX1[i];
        }

        /*printf("Vetor Diferença: ");
        for(int i = 0; i < n; i++) {
            printf("%lf ", vetorDiferenca[i]);
        }*/

        PULA_LINHAS

        double comparaErro = max(vetorDiferenca) / max(vetorX2);

        printf("Erro relativo calculado na iteração %i: %lf", k, comparaErro);

        PULA_LINHAS

        if(comparaErro <= erro) {
            PULA_LINHAS

            printf("Solução aproximada encontrada!");

            PULA_LINHAS

            printf("Vetor X%i: ", k);
            for(int i = 0; i < n; i++) {
                printf("%lf ", vetorX2[i]);
            }

            PULA_LINHAS

            printf("Erro relativo calculado: %lf < %lf", comparaErro, erro);

            PULA_LINHAS

            printf("Quantidade de iterações K: %i", k);

            PULA_LINHAS

            return 0;
        } else {
            for(int i = 0; i < n; i++) {
                vetorX1[i] = vetorX2[i];
            }

            k++;
        }
    }

    return 0;
}
