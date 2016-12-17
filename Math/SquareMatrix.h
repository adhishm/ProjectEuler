#pragma once
#include "Matrix.h"

namespace Math
{
	class SquareMatrix :
		public Matrix
	{
	public:
		SquareMatrix();
		SquareMatrix(Matrix::index_type size, Matrix::data_type value = 0.0);
		virtual ~SquareMatrix();

		SquareMatrix Cofactor(Matrix::index_type i, Matrix::index_type j) const;
		SquareMatrix CofactorMatrix() const;
		double Determinant() const;
		Matrix::index_type Size() const;
		bool IsInvertible() const;
		SquareMatrix Inverse() const;
	};
}
