# Dos pruebas propias

## Prueba propia 1 — Empate de racha, impacto y eventos

### Entrada
```text
3 4 0 10
10 10 10 10
10 10 10 10
10 10 10 10
```

### Salida esperada
```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 4 IMPACTO 4 RACHA 4 INICIO 1
FILA 3 EVENTOS 4 IMPACTO 4 RACHA 4 INICIO 1
COLUMNAS 2 2 2 2
PRIORIDAD 2
COLUMNA 1
```

### Justificación
Todas las diferencias entre filas consecutivas son `0`, que está dentro de `[0,10]`. Las filas 2 y 3 empatan en racha, impacto y eventos. El desempate final exige menor número de fila, por lo que se selecciona la fila 2. Todas las columnas empatan con dos eventos y se selecciona la columna 1.

## Prueba propia 2 — Dos rachas máximas: gana la que comienza antes

### Entrada
```text
3 6 0 0
5 5 5 5 5 5
5 5 0 0 5 5
5 5 1 1 5 5
```

### Salida esperada
```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 4 IMPACTO 4 RACHA 2 INICIO 1
FILA 3 EVENTOS 4 IMPACTO 4 RACHA 2 INICIO 1
COLUMNAS 2 2 0 0 2 2
PRIORIDAD 2
COLUMNA 1
```

### Justificación
En las filas 2 y 3 hay eventos en las columnas 1, 2, 5 y 6. Hay dos rachas máximas de longitud 2: columnas 1–2 y 5–6. Como ambas tienen igual longitud, debe conservarse la que comienza antes: inicio 1. Las dos filas también empatan en todos los criterios de prioridad, por lo que gana la fila 2. Las columnas 1, 2, 5 y 6 empatan con dos eventos; gana la de menor índice, la columna 1.
