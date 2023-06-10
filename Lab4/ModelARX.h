#pragma once

#include "ObiektSISO.h"
#include <vector>
#include <deque>
#include <random>
#include <numeric>

/*
DRY

Don�t Repeat Yourself - nie powtarzaj si�
�atwiejsze utrzymywanie kodu

KISS

Jak najprosztszych i jak najbardziej zrozumia�ych rozwi�za�

YAGNI

Nie nale�y tworzy� kodu na przysz�o��
Je�eli w danym momencie kod jest zb�dny, nie nale�y go pisa� ani utrzymywa�
*/

class ModelARX:public ObiektSISO 
{
private:
	std::vector<double> A; //wielomian A
	std::vector<double> B; //wielomian B
	int k; //rz�d op�nienia transportowego
	double e; //obiekt formuj�cy rozk�ad normalny
	std::deque<double> ui; //pami�� (kolejka) dla sygna��w wej�ciowych
	std::deque<double> yi; //pami�� (kolejka) dla sygna��w wyj�ciowych
	std::deque<double> ki; //pami�� (kolejka) dla op�nienia transportowego
	std::default_random_engine gen; //generator liczb losowych
	std::normal_distribution<double> dist; //rozk�ad normalny
	double noise(); //zak�ucenie
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

