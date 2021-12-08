#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int monthIndex(string months[12], const string& month);
void printSales(string months[12], double totals[12]);

int main() {

    string month;
    string line, months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int a;
    double sale, totals[12] = {0.0};

    ifstream inFile;
    inFile.open("sales.txt");

    while(!inFile.eof()) {
        //Get the data
        getline(inFile, line);
        month = line.substr(0, line.find(' '));
        sale = stod(line.substr(line.find(' ') + 1));

        //Tally the sales numbers
        a = monthIndex(months, month);
        if(a >= 0) totals[a] += sale;
    }

    inFile.close();

    printSales(months, totals);

    return 0;
}

int monthIndex(string months[12], const string& month) {
    for(int i = 0; i < 12; i++) {
        if(months[i] == month) return i;
    }
    return -1;
}

void printSales(string months[12], double totals[12]) {
    cout << fixed << setprecision(2);
    cout << "Month" << setw(10) << "Sales" << endl;

    for(int i = 0; i < 12; i++) {
        cout << months[i] << setw(12) << totals[i] << endl;
    }
}
