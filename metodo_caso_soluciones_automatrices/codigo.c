#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ===== COLORES ANSI =====
#define ROJO "\033[1;31m"
#define VERDE "\033[1;32m"
#define AMARILLO "\033[1;33m"
#define AZUL "\033[1;34m"
#define RESET "\033[0m"

// --- CONFIGURACIÓN Y CONSTANTES ---
#define MAX_REGISTROS 50
#define MAX_STR 100

// --- DEFINICIÓN DE TIPOS ---
typedef enum { 
    RECIBIDO, 
    EN_REPARACION, 
    LISTO, 
    ENTREGADO 
} EstadoVehiculo;

typedef struct {
    char matricula[20];
    char descripcion[MAX_STR];
    float presupuesto;
    EstadoVehiculo estado;
} Reparacion;

// --- VARIABLES GLOBALES ---
Reparacion base_datos[MAX_REGISTROS];
int total_reparaciones = 0;

// --- PROTOTIPOS ---
void registrarReparacion();
void actualizarEstado();
void mostrarReporte();
void eliminarReparacion();
const char* obtenerNombreEstado(EstadoVehiculo e);

// ================= MAIN =================
int main() {
    int opcion;

    do {
        printf(AZUL "\n========================================");
        printf("\n   SISTEMA SOLUCIONES AUTOMOTRICES");
        printf("\n========================================" RESET);

        printf(AMARILLO "\n1. Registrar Nueva Reparacion");
        printf("\n2. Actualizar Estado de Vehiculo");
        printf("\n3. Mostrar Reporte de Taller");
        printf("\n4. Eliminar Reparacion");
        printf("\n5. Salir" RESET);

        printf("\n========================================");
        printf("\nSeleccione una opcion: ");

        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: registrarReparacion(); break;
            case 2: actualizarEstado(); break;
            case 3: mostrarReporte(); break;
            case 4: eliminarReparacion(); break;
            case 5: printf(VERDE "\n✅ Cerrando sistema... Gracias.\n" RESET); break;
            default: printf(ROJO "\n❌ Opcion no valida.\n" RESET);
        }

    } while(opcion != 5);

    return 0;
}

// ================= REGISTRAR =================
void registrarReparacion() {
    if (total_reparaciones >= MAX_REGISTROS) {
        printf(ROJO "\n❌ Error: Taller lleno.\n" RESET);
        return;
    }

    printf(AZUL "\n--- REGISTRO DE ENTRADA ---" RESET);

    printf("\nMatricula: ");
    fgets(base_datos[total_reparaciones].matricula, 20, stdin);
    base_datos[total_reparaciones].matricula[strcspn(base_datos[total_reparaciones].matricula, "\n")] = 0;

    printf("Descripcion: ");
    fgets(base_datos[total_reparaciones].descripcion, MAX_STR, stdin);
    base_datos[total_reparaciones].descripcion[strcspn(base_datos[total_reparaciones].descripcion, "\n")] = 0;

    printf("Presupuesto: ");
    scanf("%f", &base_datos[total_reparaciones].presupuesto);
    getchar();

    base_datos[total_reparaciones].estado = RECIBIDO;
    total_reparaciones++;

    printf(VERDE "\n✅ Vehiculo registrado correctamente.\n" RESET);
}

// ================= ACTUALIZAR =================
void actualizarEstado() {
    char buscar[20];
    int encontrado = 0;

    printf(AMARILLO "\nActualizar vehiculo por matricula: " RESET);
    fgets(buscar, 20, stdin);
    buscar[strcspn(buscar, "\n")] = 0;

    for (int i = 0; i < total_reparaciones; i++) {
        if (strcmp(base_datos[i].matricula, buscar) == 0) {

            printf(AZUL "\nEstado actual: %s\n" RESET, 
                   obtenerNombreEstado(base_datos[i].estado));

            printf("\nSeleccione nuevo estado:\n");
            printf("0 -> RECIBIDO\n");
            printf("1 -> EN REPARACION\n");
            printf("2 -> LISTO\n");
            printf("3 -> ENTREGADO\n");
            printf("Opcion: ");

            int nuevo_estado;
            scanf("%d", &nuevo_estado);
            getchar();

            if (nuevo_estado >= 0 && nuevo_estado <= 3) {
                base_datos[i].estado = (EstadoVehiculo)nuevo_estado;

                printf(VERDE "\n✅ Estado actualizado a: %s\n" RESET,
                       obtenerNombreEstado(base_datos[i].estado));
            } 
            else {
                printf(ROJO "\n❌ Estado invalido.\n" RESET);
            }

            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf(ROJO "\n❌ Vehiculo no encontrado.\n" RESET);
}

// ================= ELIMINAR =================
void eliminarReparacion() {
    char buscar[20];
    int posicion = -1;

    printf(ROJO "\nEliminar vehiculo por matricula: " RESET);
    fgets(buscar, 20, stdin);
    buscar[strcspn(buscar, "\n")] = 0;

    for (int i = 0; i < total_reparaciones; i++) {
        if (strcmp(base_datos[i].matricula, buscar) == 0) {
            posicion = i;
            break;
        }
    }

    if (posicion == -1) {
        printf(ROJO "\n❌ Vehiculo no encontrado.\n" RESET);
        return;
    }

    for (int i = posicion; i < total_reparaciones - 1; i++) {
        base_datos[i] = base_datos[i + 1];
    }

    total_reparaciones--;

    printf(VERDE "\n✅ Registro eliminado correctamente.\n" RESET);
}

// ================= MOSTRAR =================
void mostrarReporte() {
    if (total_reparaciones == 0) {
        printf(AMARILLO "\n⚠️ No hay reparaciones registradas.\n" RESET);
        return;
    }

    printf(AZUL "\n%-15s %-20s %-15s %-10s" RESET,
           "MATRICULA", "DESCRIPCION", "ESTADO", "PRESUPUESTO");

    printf("\n-------------------------------------------------------------------------");

    for (int i = 0; i < total_reparaciones; i++) {
        printf("\n%-15s %-20s %-15s %.2f EUR", 
               base_datos[i].matricula, 
               base_datos[i].descripcion, 
               obtenerNombreEstado(base_datos[i].estado),
               base_datos[i].presupuesto);
    }

    printf("\n-------------------------------------------------------------------------\n");
}

// ================= ENUM =================
const char* obtenerNombreEstado(EstadoVehiculo e) {
    switch(e) {
        case RECIBIDO: return "RECIBIDO";
        case EN_REPARACION: return "EN REPARACION";
        case LISTO: return "LISTO";
        case ENTREGADO: return "ENTREGADO";
        default: return "DESCONOCIDO";
    }
}
