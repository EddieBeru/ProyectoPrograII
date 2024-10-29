#include "Periodo.h"

Periodo::Periodo(int per) {
	periodo = per;
	fechaInicial = FechaInicial(per);
	fechaFinal = FechaFinal(per);
}
string Periodo::FechaInicial(int per) {
	stringstream s;
	switch (per) {
	case 1:
		s << "Enero";
		break;
	case 2:
		s << "Abril" ;
		break;
	case 3:
		s << "Julio" ;
		break;
	case 4:
		s << "Octubre" ;
		break;
	}
	return s.str();
}
string Periodo::FechaFinal(int per) {
	stringstream s;
	switch (per) {
	case 1:
		s << "Marzo" ; break;
	case 2:
		s << "Junio" ; break;
	case 3:
		s << "Setiembre" ; break;
	case 4:
		s << "Diciembre" ; break;
	}
	return s.str();
}
string Periodo::toString() const {
	stringstream ss;
	ss << "Periodo: " <<periodo<<"\t(De: "<<fechaInicial<<" hasta "<<fechaFinal<<")" <<endl;
	return ss.str();
}