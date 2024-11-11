#include "formula1.h"
#include <iostream>
#include <fstream>
#include <sstream>

/*
    Análisis de Complejidad General del Programa:

    - La clase `Pilot` y sus métodos tienen complejidad constante O(1) en todos los casos, 
      ya que solo realiza operaciones de acceso y actualización de datos simples.

    - La clase `LinkedList` implementa una lista simplemente enlazada con un conjunto de métodos para manipular pilotos:
        - `addPilot` tiene complejidad O(n) en el peor caso debido al recorrido hasta el último nodo para la inserción.
        - `displayPilots` y `size` recorren toda la lista y, por lo tanto, tienen una complejidad de O(n).
        - `sortPilots` usa Merge Sort, con complejidad O(n log n) en todos los casos.

    - La clase `Championship` maneja las operaciones del campeonato:
        - Cargar datos desde un archivo (`cargarDatosDesdeArchivo`) y guardar datos (`guardarDatosEnArchivo`) tienen complejidad O(n), donde n es el número de pilotos.
        - `registrarPosicionesCarrera` actualiza puntos y luego ordena, por lo que tiene complejidad O(n log n).
    
    Complejidad Final del Programa:
    
    - Mejor caso: O(1), si no hay datos y el usuario realiza operaciones simples.
    - Caso promedio: O(m * n log n), donde `m` es el número de veces que se elige la opción de registrar una carrera.
    - Peor caso: O(m * n log n), debido a la ordenación en cada iteración del registro de posiciones.
*/

// Complejidad: O(1) en todos los casos
Pilot::Pilot() : name(""), team(""), points(0) {}

// Complejidad: O(1) en todos los casos (mejor, peor y promedio)
Pilot::Pilot(std::string _name, std::string _team, int _points)
    : name(_name), team(_team), points(_points) {}

// Complejidad: O(1) en todos los casos (mejor, peor y promedio)
std::string Pilot::getName() const { return name; }

// Complejidad: O(1) en todos los casos (mejor, peor y promedio)
std::string Pilot::getTeam() const { return team; }

// Complejidad: O(1) en todos los casos (mejor, peor y promedio)
int Pilot::getPoints() const { return points; }

// Complejidad: O(1) en todos los casos (mejor, peor y promedio)
void Pilot::updatePoints(int additionalPoints) { points += additionalPoints; }

// Complejidad: O(1) en todos los casos (mejor, peor y promedio)
LinkedList::LinkedList() : head(nullptr) {}

// Mejor caso: O(1), Caso promedio y peor caso: O(n)
LinkedList::~LinkedList() {
    PilotNode* current = head;
    while (current != nullptr) {
        PilotNode* next = current->next;
        delete current;
        current = next;
    }
}

// Mejor caso: O(1), Caso promedio y peor caso: O(n)
void LinkedList::addPilot(std::string name, std::string team, int points) {
    Pilot newPilot(name, team, points);
    PilotNode* newNode = new PilotNode(newPilot);

    if (!head) {
        head = newNode;
    } else {
        PilotNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Mejor caso: O(1), Caso promedio y peor caso: O(n)
int LinkedList::size() const {
    int count = 0;
    PilotNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Mejor caso: O(1), Caso promedio y peor caso: O(n)
void LinkedList::updatePoints(int position, int points) {
    PilotNode* temp = head;
    int currentIndex = 1;

    while (temp && currentIndex < position) {
        temp = temp->next;
        currentIndex++;
    }

    if (temp) {
        temp->pilot.updatePoints(points);
    } else {
        std::cerr << "Error: Posición fuera de rango." << std::endl;
    }
}

// Mejor caso, caso promedio y peor caso: O(n)
void LinkedList::displayPilots() const {
    PilotNode* temp = head;
    int index = 1;
    while (temp) {
        std::cout << index << " | " << temp->pilot.getName() << " | " << temp->pilot.getTeam() << " | " << temp->pilot.getPoints() << " puntos\n";
        temp = temp->next;
        ++index;
    }
    std::cout << "----------------------------------------\n";
}

// Mejor caso, caso promedio y peor caso: O(n log n)
PilotNode* LinkedList::mergeSort(PilotNode* head) {
    if (!head || !head->next) return head;

    PilotNode* middle = getMiddle(head);
    PilotNode* nextOfMiddle = middle->next;

    middle->next = nullptr;

    PilotNode* left = mergeSort(head);
    PilotNode* right = mergeSort(nextOfMiddle);

    return merge(left, right);
}

// Mejor caso, caso promedio y peor caso: O(n)
PilotNode* LinkedList::merge(PilotNode* left, PilotNode* right) {
    if (!left) return right;
    if (!right) return left;

    PilotNode* result = nullptr;

    if (left->pilot.getPoints() >= right->pilot.getPoints()) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Mejor caso: O(1), Caso promedio y peor caso: O(n)
PilotNode* LinkedList::getMiddle(PilotNode* head) {
    if (!head) return head;

    PilotNode* slow = head;
    PilotNode* fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// Complejidad: O(n log n) en todos los casos
void LinkedList::sortPilots() { head = mergeSort(head); }

// Complejidad: O(1) en todos los casos (mejor, peor y promedio)
Championship::Championship() {
    puntosPosicion[0] = 25;
    puntosPosicion[1] = 18;
    puntosPosicion[2] = 15;
    puntosPosicion[3] = 12;
    puntosPosicion[4] = 10;
    puntosPosicion[5] = 8;
    puntosPosicion[6] = 6;
    puntosPosicion[7] = 4;
    puntosPosicion[8] = 2;
    puntosPosicion[9] = 1;
}

// Mejor caso: O(1), Caso promedio y peor caso: O(n)
bool Championship::cargarDatosDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura.\n";
        return false;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string nombre, equipo;
        int puntos;

        if (std::getline(ss, nombre, ',') && std::getline(ss, equipo, ',') && ss >> puntos) {
            nombre.erase(0, nombre.find_first_not_of(" "));
            equipo.erase(0, equipo.find_first_not_of(" "));
            pilots.addPilot(nombre, equipo, puntos);
        }
    }
    archivo.close();
    return true;
}

// Mejor caso, caso promedio y peor caso: O(n)
bool Championship::guardarDatosEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura.\n";
        return false;
    }

    PilotNode* temp = pilots.head;
    while (temp) {
        archivo << temp->pilot.getName() << ", " << temp->pilot.getTeam() << ", " << temp->pilot.getPoints() << "\n";
        temp = temp->next;
    }

    archivo.close();
    return true;
}

// Mejor caso, caso promedio y peor caso: O(n log n)
void Championship::registrarPosicionesCarrera() {
    int listaSize = pilots.size();
    std::cout << "Introduce el número del piloto según su posición en la carrera (solo los primeros 10 recibirán puntos):\n";

    for (int i = 0; i < 10; ++i) {
        int position;
        std::cout << "Posición " << (i + 1) << ": ";
        std::cin >> position;

        if (position < 1 || position > listaSize) {
            std::cerr << "Error: Posición inválida. Inténtalo de nuevo.\n";
            --i;
        } else {
            pilots.updatePoints(position, puntosPosicion[i]);
        }
    }

    pilots.sortPilots();
}

// Mejor caso, caso promedio y peor caso: O(n)
void Championship::displayPilots() const {
    std::cout << "Lista de pilotos:\n";
    std::cout << "----------------------------------------\n";
    std::cout << "# | Piloto             | Equipo        | Puntos\n";
    std::cout << "----------------------------------------\n";
    pilots.displayPilots();
}

// Mejor caso: O(1), Caso promedio y peor caso: O(1)
bool Championship::preguntarOtraCarrera() {
    char opcion;
    std::cout << "\n¿Quieres registrar otra carrera? (s/n): ";
    std::cin >> opcion;

    return opcion == 's' || opcion == 'S';
}

// Mejor caso: O(1), Caso promedio y peor caso: O(n)
void Championship::consultarPilotoPorNumero() const {
    PilotNode* temp = pilots.head;
    int index = 1;
    std::cout << "\nLista de pilotos:\n";
    std::cout << "-----------------\n";
    while (temp) {
        std::cout << index << " | " << temp->pilot.getName() << "\n";
        temp = temp->next;
        ++index;
    }
    std::cout << "-----------------\n";

    int numero;
    std::cout << "Introduce el número del piloto que deseas consultar: ";
    std::cin >> numero;

    if (numero < 1 || numero > pilots.size()) {
        std::cout << "Número inválido. Intenta de nuevo.\n";
        return;
    }

    temp = pilots.head;
    for (int i = 1; i < numero; ++i) {
        temp = temp->next;
    }

    if (temp) {
        std::cout << "\nInformación del piloto:\n";
        std::cout << "Nombre: " << temp->pilot.getName() << "\n";
        std::cout << "Equipo: " << temp->pilot.getTeam() << "\n";
        std::cout << "Puntos: " << temp->pilot.getPoints() << " puntos\n";
        std::cout << std::endl;
    }
}

/*
    Complejidad de la función principal:

    - `cargarDatosDesdeArchivo`: O(n) en el peor caso, ya que puede leer hasta n pilotos del archivo.
    - Cada iteración del bucle `do-while` tiene una complejidad basada en la opción seleccionada por el usuario:
        - **Opción 1 (Registrar posiciones de carrera)**: La complejidad es O(n log n) debido a la ordenación después de registrar las posiciones.
        - **Opción 2 (Consultar piloto)**: Complejidad O(n) en el peor caso.
        - Complejidad final: O(m * n log n) en el peor caso, con `m` iteraciones de registrar carrera.
*/

int main() {
    Championship championship;
    championship.cargarDatosDesdeArchivo("pilotos.txt");  // Complejidad: O(n)

    do {
        std::cout << "Opciones:\n";
        std::cout << "1. Registrar posiciones de carrera\n";
        std::cout << "2. Consultar información de un piloto por número\n";
        std::cout << "3. Salir\n";
        std::cout << "Elige una opción: ";
        
        int opcion;
        std::cin >> opcion;

        if (opcion == 1) {
            championship.displayPilots();  // Complejidad: O(n)
            championship.registrarPosicionesCarrera();  // Complejidad: O(n log n)
            championship.displayPilots();  // Complejidad: O(n)
        } else if (opcion == 2) {
            championship.consultarPilotoPorNumero();  // Complejidad: O(n) en el peor caso
        } else if (opcion == 3) {
            break;
        } else {
            std::cout << "Opción no válida.\n";
        }

    } while (true);

    championship.guardarDatosEnArchivo("pilotos.txt");  // Complejidad: O(n)
    std::cout << "Gracias por usar el sistema de registro de carreras.\n";
    return 0;
}
