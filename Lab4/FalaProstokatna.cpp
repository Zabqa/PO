#include "FalaProstokatna.h"

FalaProstokatna::FalaProstokatna(Sygnal* sygnal, double amp, int okres, double wypelnienie, int start, int koniec) : Dekorator(sygnal), s_amp(amp), s_okres(okres), s_wypelnienie(wypelnienie), s_start(start), s_koniec(koniec) {}

double FalaProstokatna::symuluj(int t) {
	if (czyAktywny(t))
		return Dekorator::symuluj(t) + (((t % s_okres) < (s_wypelnienie * s_okres)) ? s_amp : 0.0);
	else
		return Dekorator::symuluj(t);
}

bool FalaProstokatna::czyAktywny(int t)
{
	return (t >= s_start && t <= s_koniec) ? true : false;
}