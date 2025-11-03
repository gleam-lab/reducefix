#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    // dp[i][last] = maximum rounds ending at position i with last move being 'last'
    // We only need the previous state, so we use two maps
    map<char, int> prev_dp;
    // Initialize for first character
    prev_dp[beats[s[0]]] = 1; // Alice wins first round by playing the move that beats s[0]
    prev_dp[s[0]] = 0; // Or Alice plays exactly s[0], so no win

    for (int i = 1; i < n; i++) {
        map<char, int> curr_dp;
        char opponent_move = s[i];
        char beat_move = beats[opponent_move];

        // Try all possible moves Alice can make at position i
        vector<char> moves = {'R', 'P', 'S'};
        
        for (char alice_move : moves) {
            int best = 0;
            for (auto& [prev_alice_move, value] : prev_dp) {
                // Check if this transition is valid
                // The opponent's move at i-1 should not beat Alice's move at i
                if (beats[s[i-1]] != alice_move) {
                    best = max(best, value);
                }
            }
            
            // If Alice's move beats opponent's move, she wins this round
            if (alice_move == beat_move) {
                curr_dp[alice_move] = best + 1;
            } else {
                curr_dp[alice_move] = best;
            }
        }
        
        prev_dp = curr_dp;
    }

    int result = 0;
    for (auto& [move, value] : prev_dp) {
        result = max(result, value);
    }
    
    cout << result << endl;

    return 0;
}