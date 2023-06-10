
#include "RegulatorPID.h"

void RegulatorPID::setRegulatorConst(double& reg, double val)
{
	reg = val > 0.0 ? val : 0.0;
}

void RegulatorPID::setGain(double k)
{
	setRegulatorConst(this->k, k);
}

void RegulatorPID::setIntegralConst(double Ti)
{
	setRegulatorConst(this->Ti, Ti);
}

void RegulatorPID::setDerivativeConst(double Td)
{
	setRegulatorConst(this->Td, Td);
}

RegulatorPID::RegulatorPID(double k, double Ti, double Td) : Ci(0.0), Ld(0.0)
{
	setGain(k);
	setIntegralConst(Ti);
	setDerivativeConst(Td);
}

double RegulatorPID::symuluj(double u)
{
	Ci += u;
	double temp = u - Ld;
	Ld = u;
	return k * u + (Ti > 0.0 ? Ci / Ti : 0.0) + (Td > 0.0 ? Td * temp : 0.0);
}
