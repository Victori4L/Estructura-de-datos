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
    Pilot();
    Pilot(std::string, std::string, int);
    std::string getName() const;
    std::string getTeam() const;
    int getPoints() const;
    void updatePoints(int);
};

class PilotNode {
public:
    Pilot pilot;
    PilotNode* next;

    PilotNode(Pilot p, PilotNode* n = nullptr) : pilot(p), next(n) {}
};

class LinkedList {
private:
    PilotNode* head;

    PilotNode* mergeSort(PilotNode* head);
    PilotNode* merge(PilotNode* left, PilotNode* right);
    PilotNode* getMiddle(PilotNode* head);

public:
    LinkedList();
    ~LinkedList();
    void addPilot(std::string name, std::string team, int points);
    void updatePoints(int position, int points);
    void displayPilots() const;
    void sortPilots();
    int size() const;
};

class Championship {
private:
    LinkedList pilots;
    int puntosPosicion[10];

public:
    Championship();
    void agregarPilotosIniciales();
    void registrarPosicionesCarrera();
    void displayPilots() const;
    bool preguntarOtraCarrera();
};

#endif
