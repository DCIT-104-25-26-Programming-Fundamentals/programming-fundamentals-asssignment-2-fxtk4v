// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


#include <vector>
#include <sstream>

using namespace std;

string format_num(double n) {
    // show whole numbers without a trailing .0
    if (n == (int)n) {
        return to_string((int)n);
    }
    ostringstream oss;
    oss << n;
    return oss.str();
}

vector<vector<double>> read_matrix(int& rows, int& cols, string label = "") {
    string prefix = label.empty() ? "" : " for " + label;
    cout << "Enter number of rows" << prefix << ": ";
    cin >> rows;
    cout << "Enter number of columns" << prefix << ": ";
    cin >> cols;

    vector<vector<double>> matrix;
    cin.ignore();
    for (int i = 0; i < rows; i++) {
        cout << "Enter row " << (i + 1) << ": ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<double> row;
        double val;
        while (ss >> val) {
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    return matrix;
}

void display_matrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        string formatted_row = "";
        for (size_t i = 0; i < row.size(); i++) {
            ostringstream oss;
            oss << setw(4) << right << format_num(row[i]);
            formatted_row += oss.str();
            if (i != row.size() - 1) {
                formatted_row += "  ";
            }
        }
        cout << formatted_row << endl;
    }
}

vector<vector<double>> transpose(const vector<vector<double>>& matrix, int rows, int cols) {
    vector<vector<double>> tran_matrix(cols, vector<double>(rows, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tran_matrix[j][i] = matrix[i][j];
        }
    }

    return tran_matrix;
}

vector<vector<double>> add_matrices(const vector<vector<double>>& a, const vector<vector<double>>& b, int rows, int cols) {
    vector<vector<double>> result(rows, vector<double>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

vector<vector<double>> multiply_matrices(const vector<vector<double>>& a, const vector<vector<double>>& b, int m, int n, int p) {
    vector<vector<double>> result(m, vector<double>(p, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            double total = 0;
            for (int k = 0; k < n; k++) {
                total += a[i][k] * b[k][j];
            }
            result[i][j] = total;
        }
    }

    return result;
}

void part_a() {
    cout << "\nEnter the matrix to transpose:" << endl;
    int rows, cols;
    vector<vector<double>> matrix = read_matrix(rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    display_matrix(matrix);

    vector<vector<double>> result = transpose(matrix, rows, cols);
    cout << "\nTransposed Matrix:" << endl;
    display_matrix(result);
}

void part_b() {
    cout << "\nEnter the first matrix:" << endl;
    int rows_a, cols_a;
    vector<vector<double>> a = read_matrix(rows_a, cols_a, "Matrix A");

    cout << "\nEnter the second matrix (must be the same size as Matrix A):" << endl;
    int rows_b, cols_b;
    vector<vector<double>> b = read_matrix(rows_b, cols_b, "Matrix B");

    if (rows_a != rows_b || cols_a != cols_b) {
        cout << "\nError: Matrices must be the same size to add ("
             << rows_a << "x" << cols_a << " vs " << rows_b << "x" << cols_b << ")." << endl;
        return;
    }

    cout << "\nMatrix A:" << endl;
    display_matrix(a);
    cout << "\nMatrix B:" << endl;
    display_matrix(b);

    vector<vector<double>> result = add_matrices(a, b, rows_a, cols_a);
    cout << "\nSum:" << endl;
    display_matrix(result);
}

void part_c() {
    cout << "\nEnter matrix A:" << endl;
    int m, n;
    vector<vector<double>> a = read_matrix(m, n, "Matrix A");

    cout << "\nEnter matrix B (number of rows must equal columns of A):" << endl;
    int n2, p;
    vector<vector<double>> b = read_matrix(n2, p, "Matrix B");

    if (n != n2) {
        cout << "\nError: Number of columns in A (" << n << ") must equal "
             << "number of rows in B (" << n2 << ")." << endl;
        return;
    }

    cout << "\nMatrix A:" << endl;
    display_matrix(a);
    cout << "\nMatrix B:" << endl;
    display_matrix(b);

    vector<vector<double>> result = multiply_matrices(a, b, m, n, p);
    cout << "\nProduct (A x B):" << endl;
    display_matrix(result);
}

void print_menu() {
    cout << string(30, '=') << endl;
    cout << "     MATRIX OPERATIONS" << endl;
    cout << string(30, '=') << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    int choice = 0;

    while (choice != 4) {
        print_menu();

        cout << "Select an option (1-4): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cout << endl;
            continue;
        }

        if (choice == 1) {
            part_a();
        } else if (choice == 2) {
            part_b();
        } else if (choice == 3) {
            part_c();
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please select a number between 1 and 4." << endl;
        }

        cout << endl;
    }

    return 0;
}