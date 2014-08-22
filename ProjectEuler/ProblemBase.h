#pragma once

#include <string>
#include <iostream>

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
	public:
		ProblemBase(string problemStatement);
		virtual ~ProblemBase();

		string getProblemStatement();
		double getAnswer();

		void displayProblemStatement();
		void displayAnswer();

		virtual void solve();
	};
}
