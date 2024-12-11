#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double fahrenheitToCelsius(double fahrenheit);
void displayTempTable();

int main() {
    cout << "Celsius Temperature Table" << endl;
    displayTempTable();
    return 0;
}

// Convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Display the temp table
void displayTempTable() {
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "Fahrenheit     Celsius" << endl;
    cout << "-----------------------" << endl;

    for (int fahrenheit = 0; fahrenheit <= 20; ++fahrenheit) {
        double celsius = fahrenheitToCelsius(fahrenheit);
        cout << fahrenheit << "\t\t" << celsius << endl;
    }
}