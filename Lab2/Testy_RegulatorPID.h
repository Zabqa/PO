#pragma once

#include "TESTY.h"
#include "RegulatorPID.h"

class Testy_RegulatorPID:public TESTY
{
private:
	static void test_RegulatorP_brakPobudzenia();
	static void test_RegulatorP_skokJednostkowy();
	static void test_RegulatorPI_skokJednostkowy_1();
	static void test_RegulatorPI_skokJednostkowy_2();
	static void test_RegulatorPID_skokJednostkowy();
public:
	static void test();
};