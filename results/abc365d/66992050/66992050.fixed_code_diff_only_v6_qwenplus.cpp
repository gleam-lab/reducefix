#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    char past = 'N'; // Tracks the last move we chose to make
    int ans = 0;
    
    for (char c : S) {
        if (c == 'P') {
            // If opponent plays Paper, we should play Scissors to win
            if (past != 'S') {
                ans++;
                past = 'S';
            } else {
                past = 'P'; // We lost or tied, so update state
            }
        } else if (c == 'R') {
            // If opponent plays Rock, we should play Paper to win
            if (past != 'P') {
                ans++;
                past = 'P';
            } else {
                past = 'R';
            }
        } else if (c == 'S') {
            // If opponent plays Scissors, we should play Rock to win
            if (past != 'R') {
                ans++;
                past = 'R';
            } else {
                past = 'S';
            }
        }
    }
    
    cout << ans;
    return 0;
}