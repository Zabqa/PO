#include <iostream>

#include "SygnalKonkretny.h"
#include "SygnalSinusoidalny.h"
#include "FalaProstokatna.h"
#include "SygnalTrojkatny.h"
#include "WhiteNoise.h"

int main()
{
	/*Sygnal* sygnal = new WhiteNoise(
		new SygnalTrojkatny(
		new SygnalTrojkatny(
		new FalaProstokatna(
		new FalaProstokatna(
		new SygnalSinusoidalny(
		new SygnalSinusoidalny(
		new SygnalKonkretny, 2.0, 5, 10, 20), 1.0, 5, 0, 30), 1.0, 10, 0.5, 10, 60), 2.0, 10, 0.7, 30, 60), 10, 0.8, 50), 10, 0.2, 60), 0.4);*/

	Sygnal* sygnal = new SygnalSinusoidalny(
		new SygnalSinusoidalny(
		new SygnalKonkretny, 2.0, 5, 10, 20), 1.0, 5, 0, 30);

	for (unsigned int t = 0; t < 30; ++t)
		std::clog << t << " " << sygnal->symuluj(t) << std::endl;

	delete sygnal;
	return 0;
}
