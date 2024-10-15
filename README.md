# Estructura-de-datos
# Fórmula 1 Championship Points Tracker

## Descripción del Proyecto

Este proyecto simula el manejo de la clasificación de pilotos en el campeonato de Fórmula 1 para la temporada 2024. 
Los pilotos comienzan con una lista de puntos desordenados, se ordenan por puntaje de mayor a menor utilizando el algoritmo **Merge Sort**,
y después de cada carrera, los puntos se actualizan según los resultados ingresados. El programa permite:

- Ver una lista desordenada de pilotos con sus puntos finales.
- Ordenar a los pilotos por puntaje utilizando **Merge Sort**.
- Registrar nuevos puntos después de cada carrera.
- Ver la lista de pilotos actualizada y ordenada después de registrar los resultados de una carrera.

## Cómo usar el programa
1. **Al inicio**, se mostrará una lista desordenada de 13 pilotos con sus puntos.
2. **A continuación**, el programa ordenará los pilotos por puntaje y mostrará la lista ordenada.
3. **Luego**, te pedirá que ingreses los puntos adicionales para cada piloto después de una carrera.
4. **Finalmente**, el programa ordenará nuevamente la lista de pilotos por puntos y mostrará la clasificación actualizada.

## SICT0301: Evalúa los componentes
En el programa se ha implementado el algoritmo Merge Sort, su complejidad es O(n log n), lo que lo hace altamente eficiente en comparación con otros algoritmos como Bubble Sort o Selection Sort, que tienen una complejidad de O(n²). Merge Sort divide la lista de pilotos en mitades, las ordena de manera recursiva y luego combina las sublistas ordenadas. Este análisis de complejidad demuestra que Merge Sort es apropiado para manejar listas de tamaño moderado a grande, garantizando un rendimiento óptimo en el proyecto.

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


