// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
using namespace std;

int add(vector<int> n) {
    int total = 0;

    if (n.size() < 0) {
        cout << "Error: numbers must be positive" <<endl;
    }
    else {
        for (int x : n) {
            total += x;
        }        
    }

    return total;
}

int avg(vector<int> n) {
    int total = 0;

    if (n.size() < 0) {
        cout << "Error: numbers must be postive" <<endl;
    }
    else {
        for (int x : n) {
            total += x;
        }
    }

    int num = 0;

    for (int h : n) {
        num += 1;
    }

    int average;
    average = total / n.size();

    return average;

}

int max(vector<int> n) {
    int highest;

    if (n.size() < 0) {
        cout << "Error: numbers must be positive" <<endl;
    }
    else {
        highest = n[0];

        for (int x : n) {
            if (x > highest) {
                highest = x;
            }
        }
    }

    return highest;
}

int min(vector<int> n) {
    int lowest;

    if (n.size() < 0) {
        cout << "Error: numbers must be positive" <<endl;
    }
    else {
        lowest = n[0];

        for (int x : n) {
            if (x < lowest) {
                lowest = x;
            }
        }
    }

    return lowest;
}

int main() {
    int amt_of_numbers;
    cout << "How many numbers? ";
    cin >> amt_of_numbers;

    vector<int> stat_vals;
    for (int i = 0; i < amt_of_numbers; i++) {
        int num;
        cout << "Enter number" << i + 1 << ": ";
        cin >> num;
        stat_vals.push_back(num);
    }

    int sum = add(stat_vals);
    int average = avg(stat_vals);
    int maximum = max(stat_vals);
    int minimum = min(stat_vals);

    cout << "\nResults: ";
    cout << "\nSum: " <<sum<< "\nAverage: " <<average<< "\nMaximum: " <<maximum<< "\nMinimum: " <<minimum<<endl;

}


 
