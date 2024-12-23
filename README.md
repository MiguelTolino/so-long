# so-long

Este proyecto es un pequeño juego 2D. Su propósito es trabajar con texturas, sprites y algunos otros elementos básicos de jugabilidad.

## Descripción del Proyecto

El objetivo del juego es que un personaje (puede ser un delfín, un pez, etc.) recolecte todos los objetos coleccionables en el mapa y llegue a la salida para ganar. El mapa está compuesto por diferentes tipos de tiles, incluyendo paredes, espacios vacíos, coleccionables y la salida.

## Estructura del Proyecto

- **src/**: Contiene los archivos fuente del juego.
  - **main.c**: Punto de entrada del programa. Inicializa el juego y maneja el bucle principal.
  - **parse_map.c**: Funciones para leer y validar el archivo del mapa.
  - **render_game.c**: Funciones para dibujar el mapa y los elementos del juego en la ventana.
  - **update.c**: Funciones para manejar el movimiento del jugador y actualizar el estado del juego.
  - **mlx_hooks.c**: Funciones para manejar los eventos de teclado y cerrar el juego.
  - **cleanup.c**: Funciones para liberar recursos y limpiar el juego.
  - **is_valid_path_with_collectibles.c**: Funciones para validar si hay un camino válido en el mapa que permita recolectar todos los coleccionables y llegar a la salida.
  - **load_sprites.c**: Funciones para cargar los sprites del juego.

- **lib/**: Contiene las bibliotecas utilizadas en el proyecto.
  - **libft/**: Implementación de funciones estándar de C.
  - **minilibx_opengl/**: Biblioteca para manejar gráficos y ventanas.

- **sprites/**: Contiene los archivos XPM de los sprites utilizados en el juego.

## Tareas Pendientes

### Validación del Camino del Mapa
- Robrodri necesita implementar la función de validación del camino en `is_valid_path_with_collectibles.c`. Esta función debe asegurarse de que el jugador pueda recolectar todos los coleccionables y llegar a la salida.

### Mejorar la Jugabilidad
- Ajustar el movimiento del jugador para que sea más fluido.
- Implementar nuevas mecánicas de juego si es necesario.

### Ajuste de Sprites
- Retocar el ajuste de los sprites para que se vean centrados y a pantalla completa.
- Asegurarse de que los sprites se escalen correctamente según el tamaño de la ventana.

### Nuevos Estilos y Sprites
- Crear y agregar nuevos sprites para darle un nuevo estilo al juego.
- Asegurarse de que los nuevos sprites se integren bien con el resto del juego.

### Crear un Lore del Juego
- Desarrollar una historia o contexto para el juego que lo haga más interesante y atractivo para los jugadores.

### Pantalla de Inicio y Final
- Crear una pantalla de inicio que se muestre al iniciar el juego.
- Crear una pantalla de final que se muestre cuando el jugador gane o pierda el juego.

## Cómo Ejecutar el Proyecto

1. Clonar el repositorio.
2. Ejecutar `make` para compilar el proyecto.
3. Ejecutar `./so_long <map_file.ber>` para iniciar el juego con el archivo de mapa especificado.

## Contacto

Para cualquier duda o sugerencia, por favor contacta a Santa Claus
