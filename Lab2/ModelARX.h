#pragma once

#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <random>
#include <numeric>

/*
DRY

Don’t Repeat Yourself - nie powtarzaj siê
£atwiejsze utrzymywanie kodu

KISS

Jak najprosztszych i jak najbardziej zrozumia³ych rozwi¹zañ

YAGNI

Nie nale¿y tworzyæ kodu na przysz³oœæ
Je¿eli w danym momencie kod jest zbêdny, nie nale¿y go pisaæ ani utrzymywaæ
*/

class ModelARX:public ObiektSISO 
{
private:
	std::vector<double> A; //wielomian A
	std::vector<double> B; //wielomian B
	int k; //rz¹d opóŸnienia transportowego
	double e; //obiekt formuj¹cy rozk³ad normalny
	std::deque<double> ui; //pamiêæ (kolejka) dla sygna³ów wejœciowych
	std::deque<double> yi; //pamiêæ (kolejka) dla sygna³ów wyjœciowych
	std::deque<double> ki; //pamiêæ (kolejka) dla opóŸnienia transportowego
	std::default_random_engine gen; //generator liczb losowych
	std::normal_distribution<double> dist; //rozk³ad normalny
	double noise(); //zak³ucenie
	double polynom(std::vector<double> &M, std::deque<double> &x); //wielomian
public:
	void setVectorOfCoefficientsA(std::vector<double> A);
	void setVectorOfCoefficientsB(std::vector<double> B);
	void setDelay(int k);
	void setError(double e);
	virtual double symuluj(double u);
	ModelARX() = delete;
	ModelARX(std::vector<double> A, std::vector<double> B, double k = 1, double e = 0.0);
};

