#include "formula1.h"
#include <iostream>

Pilot::Pilot() : name(""), team(""), points(0) {}

Pilot::Pilot(std::string _name, std::string _team, int _points) : name(_name), team(_team), points(_points) {}

std::string Pilot::getName() const { return name; }
std::string Pilot::getTeam() const { return team; }
int Pilot::getPoints() const { return points; }

void Pilot::updatePoints(int additionalPoints) {
    points += additionalPoints;
}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    PilotNode* current = head;
    while (current != nullptr) {
        PilotNode* next = current->next;
        delete current;
        current = next;
    }
}

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

int LinkedList::size() const {
    int count = 0;
    PilotNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

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

PilotNode* LinkedList::mergeSort(PilotNode* head) {
    if (!head || !head->next) return head;

    PilotNode* middle = getMiddle(head);
    PilotNode* nextOfMiddle = middle->next;

    middle->next = nullptr;

    PilotNode* left = mergeSort(head);
    PilotNode* right = mergeSort(nextOfMiddle);

    return merge(left, right);
}

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

void LinkedList::sortPilots() {
    head = mergeSort(head);
}

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

void Championship::agregarPilotosIniciales() {
    pilots.addPilot("Lance Stroll", "Aston Martin", 195);
    pilots.addPilot("Carlos Sainz", "Ferrari", 240);
    pilots.addPilot("Sergio Perez", "Red Bull Racing", 285);
    pilots.addPilot("Max Verstappen", "Red Bull Racing", 395);
    pilots.addPilot("Pierre Gasly", "Alpine", 215);
    pilots.addPilot("Charles Leclerc", "Ferrari", 290);
    pilots.addPilot("Valtteri Bottas", "Alfa Romeo", 170);
    pilots.addPilot("Lando Norris", "McLaren", 250);
    pilots.addPilot("Lewis Hamilton", "Mercedes", 320);
    pilots.addPilot("Esteban Ocon", "Alpine", 220);
    pilots.addPilot("Fernando Alonso", "Aston Martin", 275);
    pilots.addPilot("Oscar Piastri", "McLaren", 185);
    pilots.addPilot("George Russell", "Mercedes", 260);
}

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

void Championship::displayPilots() const {
    std::cout << "Lista de pilotos:\n";
    std::cout << "----------------------------------------\n";
    std::cout << "# | Piloto             | Equipo        | Puntos\n";
    std::cout << "----------------------------------------\n";
    pilots.displayPilots();
}

bool Championship::preguntarOtraCarrera() {
    char opcion;
    std::cout << "\n¿Quieres registrar otra carrera? (s/n): ";
    std::cin >> opcion;

    return opcion == 's' || opcion == 'S';
}

int main() {
    Championship championship;

    championship.agregarPilotosIniciales();

    do {
        std::cout << "Lista desordenada de pilotos:\n";
        championship.displayPilots();

        championship.registrarPosicionesCarrera();

        std::cout << "\nLista de pilotos después de registrar los puntos de la carrera:\n";
        championship.displayPilots();

    } while (championship.preguntarOtraCarrera());

    std::cout << "Gracias por usar el sistema de registro de carreras.\n";

    return 0;
}
