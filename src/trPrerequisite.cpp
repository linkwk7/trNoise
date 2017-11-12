//This head file do not support by windows
//#include <execinfo.h>

#include "trPrerequisite.h"

namespace tr
{
	void Assert (int expression)
	{
		assert(expression);
	}
}
