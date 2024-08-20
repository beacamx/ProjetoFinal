# ProjetoFinal
 
### Professor: 
* **Luiz Chaimowicz**



## Desenvolvedores:
*  **Beatriz Camilly**
*  **Deborah Mirella**
*  **Gabriela Soares**
*  **Lauren Cota**
*  **Bernardo Coelho**

---

## Visão Geral
Este projeto, desenvolvido para a disciplina **PDS II - Projeto Final - 2024-1**, tem como objetivo criar um sistema de jogos de tabuleiro utilizando os princípios de programação orientada a objetos em C++. O sistema implementa dois jogos clássicos: **Reversi** e **Connect Four (Lig4)**.

### Objetivos do Projeto
- **Modelagem Orientada a Objetos:** Criar uma hierarquia de classes que represente os elementos e a lógica dos jogos.
- **Modularidade e Reusabilidade:** Estruturar o código de forma modular para facilitar a manutenção e reutilização.
- **Gerenciamento de Jogadores:** Implementar um módulo para cadastro e gerenciamento de jogadores.
- **Execução de Jogos:** Desenvolver a lógica para a execução dos jogos, permitindo uma experiência de jogo completa.
- **Testes Automatizados:** Assegurar a qualidade do código através de testes unitários e de integração.

### Descrição dos Jogos

#### Reversi
Reversi é um jogo de tabuleiro para dois jogadores, também conhecido como Othello. O jogo é jogado em um tabuleiro 8x8 com discos que são pretos de um lado e brancos do outro. O objetivo é ter a maioria dos discos com a sua cor virada para cima no final do jogo. Jogadores alternam turnos colocando um disco da sua cor em uma posição que enclausura um ou mais discos do oponente entre dois dos seus discos. Os discos do oponente então são virados para a cor do jogador atual.

#### Connect Four (Lig4)
Connect Four é um jogo de tabuleiro para dois jogadores onde o objetivo é ser o primeiro a formar uma linha horizontal, vertical ou diagonal de quatro peças consecutivas. O jogo é jogado em um tabuleiro vertical com 7 colunas e 6 linhas, onde os jogadores alternam turnos soltando peças em uma das colunas. A peça então cai até o espaço mais baixo disponível na coluna.

### Ferramentas e Tecnologias Utilizadas
- **Linguagem de Programação:** C++
- **Compilador:** g++ (GCC)
- **Interface Gráfica:** Biblioteca SFML para renderização e manipulação gráfica dos jogos.
- **Testes:** Biblioteca doctest para testes unitários e de integração.
- **Controle de Versão:** Git e GitHub para colaboração e versionamento.

---

## Compilação e Execução
Este projeto foi desenvolvido e testado em um ambiente Linux, utilizando um compilador g++ e a biblioteca SFML para a interface gráfica. Para compilar e executar o sistema, siga as instruções abaixo:

### Compilação
No diretório raiz do projeto, execute:
```
make
```
e depois:

```
make run
```

## Tutorial Jogo

### Connect Four (Lig4)

#### Como jogar

O jogo Lig4 oferece três opções de tamanho de tabuleiro, permitindo uma experiência de jogo personalizada:

   - **6 x 7**
   - **7 x 8**
   - **8 x 9**

Durante o início do jogo, o jogador pode selecionar o tamanho do tabuleiro desejado antes de começar a partida.

#### 1. Jogadas

- **O jogo é jogado com o mouse.**
- **Ao iniciar a partida, você verá um tabuleiro na tela.**
- **Para fazer uma jogada, clique com o botão esquerdo do mouse na coluna onde deseja        colocar sua peça.**
- **A peça cairá na posição mais baixa disponível naquela coluna.**

#### 2. Alternância de Turnos:

- **Após cada jogada, o turno passa automaticamente para o próximo jogador.**
- **Continue jogando até que um jogador consiga alinhar quatro peças ou o tabuleiro fique completamente cheio.**

### Reversi

O jogo Reversi oferece três opções de tamanho de tabuleiro, permitindo uma experiência de jogo personalizada:

   - **6 x 6**
   - **8 x 8**
   - **10 x 10**

Ao iniciar o jogo, você será solicitado a escolher o tamanho do tabuleiro desejado. Selecione o tamanho que melhor se adapta às suas preferências e desfrute de uma partida de Reversi personalizada.

#### Como jogar

#### 1. Jogadas:

- **O jogo é jogado com o mouse.**
- **Para fazer uma jogada, clique com o botão esquerdo do mouse na casa onde deseja          posicionar sua peça.**
- **Suas peças devem capturar as peças do adversário, virando-as para a sua cor.**

#### 2. Alternância de Turnos:

- **Após cada jogada, o turno passa automaticamente para o próximo jogador.**
- **Continue jogando até que não haja mais movimentos possíveis.**