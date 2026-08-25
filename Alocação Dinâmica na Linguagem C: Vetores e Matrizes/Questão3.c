#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtd;
    int max_colunas = 50; 
    char **nomes;         
    float *precos;        

    printf("Quantas frutas voce quer cadastrar? ");
    scanf("%d", &qtd);

    nomes = (char **) malloc(qtd * sizeof(char *));
    precos = (float *) malloc(qtd * sizeof(float));

    
    for (int i = 0; i < qtd; i++) {
        
        nomes[i] = (char *) malloc(max_colunas * sizeof(char));

        printf("\nNome da fruta %d: ", i + 1);
        scanf(" %[^\n]", nomes[i]); 

        printf("Preco da fruta %d: R$ ", i + 1);
        scanf("%f", &precos[i]);

        int tamanho = 0;
        while (nomes[i][tamanho] != '\0') {
            tamanho++;
        }

        nomes[i] = (char *) realloc(nomes[i], (tamanho + 1) * sizeof(char));
    }

    
    printf("\n--- FRUTAS CADASTRADAS ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%s - R$ %.2f\n", nomes[i], precos[i]);
    }


    for (int i = 0; i < qtd; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(precos);

    return 0;
}
