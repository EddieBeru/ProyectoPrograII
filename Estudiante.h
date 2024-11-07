#pragma once
#include <sstream>
#include <iostream>
#include "ListaGrupo.h"

using namespace std;

class Estudiante {
private:
    char nombre[50];
    string id;
    string especialidad;
    int numero;
    string email;
    ListaGrupo* cursosMatriculados;
    //entre otros
public:
    Estudiante(string = "", string = "", string = "", int = 0, string = "");
    virtual ~Estudiante(); 

    string getNombre();
    string getId();
    string getEspecialidad();
    int getNumero();
    string getEmail();
    ListaGrupo* getGruposMatriculados();

    void setNombre(string);
    void setId(string);
    void setEspecialidad(string);
    void setNumero(int);
    void setEmail(string);

    void matricularGrupo(Grupo*);
    void anularGrupo(Grupo*);

    string toString() const;
};

