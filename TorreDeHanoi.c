/*
 * TORRE DE HANÓI - versão para terminal
 *
 * Como o jogo é representado:
 *   - Cada torre (A, B, C) é um vetor de inteiros com 'numDeDisc' posições.
 *   - Cada número é o tamanho de um disco (1 = menor, n = maior).
 *   - O valor 0 significa "posição vazia".
 *   - A posição 0 do vetor é o TOPO da torre e a última posição é a BASE.
 *     Exemplo com 3 discos, torre A cheia: torreA = {1, 2, 3}
 *     Exemplo com 3 discos, torre B com um disco: torreB = {0, 0, 2}
 */
#include <stdio.h>

/*
 * mostrarRegras
 * Exibe na tela o objetivo e as regras do jogo, além de explicar
 * como fazer uma jogada. Não recebe nem devolve nada.
 */
void mostrarRegras(void){
    printf("---- REGRAS DA TORRE DE HANÓI ----n\n");
    printf("OBJETIVO:\n");
    printf("  Mover todos os discos da torre A para a torre B ou para a torre C,\n");
    printf("  mantendo a mesma ordem do início (menor disco no topo, maior na base).\n\n");
    printf("REGRAS:\n");
    printf("  1. Só é possível mover UM disco por vez.\n");
    printf("  2. Só se pode mover o disco que está no TOPO de uma torre.\n");
    printf("  3. Nunca coloque um disco maior sobre um disco menor.\n");
    printf("  4. Não é possível mover um disco de uma torre vazia.\n\n");
    printf("COMO JOGAR:\n");
    printf("  A cada rodada será exibido um menu com 6 opções de jogada.\n");
    printf("  Digite o número da opção desejada (por exemplo, 1 move o disco\n");
    printf("  do topo da torre A para a torre B) e pressione ENTER.\n");
    printf("  Jogadas inválidas são recusadas e nada é alterado.\n\n");
    printf("DICA:\n");
    printf("  Com n discos, o mínimo de jogadas necessárias é 2^n - 1.\n");
    printf("  (3 discos = 7 jogadas, 4 discos = 15 jogadas, ...)\n\n");
    printf("----\n\n");
}

/*
 * printar
 * Desenha as três torres na tela, uma linha do vetor por vez.
 *
 * numDeDisc     : quantidade de discos do jogo (altura das torres)
 * largMaiorDisc : largura, em caracteres, reservada para cada torre
 * torreA/B/C    : vetores que representam cada torre
 *
 * Para cada linha 'i' (do topo para a base), imprime lado a lado a
 * linha da torre A, da torre B e da torre C, e depois pula uma linha.
 */
void printar(int numDeDisc, int largMaiorDisc, int torreA[numDeDisc], int torreB[numDeDisc], int torreC[numDeDisc]){ 
    // Colunas que delimitam o disco de tamanho 1 em torno do centro.
    // Um disco de tamanho k se estende k-1 colunas além desses limites.
    int limInf = ((largMaiorDisc-1)/2)-1;
    int limSup = ((largMaiorDisc-1)/2)+1;
    int centro = (largMaiorDisc-1)/2;   // coluna onde fica o pino "|"

    for(int i = 0; i<numDeDisc; i++){
        // printf("%d ", torreA[i]);

        // ---- Torre A ----
        for(int j = 0; j<largMaiorDisc; j++){
            if(torreA[i]==0){
                // Sem disco nessa linha: desenha só o pino no centro
                if(j==centro){
                    printf("|");
                }else{
                    printf(" ");
                }
            }else{
                // Com disco: espaços fora dele e "_" dentro dele
                if(j<limInf-torreA[i]+1 || j>limSup+torreA[i]-1){
                    printf(" ");
                }else{
                    printf("_");
                }
            }
        }

        // ---- Torre B ----
        for(int j = 0; j<largMaiorDisc; j++){
            if(torreB[i]==0){
                if(j==centro){
                    printf("|");
                }else{
                    printf(" ");
                }
            }else{
                if(j<limInf-torreB[i]+1 || j>limSup+torreB[i]-1){
                    printf(" ");
                }else{
                    printf("_");
                }
            }
        }

        // ---- Torre C ----
        for(int j = 0; j<largMaiorDisc; j++){
            if(torreC[i]==0){
                if(j==centro){
                    printf("|");
                }else{
                    printf(" ");
                }
            }else{
                if(j<limInf-torreC[i]+1 || j>limSup+torreC[i]-1){
                    printf(" ");
                }else{
                    printf("_");
                }
            }
        }
        printf("\n");   // fim da linha das três torres
    }
}

/*
 * procurar
 * Procura, de forma recursiva, o índice do disco que está no topo da torre.
 *
 * n : índice atual da busca (a chamada inicial deve passar 0)
 *
 * Devolve o primeiro índice cujo valor é diferente de 0.
 * Se a torre estiver vazia, devolve o último índice (numDeDisc - 1),
 * que nesse caso contém 0.
 */
int procurar(int numDeDisc, int torre[numDeDisc], int n){
    // Passou do fim do vetor: torre vazia, devolve a base
    if(n > numDeDisc - 1){
        return numDeDisc - 1;
    }

    // Achou um disco: esse é o topo
    if(torre[n] != 0){
        return n;
    }

    // Senão, continua procurando na posição seguinte
    return procurar(numDeDisc, torre, n + 1);
}

/*
 * mover
 * Tenta mover o disco do topo da torre de origem (torreA)
 * para a torre de destino (torreB).
 * Se a jogada for inválida, avisa e não altera nada.
 */
void mover(int numDeDisc, int torreA[numDeDisc], int torreB[numDeDisc]){
    int a, b, temp;
    a = procurar(numDeDisc, torreA, 0);   // topo da origem
    b = procurar(numDeDisc, torreB, 0);   // topo do destino

    // Regra: não dá para mover de uma torre vazia
    if(torreA[a]==0){
        printf("operação invalida\n");
        return;
    }

    // Regra: não dá para pôr um disco maior sobre um menor.
    // (torreB[numDeDisc-1]!=0 garante que o destino NÃO está vazio,
    //  pois a base só é ocupada se houver pelo menos um disco)
    if(torreA[a]>torreB[b] && torreB[numDeDisc-1]!=0){
        printf("operação invalida\n");
        return;
    }

    // Se o destino já tem discos, o novo disco entra uma posição acima do topo
    if(torreB[b] != 0){
        b--;
    }

    torreB[b]=torreA[a];   // coloca o disco no destino
    torreA[a]=0;           // e o remove da origem
}

/*
 * jogada
 * Mostra o menu de jogadas, lê a opção do jogador e chama 'mover'
 * com a origem e o destino correspondentes.
 * Se a opção for inválida, avisa e pede novamente (recursão).
 */
void jogada(int numDeDisc, int torreA[numDeDisc], int torreB[numDeDisc], int torreC[numDeDisc]){
    int opcao;
    printf("\nopções de jogada:\n\n");
    printf("1- A para B\n");
    printf("2- A para C\n");
    printf("3- B para A\n");
    printf("4- B para C\n");
    printf("5- C para A\n");
    printf("6- C para B\n");
    printf("selecione uma das opcoes acima:");
    scanf("%d", &opcao);

    if(opcao<1 || opcao>6){
        // Opção fora do intervalo: pede novamente
        printf("opcao invalida!!!\n selecione uma das opcao inteira entre 1 e 6.\n");
        jogada(numDeDisc, torreA, torreB, torreC);
    }else if(opcao==1){
        mover(numDeDisc, torreA, torreB);   
    }else if(opcao==2){
        mover(numDeDisc, torreA, torreC);   
    }else if(opcao==3){
        mover(numDeDisc, torreB, torreA);   
    }else if(opcao==4){
        mover(numDeDisc, torreB, torreC);   
    }else if(opcao==5){
        mover(numDeDisc, torreC, torreA);   
    }else if(opcao==6){
        mover(numDeDisc, torreC, torreB);   
    }
}

/*
 * verificar
 * Compara uma torre com a torre de teste (1, 2, ..., n).
 * Devolve 1 se forem idênticas (torre completa e na ordem certa)
 * e 0 se houver qualquer diferença.
 */
int verificar(int numDeDisc, int torre[numDeDisc], int torreTest[numDeDisc]){
    for(int i=0; i<numDeDisc; i++){
        if(torre[i]!=torreTest[i]){
            return 0;
        }
    }
    return 1;
}

/*
 * corrigir
 * Chamada quando o número de discos digitado é inválido.
 * Pede o valor de novo, repetindo (recursão) até ficar entre 1 e 42.
 * Devolve o número de discos válido.
 */
int corrigir(int numDeDisc){
    printf("numero de discos deve ser maior que 0 e menor ou igual a 42!!!\n");
    printf("quantos discos voce quer na torre:");
    scanf("%d", &numDeDisc);
    if(numDeDisc>42 || numDeDisc<=0){
        return corrigir(numDeDisc);
    }
    return numDeDisc;
}

/*
 * main
 * Fluxo do programa:
 *   1. Mostra as regras.
 *   2. Lê e valida o número de discos.
 *   3. Cria e inicializa as torres.
 *   4. Repete: desenha as torres -> lê a jogada -> verifica vitória.
 */
int main()
{
    int fim = 0;        // vira 1 quando o jogador vence
    int numDeDisc;

    // Apresenta as regras antes de começar
    mostrarRegras();

    // Leitura do número de discos, com validação
    printf("quantos discos voce quer na torre:");
    scanf("%d", &numDeDisc);
    if(numDeDisc>42 || numDeDisc<=0){
        numDeDisc = corrigir(numDeDisc);
    }
    printf("\n");

    // Largura de cada torre: o maior disco ocupa 2*n+1 colunas,
    // e somamos 2 de folga para as torres não ficarem coladas
    int largMaiorDisc = numDeDisc*2+3; 

    int torreTest[numDeDisc];   // torre "gabarito": {1, 2, ..., n}
    int torreA[numDeDisc];
    int torreB[numDeDisc];
    int torreC[numDeDisc];

    // Torre A começa cheia (e o gabarito recebe a mesma sequência)
    for(int i = 0; i<numDeDisc; i++){
        torreTest[i] = i+1;
        torreA[i] = i+1;
    }
    // Torres B e C começam vazias
    for(int i = 0; i<numDeDisc; i++){
        torreB[i] = 0;
        torreC[i] = 0;
    }

    // Laço principal do jogo
    while(fim!=1){
        printar(numDeDisc, largMaiorDisc, torreA, torreB, torreC);
        jogada(numDeDisc, torreA, torreB, torreC);

        // Vitória: todos os discos, em ordem, na torre B ou na torre C
        if(verificar(numDeDisc, torreB, torreTest) || verificar(numDeDisc, torreC, torreTest)){
            fim=1;
            printar(numDeDisc, largMaiorDisc, torreA, torreB, torreC);
            printf("vitoria!!!");
        }
    }
}