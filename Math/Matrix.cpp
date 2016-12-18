#include "Matrix.h"

using namespace Math;

Matrix::Matrix()
{
}

Matrix::Matrix(index_type rows, index_type cols, data_type value)
{
	_rows = rows;
	_cols = cols;
	_allocate();
	SetValue(value);
}


Matrix::Matrix(index_type rows, index_type cols, data_type ** m)
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

void Matrix::SetValue(data_type value)
{
	for (index_type i = 0; i < _rows; ++i)
	{
		for (index_type j = 0; j < _cols; ++j)
		{
			_m[i][j] = value;
		}
	}
}

void Matrix::SetValue(data_type ** m)
{
	for (index_type i = 0; i < _rows; ++i)
	{
		for (index_type j = 0; j < _cols; ++j)
		{
			_m[i][j] = m[i][j];
		}
	}
}

Matrix::index_type Matrix::Rows() const
{
	return _rows;
}

Matrix::index_type Matrix::Cols() const
{
	return _cols;
}

Matrix Matrix::Transpose() const
{
	Matrix result(Cols(), Rows());

	for (index_type i = 0; i < Rows(); ++i)
	{
		for (index_type j = 0; j < Cols(); ++j)
		{
			result(j, i) = _m[i][j];
		}
	}

	return result;
}

Matrix Matrix::operator+(Matrix m2)
{
	Matrix result(Rows(), Cols());
	if ((m2.Rows() == Rows()) && (m2.Cols() == Cols()))
	{
		for (index_type i = 0; i < Rows(); ++i)
		{
			for (index_type j = 0; j < Cols(); ++j)
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
		for (index_type i = 0; i < Rows(); ++i)
		{
			for (index_type j = 0; j < Cols(); ++j)
			{
				result(i, j) = _m[i][j] + m2(i, j);
			}
		}
	}
	return result;
}

Matrix Matrix::operator*(Matrix m2)
{
	Matrix result(Rows(), m2.Cols());

	if (Cols() == m2.Rows())
	{
		for (Matrix::index_type i = 0; i < Rows(); ++i)
		{
			for (Matrix::index_type j = 0; j < m2.Cols(); ++j)
			{
				for (Matrix::index_type k = 0; k < Cols(); ++k)
				{
					result(i, j) += _m[i][k] * m2(k, j);
				}
			}
		}
	}

	return result;
}

Matrix::data_type & Matrix::operator()(index_type i, index_type j)
{
	return _m[i][j];
}

void Math::Matrix::Show() const
{
	for (index_type i = 0; i < Rows(); ++i)
	{
		for (index_type j = 0; j < Cols(); ++j)
		{
			std::cout << _m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix::_allocate()
{
	if (_m != NULL)
	{
		_free();
	}

	_m = new data_type*[_rows];
	for (index_type i = 0; i < _rows; ++i)
	{
		_m[i] = new data_type[_cols];
	}
}

void Matrix::_free()
{
	if (_m != NULL)
	{
		for (index_type i = 0; i < _rows; ++i)
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
