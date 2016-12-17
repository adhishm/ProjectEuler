#include "SquareMatrix.h"

using namespace Math;

SquareMatrix::SquareMatrix()
	: Matrix()
{
}

SquareMatrix::SquareMatrix(Matrix::index_type size, Matrix::data_type value)
	: Matrix(size, size, value)
{
}


SquareMatrix::~SquareMatrix()
{
}

Matrix::index_type SquareMatrix::Size() const
{
	return Rows();
}

bool SquareMatrix::IsInvertible() const
{
	return (Determinant() == 0.0);
}

Matrix::data_type SquareMatrix::Determinant() const
{
	Matrix::data_type det = 0.0;

	if (Size() == 1)
	{
		return _m[0][0];
	}
	else
	{
		for (Matrix::index_type i = 0; i < Size(); ++i)
		{
			SquareMatrix cofactor = (SquareMatrix)Cofactor(0, i);
			det += _m[0][i] * cofactor.Determinant();
		}
	}

	return det;
}

SquareMatrix SquareMatrix::Cofactor(Matrix::index_type i, Matrix::index_type j) const
{
	SquareMatrix result(Size() - 1);

	Matrix::index_type ii = i + 1;
	Matrix::index_type jj = j + 1;

	Matrix::index_type i_count = 0;
	Matrix::index_type j_count = 0;

	while (ii != i)
	{
		while (jj != j)
		{
			result(i_count, j_count) = _m[ii][jj];
			++jj;
			if (jj == Size())
			{
				jj = 0;
			}
			++j_count;
		}
		++ii;
		if (ii == Size())
		{
			ii = 0;
		}
		++i_count;
	}

	return result;
}

SquareMatrix SquareMatrix::Inverse() const
{
	SquareMatrix result(Size());

	Matrix::data_type det = Determinant();

	if (det == 0.0)
	{
		Matrix cft = CofactorMatrix().Transpose();

		for (Matrix::index_type i = 0; i < Size(); ++i)
		{
			for (Matrix::index_type j = 0; j < Size(); ++j)
			{
				result(i, j) = cft(i, j) / det;
			}
		}
	}

	return result;
}

SquareMatrix SquareMatrix::CofactorMatrix() const
{
	SquareMatrix result(Size());

	for (Matrix::index_type i = 0; i < Size(); ++i)
	{
		for (Matrix::index_type j = 0; j < Size(); ++j)
		{
			result(i, j) = Cofactor(i, j).Determinant();
		}
	}

	return result;
}
