#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int ROWS = 3;
    const int COLS = 3;

    // Initialize Matrix A and Matrix B
    int matrixA[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixB[ROWS][COLS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int sumMatrix[ROWS][COLS];

    // Display Matrix A
    cout << "Matrix A:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrixA[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;

    // Display Matrix B
    cout << "Matrix B:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrixB[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;

    // Calculate Sum of Matrix A and B
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    // Display Sum Matrix
    cout << "Sum of Matrix A and B:\n\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << sumMatrix[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}