# Parcial de algoritmos en C

- Estudiante: Gerard Rafael Mencia Hernandez
- Matrícula: 20260817
- Reto asignado: Reto 20 — Filtrado: reducción entre etapas consecutivas

## Descripción

El programa analiza una matriz de etapas ordenadas. Desde la segunda fila compara cada valor con el valor de la fila anterior en la misma columna. Se genera un evento cuando `v-x` está entre `L` y `U`, inclusive. El impacto de cada evento es `v-x+1`.

El informe calcula por fila la cantidad de eventos, el impacto total, la mayor racha horizontal y el inicio de esa racha. También calcula el vector de eventos por columna, selecciona la fila prioritaria mediante los desempates indicados y determina la columna destacada.

## Compilación y ejecución

Con GCC y C11:

```bash
gcc -std=c11 -Wall -Wextra 20260817.c -o build/reto
./build/reto < pruebas/caso_01.in
```

En Windows con Git Bash se puede usar:

```bash
gcc -std=c11 -Wall -Wextra 20260817.c -o build/reto.exe
./build/reto.exe < pruebas/caso_01.in
```

## Diseño

El análisis y el pseudocódigo están en `analisis/analisis_y_pseudocodigo.md`.

## Pruebas

Los 17 casos proporcionados están en `pruebas/`. La verificación completa se documenta en `evidencias/resultados_pruebas.md`. La prueba de escritorio y dos pruebas propias están en `evidencias/`.

## Estado actual

Implementado y verificado con los 17 casos proporcionados. También se incluyen dos pruebas propias para desempates y una racha máxima con inicio más temprano.
