#include "stdafx.h"
#include "ProblemBase.h"

using namespace ProjectEuler;

ProblemBase::ProblemBase(string problemStatement)
{
	_problemStatement = problemStatement;
}

ProblemBase::~ProblemBase()
{
}

string ProblemBase::getProblemStatement()
{
	return _problemStatement;
}

double ProblemBase::getAnswer()
{
	return _answer;
}

void ProblemBase::displayProblemStatement()
{
	cout << endl << _problemStatement << endl;
}

void ProblemBase::displayAnswer()
{
	cout << endl << "Answer: " << _answer << endl;
}

void ProblemBase::solve()
{
	_answer = 0.0;
}
