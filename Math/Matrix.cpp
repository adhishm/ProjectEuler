#include "Matrix.h"

using namespace Math;

Matrix::Matrix()
{
}

Matrix::Matrix(unsigned int rows, unsigned int cols, double value)
{
	_rows = rows;
	_cols = cols;
	_allocate();
	SetValue(value);
}


Matrix::Matrix(unsigned int rows, unsigned int cols, double ** m)
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

void Matrix::SetValue(double value)
{
	for (unsigned int i = 0; i < _rows; ++i)
	{
		for (unsigned int j = 0; j < _cols; ++j)
		{
			_m[i][j] = value;
		}
	}
}

void Matrix::SetValue(double ** m)
{
	for (unsigned int i = 0; i < _rows; ++i)
	{
		for (unsigned int j = 0; j < _cols; ++j)
		{
			_m[i][j] = m[i][j];
		}
	}
}

unsigned int Matrix::Rows() const
{
	return _rows;
}

unsigned int Matrix::Cols() const
{
	return _cols;
}

Matrix Matrix::operator+(Matrix m2)
{
	Matrix result(Rows(), Cols());
	if ((m2.Rows() == Rows()) && (m2.Cols() == Cols()))
	{
		for (unsigned int i = 0; i < Rows(); ++i)
		{
			for (unsigned int j = 0; j < Cols(); ++j)
			{
				result(i, j) = _m[i][j] + m2(i, j);
			}
		}
	}
	return result;
}

Matrix Matrix::operator-(Matrix m2)
{
	Matrix result(Rows(), Cols());
	if ((m2.Rows() == Rows()) && (m2.Cols() == Cols()))
	{
		for (unsigned int i = 0; i < Rows(); ++i)
		{
			for (unsigned int j = 0; j < Cols(); ++j)
			{
				result(i, j) = _m[i][j] + m2(i, j);
			}
		}
	}
	return result;
}

double & Matrix::operator()(unsigned int i, unsigned int j)
{
	return _m[i][j];
}

void Matrix::_allocate()
{
	if (_m != NULL)
	{
		_free();
	}

	_m = new double*[_rows];
	for (unsigned int i = 0; i < _rows; ++i)
	{
		_m[i] = new double[_cols];
	}
}

void Matrix::_free()
{
	if (_m != NULL)
	{
		for (unsigned int i = 0; i < _rows; ++i)
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
