``` mermaid
flowchart TD

%% MAIN
A[INICIO] --> B["menuPrincipal()"]
B --> C{¿opción seleccionada?}

C -->|1| D["registrarReparacion()"]
C -->|2| E["actualizarEstado()"]
C -->|3| F["mostrarReporte()"]
C -->|4| Z[FIN]

%% FUNCION REGISTRAR
subgraph F1 ["Función: registrarReparacion()"]
    R1[Leer matrícula]
    R2[Leer descripción]
    R3[Leer presupuesto]
    R4[Guardar en array]
    R5[Estado = RECIBIDO]
    R1 --> R2 --> R3 --> R4 --> R5
end

%% FUNCION ACTUALIZAR
subgraph F2 ["Función: actualizarEstado()"]
    A1[Leer matrícula]
    A2[Buscar vehículo]
    A3{¿Encontrado?}
    A4[Seleccionar nuevo estado]
    A5[Actualizar estado]
    A1 --> A2 --> A3
    A3 -- SI --> A4 --> A5
end

%% FUNCION MOSTRAR
subgraph F3 ["Función: mostrarReporte()"]
    M1[Recorrer array]
    M2[Mostrar datos]
    M1 --> M2
end
```
