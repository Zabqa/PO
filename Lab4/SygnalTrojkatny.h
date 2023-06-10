#pragma once

#include "Dekorator.h"
#include <deque>

class SygnalTrojkatny : public Dekorator{
public:
	SygnalTrojkatny(Sygnal* sygnal, int okres, double wypelnienie, int op);
	double symuluj(int t);
private:
	double pobierzPrzesuniecie(double x);
	int s_okres;
	double s_wypelnienie;
	std::deque<double> s_op;
};