#pragma once
#include <sstream>
#include <iostream>
using namespace std;

class Profesor {
private:
    string nombre;
    string id;
    int numero;
    string email;
    string gradoAcademico;
public:
    Profesor();
    virtual ~Profesor();

    string getNombre();
    string getId();
    int getNumero();
    string getEmail();
    string getGradoAcademico();

    void setNombre(string);
    void setId(string);
    void setNumero(int);
    void setEmail(string);
    void setGradoAcademico(string);

    string toString() const;
};

