#pragma once
#include <sstream>
#include <iostream>
using namespace std;

class Curso {
private:
    string nombre;
    string id;
    int horas;
    float precio;
    bool estado;
    
public:
    Curso();
    Curso(string, string, int, float, bool);
    virtual ~Curso();

    string getNombre();
    string getId();
    int getHoras();
    float getPrecio();
    bool getEstado();

    void setNombre(string);
    void setId(string);
    void setHoras(int);
    void setPrecio(float);
    void setEstado(bool);

    string toString() const;
};

