#include "SygnalTrojkatny.h"

SygnalTrojkatny::SygnalTrojkatny(Sygnal* sygnal, int okres, double wypelnienie, int op) : Dekorator(sygnal), s_okres(okres), s_wypelnienie(wypelnienie) {
	s_op.resize(op+1);
}

double SygnalTrojkatny::symuluj(int t) {
	return Dekorator::symuluj(t) + pobierzPrzesuniecie(
		((t % s_okres) < (s_wypelnienie * s_okres)) ? (t % s_okres) / (s_wypelnienie * s_okres) : (s_okres - (t % s_okres)) / ((1.0 - s_wypelnienie) * s_okres)
	);
}

double SygnalTrojkatny::pobierzPrzesuniecie(double x)
{
	s_op.push_back(x);
	s_op.pop_front();
	return s_op.front();
}