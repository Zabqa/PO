#pragma once

class Sygnal {
public:
	virtual ~Sygnal() {}
	virtual double symuluj(int t) = 0;
};