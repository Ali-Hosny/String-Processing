#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <vector>

#include "stats.h"

void printStatistics(Stats stats);
void highlightMatches(const string &source, const string &pattern, const vector<int> &positions);

#endif
