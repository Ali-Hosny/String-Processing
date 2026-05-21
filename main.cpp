#include <iostream>

#include "file_io.h"
#include "search_ui.h"

using namespace std;

int main() {

    int choice;

    do{
        cout << "\n========== STRING PROCESSING SYSTEM ==========\n";
        cout << "1. Load Text File\n";
        cout << "2. Enter Text Manually\n";
        cout << "3. Search Using Boyer-Moore\n";
        cout << "4. Search Using Rabin-Karp\n";
        cout << "5. Compare Algorithms\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        cin.ignore();

        switch(choice){

            case 1:
                loadFile();
                break;

            case 2:
                manualInput();
                break;

            case 3:
                boyerMooreSearch();
                break;

            case 4:
                rabinKarpSearch();
                break;

            case 5:
                compareAlgorithms();
                break;

            case 6:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    }while(choice != 6);

    return 0;
}