#include "Matrix.h"

using namespace Math;

Matrix::Matrix()
{
}

Math::Matrix::Matrix(unsigned int rows, unsigned int cols, double value)
{
	_rows = rows;
	_cols = cols;
	_allocate();
	SetValue(value);
}


Math::Matrix::Matrix(unsigned int rows, unsigned int cols, double ** m)
{
	_rows = rows;
	_cols = cols;
	_allocate();
	SetValue(m);
}

Matrix::~Matrix()
{
	_free();
}

void Math::Matrix::SetValue(double value)
{
	for (int i = 0; i < _rows; ++i)
	{
		for (int j = 0; j < _cols; ++j)
		{
			_m[i][j] = value;
		}
	}
}

void Math::Matrix::SetValue(double ** m)
{
	for (int i = 0; i < _rows; ++i)
	{
		for (int j = 0; j < _cols; ++j)
		{
			_m[i][j] = m[i][j];
		}
	}
}

unsigned int Math::Matrix::Rows() const
{
	return _rows;
}

unsigned int Math::Matrix::Cols() const
{
	return _cols;
}

Matrix Math::Matrix::operator+(Matrix m2)
{
	Matrix result(Rows(), Cols());
	if ((m2.Rows() == Rows()) && (m2.Cols() == Cols()))
	{
		for (int i = 0; i < Rows(); ++i)
		{
			for (int j = 0; j < Cols(); ++j)
			{
				result(i, j) = _m[i][j] + m2(i, j);
			}
		}
	}
	return result;
}

Matrix Math::Matrix::operator-(Matrix m2)
{
	Matrix result(Rows(), Cols());
	if ((m2.Rows() == Rows()) && (m2.Cols() == Cols()))
	{
		for (int i = 0; i < Rows(); ++i)
		{
			for (int j = 0; j < Cols(); ++j)
			{
				result(i, j) = _m[i][j] + m2(i, j);
			}
		}
	}
	return result;
}

double & Math::Matrix::operator()(unsigned int i, unsigned int j)
{
	return _m[i][j];
}

void Math::Matrix::_allocate()
{
	if (_m != NULL)
	{
		_free();
	}

	_m = new double*[_rows];
	for (int i = 0; i < _rows; ++i)
	{
		_m[i] = new double[_cols];
	}
}

void Math::Matrix::_free()
{
	if (_m != NULL)
	{
		for (int i = 0; i < _rows; ++i)
		{
			if (_m[i] != NULL)
			{
				delete _m[i];
				_m[i] = NULL;
			}
		}

		delete _m;
		_m = NULL;
	}
}
