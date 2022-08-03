// C++ program to generate random numbers
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	// This program will create different sequence of
	// random numbers on every program run

	// Use current time as seed for random generator
	srand(time(0));

	for (int i = 0; i < 4; i++)
		cout << rand() << " ";

	return 0;
}
