/*
* Zachary Leggett
* zjl0002
* hw4_zjl0002.cpp
*
* This program takes two input files with integers sorted in ascending order.
* These integers are combined, sorted, and outputted to output.txt. 
*
* Compile using "g++ hw4_zjl0002.cpp"
* Run using "./a.out"
*
* Used www.geeksforgeeks.org/merge-two-sorted-arrays to create sort method.
*/

#include <fstream>
#include <iostream>
#include <cstdlib> 
using namespace std;

int readfile(int inputArray[], ifstream& instream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size);

const int MAX_SIZE = 100;

int main() {
	string file1, file2;
	ifstream input1, input2;
	int array1size, array2size, outputsize;
	int Array1[MAX_SIZE];
	int Array2[MAX_SIZE];
	int output[MAX_SIZE];

	cout << "*** Welcome to Zachary Leggett's sorting program ***" << endl;
	
	cout << "Enter the first input file name: ";
	cin >> file1;
	input1.open(file1.c_str());
	array1size = readfile(Array1, input1);

	cout << "The list of " << array1size << " numbers in file " << file1 << " is: " << endl;
	for (int i = 0; i < array1size; i++) {
		cout << Array1[i] << endl;
	}
	input1.close();

	cout << endl << "Enter the second input file name: ";
	cin >> file2;
	input2.open(file2.c_str());
	array2size = readfile(Array2, input2);

	cout << "The list of " << array2size << " numbers in file " << file2 << " is: " << endl;
	for (int i = 0; i < array2size; i++) {
		cout << Array2[i] << endl;
	}
	input2.close();

	outputsize = sort(Array1, array1size, Array2, array2size, output);
	writefile(output, outputsize);

	cout << endl << "The sorted list of " << outputsize << " numbers is: ";
	for (int k = 0; k < outputsize; k++) {
			cout << output[k] << " ";
	}
	cout << endl;

	return 0;
}

/*
* Reads input files and stores integer values in array.
*/
int readfile(int inputArray[], ifstream& instream) {
	if (instream.fail()) {
		cout << "Input file opening failed." << endl;
		exit(1);
	}

	int i = 0;

	while (!instream.eof()) {
		instream >> inputArray[i];
		i++;
	}

	return i;
}

/*
* Sorts arrays into new array in ascending order.
*/
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
	int i = 0, j = 0, k = 0;

	while (i < inputArray1_size && j < inputArray2_size) {
		if (inputArray1[i] <= inputArray2[j]) {
			outputArray[k] = inputArray1[i];
			i++;
		}
		else {
			outputArray[k] = inputArray2[j];
			j++;
		}
		k++;
	}

	if (i < inputArray1_size) {
		for (int n = i; n < inputArray1_size; n++) {
			outputArray[k] = inputArray1[n];
			k++;
		}
	}
	else {
		for (int n = j; n < inputArray2_size; n++) {
			outputArray[k] = inputArray2[n];
			k++;
		}
	}

	return k;
}

/*
* Writes output array to output.txt
*/
void writefile(int outputArray[], int outputArray_size) {
	string filename = "output.txt";
	ofstream output;
	output.open(filename.c_str());

	for (int i = 0; i < outputArray_size; i++) {
		output << outputArray[i] << "\n";
	}

	output.close();
}
