#include "stdafx.h"
#include "Problem0001.h"

using namespace ProjectEuler;

Problem0001::Problem0001()	
{
	_initializeProblemStatement();
}

Problem0001::~Problem0001()
{
}

void Problem0001::_initializeProblemStatement()
{
	_problemStatement = "If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.";
}

void Problem0001::solve()
{
	_answer = 0.0;

	for (int i = 3; i < 1000; ++i)
	{
		if (_math->IsMultiple(i, 3) || _math->IsMultiple(i, 5))
		{
			_answer += i;
		}
	}
}
