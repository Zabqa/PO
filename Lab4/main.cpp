#include "RegulatorPID.h"
#include "ModelARX.h"
#include "SygnalKonkretny.h"
#include "SygnalSinusoidalny.h"
#include "KonfiguracjaProgramu.h"


double object_simulation_one_iteration(RegulatorPID& reg, ModelARX& arx, double u);


int main(int argc, const char** argv)
{
	//boost_1_82_0
	// 
	//przyk³ad parametrów podawanych w momencie uruchomienia programu:
	//--A -0.4 0.2  --B 0.6 0.3 --k 2 --e 0 --K 4 --Ti 0 --Td 0 --okres 5 --start 5 --koniec 35 --amp 2

	std::string projectPath = boost::filesystem::current_path().string();
	std::string filePath = projectPath + "/settings/ustawienie.json";
	std::cerr << "Przyk³adowa œcie¿ka do zapisu: " << filePath << std::endl;

	std::vector<double> A;
	std::vector<double> B;
	int k;
	int okres;
	int start;
	int koniec;
	double e;
	double K;
	double Ti;
	double Td;
	double amp;

	KonfiguracjaProgramu ustawienia(filePath);

	if (ustawienia.wczytajKonfiguracje(argc, argv, A, B, k, e, K, Ti, Td, amp, okres, start, koniec)) 
	{
		std::cerr <<"\n\n";

		ModelARX arx(A, B, k, e);
		RegulatorPID reg(K, Ti, Td);

		std::cerr << object_simulation_one_iteration(reg, arx, 0.0);
		for (unsigned int i = 0; i < 31; i++)
		{
			std::cerr << "\n" << object_simulation_one_iteration(reg, arx, 1.0);
		}

		std::cerr << "\n\n";

		Sygnal* sygnal = new SygnalSinusoidalny(
				new SygnalKonkretny, K, okres, start, koniec);

		for (unsigned int t = 0; t < 41; ++t)
			std::cerr << t << " " << sygnal->symuluj(t) << std::endl;

		delete sygnal;

		if (ustawienia.zapiszKonfiguracje())
		{
			std::cerr << "\nPomyœlnie zapisano ustawienia" << std::endl;
		}
	}
	else 
	{
		std::cerr << "\nB³¹d odczytu ustawieñ" << std::endl;
	}

	return 0;
}

double object_simulation_one_iteration(RegulatorPID& reg, ModelARX& arx, double u)
{
	static double temp = 0.0;
	temp = arx.symuluj(reg.symuluj(u - temp));
	return temp;
}