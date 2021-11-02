#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printArr(int arr[5]);
void printArr(double arr[5]);

int main() {

    bool looping = false;
    char choice;

    do {
        /* PROBLEM 1 */

        int ints[5];
        double doubles[] = {10.0, 20.0, 30.0, 40.0, 50.0};

        //Populate the array
        for(int i = 0; i < 5; i++) {
            ints[i] = i + 1;
        }

        //Print the arrays
        printArr(ints);
        printArr(doubles);
        cout << endl;

        /* PROBLEM 2 */

        string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        string seasons[] = {"Winter", "Winter", "Spring", "Spring", "Spring", "Summer", "Summer", "Summer", "Autumn", "Autumn", "Autumn", "Winter"};
        int numM; // Month #

        cout << "Enter the number of the month (1-12): ";
        cin >> numM;
        cout << endl;

        if(numM <= 0 || numM > 12) cout << "* Invalid month " << numM << endl;
        else cout << "The month of " << months[numM - 1] << " is in " << seasons[numM - 1] << endl;
        cout << endl;

        cout << "Continue? (Y/N): ";
        cin >> choice;

        //Quit on inputs other than 'y' or 'Y'
        if(toupper(choice) == 'Y') looping = true;
        else looping = false;
        cout << endl;
    } while (looping);

    return 0;
}

//Print the arrays
void printArr(int arr[5]) {
    cout << fixed << setprecision(1);
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
}

void printArr(double arr[5]) {
    cout << fixed << setprecision(1);
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
}
