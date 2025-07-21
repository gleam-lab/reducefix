#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // DP table: dp[i][c] represents the max score up to position i, ending with character c
    // c can be 'R', 'P', 'S'
    vector<unordered_map<char, int>> dp(N);
    
    // Initialize the first step
    for (char c : {'R', 'P', 'S'}) {
        int score = 0;
        if (c == 'R' && S[0] == 'S') score = 1;
        else if (c == 'P' && S[0] == 'R') score = 1;
        else if (c == 'S' && S[0] == 'P') score = 1;
        dp[0][c] = score;
    }
    
    for (int i = 1; i < N; ++i) {
        for (char current : {'R', 'P', 'S'}) {
            int max_prev = 0;
            for (char prev : {'R', 'P', 'S'}) {
                if (prev != current) {
                    max_prev = max(max_prev, dp[i-1][prev]);
                }
            }
            int score = 0;
            if (current == 'R' && S[i] == 'S') score = 1;
            else if (current == 'P' && S[i] == 'R') score = 1;
            else if (current == 'S' && S[i] == 'P') score = 1;
            dp[i][current] = max_prev + score;
        }
    }
    
    // The answer is the maximum score in the last step
    int max_score = 0;
    for (char c : {'R', 'P', 'S'}) {
        max_score = max(max_score, dp[N-1][c]);
    }
    
    cout << max_score << endl;
    return 0;
}