
#include "RegulatorPID.h"
#include "ModelARX.h"
#include "Testy_RegulatorPID.h"

double object_simulation_one_iteration(RegulatorPID& reg, ModelARX& arx, double u);

using namespace std;

int main()
{
	Testy_RegulatorPID::test();

	std::cerr << "\n\n";

	ModelARX arx({ -0.4 }, { 0.6 }, 1, 0.0);
	RegulatorPID reg(0.5);
	//RegulatorPID reg(2.0);
	//RegulatorPID reg(0.5, 10.0);
	//RegulatorPID reg(0.4, 2.0);

	std::cerr << object_simulation_one_iteration(reg, arx, 0.0);
	for (int i = 0; i < 30; i++)
	{
		std::cerr << "\n" << object_simulation_one_iteration(reg, arx, 1.0);
	}
}

double object_simulation_one_iteration(RegulatorPID& reg, ModelARX& arx, double u)
{
	static double temp = 0.0;
	temp = arx.symuluj(reg.symuluj(u - temp));
	return temp;
}
