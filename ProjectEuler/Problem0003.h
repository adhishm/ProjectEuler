#pragma once
#include "problembase.h"
namespace ProjectEuler
{
	class Problem0003 :
		public ProblemBase
	{
	protected:
		virtual void _initializeProblemStatement ();
	public:
		Problem0003(void);
		virtual ~Problem0003(void);

		virtual void solve();
	};
}
