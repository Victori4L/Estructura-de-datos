#ifndef FORMULA1_H
#define FORMULA1_H

#include <vector>
#include <string>

class Pilot {
private:
    std::string name;
    std::string team;
    int points;

public:
    Pilot();  // Constructor por defecto
    Pilot(std::string, std::string, int);  // Constructor parametrizado
    std::string getName() const;
    std::string getTeam() const;
    int getPoints() const;
    void updatePoints(int);
};

class Championship {
private:
    std::vector<Pilot> pilots;

public:
    Championship();
    void agregarPilotosIniciales();
    void registrarPuntosCarrera();
    void ordenaPorPuntos();
    void displayPilots() const;

    // Merge sort functions
    void mergeSort(int, int);
    void merge(int, int, int);
};

#endif
