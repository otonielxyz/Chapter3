#include <iomanip>
#include <iostream>
#include <string>
#include "input.h"
#include "nQueens.h"

void mainMenu();

int main()
{

    mainMenu();

    return 0;
}
//Precondition: NA
//Postcondition: Displays main menu
void mainMenu()
{

    // Loop through main menu until user exits
    do
    {
        // Main Menu
        cout << endl;
        cout << "\tCMPR131 Chapter 3 - Games Applications using Containers by Otoniel Torres Bernal (09 / 16 / 23)" << endl;
        cout << "\t" << string(80, char(205)) << endl;
        cout << "\t1> Tic-Tac-Toe" << endl;
        cout << "\t2> Tower of Hanoi" << endl;
        cout << "\t3> n-Queens" << endl;
        cout << "\t" << string(80, char(205)) << endl;
        cout << "\t0 > exit" << endl;
        cout << "\t" << string(80, char(205)) << endl;

        // Get user input/option of main menu
        int option = inputInteger("\n\tOption: ", 0, 3);

        switch (option)
        {
        case 0: exit(1); break;
        case 1: system("cls"); cout << "case 1" << endl; system("pause"); system("cls"); break;
        case 2: system("cls"); cout << "case 2" << endl; system("pause"); system("cls"); break;
        case 3: system("cls"); NQueens game; game.initializeAndSolveInteractive(); system("pause"); system("cls"); break;
        }

        // New line
        cout << "\n";

    } while (true);
}