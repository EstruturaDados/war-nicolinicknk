/* Para facilitar a leitura dos resultados no terminal, este programa imprime uma mensagem simples.
Como testar no terminal, digite os comandos abaixo:

./desafios

Exemplo que foi testados e funcionou:
== Cadastro Inicial dos Territórios ==

Território 1:
  Nome: Índia
  Cor do exército: Laranja
  Número de tropas (inteiro >= 1): 3

Território 2:
  Nome: Estados Unidos
  Cor do exército: Vermelho
  Número de tropas (inteiro >= 1): 2

Território 3:
  Nome: Espanha
  Cor do exército: Amarelo
  Número de tropas (inteiro >= 1): 4

Território 4:
  Nome: Brasil
  Cor do exército: Verde
  Número de tropas (inteiro >= 1): 2

Território 5:
  Nome: Argentina
  Cor do exército: Azul
  Número de tropas (inteiro >= 1): 3

== Estado atual do mapa ==
-------------------------------
Território 1
  Nome   : Índia
  Cor    : Laranja
  Tropas : 3
-------------------------------
Território 2
  Nome   : Estados Unidos
  Cor    : Vermelho
  Tropas : 2
-------------------------------
Território 3
  Nome   : Espanha
  Cor    : Amarelo
  Tropas : 4
-------------------------------
Território 4
  Nome   : Brasil
  Cor    : Verde
  Tropas : 2
-------------------------------
Território 5
  Nome   : Argentina
  Cor    : Azul
  Tropas : 3
-------------------------------
Escolha o território atacante (1-5, 0 para sair): 1
Escolha o território defensor (1-5, diferente de 1): 5
Dados: Atacante(Índia) -> 4 | Defensor(Argentina) -> 3
Resultado: Atacante vence a rodada! Argentina perde 1 tropa.

== Estado atual do mapa ==
-------------------------------
Território 1
  Nome   : Índia
  Cor    : Laranja
  Tropas : 3
-------------------------------
Território 2
  Nome   : Estados Unidos
  Cor    : Vermelho
  Tropas : 2
-------------------------------
Território 3
  Nome   : Espanha
  Cor    : Amarelo
  Tropas : 4
-------------------------------
Território 4
  Nome   : Brasil
  Cor    : Verde
  Tropas : 2
-------------------------------
Território 5
  Nome   : Argentina
  Cor    : Azul
  Tropas : 2
-------------------------------
Escolha o território atacante (1-5, 0 para sair): 3
Escolha o território defensor (1-5, diferente de 3): 4
Dados: Atacante(Espanha) -> 2 | Defensor(Brasil) -> 5
Resultado: Defensor vence! Espanha perde 1 tropa.

== Estado atual do mapa ==
-------------------------------
Território 1
  Nome   : Índia
  Cor    : Laranja
  Tropas : 3
-------------------------------
Território 2
  Nome   : Estados Unidos
  Cor    : Vermelho
  Tropas : 2
-------------------------------
Território 3
  Nome   : Espanha
  Cor    : Amarelo
  Tropas : 3
-------------------------------
Território 4
  Nome   : Brasil
  Cor    : Verde
  Tropas : 2
-------------------------------
Território 5
  Nome   : Argentina
  Cor    : Azul
  Tropas : 2
-------------------------------
Escolha o território atacante (1-5, 0 para sair): 0
Saindo...



DESAFIO MESTRE CONCLUÍDO:




========== MAPA DO MUNDO ==========
 1. Índia           (Exército: Laranja    , Tropas:  3)
 2. Estados Unidos   (Exército: Vermelho   , Tropas:  2)
 3. Espanha          (Exército: Amarelo    , Tropas:  4)
 4. Brasil (Exército: Verde      , Tropas:  2)
 5. Argentina        (Exército: Azul       , Tropas:  2)
===================================

--- Menu ---
1 - Atacar
2 - Verificar Missão
0 - Sair
Escolha uma opção: 2
Missão: Destruir todas as tropas do exército de cor 'Azul'
Progresso: Em andamento
Pressione Enter para voltar ao menu...

========== MAPA DO MUNDO ==========
 1. Índia           (Exército: Laranja    , Tropas:  3)
 2. Estados Unidos   (Exército: Vermelho   , Tropas:  2)
 3. Espanha          (Exército: Amarelo    , Tropas:  4)
 4. Brasil           (Exército: Verde      , Tropas:  2)
 5. Argentina        (Exército: Azul       , Tropas:  2)
===================================

--- Menu ---
1 - Atacar
2 - Verificar Missão
0 - Sair
Escolha uma opção: 1
Escolha o território atacante (1-5): 3
Escolha o território defensor (1-5, diferente do atacante): 5
Dados: Atacante(Espanha) -> 3 | Defensor(Argentina) -> 5
Resultado: Defensor vence! Espanha perde 1 tropa.

========== MAPA DO MUNDO ==========
 1. Índia           (Exército: Laranja    , Tropas:  3)
 2. Estados Unidos   (Exército: Vermelho   , Tropas:  2)
 3. Espanha          (Exército: Amarelo    , Tropas:  3)
 4. Brasil           (Exército: Verde      , Tropas:  2)
 5. Argentina        (Exército: Azul       , Tropas:  2)
===================================

--- Menu ---
1 - Atacar
2 - Verificar Missão
0 - Sair
Escolha uma opção: 1
Escolha o território atacante (1-5): 1
Escolha o território defensor (1-5, diferente do atacante): 5
Dados: Atacante(Índia) -> 6 | Defensor(Argentina) -> 5
Resultado: Atacante vence a rodada! Argentina perde 1 tropa.

========== MAPA DO MUNDO ==========
 1. Índia           (Exército: Laranja    , Tropas:  3)
 2. Estados Unidos   (Exército: Vermelho   , Tropas:  2)
 3. Espanha          (Exército: Amarelo    , Tropas:  3)
 4. Brasil           (Exército: Verde      , Tropas:  2)
 5. Argentina        (Exército: Azul       , Tropas:  1)
===================================

--- Menu ---
1 - Atacar
2 - Verificar Missão
0 - Sair
Escolha uma opção: 1
Escolha o território atacante (1-5): 5
Escolha o território defensor (1-5, diferente do atacante): 1
Dados: Atacante(Argentina) -> 4 | Defensor(Índia) -> 1
Resultado: Atacante vence a rodada! Índia perde 1 tropa.

========== MAPA DO MUNDO ==========
 1. Índia           (Exército: Laranja    , Tropas:  2)
 2. Estados Unidos   (Exército: Vermelho   , Tropas:  2)
 3. Espanha          (Exército: Amarelo    , Tropas:  3)
 4. Brasil           (Exército: Verde      , Tropas:  2)
 5. Argentina        (Exército: Azul       , Tropas:  1)
===================================

--- Menu ---
1 - Atacar
2 - Verificar Missão
0 - Sair
Escolha uma opção: 1
Escolha o território atacante (1-5): 4
Escolha o território defensor (1-5, diferente do atacante): 5
Dados: Atacante(Brasil) -> 5 | Defensor(Argentina) -> 3
Resultado: Atacante vence a rodada! Argentina perde 1 tropa.
  Argentina foi conquistado por Brasil!

=== MISSÃO CUMPRIDA! ===
Missão: Destruir todas as tropas do exército de cor 'Azul'
Progresso: Concluída
Parabéns! Você completou a missão.
Atribuindo nova missão...
Missão: Destruir todas as tropas do exército de cor 'Verde'
Progresso: Em andamento

========== MAPA DO MUNDO ==========
 1. Índia           (Exército: Laranja    , Tropas:  2)
 2. Estados Unidos   (Exército: Vermelho   , Tropas:  2)
 3. Espanha          (Exército: Amarelo    , Tropas:  3)
 4. Brasil           (Exército: Verde      , Tropas:  1)
 5. Argentina        (Exército: Verde      , Tropas:  1)
===================================

--- Menu ---
1 - Atacar
2 - Verificar Missão
0 - Sair
Escolha uma opção: 0
Saindo do jogo...

*/