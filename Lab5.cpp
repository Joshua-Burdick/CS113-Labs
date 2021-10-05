#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Main functions for Lab problems
void CaffeineCalculator();
void CheckingAccount();

//Supplementary functions for modularization and code reduction
void BankMenu(char &choice);
void Overdraft(double &checking, double &savings, double amount);
void Validate(double num, string desc);
void Error(string issue);

int main() {

    int prob;

    cout << "1. Caffeine Calculator\n2. Checking Account Program\n";
    cout << "  Enter program to run: ";
    cin >> prob;

    cout << endl << endl;
    
    if (prob == 1) CaffeineCalculator();
    else if (prob == 2) CheckingAccount();
    else cout << "Inavlid selection!" << endl << endl;

    return 0;
}

void CaffeineCalculator() {
    double caffeine;
    int count;

    cout << "***Caffeine Calculator***" << endl << endl;

    cout << "Enter the number of 8oz cups consumed: ";
    cin >> caffeine; //Number of cups of coffee
    Validate(caffeine, "drink");
    caffeine *= 130; //Each cup contains 130mg of caffeine

    cout << fixed << setprecision(1);
    cout << "Hours    Caffeine (mg)" << endl;
    while (caffeine >= 65.0) {
        caffeine -= (caffeine * 0.13); //Eliminated at 13% an hour
        if (caffeine < 65.0) break;
        cout << setw(2) << count << setw(18) << caffeine << endl;
        count++;
    }
}

void CheckingAccount() {
    double checkBal, savBal, input;
    char choice, transfer;
    bool exit = false;

    cout << "***Checking Account Program***" << endl << endl;

    cout << "Enter checking account balance: ";
    cin >> checkBal;

    cout << "Enter savings account balance: ";
    cin >> savBal;

    cout << endl; //Formatting
    cout << fixed << setprecision(2);

    do {
        BankMenu(choice);

        switch (choice) { //Menu options
            case 'W':
                cout << "  Enter withdrawl amount: ";
                cin >> input;
                cout << endl;
                Validate(input, "withdraw");
                Overdraft(checkBal, savBal, input);
                break;
            case 'D':
                cout << "  Enter desposit amount: ";
                cin >> input;
                cout << endl;
                Validate(input, "deposit");
                checkBal += input;
                break;
            case 'T':
                cout << "  Transfer to or from acct (T/F): ";
                cin >> transfer;
                cout << endl;
                if (toupper(transfer) == 'T') {
                    cout << "  Enter amount to transfer: ";
                    cin >> input;
                    Validate(input, "transfer");
                    cout << endl;
                    checkBal += input;
                    savBal -= input;
                }
                else if (toupper(transfer) == 'F') {
                    cout << "  Enter amount to transfer: ";
                    cin >> input;
                    Validate(input, "transfer");
                    cout << endl;
                    checkBal -= input;
                    savBal += input;
                }
                else {
                    Error("Invalid Input");
                }
                break;
            case 'B':
                cout << "Checking account balance: " << setw(5) << "$" << setw(10) << checkBal << endl;
                cout << "Savings account balance: " << setw(6) << "$" << setw(10) << savBal << endl;
                break;
            case 'X':
                exit = true;
                break;
            default:
                Error("Invalid Input");
                break;
        }
        cout << endl; //Formatting
    } while (!exit);
}

void BankMenu(char &choice) {

    cout << "W - Cash Withdrawl\n";
    cout << "D - Deposit\n";
    cout << "T - Transfer to/from Checking Account\n";
    cout << "B - Display Balances\n";
    cout << "X - Exit\n";

    cout << "  Enter choice: ";
    cin >> choice;
    choice = toupper(choice);

    cout << endl; //Formatting
}

//Cover overdraft using savings acct
void Overdraft (double &checking, double &savings, double amount) {
    if (amount > checking) { //Use the amount in checking, then cover the rest using savings acct
        savings -= (amount - checking);

        cout << "NOTICE: Overdraft warning! $" << (amount - checking) << " withdrawn from savings account to cover costs." << endl;

        checking = 0.00;
    }
    else checking -= amount; //If no overdraft, proceed as normal
}

//Basic error handling
void Validate (double num, string desc) {
    if (num <= 0.0) Error("Cannot " + desc + " a negative amount.");
}

void Error (string issue) {
    cout << issue << endl;
}
