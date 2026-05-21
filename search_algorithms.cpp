#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

#include "stats.h"

using namespace std;

Stats boyerMooreStats(const string &source, const string &pattern){

    Stats stats;
    stats.algorithm = "Boyer-Moore";

    if(pattern.empty()){
        cout << "\nPattern is empty.\n";
        return stats;
    }

    if(pattern.size() > source.size()){
        cout << "\nPattern longer than text.\n";
        return stats;
    }

    auto start = chrono::high_resolution_clock::now();

    const int alphabetSize = 256;
    vector<int> badChar(alphabetSize, -1);

    for(int i = 0; i < static_cast<int>(pattern.size()); ++i){
        badChar[static_cast<unsigned char>(pattern[i])] = i;
    }

    int n = static_cast<int>(source.size());
    int m = static_cast<int>(pattern.size());
    int shift = 0;

    while(shift <= n-m){
        int j = m - 1;

        while(j >= 0) {

            stats.comparisons++;

            if(pattern[j] != source[shift + j]){
                break;
            }

            j--;
        }

        if(j<0){
            stats.matches++;
            stats.positions.push_back(shift);
            shift += 1;
        } else{
            int badIndex = badChar[static_cast<unsigned char>(source[shift + j])];
            shift += max(1, j - badIndex);
        }
    }

    auto end = chrono::high_resolution_clock::now();
    stats.executionTime = chrono::duration<double, milli>(end - start).count();

    return stats;
}

Stats rabinKarpStats(const string &source, const string &pattern){

    Stats stats;
    stats.algorithm = "Rabin-Karp";

    if(pattern.empty()){
        cout << "\nPattern is empty.\n";
        return stats;
    }

    if(pattern.size() > source.size()){
        cout << "\nPattern longer than text.\n";
        return stats;
    }

    auto start = chrono::high_resolution_clock::now();

    const int base = 256;
    const int mod = 101;
    int n = static_cast<int>(source.size());
    int m = static_cast<int>(pattern.size());

    int h = 1;
    for(int i = 0; i < m - 1; ++i){
        h = (h * base) % mod;
    }

    int patternHash = 0;
    int textHash = 0;

    for(int i = 0; i < m; ++i){
        patternHash = (base * patternHash + static_cast<unsigned char>(pattern[i])) % mod;
        textHash = (base * textHash + static_cast<unsigned char>(source[i])) % mod;
    }

    for(int i = 0; i <= n - m; ++i){
        if(patternHash == textHash){
            bool match = true;
            for(int j = 0; j < m; ++j){
                stats.comparisons++;
                if(source[i + j] != pattern[j]){
                    match = false;
                    break;
                }
            }
            if(match){
                stats.matches++;
                stats.positions.push_back(i);
            }
        }

        if(i < n-m){
            textHash = (base * (textHash - static_cast<unsigned char>(source[i]) * h)
                        + static_cast<unsigned char>(source[i + m])) % mod;

            if(textHash < 0){
                textHash += mod;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    stats.executionTime = chrono::duration<double, milli>(end - start).count();

    return stats;
}
