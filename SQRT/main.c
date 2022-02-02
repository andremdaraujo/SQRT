#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PRECISION 0.000001f

float power(float base, uint32_t expoent)
{
	uint32_t i = 0;
	float result = 1.0;

	while (i < expoent)
	{
		result = result * base;
		i++;
	}
	return (result);
}

float f_abs(float num)
{
	float result = 0.0;

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

	float x = 65536;	// function variable: f(x) = sqrt(x)
	float s = x/2;	// solution/result

	float guess		= x/2;
	float quotient	= 0.0;
	float average	= 0.0;

	printf("Iteration: %2d; solution: %f \n", i, s);
	for (i = 1; (i <= n_iterations && (f_abs(x - (guess * guess)) > PRECISION) ); i++)
	{
		guess = (guess + x / guess)/2;
		printf("Iteration: %2d; g: %f \n", i, guess);
	}
	printf("sqrt(%f) = %f \n", x, guess);
	system("pause");
}