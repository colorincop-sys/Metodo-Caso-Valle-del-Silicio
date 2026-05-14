#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
    int n, i, j;
    char canciones[MAX][50];
    char temp[50];

    srand(time(NULL));

    printf("Numero de canciones: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: numero invalido\\n");
        return 0;
    }

    // Entrada de datos
    for (i = 0; i < n; i++) {
        printf("Cancion %d: ", i + 1);
        scanf("%s", canciones[i]);
    }

    // Shuffle (Fisher-Yates)
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);

        // Intercambio
        strcpy(temp, canciones[i]);
        strcpy(canciones[i], canciones[j]);
        strcpy(canciones[j], temp);
    }

    // Salida
    printf("Lista aleatoria:\\n");
    for (i = 0; i < n; i++) {
        printf("%s\\n", canciones[i]);
    }

    return 0;
}
