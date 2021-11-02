#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>

using namespace std;

double TriangleArea(double b, double h); //Base and height
double TriangleArea(double a, double b, double angle); //Two sides and the included angle
double HeronsFormula(double a, double b, double c); //3 sides

int main() {

    int num;
    char input;
    double area;
    bool checking = true;

    cout << fixed << setprecision(2);

    do {
        cout << "1. Base and Height\n";
        cout << "2. Two sides and an angle (SAS)\n";
        cout << "3. Heron's Formula\n";
        cout << "4. Exit\n\n";

        cout << "  Enter your choice: ";
        cin >> num;

        cout << endl;

        if (num ==1) {
            double b, h;

            cout << "Enter the base: ";
            cin >> b;

            cout << "Enter the height: ";
            cin >> h;

            area = TriangleArea(b, h);
        }
        else if (num == 2) {
            double a, b, deg;

            cout << "Enter side 1: ";
            cin >> a;

            cout << "Enter side 2: ";
            cin >> b;

            cout << "Enter the included angle (in degrees): ";
            cin >> deg;

            area = TriangleArea(a, b, deg);
        }
        else if (num == 3) {
            double a, b, c;

            cout << "Enter side 1: ";
            cin >> a;

            cout << "Enter side 2: ";
            cin >> b;

            cout << "Enter side 3: ";
            cin >> c;

            area = HeronsFormula(a, b, c);
        }
        else if (num ==4) break;
        else area = -1;

        cout << endl;

        if (area == -1) cout << "Invalid input" << endl << endl;
        else cout << "Area of the Triangle: " << area << endl << endl;

        cout << "Continue? (Y/N): ";
        cin >> input;

        cout << endl;

        if (toupper(input) == 'Y') checking = true;
        else checking = false; // Inputs other than 'Y' or 'y' will terminate the program

    } while (checking);

    cout << endl;

    return 0;
}

double TriangleArea(double b, double h) {

    if (b >= 0 && h >= 0) { // Non-negative sides
        double area = (b * h) / 2; // 1/2 * base * height

        return area;
    }
    else {
        return -1;
    }
}

double TriangleArea(double a, double b, double angle) {

    if (a >= 0 && b >= 0 && angle >= 0 && angle < 180.0) { // Non-negative sides and an angle between 0 and 180 degrees.
        double rad = (angle * M_PI) / 180; // Convert degrees to radians
        double area = (a * b * sin(rad)) / 2; // 1/2 * ab* sin(C)

        return area;
    }
    else {
        return -1;
    }
}

double HeronsFormula(double a, double b, double c) {

    if(a >= 0 && b >= 0 && c >= 0 && a < b + c && b < a + c && c < a + b) { // Non-negative sides, no side must be greater than or equal to the sum of the other two
        double s = (a + b + c) / 2; //semi-perimeter

        double area = sqrt(s * (s - a) * (s - b) * (s - c)); //Heron's Formula

        return area;
    }
    else {
        return -1;
    }
}
