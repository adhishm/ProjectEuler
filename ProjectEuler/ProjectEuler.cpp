// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Problems.h"
#include "Testing.h"

ProjectEuler::ProblemBase* getProblem(int problemID);
void RunTests();

int _tmain(int argc, _TCHAR* argv[])
{
	char c;
	do
	{
		int problemID;

		cout << "Problem ID: ";	cin >> problemID;

		ProjectEuler::ProblemBase* pBase = getProblem(problemID);

		if (NULL != pBase)
		{
			pBase->solve();

			pBase->displayProblemStatement();
			pBase->displayAnswer();

			delete pBase;	pBase = NULL;
		}
		else
		{
			cout << endl << "Invalid problem id! Running tests." << endl;
			RunTests();
		}

		cout << "Again (y/N)? ";
		cin >> c;

	} while (c == 'y' || c == 'Y');
	
	return 0;
}

ProjectEuler::ProblemBase* getProblem(int problemID)
{
	switch (problemID)
	{
	case 1:
		return (new ProjectEuler::Problem0001());
		break;
	case 2:
		return (new ProjectEuler::Problem0002());
		break;
	case 3:
		return (new ProjectEuler::Problem0003());
		break;
	default:
		return ((ProjectEuler::ProblemBase*) NULL);
	}
}

void RunTests()
{
	Testing::TestMatrix();
}
