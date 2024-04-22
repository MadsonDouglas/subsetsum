#include <stdio.h>

int main()
{
    int vetor[] = {1, 4, 2, 7, 5, 3}, k = 21; // k = soma x = vetor
    int n = sizeof(vetor) / sizeof(vetor[0]); // n = elementos do vetor
    
    int matriz[n + 1][k + 1];
    
    
    for (int i = 0; i < n; i++){
        matriz[i][0] = 1;
    }
    
    for (int i = 1; i < k; i++){
        matriz[0][i] = 0;
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if (vetor[i - 1] > j) {
                matriz[i][j] = matriz[i - 1][j];
            } else {
                matriz[i][j] = matriz[i - 1][j] || matriz[i - 1][j - vetor[i - 1]];
            }
        }
    }
    
    if (matriz[n][k] == 1){
        printf("Existe a soma = %d", k);
    } else {
        printf("Não existe a soma = %d", k);
    }
    

    return 0;
}
