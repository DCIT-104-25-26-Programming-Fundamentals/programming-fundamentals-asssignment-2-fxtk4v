// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void primeNum(int n) {

    bool prime = true;

    if (n < 2) {
        prime = false;   
    }

    for (int x = 2; x < 2; x++) {
        if (n % x == 0) {
            prime = false;
        }
    }

    if (prime) {
        cout << n << " is a prime number" << endl;
    }
    else {
        cout << n << " is not a prime number" << endl;
    }

}

int main() {
    int user_input;
    cout << "Enter a number: ";
    cin >> user_input;

    primeNum(user_input);
    return 0;
}
