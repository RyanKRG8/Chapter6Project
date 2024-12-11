#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void getRegInfo(string& regionName, int& numAccidents);
bool isLower(int value1, int value2);
void showLowest(const string& regionName, int numAccidents);

int main() {
    cout << "Safest Driving Area" << endl;

    // Store region information
    string north = "North", south = "South", east = "East", west = "West", central = "Central";
    int northAccidents, southAccidents, eastAccidents, westAccidents, centralAccidents;

    // Get the accident data for each region
    getRegInfo(north, northAccidents);
    getRegInfo(south, southAccidents);
    getRegInfo(east, eastAccidents);
    getRegInfo(west, westAccidents);
    getRegInfo(central, centralAccidents);

    // Check what region has the lowest amount of accidents
    string safestRegion = north;
    int lowestAccidents = northAccidents;

    if (isLower(southAccidents, lowestAccidents)) {
        safestRegion = south;
        lowestAccidents = southAccidents;
    }
    if (isLower(eastAccidents, lowestAccidents)) {
        safestRegion = east;
        lowestAccidents = eastAccidents;
    }
    if (isLower(westAccidents, lowestAccidents)) {
        safestRegion = west;
        lowestAccidents = westAccidents;
    }
    if (isLower(centralAccidents, lowestAccidents)) {
        safestRegion = central;
        lowestAccidents = centralAccidents;
    }

    // Display the safest region
    showLowest(safestRegion, lowestAccidents);

    return 0;
}

// Get region name and number of accidents
void getRegInfo(string& regionName, int& numAccidents) {
    do {
        cout << "Enter the amount of accidents reported in the " << regionName << " region: " << endl;
        cin >> numAccidents;

        if (numAccidents < 0) {
            cout << "Invalid input. Please enter a number higher than 0." << endl;
        }
    } while (numAccidents < 0);
}

// Checks if 1 regiona dn lower or higher than the other
bool isLower(int value1, int value2) {
    return value1 < value2;
}

// Shows what region is the lowest
void showLowest(const string& regionName, int numAccidents) {
    cout << "The safest driving area is: " << regionName << " (" << numAccidents << " accidents.)" << endl;
}
