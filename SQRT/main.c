//
//	André A. M. Araújo
//	2022/02/04
//
//	This program is a solution to exercise 09 of the Classpert Course
//	Making Embedded Systems by Elecia White:
//
//	Choose a small algorithm to implement in different ways. 
//  Describe when/why you might use each. You can choose any small algorithm.
// 
//  The proposed program calculates the square root of an input using 2 methods.
//  Comments throughout the code explain the details.
// 
//  Developed in Visual Studio Community 2022
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define PRECISION		  0.0001	// Tolerance for solution against actual value
#define MAX_ITERATIONS	100			// Maximum iterations for Newton's method

// Absolute value calculation for floating point variable
float f_abs(float x)
{
	float y = 0.0;

	if (x < 0)
	{
		y = -x;
	}
	else
	{
		y = x;
	}
	return y;
}

// Absolut error calculation for floating point variables
float abs_error(float x, float y)
{
	float error = 0.0;

	error = f_abs(x - y);

	return error;
}

// Relative error calculation for floating point variables (x is the reference)
float rel_error(float x, float y)
{
	float error = 0.0;

	error = abs_error(x, y) / x;
	
	return error;
}

// Square root calculation based on Newton's successive approximation method.
// This method has convergence assured and can be repeated until the desired
// precision is met
// Reference: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
float newton_sqrt(float number)
{
	uint32_t i = 0;		// counter
	float guess = 1;	// intermediate estimate of solution
	float y = 0.0;		// solution

	printf("Newton's successive approximation method: \n");

	// Reiterate until desired precision is achieved or maximum iterations limit
	for (i = 1; (rel_error(number, guess * guess) > PRECISION && i <= MAX_ITERATIONS); i++)
	{
		guess = (guess + number / guess) / 2;
		printf("Iteration: %2d; guess: %f \n", i, guess);
	}

	y = guess;

	printf("\n");

	return y;
}

// Quake III Arena inverse square root, which is famous for being very fast
// as it only uses one floating point division. The 2nd iteration is optional
// to improve precision, but was commented out in the game code.
// Reference: https://en.wikipedia.org/wiki/Fast_inverse_square_root
// Actual code:
float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;								// evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);					// what the f***? 
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));		// 1st iteration
	y = y * ( threehalfs - ( x2 * y * y ) );	// 2nd iteration, this can be removed

	return y;
}

// Short program to calculate the square root of a real (float) number using
// Newton's and Quake III methods
//
// y = f(x) = sqrt(x)
//
void main(void)
{
	float x = 0.0;	// input
	float y = 0.0;	// output
	
	printf("Square root estimate: \n y = f(x) = sqrt(x) \n\n");
	printf("Enter floating point number (x): ");

	scanf_s("%f", &x);

	printf("\n");

	// Using Newton's method:
	y = newton_sqrt(x);

	printf("Newton\'s method: \n  y = sqrt(%f) = %f \n", x, y);
	printf("Absolut error: %f; Relative error: %f %% \n",
			abs_error(x, y * y),
			rel_error(x, y * y)*100);
	printf("    (x - y^2)         ");
	printf("    (x - y^2) / x \n\n");
	
	// Using Quake III inverse square root:
	y = 1 / Q_rsqrt(x);		// inverting again to get the sqrt

	printf("Newton\'s method: \n  y = sqrt(%f) = %f \n", x, y);
	printf("Absolut error: %f; Relative error: %f %% \n",
			abs_error(x, y * y),
			rel_error(x, y * y) * 100);
	printf("    (x - y^2)         ");
	printf("    (x - y^2) / x \n\n");

	system("pause");
}

//
// General comments about the algorithms:
// 
// Newton's method has greater precision because it reiterates until the desired
// precision is met; but this might take many iterations, so precision has a 
// direct impact on CPU use (and time to execute). However, to achieve even higher
// precision, double precision floating point must be used.
// 
// Quake III Arena method is less precise, but it takes a predetermined number
// of cycles to execute.
// 
// If an application needs a very responsive (quick) result and can tolerate
// lower precision, the second method is a good option. 
// 
// However, if higher precision is needed and execution time is no so critical,
// Newton's method can be used.
//