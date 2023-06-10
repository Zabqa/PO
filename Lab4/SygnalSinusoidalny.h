#pragma once

#include "Dekorator.h"
#include <cmath>

class SygnalSinusoidalny : public Dekorator{
public:
	SygnalSinusoidalny(Sygnal* sygnal, double amp, int okres, int start, int koniec);
	double symuluj(int t);
private:
	bool czyAktywny(int t);
	int s_start;
	int s_koniec;
	double s_amp;
	int s_okres;
	double x1;
	double x2;
};