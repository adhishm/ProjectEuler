#include "stdafx.h"
#include "MathTools.h"

MathTools* MathTools::_instance = (MathTools*) NULL;

MathTools::MathTools()
{
}


MathTools::~MathTools()
{
}

double MathTools::Square(double x)
{
	return x*x;
}

long MathTools::Factorial(int n)
{
	if (n > 1)
	{
		return n * Factorial(n - 1);
	}
	else
	{
		return 1;
	}
}

int MathTools::DigitSum(long n)
{
	int s = 0;
	// Absolute value
	n = abs(n);

	while (n > 0)
	{
		s += n % 10;
		n /= 10;
	}

	return s;
}

bool MathTools::IsMultiple(int product, int factor)
{
	int remainder = product % factor;
	return (remainder == 0);
}

bool MathTools::IsPrime(int n)
{
	int p = 2;
	int r;

	while (p <= (n / 2))
	{
		r = n % p;
		if (r == 0)
		{
			return false;
		}
	}

	return true;
}
