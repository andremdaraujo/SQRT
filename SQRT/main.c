#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PRECISION 0.001

double power(double base, uint32_t expoent)
{
	uint32_t i = 0;
	double result = 1.0;

	while (i < expoent)
	{
		result = result * base;
		i++;
	}
	return (result);
}

double f_abs(double num)
{
	double result = 0.0;

	if (num < 0)
	{
		result = -num;
	}
	else
	{
		result = num;
	}
	return result;
}

void main(void)
{
	uint32_t n_iterations = 100;
	uint32_t i = 0;	// counter

	double x = 2;	// function variable: f(x) = sqrt(x)
	double s = x/2;	// solution/result

	double guess		= 0.001;
	double result	= 0.0;

	// Square root calculation using Newton's successive approximation method
	// (based on: https://pages.mtu.edu/~shene/COURSES/cs201/NOTES/chap06/sqrt-1.html)
	for (i = 1; (i <= n_iterations && ( (f_abs(x - guess * guess)/x > PRECISION) ) ); i++)
	{
		guess = (guess + x / guess)/2;
		printf("Iteration: %2d; g: %f \n", i, guess);
	}
	result = guess;
	printf("sqrt(%f) = %f \n", x, result);
	system("pause");
}