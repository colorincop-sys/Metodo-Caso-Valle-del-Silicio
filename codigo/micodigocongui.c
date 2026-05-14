#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANCIONES 100
#define MAX_NOMBRE 100

// Estructura de datos (Teoría U1: Tipos de datos complejos)
typedef struct {
    char nombre[MAX_NOMBRE];
} Cancion;

// Ámbito de Variables: Globales (para persistencia en el sistema)
Cancion lista[MAX_CANCIONES];
int total_canciones = 0;

// Prototipos de funciones (Diseño Estructurado)
void introducirNumero();
void introducirCanciones();
void mezclarCanciones();
void mostrarLista();

int main() {
    int opcion;
    srand(time(NULL)); // Semilla para la aleatoriedad

    do {
        // Interfaz de Usuario (Salida de información)
        printf("\n----------------------------------");
        printf("\n   SISTEMA DE MEZCLA DE CANCIONES");
        printf("\n----------------------------------");
        printf("\n1. Introducir numero de canciones");
        printf("\n2. Introducir canciones");
        printf("\n3. Mezclar canciones");
        printf("\n4. Mostrar lista");
        printf("\n5. Salir");
        printf("\n----------------------------------");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer del teclado

        switch(opcion) {
            case 1: introducirNumero(); break;
            case 2: introducirCanciones(); break;
            case 3: mezclarCanciones(); break;
            case 4: mostrarLista(); break;
            case 5: printf("Saliendo del sistema...\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while(opcion != 5);

    return 0;
}

// Implementación de la entrada de datos
void introducirNumero() {
    printf("Indique cuantas canciones desea gestionar (Max %d): ", MAX_CANCIONES);
    scanf("%d", &total_canciones);
    getchar();
    if(total_canciones < 1 || total_canciones > MAX_CANCIONES) {
        printf("Error: Cantidad no valida.\n");
        total_canciones = 0;
    }
}

void introducirCanciones() {
    if(total_canciones == 0) {
        printf("Primero debe indicar el numero de canciones (Opcion 1).\n");
        return;
    }
    for(int i = 0; i < total_canciones; i++) {
        printf("Nombre de la cancion %d: ", i + 1);
        fgets(lista[i].nombre, MAX_NOMBRE, stdin);
        lista[i].nombre[strcspn(lista[i].nombre, "\n")] = 0; // Limpieza de cadena
    }
}

// PROCESO: Algoritmo Shuffle (Lógica de programación)
void mezclarCanciones() {
    if(total_canciones <= 1) {
        printf("No hay suficientes canciones para mezclar.\n");
        return;
    }
    for(int i = total_canciones - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Generar índice aleatorio
        // Intercambio (Swap)
        Cancion temp = lista[i];
        lista[i] = lista[j];
        lista[j] = temp;
    }
    printf("¡Lista mezclada correctamente!\n");
}

void mostrarLista() {
    if(total_canciones == 0) {
        printf("La lista esta vacia.\n");
        return;
    }
    printf("\n--- LISTA DE REPRODUCCION ACTUAL ---\n");
    for(int i = 0; i < total_canciones; i++) {
        printf("%d. %s\n", i + 1, lista[i].nombre);
    }
}
