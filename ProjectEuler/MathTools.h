#pragma once

#include <math.h>

class MathTools
{
private:
	static MathTools* _instance;

	MathTools();
public:
	
	virtual ~MathTools();

	// Instantiator for the singleton class
	static MathTools* getInstance()
	{
		if (NULL == _instance)
		{
			_instance = new MathTools();
		}
		
		return _instance;
	}

	// Math functions
	double Square(double x);
	long Factorial(int n);
	int DigitSum(long n);
};

