#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprime_histograma(int *vendas[], int num_cat) {
    int i, j;
    for (i = 0; i < num_cat; i++) {
        int vendas_cat = *(vendas[i]);
        printf("%d ", vendas_cat);
        
        for (j = 0; j < vendas_cat; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int i, num_cat;

    scanf("%d", &num_cat);

    int **vendas = (int **)malloc(num_cat * sizeof(int *));
    if (vendas == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }

    for (i = 0; i < num_cat; i++) {
        vendas[i] = (int *)malloc(sizeof(int));
        if (vendas[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória\n");
            return 1;
        }

        scanf("%d", vendas[i]);
    }

    
    imprime_histograma(vendas, num_cat);

    
    for (i = 0; i < num_cat; i++) {
        free(vendas[i]);
    }
    free(vendas);

    return 0;
}
