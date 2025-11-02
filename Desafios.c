#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N_TERRITORIOS 5
#define MAX_NOME 51
#define MAX_COR 31
#define LINE_BUF 128
#define TARGET_CONQUER_COUNT 3

typedef struct
{
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

typedef enum
{
    M_NONE = 0,
    M_DESTROY_COLOR,
    M_CONQUER_N_TERRITORIES
} MissionType;

typedef struct
{
    MissionType type;
    char target_color[MAX_COR];
    int target_count;
    int progress; // progreconquistas)
    int completed;
} Mission;

static void remove_newline(char *s)
{
    size_t len = strlen(s);
    if (len == 0)
        return;
    if (s[len - 1] == '\n')
        s[len - 1] = '\0';
}

static int read_int_prompt(const char *prompt, int min, int max)
{
    char buf[LINE_BUF];
    int val;
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buf, sizeof(buf), stdin) == NULL)
            continue;
        if (sscanf(buf, "%d", &val) != 1)
        {
            printf("  Entrada inválida. Digite um número inteiro.\n");
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

/* ---------------- mapa / inicialização ---------------- */
static void imprimir_mapa(const Territorio *terr, int n)
{
    printf("\n========== MAPA DO MUNDO ==========\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%2d. %-16s (Exército: %-10s , Tropas: %2d)\n",
               i + 1,
               terr[i].nome[0] ? terr[i].nome : "(vazio)",
               terr[i].cor[0] ? terr[i].cor : "(vazio)",
               terr[i].tropas);
    }
    printf("===================================\n");
}

static void init_territories_auto(Territorio *terr, int n)
{
    (void)n;
    (terr[0].nome, "Índia", MAX_NOME - 1);
    terr[0].nome[MAX_NOME - 1] = '\0';
    strncpy(terr[0].cor, "Laranja", MAX_COR - 1);
    terr[0].cor[MAX_COR - 1] = '\0';
    terr[0].tropas = 3;

    strncpy(terr[1].nome, "Estados Unidos", MAX_NOME - 1);
    terr[1].nome[MAX_NOME - 1] = '\0';
    strncpy(terr[1].cor, "Vermelho", MAX_COR - 1);
    terr[1].cor[MAX_COR - 1] = '\0';
    terr[1].tropas = 2;

    strncpy(terr[2].nome, "Espanha", MAX_NOME - 1);
    terr[2].nome[MAX_NOME - 1] = '\0';
    strncpy(terr[2].cor, "Amarelo", MAX_COR - 1);
    terr[2].cor[MAX_COR - 1] = '\0';
    terr[2].tropas = 4;

    strncpy(terr[3].nome, "Brasil", MAX_NOME - 1);
    terr[3].nome[MAX_NOME - 1] = '\0';
    strncpy(terr[3].cor, "Verde", MAX_COR - 1);
    terr[3].cor[MAX_COR - 1] = '\0';
    terr[3].tropas = 2;

    strncpy(terr[4].nome, "Argentina", MAX_NOME - 1);
    terr[4].nome[MAX_NOME - 1] = '\0';
    strncpy(terr[4].cor, "Azul", MAX_COR - 1);
    terr[4].cor[MAX_COR - 1] = '\0';
    terr[4].tropas = 2;
}

/* ---------------- Missões ---------------- */
static void assign_random_mission(Mission *m, const Territorio *terr, int n)
{
    m->completed = 0;
    m->progress = 0;
    if (rand() % 2 == 0)
    {
        m->type = M_DESTROY_COLOR;
        int idx = rand() % n;
        strncpy(m->target_color, terr[idx].cor, MAX_COR - 1);
        m->target_color[MAX_COR - 1] = '\0';
        m->target_count = 0;
    }
    else
    {
        m->type = M_CONQUER_N_TERRITORIES;
        m->target_count = TARGET_CONQUER_COUNT;
        m->target_color[0] = '\0';
    }
}

static void print_mission(const Mission *m)
{
    if (m->type == M_DESTROY_COLOR)
    {
        printf("Missão: Destruir todas as tropas do exército de cor '%s'\n", m->target_color);
        printf("Progresso: %s\n", m->completed ? "Concluída" : "Em andamento");
    }
    else if (m->type == M_CONQUER_N_TERRITORIES)
    {
        printf("Missão: Conquistar %d territórios\n", m->target_count);
        printf("Progresso: %d / %d\n", m->progress, m->target_count);
        printf("Status: %s\n", m->completed ? "Concluída" : "Em andamento");
    }
    else
    {
        printf("Nenhuma missão ativa.\n");
    }
}

static int check_destroy_color_completed(const Mission *m, const Territorio *terr, int n)
{
    if (m->type != M_DESTROY_COLOR)
        return 0;
    for (int i = 0; i < n; ++i)
    {
        if (terr[i].tropas > 0 && strcmp(terr[i].cor, m->target_color) == 0)
            return 0;
    }
    return 1;
}

static int check_conquer_count_completed(const Mission *m)
{
    if (m->type != M_CONQUER_N_TERRITORIES)
        return 0;
    return (m->progress >= m->target_count);
}

/* ---------------- combate ----------------*/
static int simulate_attack(Territorio *atk, Territorio *def)
{
    if (atk->tropas < 1)
    {
        printf("Atacante não tem tropas suficientes para atacar.\n");
        return 0;
    }
    if (atk == def)
    {
        printf("Não é possível atacar o próprio território.\n");
        return 0;
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
            return 1;
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
    return 0;
}

/* ---------------- menu / fluxo principal ---------------- */
static void print_menu(void)
{
    printf("\n--- Menu ---\n");
    printf("1 - Atacar\n");
    printf("2 - Verificar Missão\n");
    printf("0 - Sair\n");
}

int main(void)
{
    srand((unsigned)time(NULL));

    int n = N_TERRITORIOS;
    Territorio *territorios = calloc(n, sizeof(Territorio));
    if (!territorios)
    {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        return 1;
    }

    init_territories_auto(territorios, n);

    /* Missão: destruir o exército Azul*/
    Mission mission;
    mission.type = M_DESTROY_COLOR;
    strncpy(mission.target_color, "Azul", MAX_COR - 1);
    mission.target_color[MAX_COR - 1] = '\0';
    mission.target_count = 0;
    mission.progress = 0;
    mission.completed = check_destroy_color_completed(&mission, territorios, n);

    printf("Missão atribuída (sobrescrevendo para Azul)!\n");
    print_mission(&mission);

    int running = 1;
    while (running)
    {
        imprimir_mapa((const Territorio *)territorios, n);
        print_menu();
        int choice = read_int_prompt("Escolha uma opção: ", 0, 2);
        if (choice == 0)
        {
            printf("Saindo do jogo...\n");
            break;
        }
        else if (choice == 2)
        {
            print_mission(&mission);

            printf("Pressione Enter para voltar ao menu...");
            char _tmp[LINE_BUF];
            if (fgets(_tmp, sizeof(_tmp), stdin) == NULL)
            {
            }
            continue;
        }
        else if (choice == 1)
        {

            int atk = read_int_prompt("Escolha o território atacante (1-5): ", 1, n) - 1;
            if (territorios[atk].tropas < 1)
            {
                printf("Território atacante não tem tropas. Operação cancelada.\n");
                continue;
            }
            int def = read_int_prompt("Escolha o território defensor (1-5, diferente do atacante): ", 1, n) - 1;
            if (def == atk)
            {
                printf("Atacante e defensor devem ser diferentes.\n");
                continue;
            }

            int conquest = simulate_attack(&territorios[atk], &territorios[def]);
            if (conquest && mission.type == M_CONQUER_N_TERRITORIES && !mission.completed)
            {
                mission.progress += 1;
                if (check_conquer_count_completed(&mission))
                    mission.completed = 1;
            }
            if (mission.type == M_DESTROY_COLOR && !mission.completed)
            {
                if (check_destroy_color_completed(&mission, territorios, n))
                    mission.completed = 1;
            }
            if (mission.completed)
            {
                printf("\n=== MISSÃO CUMPRIDA! ===\n");
                print_mission(&mission);
                printf("Parabéns! Você completou a missão.\n");
                printf("Atribuindo nova missão...\n");
                assign_random_mission(&mission, territorios, n);
                print_mission(&mission);
            }
        }
    }

    free(territorios);
    territorios = NULL;
    return 0;
}