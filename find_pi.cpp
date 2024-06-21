
// Credits to the WITS HPC group 2024 for the serialised version of this code

#include <iostream>
#include <omp.h>
#include <math.h>
#include <climits>
#include <iomanip>
static unsigned long num_steps = 10000000000;
long double step;
using namespace std;
int main()
{
	unsigned long i;
	long double x, pi, sum = 0.0;

	step = 1.0 / (long double)num_steps;
	std::cout << "Step =\t" << std::setprecision(19) << step << std::endl;

	omp_set_num_threads(16);

#pragma omp parallel for reduction(+ : sum) private(x)
	for (i = 0; i < num_steps; i++)
	{
		x = (i + 0.5) * step;
		sum += 4.0 / (1.0 + x * x);
	}

	pi = step * sum;
	std::cout << "Calculated Pi =\t" << std::setprecision(19) << pi << std::endl
			  << "Actual Pi =\t" << M_PIl << std::endl
			  << "Difference =\t" << M_PIl - pi << std::endl;
}
