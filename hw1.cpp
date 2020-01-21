//Zachary Leggett
//zjl0002
//hw1_zjl0002.cpp
//
//User inputs weight of mouse in kg, then the fatal amount of sweetner for mouse in kg, and finally the weight of friend in kg.
//The fatal amount of Coke for friend is calculated and outputted.
//
//I recieved no help.

#include <iostream>

using namespace std;

const double SODA_SWEETNER = 0.001;

int main() {

	double MouseWeight;
	double FatalSweetner;
	double FriendWeight;
	double FatalAmountHuman;

	cout << "Please input the weight of the mouse in kg " << endl;
	cin >> MouseWeight;

	cout << "Please input the fatal amount of sweetner for mouse in kg " << endl;
	cin >> FatalSweetner;

	cout << "Please input the weight of your dear frind in kg " << endl;
	cin >> FriendWeight;

	FatalAmountHuman = (FatalSweetner * FriendWeight) / (MouseWeight * SODA_SWEETNER);

	cout << "The fatal amount of Coke for your friend is: " << FatalAmountHuman << " kg" << endl;

	return 0;
}