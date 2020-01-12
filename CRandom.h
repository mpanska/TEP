#ifndef CRANDOM_H
#define CRANDOM_H

#include "stdafx.h"

#define D_MIN 0.0;
#define D_MAX 30.0;
#define I_MIN 0;
#define I_MAX 30;


class CRandom
{
public:

	CRandom() { generator = mt19937(0);}
	CRandom(int iInstanceSeed) { generator = mt19937(iInstanceSeed); }
	~CRandom() {}

	int iGenerateInt(int i_min, int i_max){ return uniform_int_distribution<int>{i_min, i_max}(generator);};

	double dGenerateDouble(double d_min, double d_max){ return uniform_real_distribution<double>{d_min, d_max}(generator); };

private:
	
	mt19937 generator;
};

#endif 