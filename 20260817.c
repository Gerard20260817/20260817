#include <stdio.h>

#define MAX 30

int main(void) {
    int n, m, L, U;
    int a[MAX][MAX];
    int eventosFila[MAX], impactoFila[MAX], rachaFila[MAX], inicioRacha[MAX];
    int eventosCol[MAX];

    if (scanf("%d %d %d %d", &n, &m, &L, &U) != 4) {
        printf("ERROR\n");
        return 0;
    }

    if (n < 1 || n > MAX || m < 1 || m > MAX ||
        L < 0 || U < L || U > 1000) {
        printf("ERROR\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &a[i][j]) != 1 || a[i][j] < 0 || a[i][j] > 1000) {
                printf("ERROR\n");
                return 0;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        eventosCol[j] = 0;
    }

    for (int i = 0; i < n; i++) {
        eventosFila[i] = 0;
        impactoFila[i] = 0;
        rachaFila[i] = 0;
        inicioRacha[i] = 0;

        int rachaActual = 0;
        int inicioActual = 0;

        for (int j = 0; j < m; j++) {
            int evento = 0;
            int impacto = 0;

            /* La primera fila no genera eventos. */
            if (i >= 1 && a[i - 1][j] - a[i][j] >= L &&
                a[i - 1][j] - a[i][j] <= U) {
                evento = 1;
                impacto = a[i - 1][j] - a[i][j] + 1;
            }

            if (evento) {
                eventosFila[i]++;
                impactoFila[i] += impacto;
                eventosCol[j]++;

                if (rachaActual == 0) {
                    inicioActual = j + 1;
                }
                rachaActual++;

                if (rachaActual > rachaFila[i]) {
                    rachaFila[i] = rachaActual;
                    inicioRacha[i] = inicioActual;
                }
            } else {
                rachaActual = 0;
                inicioActual = 0;
            }
        }
    }

    int totalEventos = 0;
    for (int i = 0; i < n; i++) {
        totalEventos += eventosFila[i];
        printf("FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d\n",
               i + 1, eventosFila[i], impactoFila[i],
               rachaFila[i], inicioRacha[i]);
    }

    printf("COLUMNAS");
    int columnaDestacada = 0;
    int maxEventosCol = -1;
    for (int j = 0; j < m; j++) {
        printf(" %d", eventosCol[j]);
        if (eventosCol[j] > maxEventosCol) {
            maxEventosCol = eventosCol[j];
            columnaDestacada = j + 1;
        }
    }
    printf("\n");

    int filaPrioritaria = 0;
    if (totalEventos > 0) {
        filaPrioritaria = 1;
        for (int i = 1; i < n; i++) {
            if (rachaFila[i] > rachaFila[filaPrioritaria - 1] ||
                (rachaFila[i] == rachaFila[filaPrioritaria - 1] &&
                 impactoFila[i] > impactoFila[filaPrioritaria - 1]) ||
                (rachaFila[i] == rachaFila[filaPrioritaria - 1] &&
                 impactoFila[i] == impactoFila[filaPrioritaria - 1] &&
                 eventosFila[i] > eventosFila[filaPrioritaria - 1])) {
                filaPrioritaria = i + 1;
            }
        }
    } else {
        columnaDestacada = 0;
    }

    printf("PRIORIDAD %d\n", filaPrioritaria);
    printf("COLUMNA %d\n", columnaDestacada);

    return 0;
}
