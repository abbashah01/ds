#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int ROWS = 4;
    const int COLS = 5;

    // 1. Create and initialize 2D parking array (0 = Empty, 1 = Occupied)
    int parking[ROWS][COLS] = {
        {1, 0, 1, 0, 1}, // Row 0
        {0, 1, 0, 0, 1}, // Row 1
        {1, 1, 0, 1, 0}, // Row 2
        {0, 0, 0, 1, 1}  // Row 3
    };

    int occupiedCount = 0;
    int emptyCount = 0;
    int totalCapacity = ROWS * COLS;

    // 3 & 4. Count occupied and empty spaces
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (parking[i][j] == 1) {
                occupiedCount++;
            } else {
                emptyCount++;
            }
        }
    }

    // 2. Display the complete parking layout
    cout << "========================================\n";
    cout << "        PARKING MANAGEMENT SYSTEM       \n";
    cout << "========================================\n";
    cout << "Layout Key: [0 = Empty, 1 = Occupied]\n\n";

    cout << "         Col 0  Col 1  Col 2  Col 3  Col 4\n";
    cout << "------------------------------------------\n";

    for (int i = 0; i < ROWS; ++i) {
        cout << "Row " << i << "  |";
        for (int j = 0; j < COLS; ++j) {
            cout << setw(5) << parking[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "------------------------------------------\n\n";

    // 7. Display total parking capacity and current occupancy metrics
    cout << "Parking Summary:\n";
    cout << "----------------\n";
    cout << "Total Capacity:    " << totalCapacity << " spaces\n";
    cout << "Occupied Spaces:   " << occupiedCount << "\n";
    cout << "Empty Spaces:      " << emptyCount << "\n";
    cout << "Occupancy Rate:    " << (static_cast<double>(occupiedCount) / totalCapacity) * 100 << "%\n\n";

    // 5. Ask user to enter a row and column number
    int targetRow, targetCol;
    cout << "Check Space Availability:\n";
    cout << "-------------------------\n";
    cout << "Enter Row number (0-" << (ROWS - 1) << "): ";
    cin >> targetRow;
    cout << "Enter Column number (0-" << (COLS - 1) << "): ";
    cin >> targetCol;

    // 6. Validate input bounds and check space status
    if (targetRow < 0 || targetRow >= ROWS || targetCol < 0 || targetCol >= COLS) {
        cout << "\n[Error] Invalid space coordinates! Row must be 0-" << (ROWS - 1) 
             << " and Column must be 0-" << (COLS - 1) << ".\n";
    } else {
        if (parking[targetRow][targetCol] == 1) {
            cout << "\n-> Space [" << targetRow << "][" << targetCol << "] is OCCUPIED.\n";
        } else {
            cout << "\n-> Space [" << targetRow << "][" << targetCol << "] is AVAILABLE (Empty).\n";
        }
    }

    return 0;
}