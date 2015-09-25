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
		++p;
	}

	return true;
}

bool MathTools::IsEven(long n)
{
	long remainder = n % 2;
	return (remainder == 0);
}

bool MathTools::IsOdd(long n)
{
	long remainder = n % 2;
	return (remainder != 0);
}

long MathTools::FibonacciTerm(int n)
{
	if (n < 1)
	{
		return 0;
	}

	if ((n == 1) || (n == 2))
	{
		return 1;
	}

	long a = 1;
	long b = 1;
	long c;

	for (int i = 3; i <= n; ++i)
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

vector<long> MathTools::FibonacciSeries(int n)
{
	if (n < 1)
	{
		vector<long> f(1,0);
		return f;
	}

	vector<long> f(n, 1);

	if (n > 2)
	{
		for (int i = 3; i <= n; ++i)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
	}

	return f;
}

// Returns a vector of integers of the Fibonacci series smaller than the limit given.
vector<long> MathTools::FibonacciSeriesLimit(long limit)
{
	if (limit < 1)
	{
		vector<long> f(1, 0);
		return f;
	}

	vector<long> f(2, 1);
	long t;
	int n = 2;

	while (f.back() < limit)
	{
		f.push_back(f[n - 1] + f[n - 2]);
		++n;
	}

	if (f.back() > limit)
	{
		f.pop_back();
	}

	return f;
}

// Returns a boolean flag indicating if f is a factor of n.
bool MathTools::IsFactor(long n, long f)
{
	return ( (n%f) == 0 );
}

// This function returns a vector of prime factors for the integer n given.
vector<long> MathTools::PrimeFactors(long n)
{
	vector<long> factors;
	factors.clear();
	for (int i=2; i<(n/2); ++i)
	{
		if (IsPrime(i))
		{
			if (IsFactor(n, i))
			{
				factors.push_back(i);
			}
		}
	}

	return factors;
}

long MathTools::Permutation(int n, int r)
{
	if ((0==r) || (n==r))
	{
		return 1;
	}
	
	return Factorial(n) / Factorial(n-r);
}

long MathTools::Combination(int n, int r)
{
	if ((0==r) || (0==n) || (n==r))
	{
		return 1;
	}
	
	return (Permutation(n,r)/Factorial(r));
}
