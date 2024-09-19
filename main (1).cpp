#include "formula1.h"
#include <iostream>

// Constructor por defecto de Pilot
Pilot::Pilot() : name(""), team(""), points(0) {}

// Constructor parametrizado de Pilot
Pilot::Pilot(std::string _name, std::string _team, int _points) : name(_name), team(_team), points(_points) {}

// Métodos para obtener los atributos de Pilot
std::string Pilot::getName() const { return name; }
std::string Pilot::getTeam() const { return team; }
int Pilot::getPoints() const { return points; }

// Actualizar puntos del piloto
void Pilot::updatePoints(int additionalPoints) {
    points += additionalPoints; // Incrementa los puntos del piloto de acuerdo a la carrera, O(1)
}

// Constructor de Championship
Championship::Championship() {}

// Agregar 13 pilotos iniciales desordenados
void Championship::agregarPilotosIniciales() {
    // Se agregan los pilotos con puntajes iniciales al vector. Complejidad de push_back es O(1) por cada inserción
    pilots.push_back(Pilot("Lance Stroll", "Aston Martin", 195));
    pilots.push_back(Pilot("Carlos Sainz", "Ferrari", 240));
    pilots.push_back(Pilot("Sergio Perez", "Red Bull Racing", 285));
    pilots.push_back(Pilot("Max Verstappen", "Red Bull Racing", 395));
    pilots.push_back(Pilot("Pierre Gasly", "Alpine", 215));
    pilots.push_back(Pilot("Charles Leclerc", "Ferrari", 290));
    pilots.push_back(Pilot("Valtteri Bottas", "Alfa Romeo", 170));
    pilots.push_back(Pilot("Lando Norris", "McLaren", 250));
    pilots.push_back(Pilot("Lewis Hamilton", "Mercedes", 320));
    pilots.push_back(Pilot("Esteban Ocon", "Alpine", 220));
    pilots.push_back(Pilot("Fernando Alonso", "Aston Martin", 275));
    pilots.push_back(Pilot("Oscar Piastri", "McLaren", 185));
    pilots.push_back(Pilot("George Russell", "Mercedes", 260));
}

// Registrar puntos después de una carrera
void Championship::registrarPuntosCarrera() {
    std::cout << "\nIntroduce los puntos adicionales obtenidos por cada piloto después de la carrera:\n";

    // Usamos un bucle basado en índices para iterar por la lista de pilotos, O(n)
    for (size_t i = 0; i < pilots.size(); ++i) {
        int puntos;
        std::cout << pilots[i].getName() << " (" << pilots[i].getTeam() << ") - Puntos: ";
        std::cin >> puntos;
        pilots[i].updatePoints(puntos); // Actualiza los puntos del piloto, O(1)
    }
}

// Mostrar la lista de pilotos
void Championship::displayPilots() const {
    std::cout << "----------------------------------------\n";
    std::cout << "# | Piloto             | Equipo        | Puntos\n";
    std::cout << "----------------------------------------\n";

    // Usamos un bucle basado en índices para mostrar la lista de pilotos, O(n)
    for (size_t i = 0; i < pilots.size(); i++) {
        std::cout << (i + 1) << " | " << pilots[i].getName() << " | " << pilots[i].getTeam() << " | " << pilots[i].getPoints() << " puntos\n";
    }
    std::cout << "----------------------------------------\n";
}

// Merge Sort y funciones auxiliares

// Función para mezclar dos sublistas ordenadas
void Championship::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;  // Tamaño de la sublista izquierda
    int n2 = right - mid;     // Tamaño de la sublista derecha

    // Crear arreglos temporales, complejidad O(n1 + n2)
    std::vector<Pilot> leftArr(n1), rightArr(n2);

    // Copiar los datos en los arreglos temporales, complejidad O(n1 + n2)
    for (int i = 0; i < n1; ++i)
        leftArr[i] = pilots[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = pilots[mid + 1 + i];

    // Mezclar las sublistas, comparando elemento a elemento, complejidad O(n1 + n2)
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].getPoints() >= rightArr[j].getPoints()) { // Comparación O(1)
            pilots[k] = leftArr[i];
            i++;
        } else {
            pilots[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de las sublistas, O(n1) o O(n2)
    while (i < n1) {
        pilots[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        pilots[k] = rightArr[j];
        j++;
        k++;
    }
}

// Función recursiva Merge Sort
void Championship::mergeSort(int left, int right) {
    if (left >= right) // Caso base de la recursión, O(1)
        return;
    int mid = left + (right - left) / 2; // Dividir la lista en mitades, O(1)

    mergeSort(left, mid);   // Ordenar la primera mitad, O(log n) por la recursión
    mergeSort(mid + 1, right); // Ordenar la segunda mitad, O(log n) por la recursión

    merge(left, mid, right);  // Mezclar ambas mitades ordenadas, O(n)
}

// Ordenar los pilotos por puntos usando Merge Sort
void Championship::ordenaPorPuntos() {
    mergeSort(0, pilots.size() - 1); // Complejidad total O(n log n)
}

int main() {
    Championship championship;

    // Agregar los 13 pilotos iniciales desordenados
    championship.agregarPilotosIniciales();

    std::cout << "Lista desordenada de pilotos:\n";
    championship.displayPilots(); // Mostrar la lista desordenada, O(n)

    // Ordenar los pilotos por puntos
    championship.ordenaPorPuntos(); // Ordenar usando Merge Sort, O(n log n)

    std::cout << "\nLista de pilotos ordenada por puntos:\n";
    championship.displayPilots(); // Mostrar la lista ordenada, O(n)

    // Registrar puntos de una nueva carrera
    championship.registrarPuntosCarrera(); // Registrar los nuevos puntos, O(n)

    // Ordenar los pilotos después de la nueva carrera
    championship.ordenaPorPuntos(); // Reordenar con Merge Sort, O(n log n)

    std::cout << "\nLista de pilotos después de registrar los puntos de la carrera:\n";
    championship.displayPilots(); // Mostrar la lista actualizada, O(n)

    return 0;
}
