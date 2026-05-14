flowchart TD

A[INICIO] --> B["Leer número (n)"]

B --> C{¿n > 0?}

C -- NO --> D[Mostrar error]
D --> E[FIN]

C -- SI --> F[Introducir canciones]
F --> G[Aplicar Fisher-Yates]
G --> H[Mostrar lista final]
H --> E[FIN]
