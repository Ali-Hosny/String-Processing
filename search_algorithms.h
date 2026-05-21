#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <string>

#include "stats.h"

Stats boyerMooreStats(const string &source, const string &pattern);
Stats rabinKarpStats(const string &source, const string &pattern);

#endif
