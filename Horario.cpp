#include "Horario.h"

Horario::Horario()
	:horaInicio(0), horaFinal(0), diasSemana(0){}


Horario::Horario(int horaIn, int horaFin, int diasSem)
	:horaInicio(horaIn), horaFinal(horaFin), diasSemana(diasSem) {}

Horario::~Horario(){}

int Horario::getHoraInicio() { return horaInicio; }
int Horario::getHoraFinal() {
	return horaFinal;
}
int Horario::getDiasSemana() { return diasSemana; }

void Horario::setHoraInicio(int HoraIn) {
	horaInicio = HoraIn;
}
void Horario::setHoraFinal(int HoraFin) {
	horaFinal = HoraFin;
}
void Horario::setDiasSemana(int DiasSem) {
	diasSemana = DiasSem;
}

string Horario::toString() const {
	stringstream s;
	s << "Hora Inicio: " << horaInicio << endl;
	s << "Hora Final: " << horaFinal << endl;
	s << "Dias Semana: " << diasSemana << endl;
	return s.str();
}