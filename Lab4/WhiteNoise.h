#pragma once

#include "Dekorator.h"
#include <random>

class WhiteNoise : public Dekorator{
public:
	WhiteNoise(Sygnal* sygnal, double ogr);
	double symuluj(int t);
private:
	bool czyOgraniczony(double x);
	double s_ogr;
	std::default_random_engine gen;
	std::uniform_real_distribution<> dist;
};