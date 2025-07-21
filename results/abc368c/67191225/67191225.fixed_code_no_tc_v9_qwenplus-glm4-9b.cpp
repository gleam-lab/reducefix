#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> H(N);
    long long totalTurns = 0;
    
    for (long long &h : H) {
        // Calculate full sets of 3 attacks and the remainder
        long long fullSetsOf3 = h / 3;
        long long remainder = h % 3;
        
        // Add the full sets of 3 attacks
        totalTurns += fullSetsOf3 * 3;
        
        // Add the minimum turns needed for the remainder
        // Remainder can be 0, 1, or 2
        // For remainder 0, no additional turns are needed
        // For remainder 1, we need 1 additional turn
        // For remainder 2, we need 2 additional turns (1 turn of -1 and 1 turn of -2)
        if (remainder == 0) {
            // Do nothing
        } else if (remainder == 1) {
            totalTurns += 1;
        } else {
            totalTurns += 2;
        }
    }
    
    cout << totalTurns << endl;
}