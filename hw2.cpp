//Zachary Leggett
//zjl0002
//hw2_zjl0002.cpp
//
//This program computes the amortization table for a loan based on user inputted
//loan amount, annual interest rate, and monthly payment amount.
//
//Compile using "g++ hw2_zjl0002.cpp"
//Run using "./a.out"
//
//Used stackoverflow.com to learn how to use the setw() function for formatting columns.

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


int main() {
	
	//Intialize variables
	float loan, annualRate, monthlyPay, monthlyRate, interest, balance, payment, principal, calcRate, total;
	double roundedBalance;
	int month;

	//Takes user input
	cout << "Loan Amount: ";
	cin >> loan;
	cout << "Interest Rate (% per year): ";
	cin >> annualRate;
	cout << "Monthly Payents: ";
	cin >> monthlyPay;
	cout << endl;

	//Format table
	cout << "******************************************************" << endl;
	cout << "\tAmortization Table" << endl;
	cout << "******************************************************" << endl;
	cout << left << setw(8) << "Month" 
		 << setw(13) << "Balance" 
		 << setw(11) << "Payment"
		 << setw(8) << "Rate"
		 << setw(11) << "Interest"
		 << setw(12) << "Principal" << endl;

	month = 0;
	balance = loan;

	//Output first line of table
	cout.precision(2);
	cout << left << setw(8) << month << "$" << fixed << setw(12) << loan 
		 << setw(11) << "N/A" << setw(8) << "N/A" << setw(11) << "N/A"
		 << setw(12) << "N/A" << endl;
	
	monthlyRate = annualRate / 12;
	calcRate = (annualRate / 12) / 100;
	roundedBalance = static_cast<int>(balance * 100.0) / 100.0;

		//roundedBalance used for loop to prevent infinite/longer loop with very small float values
		//Calculations for each month are made and outputted
		while (roundedBalance > 0) {
			
			interest = calcRate * balance;

			if (interest > monthlyPay) {
				cout << endl << "Error: Monthly paymenet is less than interest." << endl << endl;
				exit(0);
			}

			//Checks if remaining balance is less than standard monthly payment
			if (balance < monthlyPay) {
				monthlyPay = balance + interest;
				principal = monthlyPay - interest;
				balance = 0.00;
			}
			else {
				principal = monthlyPay - interest;
				balance = balance - principal;
			}

			month++;
			total += interest;
			roundedBalance = static_cast<int>(balance * 100.0) / 100.0;

			cout.precision(2);
			cout << left << noshowpoint << setw(8) << month << "$" << setw(12) << fixed << balance << "$" << setw(10) << monthlyPay;
			cout << setw(8) << resetiosflags(ios::fixed) << showpoint << noshowpoint << monthlyRate;
			cout << fixed << "$" << setw(10) << interest << "$" << setw(12) << principal << endl;
		}
	
	//Ends table and outputs month and total interest
	cout << "******************************************************" << endl << endl;
	cout << "It takes " << month << " months to pay off the loan." << endl;
	cout.precision(2);
	cout << "Total interest paid is: $" << fixed << total << endl;

	return 0;
}

