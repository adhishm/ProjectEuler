#include "huge.h"

using namespace Math;

huge::huge(std::vector<unsigned int> digits, bool positive)
{
	_digits.assign(digits.begin(), digits.end());
	_n = _digits.size();
	_positive = positive;
}

huge::huge(unsigned int * digits, int n, bool positive)
{
	if (digits != NULL)
	{ 
		Assign(digits, n, positive);
	}
	else
	{
		_n = 0;
		_positive = true;
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

void huge::Assign(unsigned int * digits, int n, bool positive)
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
	_positive = (num >= 0);
}

int huge::NumDigits() const
{
	return _n;
}

bool huge::IsPositive() const
{
	return _positive;
}

// Operators
/*
* @brief Get the ith digit of the number.
*/
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
	std::vector<unsigned int> _result;
	if (n.IsPositive() && this->IsPositive())
	{
		// Both are positive
		int nMax = std::max(n.NumDigits(), this->NumDigits());
		int carryOver = 0;

		for (int i = 0; i < nMax; ++i)
		{
			int r = carryOver + n(i) + (*this)(i);
			if (r > 10)
			{
				carryOver = r / 10;
				r = r - (10 * carryOver);
			}
			else
			{
				carryOver = 0;
			}
			_result.push_back(r);
		}

		return huge(_result);
	}

	return huge(0);
}

bool huge::operator==(huge n) const
{
	if (n.IsPositive() != _positive)
	{
		return false;
	}
	
	if (n.NumDigits() != _n)
	{
		return false;
	}

	for (int i = 0; i < _n; ++i)
	{
		if (n(i) != _digits[i])
		{
			return false;
		}
	}

	return true;
}

bool Math::huge::operator==(int n) const
{
	return ((*this) == huge(n));
}

bool huge::operator<(huge n) const
{
	

	return true;
}

