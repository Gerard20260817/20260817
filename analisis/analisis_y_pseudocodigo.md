# Análisis y pseudocódigo — Reto 20

## 1. Entradas, salidas y restricciones

**Entradas:** `N`, `M`, `L`, `U` y una matriz de `N x M` enteros.

**Restricciones:** `1 <= N,M <= 30`, `0 <= L <= U <= 1000` y cada valor de la matriz está entre `0` y `1000`.

**Salidas:** una línea `FILA` por cada fila, el vector `COLUMNAS`, la fila `PRIORIDAD` y la `COLUMNA` destacada. Si alguna restricción de entrada falla, se imprime únicamente `ERROR`.

## 2. Variables y arreglos

- `a[30][30]`: matriz de valores originales.
- `eventosFila[30]`: cantidad de eventos de cada fila.
- `impactoFila[30]`: suma de impactos de cada fila.
- `rachaFila[30]`: longitud de la mayor racha horizontal de cada fila.
- `inicioRacha[30]`: primera columna de la mayor racha.
- `eventosCol[30]`: cantidad de eventos de cada columna.
- `rachaActual`: longitud de la racha que se está recorriendo.
- `inicioActual`: inicio de la racha actual.
- `totalEventos`: cantidad total de eventos de la matriz.
- `filaPrioritaria`: fila elegida después de aplicar los desempates.
- `columnaDestacada`: columna con más eventos.

## 3. Pseudocódigo de lectura y validación

```text
leer N, M, L, U
si la lectura falla:
    imprimir ERROR
    terminar

si N, M, L o U no cumplen sus límites:
    imprimir ERROR
    terminar

para cada fila i:
    para cada columna j:
        leer a[i][j]
        si el valor está fuera de 0..1000:
            imprimir ERROR
            terminar
```

## 4. Pseudocódigo de eventos e impacto

```text
inicializar eventosCol en cero

para i desde 0 hasta N-1:
    inicializar resumen de la fila en cero
    rachaActual = 0
    inicioActual = 0

    para j desde 0 hasta M-1:
        evento = 0
        impacto = 0

        si i >= 1 y a[i-1][j] - a[i][j] >= L
                  y a[i-1][j] - a[i][j] <= U:
            evento = 1
            impacto = a[i-1][j] - a[i][j] + 1

        si evento:
            sumar 1 a eventosFila[i]
            sumar impacto a impactoFila[i]
            sumar 1 a eventosCol[j]
        si no:
            no sumar impacto
```

La primera fila no genera eventos porque la condición exige `i >= 1`. Los datos originales de la matriz nunca se modifican.

## 5. Pseudocódigo de rachas, resúmenes y desempates

```text
si evento:
    si rachaActual == 0:
        inicioActual = j + 1
    rachaActual = rachaActual + 1

    si rachaActual > rachaFila[i]:
        rachaFila[i] = rachaActual
        inicioRacha[i] = inicioActual
si no:
    rachaActual = 0
    inicioActual = 0
```

Al usar `>` y no `>=`, si existen varias rachas de la misma longitud se conserva la que comenzó primero. Si una fila no tiene eventos, su racha e inicio quedan en `0`.

La fila prioritaria se selecciona en este orden:

1. Mayor longitud de racha.
2. Mayor impacto total.
3. Mayor cantidad de eventos.
4. Menor número de fila; al recorrer en orden y reemplazar solo ante una mejora en los tres primeros criterios, el primer empate queda seleccionado.

La columna destacada es la de mayor cantidad de eventos. Al recorrer de izquierda a derecha y reemplazar solo cuando aparece un valor estrictamente mayor, los empates conservan la menor columna. Si no existe ningún evento, tanto prioridad como columna son `0`.
