# Juego de la Vida de Conway

Este proyecto presenta una implementación del autómata celular conocido como Juego de la Vida de Conway, desarrollado en lenguaje C. La implementación aprovecha operaciones a nivel de bits para gestionar eficientemente la memoria y emplea paralelización mediante OpenMP para optimizar los tiempos de cómputo.

## Requisitos del Sistema

Para compilar y ejecutar este proyecto es necesario contar con:

- Compilador C compatible con OpenMP (se recomienda GCC versión 4.2 o superior)
- Bibliotecas estándar de C
- Sistema operativo que soporte códigos de escape ANSI para la salida por consola
- Biblioteca `unistd.h` para control de pausas (presente en sistemas POSIX)

## Proceso de Compilación

La compilación del proyecto se realiza mediante los siguientes pasos:

1. Descargar o clonar el repositorio en el directorio de trabajo
2. Abrir una terminal en el directorio raíz del proyecto
3. Ejecutar el comando de compilación:

```bash
make
```

Este proceso generará el archivo ejecutable `game_of_life` en el directorio actual.

## Instrucciones de Uso

El programa se ejecuta desde la terminal con la siguiente sintaxis:

```bash
./game_of_life [manual]
```

**Modos de ejecución:**

- **Modo automático** (sin parámetros): El programa ejecuta las generaciones con intervalos de 0.5 segundos entre cada una
- **Modo manual** (con parámetro `manual`): Cada generación requiere que el usuario presione Enter para continuar

## Configuración de Parámetros

Los parámetros principales del programa (dimensiones del tablero, número de generaciones y cantidad de hilos) pueden modificarse en el archivo:

```
include/config.h
```

## Organización del Código

El proyecto mantiene la siguiente estructura de directorios:

- **`include/`**: Contiene los archivos de cabecera con las declaraciones y definiciones
- **`src/`**: Incluye las implementaciones de todas las funciones del programa
- **`Makefile`**: Script de automatización para el proceso de compilación
- **`README.md`**: Documentación del proyecto

## Características Técnicas

La implementación incorpora las siguientes características:

**Optimización de memoria**: Utiliza tipos de datos `uint64_t` y operaciones bit a bit para representar el estado de las células, reduciendo significativamente el consumo de memoria comparado con implementaciones convencionales.

**Paralelización**: Emplea OpenMP para distribuir los cálculos de cada generación entre múltiples hilos de procesamiento, mejorando el rendimiento en sistemas multiprocesador.

**Visualización interactiva**: Presenta la evolución del autómata generación tras generación, con opciones de pausa automática o control manual por parte del usuario.


La implementación sigue las reglas originales establecidas por John Conway: una célula viva permanece viva si tiene 2 o 3 vecinos vivos, una célula muerta nace si tiene exactamente 3 vecinos vivos, y en cualquier otro caso la célula muere o permanece muerta.