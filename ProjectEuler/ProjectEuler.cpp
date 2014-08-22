// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Problems.h"

ProjectEuler::ProblemBase* getProblem(int problemID);

int _tmain(int argc, _TCHAR* argv[])
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
		cout << endl << "Invalid problem id!" << endl;
	}
	
	
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
	default:
		return ((ProjectEuler::ProblemBase*) NULL);
	}
}
