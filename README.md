# SQRT

Code:
https://github.com/andremdaraujo/SQRT/blob/master/SQRT/main.c

Output example:
![alt text](https://github.com/andremdaraujo/SQRT/blob/master/EX09.PNG?raw=true)

André A. M. Araújo
2022/02/04

This program is a solution to exercise 09 of the Classpert Course Making Embedded Systems by Elecia White:

Choose a small algorithm to implement in different ways.  Describe when/why you might use each. You can choose any small algorithm.

The proposed program calculates the square root of an input using 2 methods. Comments throughout the code explain the details.

Developed in Visual Studio Community 2022

Square root calculation based on Newton's successive approximation method. This method has convergence assured and can be repeated until the desired precision is met. Reference: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots

Quake III Arena inverse square root, which is famous for being very fast as it only uses one floating point division. The 2nd iteration is optional to improve precision, but was commented out in the game code.
Reference: https://en.wikipedia.org/wiki/Fast_inverse_square_root


Newton's method has greater precision because it reiterates until the desired precision is met; but this might take many iterations, so precision has a direct impact on CPU use (and time to execute). However, to achieve even higher precision, double precision floating point must be used.

Quake III Arena method is less precise, but it takes a predetermined number of cycles to execute.

If an application needs a very responsive (quick) result and can tolerate lower precision, the second method is a good option. 

However, if higher precision is needed and execution time is no so critical, Newton's method can be used.
