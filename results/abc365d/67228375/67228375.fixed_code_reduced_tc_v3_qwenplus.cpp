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

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Try all possible starting moves for the player
    int max_rounds = 1;
    
    // We'll try each of the three possible initial moves
    for (char start : {'R', 'P', 'S'}) {
        int rounds = 1;
        char player_move = start;
        
        for (int i = 0; i < n; i++) {
            char opponent_move = s[i];
            // If current player move loses to opponent, we need to change before this round
            if (beats[player_move] == opponent_move) {
                // We must have switched to a winning move before this round
                // Find a move that beats the opponent's current move
                for (char c : {'R', 'P', 'S'}) {
                    if (beats[c] == opponent_move) {
                        player_move = c;
                        break;
                    }
                }
                rounds++;
            }
            // If we're already winning or drawing, continue with current move
            // After this round, the player's move becomes the one they just played
        }
        max_rounds = max(max_rounds, rounds);
    }

    cout << max_rounds << endl;

    return 0;
}