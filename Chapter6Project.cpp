#include <iostream>
#include <iomanip>
using namespace std;

// This program when ran will ask the user to enter the length and width of the rectangle that they're trying to get the area of.
// Once the user inputs the measurements it will then display them the perimeter and the area of the rectangle. 
// After the results are displayed it will then ask the user if they want to run another calculation.

void getLengthWidth(double& length, double& width);
double calcPerimeter(double length, double width);
double calcArea(double length, double width);
void displayProperties(double perimeter, double area);

int main() {
    cout << "Rectangle Properties Calculator" << endl;
    cout << fixed << setprecision(2);

    double length, width, perimeter, area;
    char choice;

    do {
        // Gets the length and width
        getLengthWidth(length, width);

        // Calculates the perimeter and area
        perimeter = calcPerimeter(length, width);
        area = calcArea(length, width);

        // Display results from calculation
        displayProperties(perimeter, area);

        // Ask user if they want to continue
        do {
            cout << "Would you like to calculate another rectangle? (y/n): " << endl;
            cin >> choice;

            if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
                cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
            }
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

    } while (choice == 'y' || choice == 'Y');
    return 0;
}

void getLengthWidth(double& length, double& width) {
    do {
        cout << "Enter the length of the rectangle (cannot be a negative value): " << endl;
        cin >> length;
        if (length < 0) {
            cout << "Invalid input. Length cannot be smaller than 0." << endl;
        }
    } while (length < 0);

    do {
        cout << "Enter the width of the rectangle (cannot be a negative value): " << endl;
        cin >> width;

        if (width < 0) {
            cout << "Invalid input. Width can-not be smaller than 0.\n" << endl;
        }
    } while (width < 0);
}

// Calculates the perimeter
double calcPerimeter(double length, double width) {
    return 2 * (length + width);
}

// Calculates the area
double calcArea(double length, double width) {
    return length * width;
}

// Displays the calculations 
void displayProperties(double perimeter, double area) {
    cout << "\nRectangle Properties:" << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
}