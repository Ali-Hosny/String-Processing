#include <iostream>
#include <string>

#include "text_store.h"
#include "stats.h"
#include "output.h"
#include "search_algorithms.h"

using namespace std;

void boyerMooreSearch(){

    if(text.empty()){
        cout << "\nNo text loaded.\n";
        return;
    }

    int count;

    cout << "\nHow many patterns? ";
    cin >> count;
    cin.ignore();

    for(int i = 0; i < count; ++i){

        string pattern;

        cout << "\nEnter pattern " << i + 1 << ": ";
        getline(cin, pattern);

        if(pattern.empty()){
            cout << "\nPattern cannot be empty.\n";
            continue;
        }

        Stats stats = boyerMooreStats(text, pattern);

        cout << "\nSearching for pattern: " << pattern << endl;
        printStatistics(stats);

        highlightMatches(text, pattern, stats.positions);
    }
}

void rabinKarpSearch(){

    if(text.empty()){
        cout << "\nNo text loaded.\n";
        return;
    }

    int count;

    cout << "\nHow many patterns? ";
    cin >> count;
    cin.ignore();

    for(int i = 0; i < count; ++i){

        string pattern;

        cout << "\nEnter pattern " << i + 1 << ": ";
        getline(cin, pattern);

        if(pattern.empty()){
            cout << "\nPattern cannot be empty.\n";
            continue;
        }

        Stats stats = rabinKarpStats(text, pattern);

        cout << "\nSearching for pattern: " << pattern << endl;
        printStatistics(stats);

        highlightMatches(text, pattern, stats.positions);
    }
}

void compareAlgorithms(){

    if(text.empty()){
        cout << "\nNo text loaded.\n";
        return;
    }

    string pattern;

    cout << "\nEnter pattern: ";
    getline(cin, pattern);

    Stats bmStats = boyerMooreStats(text, pattern);
    Stats rkStats = rabinKarpStats(text, pattern);

    cout << "\n========== COMPARISON ==========\n";

    cout << "\n--- Boyer-Moore ---\n";
    printStatistics(bmStats);
    cout << "\nBoyer-Moore Highlighted Text:\n";
    highlightMatches(text, pattern, bmStats.positions);

    cout << "\n--- Rabin-Karp ---\n";
    printStatistics(rkStats);
    cout << "\nRabin-Karp Highlighted Text:\n";
    highlightMatches(text, pattern, rkStats.positions);
}
