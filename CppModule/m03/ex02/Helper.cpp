#include "Helper.hpp"

// helper function
int	Helper::clamp(int val, int min, int max)
{
	if (val > max)
		return max;
	else if (val < min)
		return min;
	else
		return val;
}
