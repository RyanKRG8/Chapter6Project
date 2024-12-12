#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double getScore();
bool isLower(double value1, double value2);
bool isHigher(double value1, double value2);
double calcAverage(double total, int scoreCount, double minScore, double maxScore);

int main() {
    const int TOTAL_JUDGES = 5;
    double score, total = 0.0, minScore, maxScore, average;

    // Get the first judge's score
    cout << "Plesae provide the score for judge 1: " << endl;
    score = getScore();

    minScore = score;
    maxScore = score;
    total += score;

    // Gets the user to input the scores for the remaining judges
    for (int judge = 2; judge <= TOTAL_JUDGES; ++judge) {
        cout << "Enter the score for judge " << judge << ": " << endl;
        score = getScore();

        total += score;

        if (isLower(score, minScore)) {
            minScore = score;
        }
        if (isHigher(score, maxScore)) {
            maxScore = score;
        }
    }

    // Calculates the average scores
    average = calcAverage(total, TOTAL_JUDGES, minScore, maxScore);

    // Displays the average score
    cout << fixed << setprecision(2);
    cout << "The performer's average score is: " << average << endl;

    return 0;
}

// Get a score from the user
double getScore() {
    double score;
    cin >> score;

    while (score < 0.0 || score > 10.0) {
        cout << "The score cannot be lower than 0 or higher than 10. Enter a score between 0 and 10: " << endl;
        cin >> score;
    }

    return score;
}

bool isLower(double value1, double value2) {
    return value1 < value2;
}

bool isHigher(double value1, double value2) {
    return value1 > value2;
}

// Calculate the average score
double calcAverage(double total, int scoreCount, double minScore, double maxScore) {
    return (total - minScore - maxScore) / (scoreCount - 2);
}
