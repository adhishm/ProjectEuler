#pragma once

#include <vector>
#include <algorithm>
#include <math.h>

namespace Math
{
	/**
	 * @brief Class to store and handle very large integers.
	 * @details The digits of the integer are stored in a vector container
	 *          with the first digit in the first slot, etc.
	 */
	class huge
	{
	public:
		// Constructors / Destructor
		huge(std::vector<unsigned int> digits, bool positive = true);
		huge(unsigned int* digits, int n, bool positive = true);
		huge(int num);
		virtual ~huge();

		// Setters
		void Assign(unsigned int* digits, int n, bool positive = true);
		void Assign(int num);

		// Getters
		int NumDigits() const;
		bool IsPositive() const;

		// Operators
		/*
		 * @brief Get the ith digit of the number.
		 */
		virtual int operator()(int i) const;
		// Addition
		virtual huge operator+(int n) const;
		virtual huge operator+(huge n) const;
		// Add to
		virtual void operator+=(int n);
		virtual void operator+=(huge n);
		// Comparison
		virtual bool operator==(huge n) const;
		virtual bool operator==(int n) const;
		virtual bool operator<(huge n) const;
		virtual bool operator<=(huge n) const;
		virtual bool operator>(huge n) const;
		virtual bool operator>=(huge n) const;

	protected:
		// The vector of digits
		std::vector<unsigned int> _digits;
		int _n;
		bool _positive;
	};
}
