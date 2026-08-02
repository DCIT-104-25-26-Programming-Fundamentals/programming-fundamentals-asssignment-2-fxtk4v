// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
#include <vector>

vector<int> fibonacci(int N) {
    vector<int> seq;
    int a = 0, b = 1;

    for (int i = 0; i < N; i++) {
        seq.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;
    }
    return seq;
}

int main() {
    int user_input;
    cout << "How many term? ";
    cin >> user_input;

    vector<int> fibonacci_seq = fibonacci(user_input);
    cout << "[";
    for (size_t i = 0; i < fibonacci_seq.size(); i++) {
        cout << fibonacci_seq[i];
        if (i != fibonacci_seq.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

// PART B
bool fibonacci_check(int x) {
    vector<int> seq;
    int a = 0, b = 1;

    while (a <= x) {
        seq.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;

        for (int val : seq) {
            if (val == x) {
                return true;
            }
        }
    }
    return false;
}