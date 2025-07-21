#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // The three possible hands: Rock, Paper, Scissors
    vector<char> hands = {'R', 'P', 'S'};
    
    // DP table: dp[i][c] represents the maximum score up to index i when the last move is c
    vector<unordered_map<char, int>> dp(N);
    
    // Initialize the first move
    for (char c : hands) {
        if (c == 'R' && S[0] == 'S') dp[0][c] = 1;
        else if (c == 'P' && S[0] == 'R') dp[0][c] = 1;
        else if (c == 'S' && S[0] == 'P') dp[0][c] = 1;
        else dp[0][c] = 0;
    }
    
    // Fill the DP table
    for (int i = 1; i < N; ++i) {
        for (char current : hands) {
            int score = 0;
            if (current == 'R' && S[i] == 'S') score = 1;
            else if (current == 'P' && S[i] == 'R') score = 1;
            else if (current == 'S' && S[i] == 'P') score = 1;
            
            // The previous move must be different from current
            int max_prev = 0;
            for (char prev : hands) {
                if (prev != current) {
                    max_prev = max(max_prev, dp[i-1][prev]);
                }
            }
            dp[i][current] = max_prev + score;
        }
    }
    
    // The answer is the maximum score in the last move
    int max_score = 0;
    for (char c : hands) {
        max_score = max(max_score, dp[N-1][c]);
    }
    
    cout << max_score << endl;
    return 0;
}