# Estructura-de-datos
# Fórmula 1 Championship Points Tracker

## Correciones del los avances:
Se especifico bien la subcompetencia SICT0302: Toma decisiones, ya que en el anterior no explique porque la eficiencia de utilizar el merge sort, el main que se utiliza es "main.cpp" el que habia subido en el primer avance lo descague mas veces y aparecio como "main(1).cpp" 

## Descripción del Proyecto

Este proyecto simula el manejo de la clasificación de pilotos en el campeonato de Fórmula 1 para la temporada 2024. 
Lo primero que se observa en la terminal es que hay 3 opciones para escoger 

-Primera opcion: "Registrar posiciones de carrera" 
Los pilotos comienzan con una lista de puntos desordenados y a su lado izquiero un numero para cada piloto 
Se preguntan las primeras diez posiciones de la carrera para sumar los puntos a esos pilotos, y despues se ordenan por puntaje de mayor a menor utilizando el algoritmo **Merge Sort**, se da la opcion de volver a simular una carrera y si es que elige que si se repite el ciclo y se van actualizando los puntos en el archivo .txt 

-Segunda opcion: "Consultar información de un piloto por número"
Si esta opción es elegida se da la lista de los pilotos de la temporada con un numero cada quien, después se pide ingresar el numero del piloto que se quiere saber la información, la información que se muestra es el nombre del piloto, el equipo al que pertenece y los puntos que lleva en la temporada 

- Tercera opción: "Salir"
Termina el programa y guarda la información actualizada.

## SICT0301 Evalúa los componentes

En el programa se ha implementado el algoritmo Merge Sort, su complejidad es O(n log n), lo que lo hace altamente eficiente en comparación con otros algoritmos como Bubble Sort o Selection Sort, que tienen una complejidad de O(n²). Merge Sort divide la lista de pilotos en mitades, las ordena de manera recursiva y luego combina las sublistas ordenadas. Este análisis de complejidad demuestra que Merge Sort es apropiado para manejar listas de tamaño moderado a grande, garantizando un rendimiento óptimo en el proyecto.
**Complejidad de la Lista Simplemente Enlazada**
La **lista simplemente enlazada** se ha seleccionado por su eficiencia en la gestión dinámica de datos, ya que permite agregar y actualizar pilotos en \( O(n) \) sin requerir reordenación en memoria, a diferencia de estructuras más costosas en términos de complejidad. Esta estructura es adecuada para el proyecto, ya que permite recorrer y modificar la clasificación de pilotos de manera eficiente, lo cual resulta óptimo para un manejo continuo y dinámico de los datos a lo largo de la temporada.


## SICT0302: Toma decisiones
-**Se seleccionó Merge Sort** como el algoritmo de ordenamiento por su eficiencia y estabilidad, es mas eficiente porque tiene una complejidad de tiempo de ejecución O(n log n) en el peor caso y en el promedio. Esto es mucho más eficiente que otros algoritmos como el de Bubble Sort o Selection Sort, que tienen una complejidad de O(n²), especialmente cuando se trabaja con grandes cantidades de datos, como en el caso de varias carreras y pilotos en la temporada de Fórmula 1.
- **Selección de estructura de datos**: Se seleccionó una **lista simplemente enlazada** para este proyecto porque se adapta bien a la naturaleza dinámica del manejo de la clasificación de pilotos. Las listas simplemente enlazadas permiten agregar, eliminar y actualizar elementos (pilotos) de forma eficiente, lo cual es esencial en un contexto donde los resultados de las carreras pueden variar y los puntos de los pilotos deben actualizarse frecuentemente.

- **Uso correcto de la lista simplemente enlazada**: La lista simplemente enlazada facilita la adición de nuevos pilotos al final de la lista y la actualización de puntos de manera dinámica después de cada carrera. Además, su implementación permite recorrer la lista para ordenar los pilotos utilizando Merge Sort, una elección que ofrece un equilibrio entre eficiencia y simplicidad en el manejo de datos. La capacidad de recorrer y modificar la lista sin necesidad de reestructurar toda la lista hace que esta estructura de datos sea la más adecuada para gestionar de manera flexible la clasificación de los pilotos de Fórmula 1.

### SICT0303: Implementa acciones científicas

- **Consultas de información**: El programa implementa mecanismos para consultar la lista de pilotos ordenados y desordenados, mostrando los puntos y la posición de cada piloto antes y después de cada carrera. Esto permite una visualización clara de la evolución de la clasificación.

- **Mecanismos de lectura de archivos**: Aunque la carga de datos inicial en esta versión es manual, el programa está diseñado para facilitar la implementación de mecanismos de lectura de archivos, que podrían utilizarse para cargar datos de pilotos desde un archivo de texto y poblar la lista simplemente enlazada, permitiendo una inicialización rápida del sistema de puntos.



### Compilación

Compila el archivo principal del programa usando un compilador de C++. Por ejemplo, si estás utilizando `g++`, puedes compilarlo de la siguiente manera:

```bash
g++ main.cpp -o formula1


