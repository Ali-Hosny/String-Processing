#ifndef STATS_H
#define STATS_H

#include <string>
#include <vector>

using namespace std;

struct Stats {
    int comparisons = 0;
    int matches = 0;
    double executionTime = 0;
    string algorithm;
    vector<int> positions;
};

#endif
