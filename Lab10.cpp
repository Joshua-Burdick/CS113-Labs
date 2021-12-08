#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

void getInput(string& name, string& address, string& town, double& value);
void printLetter(string name, string address, string town, double value);

int  main() {

    string name, address, town;
    double value;

    getInput(name, address, town, value);

    //manipulate input
    name = name.substr(name.find(' ') + 1); // Last name
    address = address.substr(address.find(' ') + 1); // Street name
    town = town.substr(0, town.find(' ') - 1); // Town name
    transform(town.begin(), town.end(), town.begin(), ::toupper); // Capitalize town name

    printLetter(name, address, town, value);

    return 0;
}

void getInput(string& name, string& address, string& town, double& value) {
    printf("Tax Letter\n\n");

    printf("Enter name (First Last): ");
    getline(cin, name);

    printf("Enter street address: ");
    getline(cin, address);

    printf("Enter town, state and zip (town, state zip): ");
    getline(cin, town);

    printf("Enter property value: ");
    cin >> value;

    printf("\n");
}

void printLetter(string name, string address, string town, double value) {
    printf("Dear Mr/Mrs %s:\n", name.c_str());
    printf("Taxes for %s are due by the 15th of the month.\n", town.c_str());
    printf("Based on your property value of $%.2f, your tax is $%.2f\n", value, value * 0.04);
    printf("Due to increased development on %s, your taxes will increase next year to $%.2f\n", address.c_str(), value * 0.06);
}
