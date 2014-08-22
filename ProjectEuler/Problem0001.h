#pragma once

#include "ProblemBase.h"

namespace ProjectEuler
{
	class Problem0001 :
		public ProblemBase
	{
	protected:
		virtual void _initializeProblemStatement();
	public:
		Problem0001();
		virtual ~Problem0001();

		virtual void solve();
	};
}


