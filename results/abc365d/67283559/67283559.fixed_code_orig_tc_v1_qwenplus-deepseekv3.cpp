#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // dp[i][c] represents the maximum score up to position i, ending with character c
    vector<unordered_map<char, int>> dp(N);
    
    // Initialize the first step
    for (char c : {'R', 'P', 'S'}) {
        if (c == 'R' && S[0] == 'S') {
            dp[0][c] = 1;
        } else if (c == 'P' && S[0] == 'R') {
            dp[0][c] = 1;
        } else if (c == 'S' && S[0] == 'P') {
            dp[0][c] = 1;
        } else {
            dp[0][c] = 0;
        }
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
            if (current == 'R' && S[i] == 'S') {
                score = 1;
            } else if (current == 'P' && S[i] == 'R') {
                score = 1;
            } else if (current == 'S' && S[i] == 'P') {
                score = 1;
            }
            dp[i][current] = max_prev + score;
        }
    }

    int max_score = 0;
    for (char c : {'R', 'P', 'S'}) {
        max_score = max(max_score, dp[N-1][c]);
    }

    cout << max_score << endl;
    return 0;
}