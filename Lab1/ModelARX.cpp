
#include "ModelARX.h"

double ModelARX::noise()
{
	return (e > 0) ? dist(gen) : 0;
}

double ModelARX::polynom(std::vector<double> &M, std::deque<double> &x)
{
	return std::inner_product(M.begin(), M.end(), x.begin(), 0.0);
}

void ModelARX::setVectorOfCoefficientsA(std::vector<double> A)
{
	this->A = A;
	yi.resize(A.size());
}

void ModelARX::setVectorOfCoefficientsB(std::vector<double> B)
{
	this->B = B;
	ui.resize(B.size());
}

void ModelARX::setDelay(int k)
{
	this->k = (k > 0) ? k : 1;
	ki.resize(this->k);
}

void ModelARX::setError(double e)
{
	this->e = (e >= 0) ? e : 0;
	if(e > 0) 
		dist = std::normal_distribution<double>(0, e);
}

double ModelARX::symuluj(double u)
{
	ki.push_front(u);
	ui.push_front(ki.back());
	ki.pop_back();
	ui.pop_back();
	yi.push_front(polynom(B, ui) - polynom(A, yi) + noise());
	yi.pop_back();
	return yi.front();
}

ModelARX::ModelARX(std::vector<double> A, std::vector<double> B, double k, double e)
{
	setVectorOfCoefficientsA(A);
	setVectorOfCoefficientsB(B);
	setDelay(k);
	setError(e);
}
