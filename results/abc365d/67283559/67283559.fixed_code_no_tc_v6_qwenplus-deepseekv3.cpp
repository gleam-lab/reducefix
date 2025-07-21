#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // dp[i][c] = max score up to position i when last choice was c
    vector<unordered_map<char, int>> dp(N);
    
    // Initialize first move
    if (S[0] == 'S') dp[0]['R'] = 1;
    else if (S[0] == 'R') dp[0]['P'] = 1;
    else if (S[0] == 'P') dp[0]['S'] = 1;
    
    for (int i = 1; i < N; i++) {
        char opponent = S[i];
        
        // For each possible current choice
        for (char current : {'R', 'P', 'S'}) {
            int score = 0;
            if (current == 'R' && opponent == 'S') score = 1;
            else if (current == 'P' && opponent == 'R') score = 1;
            else if (current == 'S' && opponent == 'P') score = 1;
            
            // Find the best previous choice that's different from current
            int max_prev = 0;
            for (char prev : {'R', 'P', 'S'}) {
                if (prev != current && (i == 1 || dp[i-1].count(prev))) {
                    int prev_score = (i == 1) ? dp[0][prev] : dp[i-1][prev];
                    max_prev = max(max_prev, prev_score);
                }
            }
            
            dp[i][current] = max_prev + score;
        }
    }
    
    // Find the maximum score from the last position
    int max_score = 0;
    for (auto& [c, score] : dp[N-1]) {
        max_score = max(max_score, score);
    }
    
    cout << max_score << endl;
    return 0;
}