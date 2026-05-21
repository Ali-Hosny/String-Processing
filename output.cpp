#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

#include "stats.h"

using namespace std;

void printStatistics(Stats stats) {

    cout << "\n========== STATISTICS ==========\n";

    cout << "Algorithm Used: " << stats.algorithm << endl;
    cout << "Comparisons: " << stats.comparisons << endl;
    cout << "Matches Found: " << stats.matches << endl;

    cout << fixed << setprecision(4);
    cout << "Execution Time: " << stats.executionTime << " ms\n";

    cout << "Match Positions: ";
    if(stats.positions.empty()) {
        cout << "None";
    }
    else {
        for(int pos : stats.positions) {
            cout << pos << " ";
        }
    }

    if(stats.matches == 0) {
        cout << "No matches found.\n";
    }
    cout << endl;

}

void highlightMatches(const string &source, const string &pattern, const vector<int> &positions) {

    if(positions.empty()) {
        cout << source << endl;
        return;
    }

    int currentPos = 0;
    int m = pattern.size();

    for(int pos : positions) {

        while(currentPos < pos) {
            cout << source[currentPos];
            currentPos++;
        }

        cout << "[";

        for(int i = 0; i < m && pos + i < source.size(); ++i) {
            cout << source[pos + i];
        }

        cout << "]";

        currentPos = max(currentPos, pos + m);
    }

    while(currentPos < source.size()) {
        cout << source[currentPos];
        currentPos++;
    }

    cout << endl;
}
