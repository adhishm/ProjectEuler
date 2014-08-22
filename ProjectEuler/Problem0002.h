#pragma once

#include "ProblemBase.h"

namespace ProjectEuler
{
	class Problem0002 :
		public ProblemBase
	{
	protected:
		virtual void _initializeProblemStatement();
	public:
		Problem0002();
		virtual ~Problem0002();

		virtual void solve();
	};
}


