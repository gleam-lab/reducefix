#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    char last_move = 'N'; // Last move played by Takahashi
    int ans = 0;
    
    for (char c : S) {
        if (c == 'R') {
            // Opponent plays Rock
            if (last_move != 'P') {
                // We haven't just played Paper, so we can play Paper to win
                ans++;
                last_move = 'P';
            } else {
                // We just played Paper, so we must play something else (non-winning)
                last_move = 'S'; // Arbitrarily choose Scissors
            }
        } else if (c == 'P') {
            // Opponent plays Paper
            if (last_move != 'S') {
                // We haven't just played Scissors, so we can play Scissors to win
                ans++;
                last_move = 'S';
            } else {
                // We just played Scissors, so we must play something else
                last_move = 'R'; // Arbitrarily choose Rock
            }
        } else if (c == 'S') {
            // Opponent plays Scissors
            if (last_move != 'R') {
                // We haven't just played Rock, so we can play Rock to win
                ans++;
                last_move = 'R';
            } else {
                // We just played Rock, so we must play something else
                last_move = 'P'; // Arbitrarily choose Paper
            }
        }
    }
    
    cout << ans;
    return 0;
}