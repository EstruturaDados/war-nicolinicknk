#include <stdio.h>
#include <string.h>

#define N_TERRITORIOS 5
#define MAX_NOME 51
#define MAX_COR 31

typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

static void remove_newline(char *s) {
    size_t len = strlen(s);
    if (len == 0) return;
    if (s[len - 1] == '\n') s[len - 1] = '\0';
}

int main(void) {
    Territorio territorios[N_TERRITORIOS];

    printf("== Cadastro Inicial dos Territórios ==\n\n");

    for (int i = 0; i < N_TERRITORIOS; ++i) {
        printf("Território %d:\n", i + 1);

        // Nome
        printf("  Nome: ");
        if (fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin) == NULL) {
            territorios[i].nome[0] = '\0';
        }
        remove_newline(territorios[i].nome);

        // Cor do exército
        printf("  Cor do exército: ");
        if (fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin) == NULL) {
            territorios[i].cor[0] = '\0';
        }
        remove_newline(territorios[i].cor);

        // Número de tropas
        printf("  Número de tropas: ");
        while (scanf("%d", &territorios[i].tropas) != 1) {
            // entrada inválida — limpar buffer e pedir novamente
            printf("    Entrada inválida. Digite um número inteiro: ");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { /* limpar */ }
        }

        // limpar o '\n' restante após scanf para que o próximo fgets funcione corretamente
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { /* limpar */ }

        printf("\n");
    }

    // Exibir estado atual do mapa
    printf("== Estado atual do mapa ==\n");
    printf("-------------------------------\n");
    for (int i = 0; i < N_TERRITORIOS; ++i) {
        printf("Território %d\n", i + 1);
        printf("  Nome   : %s\n", territorios[i].nome[0] ? territorios[i].nome : "(vazio)");
        printf("  Cor    : %s\n", territorios[i].cor[0] ? territorios[i].cor : "(vazio)");
        printf("  Tropas : %d\n", territorios[i].tropas);
        printf("-------------------------------\n");
    }

    return 0;
}