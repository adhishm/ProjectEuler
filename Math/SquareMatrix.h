#pragma once
#include "Matrix.h"

namespace Math
{
	class SquareMatrix :
		public Matrix
	{
	public:
		SquareMatrix();
		SquareMatrix(unsigned int size, double value = 0.0);
		virtual ~SquareMatrix();

		SquareMatrix Cofactor(unsigned int i, unsigned int j) const;
		double Determinant() const;
		unsigned int Size() const;
	};
}
