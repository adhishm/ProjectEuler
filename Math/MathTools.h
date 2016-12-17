#pragma once

#include <math.h>
#include <vector>
#include <iterator>

using namespace std;

namespace Math
{
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
		bool IsMultiple(int product, int factor);
		bool IsPrime(int n);
		bool IsEven(long n);
		bool IsOdd(long n);
		long FibonacciTerm(int n);
		vector<long> FibonacciSeries(int n);
		vector<long> FibonacciSeriesLimit(long limit);
		bool IsFactor(long n, long f);
		vector<long> PrimeFactors(long double n);
		long MaxPrimeFactor(long double n);
		long Permutation(int n, int r);
		long Combination(int n, int r);
	};
}
