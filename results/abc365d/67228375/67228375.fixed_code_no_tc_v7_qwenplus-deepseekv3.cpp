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
    
    int max_wins = 0;
    char current_move;
    
    // Try all possible first moves (R, P, S)
    for (char initial : {'R', 'P', 'S'}) {
        current_move = initial;
        int wins = (current_move == beats[s[0]]);
        
        for (int i = 1; i < n; i++) {
            // If current move beats next move, keep it
            if (current_move == beats[s[i]]) {
                wins++;
            } else {
                // Otherwise, switch to the move that beats next move
                current_move = beats[s[i]];
            }
        }
        max_wins = max(max_wins, wins);
    }
    
    cout << max_wins << endl;

    return 0;
}