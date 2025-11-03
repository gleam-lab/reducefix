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

    // Try both possible starting moves for the opponent
    auto simulate = [&](char first_opponent_move) {
        int rounds_won = 1; // First round is always won by us
        char opponent_last = first_opponent_move;
        
        for (int i = 1; i < n; i++) {
            char our_move = s[i];
            char winning_move = beats[our_move];
            
            if (winning_move == opponent_last) {
                // Opponent repeats their move, we win
                opponent_last = our_move;
            } else {
                // Opponent changes to beat our previous move
                opponent_last = winning_move;
                rounds_won++;
            }
        }
        return rounds_won;
    };

    // Try both possibilities for opponent's first move
    char first_our_move = s[0];
    char first_opponent_alternative1 = first_our_move;  // Opponent plays same as us
    char first_opponent_alternative2 = beats[first_our_move];  // Opponent plays what beats us
    
    int result1 = simulate(first_opponent_alternative1);
    int result2 = simulate(first_opponent_alternative2);
    
    cout << max(result1, result2) << endl;

    return 0;
}