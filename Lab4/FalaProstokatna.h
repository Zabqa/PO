#pragma once

#include "Dekorator.h"

class FalaProstokatna : public Dekorator {
public:
	FalaProstokatna(Sygnal* sygnal, double amp, int okres, double wypelnienie, int start, int koniec);
	double symuluj(int t);
private:
	bool czyAktywny(int t);
	int s_start;
	int s_koniec;
	double s_amp;
	int s_okres;
	double s_wypelnienie;
};