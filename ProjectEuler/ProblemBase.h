#pragma once

#include <string>
#include <iostream>
#include "MathTools.h"

using namespace std;

namespace ProjectEuler
{
	/*
	Base class for a problem
	*/
	class ProblemBase
	{
	protected:
		string _problemStatement;
		double _answer;
		MathTools* _math;

		virtual void _initializeProblemStatement();
	public:
		ProblemBase();
		virtual ~ProblemBase();

		string getProblemStatement();
		double getAnswer();

		void displayProblemStatement();
		virtual void displayAnswer();

		virtual void solve();
	};
}
