#pragma once
#include <sstream>
#include <iostream>
#include "Horario.h"
using namespace std;

class Grupo {
private:
    int numeroGrupo;
    int capacidadAlumnos;
    int cantidadAlumnos;
    Horario* horario;
public:
    Grupo();
    Grupo(int, int, int, Horario*);
    virtual ~Grupo();

    int getNumeroGrupo();
    int getCapacidadAlumnos();
    int getCantidadAlumnos();
    Horario* getHorario();

    void setNumeroGrupo(int);
    void setCapacidadAlumnos(int);
    void setCantidadAlumnos(int);
    void setHorario(Horario*);

    string toString() const;
};

