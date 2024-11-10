#pragma once
#include <sstream>
#include <iostream>
#include "Horario.h"
#include "Curso.h"
#include "Profesor.h"
#include "Periodo.h"
using namespace std;

class Grupo {
private:
    int numeroGrupo;
    int capacidadAlumnos;
    int cantidadAlumnos;
    Horario* horario;
    Curso* curso;
    Profesor* profesor;
    Periodo* periodo;
public:
    Grupo();
    Grupo(int, int, int, Horario*, Curso*,Periodo*);
    virtual ~Grupo();

    int getNumeroGrupo();
    int getCapacidadAlumnos();
    int getCantidadAlumnos();
    Horario* getHorario();
    Curso* getCurso();
    Profesor* getProfesor();
    Periodo* getPeriodo();
    void setNumeroGrupo(int);
    void setCapacidadAlumnos(int);
    void setCantidadAlumnos(int);
    void setHorario(Horario*);
    void setCurso(Curso*);
    void setProfesor(Profesor*);
    void setPeriodo(Periodo*);

    string toString() const;
};

