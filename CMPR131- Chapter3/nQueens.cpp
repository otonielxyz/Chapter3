#include "NQueens.h"
#include <iostream>

using namespace std;

// Default constructor for the NQueens class
NQueens::NQueens() : size(0), board(0, vector<int>(0, 0)) {}

// Function to initialize and solve the board interactively
void NQueens::initializeAndSolveInteractive() {
    cout << "Enter the size of the board: "; // Prompt the user to enter board size
    cin >> size; // Read board size

    // Check if the size is valid
    if (size < 4) {
        cout << "Board size must be at least 4.\n";
        return;
    }

    // Check if the size is valid
    board = vector<vector<int>>(size, vector<int>(size, 0));
    solveInteractive(); // Call the interactive solving function
}

// Function to check if placing a queen is safe at a given position
bool NQueens::isSafe(int row, int col) {

    // Check if the position is already occupied
    if (isOccupied(row, col)) {
        cout << "ERROR: A queen has already been placed in the position (" << row + 1 << ", " << col + 1 << "). Try again." << endl;
        return false;
    }

    // Check if any queen exists in the same column in preceding rows
    for (int i = 0; i < row; ++i) {
        if (board[i][col]) return false;
    }

    // Check diagonals from the top-left to the position
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) return false;
    }

    // Check diagonals from the top-right to the position
    for (int i = row, j = col; i >= 0 && j < size; --i, ++j) {
        if (board[i][j]) return false;
    }

    return true; // Return true if the position is safe
}

// Function to check if a position is already occupied by a queen
bool NQueens::isOccupied(int row, int col) {
    return board[row][col];
}

// Function to print the current state of the board
void NQueens::printBoard() {
    for (const auto& row : board) { // Loop through each row
        for (const auto& cell : row) { // Loop through each cell in the row}
            cout << (cell ? "Q " : ". "); // Print 'Q' if a queen is present, else print '.'
        }
        cout << endl; // Move to the next line after each row
    }
    cout << endl; // Add an extra line for separation
}

// Function to solve the board in an interactive manner
void NQueens::solveInteractive() {
    char option; // To hold the user's choice
    int row, col; // To hold the user's input for row and column


    while (true) { // Infinite loop until the user chooses to exit
        printBoard(); // Display the current state of the board
        cout << "A> Place a queen\n";
        cout << "B> Remove an existing queen\n";
        cout << "0> Return\n";
        cout << "Choose an option: ";
        cin >> option; // Read the user's choice

        if (option == '0') { 
            return; // Exit the loop if the user chooses '0'
        }

        // Prompt for row and column to place or remove a queen
        cout << "Position a queen in the row (1.." << size << "): ";
        cin >> row;
        row--; // Convert to 0-based index
        cout << "Position a queen in the column (1.." << size << "): ";
        cin >> col;
        col--; // Convert to 0-based index

        // Check if the entered row and column are within valid range
        if (row < 0 || row >= size || col < 0 || col >= size) {
            cout << "ERROR: Invalid position. Try again.\n";
            continue; // Skip the rest of the loop and go back to the start
        }

        // Place a queen if the 'A' option is chosen
        if (option == 'A') {
            if (isSafe(row, col)) {
                board[row][col] = 1;  // Place the queen
            }
            else {
                cout << "ERROR: Conflict with queens in existing rows. Try again.\n";
            }
        }

        // Remove a queen if the 'B' option is chosen
        else if (option == 'B') {
            if (isOccupied(row, col)) {
                board[row][col] = 0; // Remove the queen
            }
            else {
                cout << "ERROR: No queen exists at the specified position. Try again.\n";
            }
        }

        // Handle invalid options
        else {
            cout << "ERROR: Invalid option. Try again.\n";
        }
    }
}