#pragma once

#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <random>
#include <numeric>

/*
DRY

Don’t Repeat Yourself - nie powtarzaj się
Łatwiejsze utrzymywanie kodu

KISS

Jak najprosztszych i jak najbardziej zrozumiałych rozwiązań

YAGNI

Nie należy tworzyć kodu na przyszłość
Jeżeli w danym momencie kod jest zbędny, nie należy go pisać ani utrzymywać
*/

class ModelARX:public ObiektSISO 
{
private:
	std::vector<double> A; //wielomian A
	std::vector<double> B; //wielomian B
	int k; //rząd opóźnienia transportowego
	double e; //obiekt formujący rozkład normalny
	std::deque<double> ui; //pamięć (kolejka) dla sygnałów wejściowych
	std::deque<double> yi; //pamięć (kolejka) dla sygnałów wyjściowych
	std::deque<double> ki; //pamięć (kolejka) dla opóźnienia transportowego
	std::default_random_engine gen; //generator liczb losowych
	std::normal_distribution<double> dist; //rozkład normalny
	double noise(); //zakłucenie
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

