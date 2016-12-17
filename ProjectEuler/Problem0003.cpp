#include "stdafx.h"
#include "Problem0003.h"

using namespace ProjectEuler;

Problem0003::Problem0003(void)
	: ProblemBase()
{
	_initializeProblemStatement();
}

void Problem0003::_initializeProblemStatement()
{
	_problemStatement = "The prime factors of 13195 are 5, 7, 13 and 29. What is the largest prime factor of the number 600851475143 ?";
}

Problem0003::~Problem0003(void)
{
}

void Problem0003::solve()
{
	long double n = 600851475143;
	_answer = _math->MaxPrimeFactor(n);
}
