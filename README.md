# ProjetoFinal
 
### Professor: 
* **Luiz Chaimowicz**

---

## Desenvolvedores:
*  **Beatriz Camilly**
*  **deborah Mirella**
*  **Gabriela Soares**
*  **Lauren Cota**
*  **Bernardo Coelho**


## Visão Geral
Este projeto, desenvolvido para a disciplina **PDS II - Projeto Final - 2024-1**, tem como objetivo criar um sistema de jogos de tabuleiro utilizando os princípios de programação orientada a objetos em C++. O sistema implementa dois jogos clássicos: **Reversi** e **Connect Four (Lig4)**.

### Objetivos do Projeto
- **Modelagem Orientada a Objetos:** Criar uma hierarquia de classes que represente os elementos e a lógica dos jogos.
- **Modularidade e Reusabilidade:** Estruturar o código de forma modular para facilitar a manutenção e reutilização.
- **Gerenciamento de Jogadores:** Implementar um módulo para cadastro e gerenciamento de jogadores.
- **Execução de Jogos:** Desenvolver a lógica para a execução dos jogos, permitindo uma experiência de jogo completa.
- **Testes Automatizados:** Assegurar a qualidade do código através de testes unitários e de integração.

### Descrição dos Jogos

# colocar print tela inicial

#### Reversi
Reversi é um jogo de tabuleiro para dois jogadores, também conhecido como Othello. O jogo é jogado em um tabuleiro 8x8 com discos que são pretos de um lado e brancos do outro. O objetivo é ter a maioria dos discos com a sua cor virada para cima no final do jogo. Jogadores alternam turnos colocando um disco da sua cor em uma posição que enclausura um ou mais discos do oponente entre dois dos seus discos. Os discos do oponente então são virados para a cor do jogador atual.

# print do jogo


#### Connect Four (Lig4)
Connect Four é um jogo de tabuleiro para dois jogadores onde o objetivo é ser o primeiro a formar uma linha horizontal, vertical ou diagonal de quatro peças consecutivas. O jogo é jogado em um tabuleiro vertical com 7 colunas e 6 linhas, onde os jogadores alternam turnos soltando peças em uma das colunas. A peça então cai até o espaço mais baixo disponível na coluna.

# print do jogo

### Ferramentas e Tecnologias Utilizadas
- **Linguagem de Programação:** C++
- **Compilador:** g++ (GCC)
- **Interface Gráfica:** Biblioteca SFML para renderização e manipulação gráfica dos jogos.
- **Testes:** Biblioteca doctest para testes unitários e de integração.
- **Controle de Versão:** Git e GitHub para colaboração e versionamento.


## Compilação e Execução
Este projeto foi desenvolvido e testado em um ambiente Linux, utilizando um compilador g++ e a biblioteca SFML para a interface gráfica. Para compilar e executar o sistema, siga as instruções abaixo:

### Compilação
No diretório raiz do projeto, execute:

```
make run
```

## Tutorial Jogo