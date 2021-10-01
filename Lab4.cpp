#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	// Constants
	const double ROOM_TAX = 0.065;
	const double BEEF_MEAL = 15.95;
	const double VEGAN_MEAL = 10.95;
	const double GRATUITY = 0.18;
	const double ROOM1_COST = 250.00; // Seats 200
	const double ROOM2_COST = 150.00; // Seats 100
	const double ROOM3_COST = 75.00; // Seats 50

	// Input
	int numBeef, numVegan, numParty;
	double roomCost = 0.0;

	cout << "Enter the number of Beef Meals: ";
	cin >> numBeef;

	cout << "Enter the number of Vegan Meals: ";
	cin >> numVegan;

	cout << endl; // Blank line for formatting

	numParty = numBeef + numVegan; // Find the size of the party

	// Calculate room cost
	if (numParty > 100) { // R1 seats 200, 2 seats 100. If > 100, go to R1
		roomCost += ROOM1_COST;
		numParty %= 200;
	}
	if (numParty > 50) { // R2 seats 100, 3 seats 50. If > 50, go to R2
		roomCost += ROOM2_COST;
		numParty %= 100;
	}
	if (numParty <= 50)
		roomCost += ROOM3_COST;

	//Final Costs
	double roomFinal = roomCost + (roomCost * ROOM_TAX); // Final cost includes tax
	double beefCost = numBeef * BEEF_MEAL;
	double veganCost = numVegan * VEGAN_MEAL;
	double mealTax = (beefCost + veganCost) * GRATUITY;
	double total = roomFinal + beefCost + veganCost + mealTax;

	// Output

	cout << fixed << setprecision(2); // Output formatting
	cout << "Number in Party: " << setw(5) << numParty << endl;
	if (roomCost >= 100)
		cout << "Room Cost: " << setw(30) << "$ " << roomCost << endl;
	else
		cout << "Room Cost: " << setw(31) << "$  " << roomCost << endl;
	cout << "Room Tax: " << setw(37) << roomCost * ROOM_TAX << endl;
	cout << "Beef Meals: " << setw(10) << numBeef << setw(25) << beefCost << endl;
	cout << "Vegan Meals: " << setw(9) << numVegan << setw(25) << veganCost << endl;
	cout << "Gratuity: " << setw(37) << mealTax << endl;
	if (total >= 1000)
		cout << "Grand Total: " << setw(27) << "$" << total << endl;
	else
		cout << "Grand Total: " << setw(28) << "$ " << total << endl;
	return 0;
}
