#include "graphics\Context.h"
#include <iostream>

int main()
{
	Context context;
	context.init();

	double x = 0, y = 0;

	while (context.step())
	{
		std::cout << context.getKey(69) << std::endl;
	}

	context.term();
	return 0;
}