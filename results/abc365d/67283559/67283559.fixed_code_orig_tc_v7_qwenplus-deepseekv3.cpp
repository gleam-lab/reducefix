#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // The three possible moves: Rock, Paper, Scissors
    vector<char> moves = {'R', 'P', 'S'};
    
    // DP table: dp[i][j] represents the maximum score up to position i with last move j
    vector<vector<int>> dp(N + 1, vector<int>(3, 0));
    
    // Initialize the first move
    for (int j = 0; j < 3; ++j) {
        char move = moves[j];
        if ((move == 'R' && S[0] == 'S') || (move == 'P' && S[0] == 'R') || (move == 'S' && S[0] == 'P')) {
            dp[1][j] = 1;
        } else {
            dp[1][j] = 0;
        }
    }
    
    // Fill the DP table
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            char current_move = moves[j];
            int current_score = 0;
            if ((current_move == 'R' && S[i-1] == 'S') || (current_move == 'P' && S[i-1] == 'R') || (current_move == 'S' && S[i-1] == 'P')) {
                current_score = 1;
            }
            // The previous move must be different from the current move
            for (int k = 0; k < 3; ++k) {
                if (k != j) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + current_score);
                }
            }
        }
    }
    
    // The answer is the maximum score after N moves
    int max_score = max({dp[N][0], dp[N][1], dp[N][2]});
    cout << max_score << endl;
    
    return 0;
}