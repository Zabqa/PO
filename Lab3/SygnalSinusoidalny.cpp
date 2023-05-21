#include "SygnalSinusoidalny.h"

SygnalSinusoidalny::SygnalSinusoidalny(Sygnal* sygnal, double amp, int okres, int start, int koniec) : Dekorator(sygnal), s_amp(amp), s_okres(okres), s_start(start), s_koniec(koniec) {
	x2 = sin(-12.56 / okres);
	x1 = sin(-6.28 / okres);
}

double SygnalSinusoidalny::symuluj(int t)
{
	if (czyAktywny(t))
	{
		x1 = x1 + x2;
		x2 = x1 - x2;
		x1 = x1 - x2;
		x1 = 2 * cos(6.28 / s_okres) * x2 - x1;
		return Dekorator::symuluj(t) + s_amp * x1;
	}
	else
		return Dekorator::symuluj(t);
}

bool SygnalSinusoidalny::czyAktywny(int t)
{
	return (t >= s_start && t <= s_koniec) ? true : false;
}