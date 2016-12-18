#pragma once
#include <stdlib.h>
#include <iostream>

namespace Math
{
	class Matrix
	{
	public:
		typedef unsigned int index_type;
		typedef double data_type;

		Matrix();
		Matrix(index_type rows, index_type cols, data_type value = 0.0);
		Matrix(index_type rows, index_type cols, data_type** m);
		virtual ~Matrix();

		virtual void SetValue(data_type value);
		virtual void SetValue(data_type** m);
		virtual index_type Rows() const;
		virtual index_type Cols() const;

		virtual Matrix Transpose() const;

		virtual Matrix operator+(Matrix m2);
		virtual Matrix operator-(Matrix m2);
		virtual Matrix operator*(Matrix m2);
		virtual data_type& operator()(index_type i, index_type j);

		void Show() const;

	protected:
		data_type** _m;
		index_type _rows;
		index_type _cols;

		void _allocate();
		void _free();
	};
}
