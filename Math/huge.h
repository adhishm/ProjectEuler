#pragma once

#include <vector>
#include <math.h>

namespace Math
{
	/**
	 * @brief Class to store and handle very large integers
	 */
	class huge
	{
	public:
		// Constructors / Destructor
		huge(std::vector<int> digits);
		huge(int* digits, int n);
		huge(int num);
		virtual ~huge();

		// Setters
		void Assign(int* digits, int n);
		void Assign(int num);

		// Getters
		int NumDigits() const;

		// Operators
		virtual int operator()(int i) const;
		virtual huge operator+(int n) const;
		virtual huge operator+(huge n) const;

	protected:
		// The vector of digits
		std::vector<int> _digits;
		int _n;
	};
}
