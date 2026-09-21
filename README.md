# Torre de Hanói

> **Aviso:** Este projeto é uma adaptação inspirada no clássico quebra-cabeça matemático Torre de Hanói, desenvolvido exclusivamente para fins educacionais e didáticos. Não possui fins lucrativos nem intenção comercial, servindo apenas como estudo prático de desenvolvimento e lógica de programação.

## Sobre a Torre de Hanói

A Torre de Hanói é um quebra-cabeça clássico composto por três pinos e $n$ discos de diâmetros distintos. O objetivo consiste em transferir toda a pilha inicial do pino de origem para o pino de destino, movendo apenas um disco por vez e sem nunca apoiar um disco maior sobre outro menor. O número mínimo de movimentos necessários para resolver o jogo pode ser representado pela equação $M(n) = 2^n - 1$, com $n$ sendo o número de discos.

## Pré-requisitos

* Compilador C (como `gcc` ou `clang`)

## Compilação e Execução

Certifique-se de que o arquivo `TorreDeHanoi.c` esteja no diretório atual do seu terminal.

**1. Compilar:**

```bash
gcc TorreDeHanoi.c -o TorreDeHanoi
```

**2. Executar:**

```bash
# No Linux / macOS:
./TorreDeHanoi
```

```bash
# No Windows:
TorreDeHanoi.exe
```

O jogo abrirá no terminal e receberá os comandos por ele. O jogo se encerrará ao resolver o desafio; para começar um novo jogo, basta executar o comando de execução novamente.

## Regras e Dinâmica do Jogo

### OBJETIVO

Mover todos os discos da torre A para a torre B ou para a torre C, mantendo a mesma ordem do início (menor disco no topo, maior na base).

### REGRAS

1. Só é possível mover UM disco por vez.
2. Só se pode mover o disco que está no TOPO de uma torre.
3. Nunca coloque um disco maior sobre um disco menor.
4. Não é possível mover um disco de uma torre vazia.

### COMO JOGAR

A cada rodada será exibido um menu com 6 opções de jogada. Digite o número da opção desejada (por exemplo, 1 move o disco do topo da torre A para a torre B) e pressione ENTER. Jogadas inválidas são recusadas e nada é alterado.

### DICA

Com n discos, o mínimo de jogadas necessárias é 2^n - 1. (3 discos = 7 jogadas, 4 discos = 15 jogadas, ...)

## Desenvolvedores

* Brian Yuta Maruyama Tatewaki 
* Igor Rafael Pitoli
* Luiz Pedro Pereira dos Santos

---

# Tower of Hanoi

> **Notice:** This project is an adaptation inspired by the classic mathematical puzzle Tower of Hanoi, developed exclusively for educational and learning purposes. It has no commercial purpose or intent and serves solely as a practical study of software development and programming logic.

## About the Tower of Hanoi

The Tower of Hanoi is a classic puzzle consisting of three pegs and $n$ disks of different diameters. The objective is to transfer the entire initial stack from the source peg to the destination peg, moving only one disk at a time and never placing a larger disk on top of a smaller one. The minimum number of moves required to solve the game can be represented by the equation $M(n) = 2^n - 1$, where $n$ is the number of disks.

## Prerequisites

* A C compiler (such as `gcc` or `clang`)

## Compilation and Execution

Make sure that the `TorreDeHanoi.c` file is located in the current directory of your terminal.

**1. Compile:**

```bash
gcc TorreDeHanoi.c -o TorreDeHanoi
```

**2. Run:**

```bash
# On Linux / macOS:
./TorreDeHanoi
```

```bash
# On Windows:
TorreDeHanoi.exe
```

The game will open in the terminal and receive commands through it. The game will end once the challenge is solved. To start a new game, simply run the program again.

## Game Rules and Mechanics

### OBJECTIVE

Move all the disks from tower A to tower B or tower C, maintaining the same order as at the beginning (smallest disk on top, largest disk at the bottom).

### RULES

1. Only ONE disk can be moved at a time.
2. Only the disk at the TOP of a tower can be moved.
3. Never place a larger disk on top of a smaller disk.
4. A disk cannot be moved from an empty tower.

### HOW TO PLAY

Each round will display a menu with 6 move options. Enter the number of the desired option (for example, 1 moves the top disk from tower A to tower B) and press ENTER. Invalid moves are rejected and nothing is changed.

### TIP

With n disks, the minimum number of moves required is 2^n - 1. (3 disks = 7 moves, 4 disks = 15 moves, ...)

## Developers

* Brian Yuta Maruyama Tatewaki 
* Igor Rafael Pitoli
* Luiz Pedro Pereira dos Santos
