```mermaid
flowchart TD

%% MAIN
A[INICIO] --> B["leerNumeroCanciones()"]
B --> C{¿n > 0?}

C -- NO --> D["mostrarError()"]
D --> Z[FIN]

C -- SI --> E["cargarCanciones()"]
E --> F["aplicarShuffle()"]
F --> G["mostrarLista()"]
G --> Z[FIN]

%% FUNCION: leerNumeroCanciones
subgraph F1 ["Función: leerNumeroCanciones()"]
    B1[Solicitar número al usuario]
    B2[Leer n]
    B3[Devolver n]
    B1 --> B2 --> B3
end

%% FUNCION: cargarCanciones
subgraph F2 ["Función: cargarCanciones()"]
    E1[Inicializar i = 0]
    E2{¿i < n?}
    E3[Leer canción]
    E4[Guardar en array]
    E5[i = i + 1]

    E1 --> E2
    E2 -- SI --> E3 --> E4 --> E5 --> E2
    E2 -- NO --> E6[Fin carga]
end

%% FUNCION: aplicarShuffle
subgraph F3 ["Función: aplicarShuffle()"]
    F1A[i=n-1]
    F1B{¿i>0?}
    F1C[Random j]
    F1D[Swap]
    F1E[i=i-1]

    F1A --> F1B
    F1B -- SI --> F1C --> F1D --> F1E --> F1B
end
```
