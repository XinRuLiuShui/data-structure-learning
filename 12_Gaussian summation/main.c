#include <stdio.h>
#include <stdlib.h>

int Gaussian_sum(int value)
{
	if (value == 1)
	{
		return value;
	}
	return  value + Gaussian_sum(value - 1);
}

int main()
{
	printf("%d", Gaussian_sum(4));
}