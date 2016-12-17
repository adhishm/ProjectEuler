#pragma once
#include <stdlib.h>
namespace Math
{
	class Matrix
	{
	public:
		Matrix();
		Matrix(unsigned int rows, unsigned int cols, double value = 0.0);
		Matrix(unsigned int rows, unsigned int cols, double** m);
		virtual ~Matrix();

		virtual void SetValue(double value);
		virtual void SetValue(double** m);
		virtual unsigned int Rows() const;
		virtual unsigned int Cols() const;

		virtual Matrix operator+(Matrix m2);
		virtual Matrix operator-(Matrix m2);
		virtual double& operator()(unsigned int i, unsigned int j);

	protected:
		double** _m;
		unsigned int _rows;
		unsigned int _cols;

		void _allocate();
		void _free();
	};
}
