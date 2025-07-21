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
    
    // DP table: dp[i][c] represents the maximum score up to the i-th round using move c
    // c can be 'R', 'P', 'S'
    vector<unordered_map<char, int>> dp(N);
    
    // Initialize the first round
    dp[0]['R'] = (S[0] == 'S') ? 1 : 0;
    dp[0]['P'] = (S[0] == 'R') ? 1 : 0;
    dp[0]['S'] = (S[0] == 'P') ? 1 : 0;
    
    for (int i = 1; i < N; ++i) {
        // For each possible move in the current round
        for (char current : {'R', 'P', 'S'}) {
            int score = (current == 'R' && S[i] == 'S') ? 1 :
                        (current == 'P' && S[i] == 'R') ? 1 :
                        (current == 'S' && S[i] == 'P') ? 1 : 0;
            
            // The previous move cannot be the same as the current move
            for (char prev : {'R', 'P', 'S'}) {
                if (prev != current) {
                    if (dp[i][current] < dp[i-1][prev] + score) {
                        dp[i][current] = dp[i-1][prev] + score;
                    }
                }
            }
        }
    }
    
    // The answer is the maximum score in the last round considering all possible moves
    int max_score = max({dp[N-1]['R'], dp[N-1]['P'], dp[N-1]['S']});
    cout << max_score << endl;
    
    return 0;
}