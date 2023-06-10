#include "Dekorator.h"

Dekorator::Dekorator(Sygnal* sygnal) : s_sygnal(sygnal) {}

double Dekorator::symuluj(int t)
{
	return this->s_sygnal->symuluj(t);
}