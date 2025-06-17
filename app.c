#include <stdio.h>

#define TAM 8

// Função para verificar se a posição está dentro do tabuleiro
int dentro_do_tabuleiro(int x, int y) {
    return (x >= 0 && x < TAM && y >= 0 && y < TAM);
}

// Simula movimentos da Torre (linha e coluna)
void movimento_torre(int x, int y) {
    printf("Movimentos da Torre a partir de (%d, %d):\n", x, y);
    for (int i = 0; i < TAM; i++) {
        if (i != x) printf("(%d, %d)\n", i, y);
        if (i != y) printf("(%d, %d)\n", x, i);
    }
}

// Simula movimentos do Bispo (diagonais) usando while
void movimento_bispo(int x, int y) {
    printf("Movimentos do Bispo a partir de (%d, %d):\n", x, y);
    int i, j;

    // ↘
    i = x + 1; j = y + 1;
    while (dentro_do_tabuleiro(i, j)) {
        printf("(%d, %d)\n", i, j);
        i++; j++;
    }

    // ↙
    i = x + 1; j = y - 1;
    while (dentro_do_tabuleiro(i, j)) {
        printf("(%d, %d)\n", i, j);
        i++; j--;
    }

    // ↖
    i = x - 1; j = y - 1;
    while (dentro_do_tabuleiro(i, j)) {
        printf("(%d, %d)\n", i, j);
        i--; j--;
    }

    // ↗
    i = x - 1; j = y + 1;
    while (dentro_do_tabuleiro(i, j)) {
        printf("(%d, %d)\n", i, j);
        i--; j++;
    }
}

// Simula movimentos da Rainha (Torre + Bispo)
void movimento_rainha(int x, int y) {
    printf("Movimentos da Rainha a partir de (%d, %d):\n", x, y);
    movimento_torre(x, y);
    movimento_bispo(x, y);
}

// Cavalo com loops aninhados
void movimento_cavalo(int x, int y) {
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    printf("Movimentos do Cavalo a partir de (%d, %d):\n", x, y);

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (dentro_do_tabuleiro(nx, ny)) {
            printf("(%d, %d)\n", nx, ny);
        }
    }
}

// Recursividade para movimento diagonal até a borda
void movimento_bispo_recursivo(int x, int y, int dx, int dy) {
    int nx = x + dx;
    int ny = y + dy;
    if (dentro_do_tabuleiro(nx, ny)) {
        printf("(%d, %d)\n", nx, ny);
        movimento_bispo_recursivo(nx, ny, dx, dy);
    }
}

void movimentos_bispo_com_recursao(int x, int y) {
    printf("Movimentos recursivos do Bispo a partir de (%d, %d):\n", x, y);
    movimento_bispo_recursivo(x, y, 1, 1);
    movimento_bispo_recursivo(x, y, 1, -1);
    movimento_bispo_recursivo(x, y, -1, -1);
    movimento_bispo_recursivo(x, y, -1, 1);
}

// Menu principal
int main() {
    int x, y, escolha;

    printf("=== Simulador de Movimentos de Xadrez ===\n");
    printf("Digite a posição inicial (linha e coluna de 0 a 7): ");
    scanf("%d %d", &x, &y);

    if (!dentro_do_tabuleiro(x, y)) {
        printf("Posição inválida!\n");
        return 1;
    }

    printf("\nEscolha a peça:\n");
    printf("1 - Torre\n");
    printf("2 - Bispo\n");
    printf("3 - Rainha\n");
    printf("4 - Cavalo\n");
    printf("5 - Bispo (com recursão)\n");
    printf("Opção: ");
    scanf("%d", &escolha);

    printf("\n");

    switch (escolha) {
        case 1: movimento_torre(x, y); break;
        case 2: movimento_bispo(x, y); break;
        case 3: movimento_rainha(x, y); break;
        case 4: movimento_cavalo(x, y); break;
        case 5: movimentos_bispo_com_recursao(x, y); break;
        default: printf("Opção inválida!\n");
    }

    return 0;
}