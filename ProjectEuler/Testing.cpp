#include "stdafx.h"
#include "Testing.h"


Testing::Testing()
{
}


Testing::~Testing()
{
}

void Testing::TestMatrix()
{
	Math::Matrix* mat = new Math::Matrix(3, 4);

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			(*mat)(i, j) = (Math::Matrix::data_type) i * j;
		}
	}

	mat->Show();
}
