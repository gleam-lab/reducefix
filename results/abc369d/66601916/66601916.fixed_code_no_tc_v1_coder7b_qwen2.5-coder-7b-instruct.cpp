#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>

using namespace std;

#define INF (long long)1e18+7

int main(){
    int n;
    long long dp[2] = {0, -INF}; // Initialize two states: dp[0] for not defeating the current monster, dp[1] for defeating the current monster
    long long x;
    
    cin >> n;

    for ( int i = 0; i < n; i++) {
        cin >> x;
        // Update dp states based on whether to defeat or not defeat the current monster
        dp[i % 2] = max(dp[(i-1) % 2], dp[i % 2]); // Not defeating the current monster
        dp[(i+1) % 2] = max(dp[i % 2] + x + (i % 2 == 1 ? x : 0), dp[(i+1) % 2]); // Defeating the current monster, add extra points if it's an even-indexed defeat
    }

    cout << max(dp[0], dp[1]) << endl; // Output the maximum points between not defeating and defeating the last monster
    return 0;
}