/* Para facilitar a leitura dos resultados no terminal, este programa imprime uma mensagem simples.
Como testar no terminal, digite os comandos abaixo:

gcc -std=c11 -Wall -Wextra -o desafios Desafios.c
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

*/