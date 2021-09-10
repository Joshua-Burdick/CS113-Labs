// Lab1.cpp : This file contains code for the first lab assignment
//

#include <iostream>
using namespace std;

int main()
{
    //Hello World
    cout << "Hello World!" << endl << endl;

    //Character Art
    cout << "/\\    /\\" << endl;
    cout << "  o  o    " << endl;
    cout << " =    =   " << endl;
    cout << "  ----    " << endl << endl;

    //Squaring a number
    int num, squared;
    cout << "Enter a number: ";
    cin >> num;
    squared = pow(num, 2); //pow(int, power) to square the number
    cout << "The number squared: " << squared << endl;
}
