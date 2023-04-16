#pragma once

#include "ObiektSISO.h"

class RegulatorPID :public ObiektSISO
{
private:
	double k;
	double Ti;
	double Td;
	double Ci;
	double Ld;
	void setRegulatorConst(double& reg, double val);
public:
	void setGain(double k);
	void setIntegralConst(double Ti);
	void setDerivativeConst(double Td);
	virtual double symuluj(double u);
	RegulatorPID() = delete;
	RegulatorPID(double k, double Ti = 0.0, double Td = 0.0);
};