#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N_TERRITORIOS 5
#define MAX_NOME 51
#define MAX_COR 31
#define LINE_BUF 128

typedef struct
{
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

static void remove_newline(char *s)
{
    size_t len = strlen(s);
    if (len == 0)
        return;
    if (s[len - 1] == '\n')
        s[len - 1] = '\0';
}

static void read_line(const char *prompt, char *out, size_t size)
{
    char buf[LINE_BUF];
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buf, sizeof(buf), stdin) == NULL)
        {
            out[0] = '\0';
            return;
        }
        remove_newline(buf);
        if (strlen(buf) == 0)
        {
            printf("  Entrada vazia, por favor digite algo.\n");
            continue;
        }
        strncpy(out, buf, size - 1);
        out[size - 1] = '\0';
        return;
    }
}

static int read_int(const char *prompt, int min, int max)
{
    char buf[LINE_BUF];
    int val;
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buf, sizeof(buf), stdin) == NULL)
        {
            continue;
        }
        if (sscanf(buf, "%d", &val) != 1)
        {
            printf("  Entrada inválida: digite um número inteiro.\n");
            continue;
        }
        if (val < min || val > max)
        {
            printf("  Valor fora do intervalo [%d..%d]. Tente novamente.\n", min, max);
            continue;
        }
        return val;
    }
}

static void cadastro_territorios(Territorio *terr, int n)
{
    printf("== Cadastro Inicial dos Territórios ==\n\n");
    for (int i = 0; i < n; ++i)
    {
        printf("Território %d:\n", i + 1);
        read_line("  Nome: ", terr[i].nome, sizeof(terr[i].nome));
        read_line("  Cor do exército: ", terr[i].cor, sizeof(terr[i].cor));
        while (1)
        {
            char buf[LINE_BUF];
            printf("  Número de tropas (inteiro >= 1): ");
            if (fgets(buf, sizeof(buf), stdin) == NULL)
                continue;
            if (sscanf(buf, "%d", &terr[i].tropas) != 1)
            {
                printf("    Entrada inválida. Digite um número inteiro.\n");
                continue;
            }
            if (terr[i].tropas < 1)
            {
                printf("    Deve ser >= 1.\n");
                continue;
            }
            break;
        }
        printf("\n");
    }
}

static void imprimir_mapa(const Territorio *terr, int n)
{
    printf("== Estado atual do mapa ==\n");
    printf("-------------------------------\n");
    for (int i = 0; i < n; ++i)
    {
        printf("Território %d\n", i + 1);
        printf("  Nome   : %s\n", terr[i].nome[0] ? terr[i].nome : "(vazio)");
        printf("  Cor    : %s\n", terr[i].cor[0] ? terr[i].cor : "(vazio)");
        printf("  Tropas : %d\n", terr[i].tropas);
        printf("-------------------------------\n");
    }
}

/*
  Simula um ataque entre dois territórios
*/
static void simulate_attack(Territorio *atk, Territorio *def)
{
    if (atk->tropas < 1)
    {
        printf("Atacante não tem tropas suficientes para atacar.\n");
        return;
    }
    if (atk == def)
    {
        printf("Não é possível atacar o próprio território.\n");
        return;
    }

    int atk_roll = rand() % 6 + 1;
    int def_roll = rand() % 6 + 1;

    printf("Dados: Atacante(%s) -> %d | Defensor(%s) -> %d\n", atk->nome, atk_roll, def->nome, def_roll);

    if (atk_roll >= def_roll)
    {
        def->tropas -= 1;
        printf("Resultado: Atacante vence a rodada! %s perde 1 tropa.\n", def->nome);
        if (def->tropas <= 0)
        {
            printf("  %s foi conquistado por %s!\n", def->nome, atk->nome);
            strncpy(def->cor, atk->cor, MAX_COR - 1);
            def->cor[MAX_COR - 1] = '\0';
            def->tropas = 1;
            if (atk->tropas > 1)
                atk->tropas -= 1;
        }
    }
    else
    {
        atk->tropas -= 1;
        printf("Resultado: Defensor vence! %s perde 1 tropa.\n", atk->nome);
        if (atk->tropas <= 0)
        {
            printf("  %s ficou sem tropas.\n", atk->nome);
            if (atk->tropas < 0)
                atk->tropas = 0;
        }
    }
    printf("\n");
}

int main(void)
{
    srand((unsigned)time(NULL));

    int n = N_TERRITORIOS;
    Territorio *territorios = calloc(n, sizeof(Territorio));
    if (territorios == NULL)
    {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        return 1;
    }
    cadastro_territorios(territorios, n);
    while (1)
    {
        imprimir_mapa(territorios, n);

        int atacante = -1, defensor = -1;
        while (1)
        {
            char prompt[LINE_BUF];
            snprintf(prompt, sizeof(prompt), "Escolha o território atacante (1-%d, 0 para sair): ", n);
            atacante = read_int(prompt, 0, n);
            if (atacante == 0)
                break;
            if (atacante < 1 || atacante > n)
            {
                printf("  Índice inválido. Tente novamente.\n");
                continue;
            }
            if (territorios[atacante - 1].tropas < 1)
            {
                printf("  Território selecionado não tem tropas suficientes.\n");
                continue;
            }
            break;
        }
        if (atacante == 0)
        {
            printf("Saindo...\n");
            break;
        }
        while (1)
        {
            char prompt[LINE_BUF];
            snprintf(prompt, sizeof(prompt), "Escolha o território defensor (1-%d, diferente de %d): ", n, atacante);
            defensor = read_int(prompt, 1, n);
            if (defensor < 1 || defensor > n)
            {
                printf("  Índice inválido. Tente novamente.\n");
                continue;
            }
            if (defensor == atacante)
            {
                printf("  Atacante e defensor devem ser diferentes.\n");
                continue;
            }
            break;
        }
        simulate_attack(&territorios[atacante - 1], &territorios[defensor - 1]);
    }
    free(territorios);

    return 0;
}