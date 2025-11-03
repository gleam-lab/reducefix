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

    // Count maximum number of wins by choosing optimal starting move
    int max_wins = 0;

    // Try all three possible starting moves
    for (char start : {'R', 'P', 'S'}) {
        int wins = 0;
        char current_move = start;
        
        for (int i = 0; i < n; i++) {
            // If our move beats opponent's move
            if (beats[opponent_move] == current_move) {
                wins++;
            }
            // Update our next move based on opponent's current move
            // We should play the move that beats the opponent's current move
            current_move = beats[s[i]];
        }
        
        max_wins = max(max_wins, wins);
    }

    cout << max_wins << endl;

    return 0;
}