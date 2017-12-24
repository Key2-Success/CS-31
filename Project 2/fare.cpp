// Name: Kitu Komya
// UID: 404-491-375
// Class: CS 31 - Winter 2017
// Dis: 1B
// Project: Homework 2
// Due Date: 1/28/2017

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// declares variables
	string name;
	float miles;
	float mins;
	string ride;
	float fare = 0;

	// prompts user for name and store input as variable name
	cout << "Customer Name: ";
	getline(cin, name);

	// prompts user for # of miles and store input as variable miles
	cout << "Miles to be driven: ";
	cin >> miles;

	// prompts user for # of mins and store input as variable mins
	cout << "Minutes to be driven: ";
	cin >> mins;

	// prompts user for ride type and store input as variable ride
	cout << "Ride Type: ";
	cin >> ride;

	// uses magic formula to only display 2 decimal points for fare
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// computes fare for Br-UberX
	if (ride == "Br-UberX")
	{
		fare = 0.15*mins + 0.90*miles + 1.65; // calculates cost
		if (fare < 5.15) // changes fare to base price if base price not met
		{
			fare = 5.15;
		}
	}

	// computes fare for Br-UberXL
	else if (ride == "Br-UberXL")
	{
		fare = 0.30*mins + 1.55*miles + 1.65; // calculates cost
		if (fare < 7.65) // changes fare to base price if base price is not met
		{
			fare = 7.65;
		}
	}

	// returns error if name is empty
	if (name == "")
	{
		cout << "--- You must enter a customer name." << endl;
	}

	// returns error if miles is not positive
	else if (miles < 1)
	{
		cout << "--- The mileage must be positive." << endl;
	}

	// returns error if mins is not positive
	else if (mins < 1)
	{
		cout << "--- The time must be positive." << endl;
	}

	// determines if ride type is invalid
	else if (ride != "Br-UberX")
	{
		if (ride != "Br-UberXL")
		{
			cout << "--- The ride type is not valid." << endl; // returns error if ride type is wrong
		}
		else // returns fare if ride type is correct
		{
			cout << "--- The fare for " << name << " is $" << fare << endl;
		}
	}
	else // returns fare if no errors are present
	{
		cout << "--- The fare for " << name << " is $" << fare << endl;
	}
}