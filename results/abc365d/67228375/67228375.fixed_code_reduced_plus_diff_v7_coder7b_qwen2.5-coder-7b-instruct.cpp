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
    
    // Initialize counters for both players
    int player1 = 0, player2 = 0;
    int total_moves = n;

    // Determine the moves for Player 1
    char last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            last_move = s[i];
            continue;
        }
        last_move = beats[s[i]];
        player1++;
    }

    // Reset last move for Player 2 and determine the moves
    last_move = s[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (beats[s[i]] == last_move) {
            last_move = s[i];
            continue;
        }
        last_move = beats[s[i]];
        player2++;
    }

    // The total number of moves is the sum of moves made by both players
    cout << max(player1 + 1, player2 + 1) << endl; // Adding 1 because the first move is always by Player 1

    return 0;
}