#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    char past = 'N'; // Tracks the last move we chose to play
    int ans = 0;
    
    for (char c : S) {
        if (c == 'P') {
            // Opponent plays Paper
            // To win, we should play Scissors; to tie, play Paper
            if (past != 'S') {
                ans++;
                past = 'S'; // Play Scissors to beat Paper
            } else {
                past = 'P'; // Already played Scissors, now play Paper (tie)
            }
        } else if (c == 'R') {
            // Opponent plays Rock
            // To win, we should play Paper; to tie, play Rock
            if (past != 'P') {
                ans++;
                past = 'P'; // Play Paper to beat Rock
            } else {
                past = 'R'; // Already played Paper, now play Rock (tie)
            }
        } else if (c == 'S') {
            // Opponent plays Scissors
            // To win, we should play Rock; to tie, play Scissors
            if (past != 'R') {
                ans++;
                past = 'R'; // Play Rock to beat Scissors
            } else {
                past = 'S'; // Already played Rock, now play Scissors (tie)
            }
        }
    }
    
    cout << ans;
    return 0;
}