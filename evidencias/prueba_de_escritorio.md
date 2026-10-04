# Prueba de escritorio — Caso 01

Entrada:

```text
3 5 5 15
5 15 30 10 25
25 10 5 20 30
10 20 15 5 35
```

Para la fila 2 se compara con la fila 1. Para la fila 3 se compara con la fila 2.

| Fila | Columna | Valor anterior `v` | Valor actual `x` | `v-x` | Evento | Impacto | Racha actual |
|---:|---:|---:|---:|---:|---:|---:|---:|
| 1 | 1 | — | 5 | — | 0 | 0 | 0 |
| 1 | 2 | — | 15 | — | 0 | 0 | 0 |
| 1 | 3 | — | 30 | — | 0 | 0 | 0 |
| 1 | 4 | — | 10 | — | 0 | 0 | 0 |
| 1 | 5 | — | 25 | — | 0 | 0 | 0 |
| 2 | 1 | 5 | 25 | -20 | 0 | 0 | 0 |
| 2 | 2 | 15 | 10 | 5 | 1 | 6 | 1 |
| 2 | 3 | 30 | 5 | 25 | 0 | 0 | 0 |
| 2 | 4 | 10 | 20 | -10 | 0 | 0 | 0 |
| 2 | 5 | 25 | 30 | -5 | 0 | 0 | 0 |
| 3 | 1 | 25 | 10 | 15 | 1 | 16 | 1 |
| 3 | 2 | 10 | 20 | -10 | 0 | 0 | 0 |
| 3 | 3 | 5 | 15 | -10 | 0 | 0 | 0 |
| 3 | 4 | 20 | 5 | 15 | 1 | 16 | 1 |
| 3 | 5 | 30 | 35 | -5 | 0 | 0 | 0 |

Resumen:

```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 1 IMPACTO 6 RACHA 1 INICIO 2
FILA 3 EVENTOS 2 IMPACTO 32 RACHA 1 INICIO 1
COLUMNAS 1 1 0 1 0
PRIORIDAD 3
COLUMNA 1
```

La fila 3 queda prioritaria porque tiene la mayor racha empatada con la fila 2 y supera a la fila 2 en impacto total y cantidad de eventos.
