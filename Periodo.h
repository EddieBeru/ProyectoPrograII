#pragma once
#include <sstream>
#include <iostream>
using namespace std;

class Periodo {
private:
	int periodo;
	string fechaInicial;
	string fechaFinal;
public:
	Periodo(int);
	int getPeriodo();
	string FechaInicial(int);
	string FechaFinal(int);
	string toString() const;
};

