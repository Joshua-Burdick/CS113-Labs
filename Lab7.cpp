#include <iostream>
#include <iomanip>

using namespace std;

// Driving Cost
double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon);

// Change Calculator
int getInput();
int computeCoins(int coinValue, int& amount);
void displayChange(int halfDollars, int quarters, int dimes, int nickels, int pennies);

int main() {

    int choice;
    double mpg, dpg;
    bool loop = true;
    char repeat;

    // Menu
    do {
        cout << "1. Driving Cost Calculator" << endl;
        cout << "2. Change Calculator" << endl;
        cout << "3. Exit" << endl << endl;

        cout << "  Enter choice: ";
        cin >> choice;

        cout << endl;

        if (choice == 1) { // **Driving Cost Calculator**
            cout << fixed << setprecision(4); // Output formatting

            cout << "Enter the miles/gallon: ";
            cin >> mpg;

            cout << "Enter the dollars/gallon: ";
            cin >> dpg;

            cout << endl;

            cout << "Miles Driven    Cost" << endl;
            cout << "     10" << setw(13) << DrivingCost(10, mpg, dpg) << endl;
            cout << "     50" << setw(13) << DrivingCost(50, mpg, dpg) << endl;
            cout << "    400" << setw(13) << DrivingCost(400, mpg, dpg) << endl;
        }
        else if (choice == 2) { // **Change Calculator**
            int pennies = getInput();

            int numHD = computeCoins(50, pennies);
            int numQ = computeCoins(25, pennies);
            int numD = computeCoins(10, pennies);
            int numN = computeCoins(5, pennies);

            displayChange(numHD, numQ, numD, numN, pennies);
        }
        else if (choice == 3) break;
        else cout << "Error: Invalid Input." << endl;

        cout << endl;

        cout << "Would you like to continue? (Y/N): ";
        cin >> repeat;
        cout << endl;
        
        if(toupper(repeat) != 'Y') loop = false; // Quit the program on inputs other than 'Y'
    } while (loop);

    cout << endl;

    return 0;
}

double DrivingCost (double drivenMiles, double milesPerGallon, double dollarsPerGallon) {
    return (drivenMiles / milesPerGallon) * dollarsPerGallon; // Return the cost per the number of miles driven
}

int getInput() { // Read in the amount of change to break down
    int change;

    cout << "Enter the change (in cents): ";
    cin >> change;

    cout << endl;

    return change;
}

int computeCoins(int coinValue, int& amount) {
    int num = amount / coinValue; // How many coins there are
    amount %= coinValue; // Get the remaining change

    return num;
}
void displayChange(int halfDollars, int quarters, int dimes, int nickels, int pennies) { // Print the numbers of coins
    cout << "\tHalf Dollar(s): " << halfDollars << endl;
    cout << "\tQuarter(s): " << quarters << endl;
    cout << "\tDime(s): " << dimes << endl;
    cout << "\tNickel(s): " << nickels << endl;
    cout << "\tPennies: " << pennies << endl;
}
