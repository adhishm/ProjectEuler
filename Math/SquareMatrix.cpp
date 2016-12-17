#include "SquareMatrix.h"

using namespace Math;

SquareMatrix::SquareMatrix()
	: Matrix()
{
}

SquareMatrix::SquareMatrix(unsigned int size, double value)
	: Matrix(size, size, value)
{
}


SquareMatrix::~SquareMatrix()
{
}

unsigned int SquareMatrix::Size() const
{
	return Rows();
}

double SquareMatrix::Determinant() const
{
	double det = 0.0;

	if (Size() == 1)
	{
		return _m[0][0];
	}
	else 
	{
		for (unsigned int i = 0; i < Size(); ++i)
		{
			SquareMatrix cofactor = (SquareMatrix) Cofactor(0, i);
			det += _m[0][i] * cofactor.Determinant();
		}
	}

	return det;
}

SquareMatrix SquareMatrix::Cofactor(unsigned int i, unsigned int j) const
{
	SquareMatrix result(Size() - 1);

	int ii = i + 1;
	int jj = j + 1;

	int i_count = 0;
	int j_count = 0;

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
