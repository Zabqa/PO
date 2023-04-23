#pragma once

#include <iostream>
#include <iomanip>
#include "vector"

class TESTY
{
public:
	static void raportBleduSekwencji(std::vector<double>& spodz, std::vector<double>& fakt);
	static bool porownanieSekwencji(std::vector<double>& spodz, std::vector<double>& fakt);
};