#include "huge.h"

using namespace Math;

huge::huge(std::vector<int> digits)
{
	_digits.assign(digits.begin(), digits.end());
	_n = _digits.size();
}

huge::huge(int * digits, int n)
{
	if (digits != NULL)
	{ 
		Assign(digits, n);
	}
	else
	{
		_n = 0;
	}
}

huge::huge(int num)
{
	Assign(num);
}

huge::~huge()
{
	_digits.clear();
}

void huge::Assign(int * digits, int n)
{
	_n = n;
	_digits.clear();
	for (int i = 0; i < n; ++n)
	{
		_digits.push_back(digits[i]);
	}
}

void huge::Assign(int num)
{
	_digits.clear();
	_n = 0;
	int rem = num;
	while (rem > 0)
	{
		int quo = rem / 10;
		int dif = rem - (quo * 10);
		_digits.push_back(dif);
		++_n;
		rem = quo;
	}
}

int huge::NumDigits() const
{
	return _n;
}

// Operators
int huge::operator()(int i) const
{
	if (_digits.size() < i)
	{
		return 0;
	}
	else if ((i < 0) || (i >= _n))
	{
		return 0;
	}
	else
	{
		return _digits[i];
	}
}

huge Math::huge::operator+(int n) const
{
	if (n == 0)
	{
		return (*this);
	}
	else
	{
		return (*this) + huge(n);
	}
}

huge Math::huge::operator+(huge n) const
{
	std::vector<int> result;

	return huge(0);
}
