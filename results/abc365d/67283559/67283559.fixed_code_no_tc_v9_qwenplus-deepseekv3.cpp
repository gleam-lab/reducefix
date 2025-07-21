#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // DP[i][c] = max score up to position i, ending with move c
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    // Map characters to indices: R=0, P=1, S=2
    auto charToIdx = [](char c) {
        if (c == 'R') return 0;
        if (c == 'P') return 1;
        return 2;
    };
    
    // Initialize first move
    for (int c = 0; c < 3; ++c) {
        char myMove;
        if (c == 0) myMove = 'R';
        else if (c == 1) myMove = 'P';
        else myMove = 'S';
        
        int oppIdx = charToIdx(S[0]);
        if ((myMove == 'R' && S[0] == 'S') ||
            (myMove == 'P' && S[0] == 'R') ||
            (myMove == 'S' && S[0] == 'P')) {
            dp[0][c] = 1;
        } else {
            dp[0][c] = 0;
        }
    }
    
    for (int i = 1; i < N; ++i) {
        int oppIdx = charToIdx(S[i]);
        for (int curr = 0; curr < 3; ++curr) {
            int maxPrev = 0;
            for (int prev = 0; prev < 3; ++prev) {
                if (prev == curr) continue; // Cannot repeat moves
                maxPrev = max(maxPrev, dp[i-1][prev]);
            }
            
            char myMove;
            if (curr == 0) myMove = 'R';
            else if (curr == 1) myMove = 'P';
            else myMove = 'S';
            
            int gain = 0;
            if ((myMove == 'R' && S[i] == 'S') ||
                (myMove == 'P' && S[i] == 'R') ||
                (myMove == 'S' && S[i] == 'P')) {
                gain = 1;
            }
            dp[i][curr] = maxPrev + gain;
        }
    }
    
    int maxScore = 0;
    for (int c = 0; c < 3; ++c) {
        maxScore = max(maxScore, dp[N-1][c]);
    }
    cout << maxScore << endl;
    
    return 0;
}