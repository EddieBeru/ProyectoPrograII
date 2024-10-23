#pragma once
#include <sstream>
#include <iostream>
using namespace std;

class Horario {
private:
	int horaInicio;
	int horaFinal;
	int diasSemana;
public:
	Horario();
	virtual ~Horario();

	int getHoraInicio();
	int getHoraFinal();
	int getDiasSemana();
	void setHoraInicio(int);
	void setHoraFinal(int);
	void setDiasSemana(int);

	string toString() const;
};

