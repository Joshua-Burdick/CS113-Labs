#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	/* COIN CALCULATOR - PART 1 */

	int numQ, numD, numN; // # of quarters, dimes, and nickels resepectively

	// Get the number of coins
	cout << "Enter the number of quarters: ";
	cin >> numQ;
	cout << "Enter the number of dimes: ";
	cin >> numD;
	cout << "Enter the number of nickels: ";
	cin >> numN;
	cout << endl;

	// Print total value of the coins entered
	cout << "    Total coins are worth " << (25 * numQ) + (10 * numD) + (5 * numN) << " cents" << endl << endl; // Double blank lines at the end (formatting)

	/* COIN CALCULATOR - PART 2*/

	int cents, temp;

	// Get the total coin value
	cout << "Enter the change (in cents): ";
	cin >> cents;

	// Calculate and print the proper number of coins (round down and subtract that many coins from the total cents. Repeat.)
	string types[5] = { "Half Dollar(s): ", "Quarter(s): ", "Dime(s): ", "Nickel(s): ", "Pennies: " };
	int values[5] = { 50, 25, 10, 5, 1 };

	for (int i = 0; i < 5; i++) { // Print each coin type and find how many there are
		temp = floor(cents / values[i]);
		cout << types[i] << temp << endl;
		cents %= values[i]; // The remaining cents to evaluate is the remainder of the previous coin
	}

	cout << endl; // Add an extra blank line before part 3 (for formatting)

	/* FAHRENHEIT TO CELSIUS CONVERSION */

	double deg;

	// Get Fahrenheit temp
	cout << "Enter the temperature in Fahrenheit: ";
	cin >> deg;

	//Evaluate and print temp in Celsius
	cout << fixed << setprecision(2) << "     The temperature is " << (deg - 32) * (5.00 / 9.00) << " degrees Celsisus" << endl << endl;

	return 0;
}
