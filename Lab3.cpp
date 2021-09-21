#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

	/* LAWN MOWING TIME CALCULATOR */
	cout << "    ***MOW TIME CALCULATOR***" << endl << endl;

	double lawnLen, lawnWid, houseLen, houseWid; // 'Len' and 'Wid' variables correspond to length and width of the lawn and house respectively

	// Get user input
	cout << "Enter the length of the yard (ft): ";
	cin >> lawnLen;

	cout << "Enter the width of the yard (ft): ";
	cin >> lawnWid;

	cout << "Enter the length of the house (ft): ";
	cin >> houseLen;

	cout << "Enter the width of the house (ft): ";
	cin >> houseWid;

	cout << endl; // Output formatting w/ an extra blank line before output

	// Calculations for area of yard, house, and grass, as well as time to mow
	double yardAr = lawnLen * lawnWid;
	double houseAr = houseLen * houseWid;
	double grassAr = yardAr - houseAr;
	double mowTime = grassAr / 7 / 60; // Divide by 7 for 7 sq. ft. / sec -- divide by 60 to convert into *minutes*

	//Print results
	cout << fixed << setprecision(2); // All numbers will only show to 2 decimal points

	cout << "Area of the yard: " << yardAr << " square feet" << endl;
	cout << "Area of the house: " << houseAr << " square feet" << endl;
	cout << "Area of the grass: " << grassAr << " square feet" << endl;
	cout << "Time to mow the lawn: " << mowTime << " minutes" << endl << endl;

	/* BALL HEIGHT CALCULATOR */
	cout << "    ***BALL HEIGHT CALCULATOR***" << endl << endl;

	double v0, h0, T; // v0 is initial vel, h0 is initial height, and T is for time in seconds

	// Get user input
	cout << "Enter the initial velocity (ft/s): ";
	cin >> v0;

	cout << "Enter the initial height (ft): ";
	cin >> h0;

	cout << "Enter seconds: ";
	cin >> T;

	cout << endl; // Output formatting w/ an extra blank line before output

	// hF[#] are for each of the calculated heights. The number represents t + # seconds

	double hF0 = (-16 * pow(T, 2)) + (v0 * T) + h0;
	double hF1 = (-16 * pow(T + 1, 2)) + (v0 * (T + 1)) + h0;
	double hF2 = (-16 * pow(T + 2, 2)) + (v0 * (T + 2)) + h0;

	//Print results -- all numbers will have 2 decimal places due to cout formatting above
	cout << "Height Sec +0: " << hF0 << " feet" << endl;
	cout << "Height Sec +1: " << hF1 << " feet" << endl;
	cout << "Height Sec +2: " << hF2 << " feet" << endl;

	return 0;
}
