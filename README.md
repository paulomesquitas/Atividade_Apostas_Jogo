# Sistema de Bolão

Este é um programa desenvolvido em **C++** como parte de uma atividade do curso de **Desenvolvimento Fullstack**. O objetivo do sistema é gerenciar um bolão de apostas esportivas para 3 participantes, utilizando lógicas fundamentais de programação (como estruturas de repetição e decisão simples) sem o uso de arrays.

## Desenvolvedores
Atividade realizada por:
- **Paulo Mesquita**
- **Felipe Spinola**
- **Lucas Santos**

## Como funciona
1. O programa solicita o nome dos 3 participantes e a quantidade de jogos que farão parte do bolão.
2. Para cada jogo, o sistema pede:
   - O placar real da partida.
   - O palpite (aposta) de cada um dos 3 participantes.
3. A cada rodada, os pontos são calculados automaticamente seguindo a regra:
   - **10 pontos:** Acertou o placar exato (vencedor e número de gols).
   - **5 pontos:** Acertou apenas o time vencedor.
   - **2 pontos:** Acertou que o jogo seria um empate, mas errou o número de gols.
   - **0 pontos:** Não acertou o vencedor nem o placar.
4. Ao final de todos os jogos, o programa exibe um **Ranking Final**, ordenando os participantes do 1º ao 3º lugar.

## Como executar
Para compilar e executar o código em seu terminal, utilize o compilador `g++`:

```bash
g++ appAposta.cpp -o appAposta
./appAposta
```
