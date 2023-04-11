#pragma once

#include "ModelARX.h"
#include <iostream>
#include <iomanip>

class Testy_ModelARX:public ModelARX
{
private:
	static void raportBleduSekwencji(std::vector<double>& spodz, std::vector<double>& fakt);
	static bool porownanieSekwencji(std::vector<double>& spodz, std::vector<double>& fakt);
	static void test_ModelARX_brakPobudzenia();
	static void test_ModelARX_skokJednostkowy_1();
	static void test_ModelARX_skokJednostkowy_2();
	static void test_ModelARX_skokJednostkowy_3();
public:
	static void test();
};

