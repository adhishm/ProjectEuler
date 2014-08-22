#include "stdafx.h"
#include "ProblemBase.h"

using namespace ProjectEuler;

ProblemBase::ProblemBase()
{
	_initializeProblemStatement();
	_answer = 0.0;
	_math = MathTools::getInstance();
}

ProblemBase::~ProblemBase()
{
}

void ProblemBase::_initializeProblemStatement()
{
	_problemStatement = "";
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
