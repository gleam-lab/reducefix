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

    // Try all possible starting moves for the player
    int max_rounds = 1;
    
    // For each possible initial move the player could make
    for (char start : {'R', 'P', 'S'}) {
        int rounds = 1;
        char player_move = start;
        
        for (int i = 0; i < n; i++) {
            char opponent_move = s[i];
            
            // If current player move loses to opponent, we need to change before this round
            if (beats[player_move] == opponent_move) {
                // We must have switched to a winning move before this round
                // Find the move that beats opponent_move
                player_move = beats[opponent_move];
                rounds++;
            }
            // If we win or tie, we can continue with same strategy
            // No need to increment rounds for continuing same move
        }
        max_rounds = max(max_rounds, rounds);
    }
    
    cout << max_rounds << endl;
    return 0;
}