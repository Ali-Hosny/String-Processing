#include <iostream>
#include <fstream>
#include <string>

#include "text_store.h"

using namespace std;

void loadFile() {

    string filename;
    cout << "\nEnter file name: ";
    getline(cin, filename);

    if(filename.find_first_not_of(" \t\r\n") == string::npos) {
        cout << "\nFile name is empty.\n";
        return;
    }

    ifstream file(filename);

    if(!file) {
        cout << "\nError opening file: " << filename << "\n";
        return;
    }

    text = "";
    string line;

    while(getline(file, line)) {
        text += line + "\n";
    }

    file.close();

    if(text.empty()) {
        cout << "\nFile is empty or unreadable.\n";
        return;
    }

    cout << "\nFile loaded successfully.\n";
}

void manualInput() {

    cout << "\nEnter text:\n";
    getline(cin, text);

    cout << "\nText stored successfully.\n";
}
