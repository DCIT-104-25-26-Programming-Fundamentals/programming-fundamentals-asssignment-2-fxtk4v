// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int multiplication(int n, int a) {
    int product = 0;
    for (int x = 0; x < a; x++) {
        product += n;
    }
    return product;
}

int main() {
    int user_input;
    cout << "Enter a number: ";
    cin >> user_input;

    if (user_input < 0) {
        cout << "Error: enter positive numbers only." << endl;
    } else {
        for (int i = 1; i < 13; i++) {
            int mul_table = multiplication(user_input, i);
            cout << user_input << " x " << i << " = " << mul_table << endl;
        }
    }

    // PART B

    int N;
    cout << "Enter a number: ";
    cin >> N;

    if (N < 0) {
        cout << "Error: enter positive numbers only." << endl;
    } else {
        for (int h = 1; h < N + 1; h++) {
            for (int m = 1; m < 13; m++) {
                int mul_table1 = multiplication(h, m);
                cout << h << " x " << m << " = " << mul_table1 << endl;
            }
            cout << "___________________" << endl;
        }
    }

    return 0;
}
