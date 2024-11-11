#ifndef FORMULA1_H
#define FORMULA1_H

#include <iostream>
#include <string>


class Pilot {
private:
    std::string name;
    std::string team;
    int points;

public:

    // Complejidad: O(1)
    Pilot();

    // Complejidad: O(1)
    Pilot(std::string, std::string, int);

    // Complejidad: O(1)
    std::string getName() const;

    // Complejidad: O(1)
    std::string getTeam() const;

    // Complejidad: O(1)
    int getPoints() const;

    // Complejidad: O(1)
    void updatePoints(int);
};


class PilotNode {
public:
    Pilot pilot;
    PilotNode* next;


    // Complejidad: O(1) en todos los casos
    PilotNode(Pilot p, PilotNode* n = nullptr) : pilot(p), next(n) {}
};


class LinkedList {
private:
    PilotNode* head;

    // Mejor caso: O(n log n), Caso promedio: O(n log n), Peor caso: O(n log n)
    PilotNode* mergeSort(PilotNode* head);

    // Mejor caso: O(n), Caso promedio: O(n), Peor caso: O(n)
    PilotNode* merge(PilotNode* left, PilotNode* right);

    // Mejor caso: O(1), Caso promedio: O(n), Peor caso: O(n)
    PilotNode* getMiddle(PilotNode* head);


public:

    LinkedList();
    ~LinkedList();

    // Mejor caso: O(1), Caso promedio: O(n), Peor caso: O(n)
    void addPilot(std::string name, std::string team, int points);

    // Mejor caso: O(1), Caso promedio: O(n), Peor caso: O(n)
    void updatePoints(int position, int points);

    // Mejor caso: O(n), Caso promedio: O(n), Peor caso: O(n)
    void displayPilots() const;

    // Complejidad: O(n log n) en todos los casos
    void sortPilots();

    // Mejor caso: O(1), Caso promedio: O(n), Peor caso: O(n)
    int size() const;

    friend class Championship;
};


class Championship {
private:
    LinkedList pilots;                
    int puntosPosicion[10];          
public:

    Championship();

    // Complejidad: O(n) en todos los casos, donde n es el número de pilotos agregados
    void agregarPilotosIniciales();

    // Mejor caso: O(n log n), Caso promedio: O(n log n), Peor caso: O(n log n)
    void registrarPosicionesCarrera();

    // Mejor caso: O(n), Caso promedio: O(n), Peor caso: O(n)
    void displayPilots() const;


    // Complejidad: O(1) en todos los casos
    bool preguntarOtraCarrera();

    // Mejor caso: O(1), Caso promedio: O(n), Peor caso: O(n)
    void consultarPilotoPorNumero() const;

    // Mejor caso: O(1) si el archivo está vacío, Caso promedio: O(n), Peor caso: O(n)
    bool cargarDatosDesdeArchivo(const std::string& nombreArchivo);

    // Mejor caso: O(n), Caso promedio: O(n), Peor caso: O(n)
    bool guardarDatosEnArchivo(const std::string& nombreArchivo) const;
};

#endif  // FORMULA1_H
