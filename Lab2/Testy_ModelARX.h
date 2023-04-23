#pragma once

#include "TESTY.h"
#include "ModelARX.h"

class Testy_ModelARX:public TESTY
{
private:
	static void test_ModelARX_brakPobudzenia();
	static void test_ModelARX_skokJednostkowy_1();
	static void test_ModelARX_skokJednostkowy_2();
	static void test_ModelARX_skokJednostkowy_3();
public:
	static void test();
};

