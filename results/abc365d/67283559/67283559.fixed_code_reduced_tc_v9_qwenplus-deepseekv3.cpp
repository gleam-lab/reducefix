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
    
    // dp[i][c] represents the maximum score up to index i, where the last move is c ('R', 'P', 'S')
    vector<unordered_map<char, int>> dp(N);
    
    // Initialize the first step
    dp[0]['R'] = (S[0] == 'S') ? 1 : 0;
    dp[0]['P'] = (S[0] == 'R') ? 1 : 0;
    dp[0]['S'] = (S[0] == 'P') ? 1 : 0;
    
    for (int i = 1; i < N; ++i) {
        // For each possible current move
        for (char current : {'R', 'P', 'S'}) {
            int current_score = ( (current == 'R' && S[i] == 'S') || 
                                 (current == 'P' && S[i] == 'R') || 
                                 (current == 'S' && S[i] == 'P') ) ? 1 : 0;
            // The previous move must be different from current
            int max_prev = 0;
            for (char prev : {'R', 'P', 'S'}) {
                if (prev != current) {
                    max_prev = max(max_prev, dp[i-1][prev]);
                }
            }
            dp[i][current] = max_prev + current_score;
        }
    }
    
    // The answer is the maximum score at the last step
    int max_score = max({dp[N-1]['R'], dp[N-1]['P'], dp[N-1]['S']});
    cout << max_score << endl;
    
    return 0;
}