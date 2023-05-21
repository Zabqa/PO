#pragma once

#include "Sygnal.h"

class Dekorator : public Sygnal{
public:
	Dekorator(Sygnal* sygnal);
	double symuluj(int t);
private:
	Sygnal* s_sygnal;
};