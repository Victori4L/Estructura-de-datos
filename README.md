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
-Al inicio, se mostrará una lista desordenada de 13 pilotos con sus puntos.
-A continuación, el programa ordenará los pilotos por puntaje y mostrará la lista ordenada.
-Luego, te pedirá que ingreses los puntos adicionales para cada piloto después de una carrera.
-Finalmente, el programa ordenará nuevamente la lista de pilotos por puntos y mostrará la clasificación actualizada.

## SICT0301: Evalúa los componentes
En el programa se ha implementado el algoritmo Merge Sort, su complejidad es O(n log n), lo que lo hace altamente eficiente en comparación con otros algoritmos como Bubble Sort o Selection Sort, que tienen una complejidad de O(n²). Merge Sort divide la lista de pilotos en mitades, las ordena de manera recursiva y luego combina las sublistas ordenadas. Este análisis de complejidad demuestra que Merge Sort es apropiado para manejar listas de tamaño moderado a grande, garantizando un rendimiento óptimo en el proyecto.

## SICT0302: Toma decisiones
Se seleccionó Merge Sort como el algoritmo de ordenamiento por su eficiencia y estabilidad. La estabilidad asegura que los pilotos con el mismo puntaje mantengan su orden relativo, lo cual es muuy importante en un sistema de clasificación. Además, Merge Sort maneja listas parcialmente ordenadas y es adecuado para reordenar los puntos de los pilotos tras cada carrera, lo que lo convierte en una elección correcta para este problema recurrente en el programa.


### Compilación

Compila el archivo principal del programa usando un compilador de C++. Por ejemplo, si estás utilizando `g++`, puedes compilarlo de la siguiente manera:

```bash
g++ main.cpp -o formula1


