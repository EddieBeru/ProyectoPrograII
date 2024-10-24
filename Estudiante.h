#pragma once
#include <sstream>
#include <iostream>
using namespace std;

class Estudiante {
private:
    string nombre;
    string id;
    string especialidad;
    int numero;
    string email;
    //entre otros
public:
    Estudiante();
    virtual ~Estudiante();

    string getNombre();
    string getId();
    string getEspecialidad();
    int getNumero();
    string getEmail();

    void setNombre(string);
    void setId(string);
    void setEspecialidad(string);
    void setNumero(int);
    void setEmail(string);

    string toString() const;
};

