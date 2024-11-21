# Estructura-de-datos
# Fórmula 1 Championship Points Tracker

## Corrección final:
Se agrego la parte de **Mecanismos para consultar información de las estructuras** en el readme 

**Correciones del los avances:**
Se modifico el analisis de las complejidades de todo el proyecto (estan en los comentarios del codigo), en la descripción de SICT0301 Evalúa los componentes, SICT0302: Toma decisiones y SICT0303: Implementa acciones científicas se cambiaron y añadieron cosas
Se implementaron mecanismos para consultar información de las estructras

## Descripción del Proyecto

Este proyecto simula el manejo de la clasificación de pilotos en el campeonato de Fórmula 1 para la temporada 2024. 
Lo primero que se observa en la terminal es que hay 3 opciones para escoger 

- Primera opcion: "Registrar posiciones de carrera" 
Los pilotos comienzan con una lista de puntos desordenados, con un número asignado para cada uno. El programa solicita las posiciones de los primeros diez pilotos en la carrera, agrega los puntos correspondientes, y ordena la lista por puntaje de mayor a menor utilizando el algoritmo **Merge Sort**. Posteriormente, se da la opción de simular otra carrera, actualizando los puntos en el archivo `pilotos.txt`.

- Segunda opcion: "Consultar información de un piloto por número"
Si esta opción es elegida se da la lista de los pilotos de la temporada con un numero cada quien, después se pide ingresar el numero del piloto que se quiere saber la información, la información que se muestra es el nombre del piloto, el equipo al que pertenece y los puntos que lleva en la temporada 

- Tercera opción: "Salir"
Termina el programa y guarda la información actualizada.

## SICT0301 Evalúa los componentes

-**Complejidad de Merge Sort**

En el programa se ha implementado el algoritmo **Merge Sort**, su complejidad es O(n log n), lo que lo hace altamente eficiente en comparación con otros algoritmos como Bubble Sort o Selection Sort, que tienen una complejidad de O(n²). Merge Sort divide la lista de pilotos en mitades, las ordena de manera recursiva y luego combina las sublistas ordenadas. Este análisis de complejidad demuestra que Merge Sort es apropiado para manejar listas de tamaño moderado a grande, garantizando un rendimiento óptimo en el proyecto.

-**Complejidad de la Lista Simplemente Enlazada**
 La **lista simplemente enlazada** fue seleccionada por su eficiencia en la gestión dinámica de datos. Con una complejidad de acceso de O(n), permite agregar y actualizar pilotos sin necesidad de reordenar en memoria, lo cual es menos costoso en términos de tiempo y espacio que estructuras como los arreglos. Esta estructura es adecuada para el proyecto, ya que permite recorrer y modificar la clasificación de pilotos de manera continua y eficiente, optimizando el rendimiento en un manejo dinámico de datos a lo largo de la temporada.
Se consideraron otras estructuras, como **vectores** y **listas dobles**, pero la lista simplemente enlazada se consideró ideal por su simplicidad y por el tipo de operaciones que se requieren. Aunque un vector permite un acceso de tiempo constante O(1) a elementos por índice, sería menos eficiente al añadir o eliminar elementos en posiciones arbitrarias, ya que se requiere reordenar la memoria en tales casos, resultando en una complejidad de O(n) para estas operaciones. Por otro lado, una lista doblemente enlazada ocuparía más memoria debido a los punteros adicionales y no aportaría un beneficio considerable en este contexto, donde solo se necesita recorrer la lista en una dirección y mantener actualizados los puntajes de los pilotos.


-**Complejidad de los componentes del programa y del programa final** 

El análisis detallado de la complejidad de cada componente se encuentra en los comentarios del código, especificando el mejor, peor y promedio de cada función para asegurar la claridad del rendimiento esperado en diversas condiciones.



## SICT0302: Toma decisiones
-**Se seleccionó Merge Sort** 

Como el algoritmo de ordenamiento por su eficiencia y estabilidad, es mas eficiente porque tiene una complejidad de tiempo de ejecución O(n log n) en el peor caso y en el promedio. Esto es mucho más eficiente que otros algoritmos como el de Bubble Sort o Selection Sort, que tienen una complejidad de O(n²), especialmente cuando se trabaja con grandes cantidades de datos, como en el caso de varias carreras y pilotos en la temporada de Fórmula 1.

-**Selección de estructura de datos**:
La **lista simplemente enlazada** fue elegida para manejar la clasificación de los pilotos por su eficiencia en la actualización y manejo dinámico de datos. Esta estructura permite realizar operaciones de inserción y eliminación en O(1) cuando se realizan al inicio o al final de la lista, y búsquedas en O(n), lo cual es adecuado para la cantidad de datos moderada del proyecto. A diferencia de los arreglos, la lista simplemente enlazada permite agregar o eliminar pilotos sin necesidad de reorganizar toda la estructura, lo que optimiza el rendimiento y la flexibilidad en el manejo de la clasificación de pilotos en el campeonato. Esta elección permite un acceso eficiente y adecuado a los elementos sin la necesidad de tiempo constante en cada operación, optimizando el programa en términos de simplicidad y funcionalidad.



### SICT0303: Implementa acciones científicas


**Mecanismos para consultar información de las estructuras**  
El programa permite consultar la información de los pilotos de manera eficiente. Con la opción 2 del menú, se puede seleccionar un piloto por número para obtener detalles específicos, como el nombre, el equipo y los puntos acumulados en la temporada. Además, la opción 1 permite ver una lista de pilotos ordenada por puntaje luego de cada carrera, lo que facilita el seguimiento de las posiciones en el campeonato.

El método para consultar información de un piloto en el proyecto utiliza una búsqueda secuencial en una lista simplemente enlazada, donde cada nodo representa a un piloto. Esta búsqueda comienza desde el nodo inicial de la lista, recorriendo cada nodo de manera lineal hasta alcanzar la posición especificada por el usuario, previamente ingresada como un número que identifica al piloto. Durante este recorrido, el programa compara el índice actual con el número ingresado, avanzando al siguiente nodo hasta encontrar el correspondiente. Una vez localizado, se extrae la información del piloto, como su nombre, equipo y puntos acumulados, y se muestra al usuario. Este mecanismo es eficiente para el tamaño moderado de datos del proyecto, ya que permite acceder dinámicamente a cualquier piloto sin necesidad de reorganizar la estructura o usar índices directos, aprovechando así las características de una lista simplemente enlazada.

**Mecanismos de lectura de archivos**  
El programa incluye un sistema de lectura de archivos que carga los datos de los pilotos desde el archivo `pilotos.txt` al inicio. Este mecanismo permite una experiencia de uso continua entre ejecuciones, recuperando la información actualizada sin necesidad de ingresar datos manualmente en cada ejecución. Esto asegura la persistencia de datos y mantiene la integridad de la clasificación a lo largo del uso del sistema.

**Mecanismos de escritura de archivos**  
Para conservar los datos de los pilotos y sus puntajes actualizados, el programa guarda automáticamente la información al finalizar, escribiéndola en el archivo `pilotos.txt`. Este sistema de persistencia garantiza que cualquier actualización realizada durante la ejecución se registre, permitiendo que los datos estén siempre actualizados y listos para la próxima sesión de uso.

### Compilación

Compila el archivo principal del programa usando un compilador de C++. Por ejemplo, si estás utilizando `g++`, puedes compilarlo de la siguiente manera:

```bash
g++ main.cpp -o formula1


