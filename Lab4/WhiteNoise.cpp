#include "WhiteNoise.h"

WhiteNoise::WhiteNoise(Sygnal* sygnal, double ogr) : Dekorator(sygnal), s_ogr(ogr) {
	dist = std::uniform_real_distribution<>(-1, 1);
}

double WhiteNoise::symuluj(int t) {
	double noise = dist(gen);
	if (czyOgraniczony(noise))
		return Dekorator::symuluj(t);
	else
		return Dekorator::symuluj(t)+ noise;
}

bool WhiteNoise::czyOgraniczony(double x)
{
	return (x >= s_ogr || x <= -s_ogr) ? true : false;
}