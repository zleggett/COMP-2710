//Zachary Leggett
//Simple.cpp
//
//User inputs desired amount of positive numbers (less than 10) for standard deviation and factorial.
//User then inputs series of numbers as specified above. Standard deviation of all entered
//numbers is outputted as well as fatorial of amount of numbers entered.
//
//Used factorial.cpp and standard.cpp files from Canvas to develop calculateSD and factorial functions as well as main

#include <iostream>
#include <cmath>
using namespace std;

float calculateSD(float data[], int n);
int factorial(int n);

//Used the main() format from factorial.cpp and standard.cpp
int main()
{
	int n;
	int i;
	float data[10];

	cout << "How many positive numbers (must be less than 10) do you want to calculate: ";
	cin >> n;

	cout << "Please enter " << n << " elements: ";
	for (i = 0; i < n; ++i) {
		cin >> data[i];
	}

	cout << endl << "Standard Deviation = " << calculateSD(data, n) << endl;
	cout << "Factorial of " << n << " = " << factorial(n) << endl;

	return 0;
}

//Based on standard.cpp file
float calculateSD(float data[], int n)
{
	float sum = 0.0, mean, standardDeviation = 0.0;

	int i;

	for (i = 0; i < n; ++i) {
		sum += data[i];
	}

	mean = sum / n;

	for (i = 0; i < n; ++i) {
		standardDeviation += pow(data[i] - mean, 2);
	}

	return sqrt(standardDeviation / n);
}

//Based on factorial.cpp file
int factorial(int n)
{
	int i, factorial = 1;

	for (i = 1; i <= n; ++i) {
		factorial *= i;   // factorial = factorial * i;
	}

	return factorial;
}