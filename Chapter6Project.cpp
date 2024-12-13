#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function prototypes
int getRooms();
double getSqFtPerRoom(int roomNumber);
double getPaintPricePerRoom(int roomNumber);
double gallonsForRoom(double squareFeet);
void writeEstimate(double paintCharge, double gallonsNeeded, double laborCharge, double laborHours);

const double GALLONS_SQFT = 110.0;
const double LABOR_HOURS_PER_SQFT = 8.0 / 110.0;
const double LABOR_RATE_PER_HOUR = 25.0;

int main() {
    double paintCharge = 0.0, laborCharge = 0.0, gallonsNeeded = 0.0, laborHours = 0.0;
    int numRooms = getRooms(); // Gets the number of rooms

    // Process each of the rooms
    for (int room = 1; room <= numRooms; ++room) {
        double squareFeet = getSqFtPerRoom(room);
        double gallons = gallonsForRoom(squareFeet);
        gallonsNeeded += gallons;

        double paintPrice = getPaintPricePerRoom(room);
        paintCharge += gallons * paintPrice;

        double labor = squareFeet * LABOR_HOURS_PER_SQFT;
        laborHours += labor;
        laborCharge += labor * LABOR_RATE_PER_HOUR;
    }

    // Display the estimate
    writeEstimate(paintCharge, gallonsNeeded, laborCharge, laborHours);

    return 0;
}

// Gets the number of rooms
int getRooms() {
    int rooms;

    cout << "Enter the number of rooms that need to be painted: " << endl;
    cin >> rooms;
    while (rooms < 1) {
        cout << "Invalid input. Enter a value of at least 1: " << endl;
        cin >> rooms;
    }

    return rooms;
}

// Gets the square footage of a room
double getSqFtPerRoom(int roomNumber) {
    double squareFeet;

    cout << "Enter the square feet of wall space for room " << roomNumber << ": " << endl;
    cin >> squareFeet;
    while (squareFeet < 0.0) {
        cout << "Invalid input. Enter a non-negative value: " << endl;
        cin >> squareFeet;
    }

    return squareFeet;
}

// Function to get the paint price per gallon for a room
double getPaintPricePerRoom(int roomNumber) {
    double price;

    cout << "Enter the price of paint per gallon for room: " << roomNumber << ": ";
    cin >> price;
    while (price < 10.0) {
        cout << "Invalid input. Enter a value of at least $10.00: ";
        cin >> price;
    }

    return price;
}

double gallonsForRoom(double squareFeet) {
    return ceil(squareFeet / GALLONS_SQFT); // Rounds up to the nearest gallon
}

// Displays the estimate of the paint job
void writeEstimate(double paintCharge, double gallonsNeeded, double laborCharge, double laborHours) {
    cout << fixed << setprecision(2);
    cout << "\n----- Paint Job Estimate -----\n";
    cout << "Gallons of paint required: " << gallonsNeeded << endl;
    cout << "Hours of labor required: " << laborHours << endl;
    cout << "Cost of paint: $" << paintCharge << endl;
    cout << "Labor charges: $" << laborCharge << endl;
    cout << "Total cost of the paint job: $" << (paintCharge + laborCharge) << endl;
}
