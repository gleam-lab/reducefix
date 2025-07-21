#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    // Initialize variables
    char past = 'N'; // Past move of Takahashi
    int ans = 0;     // Number of games Takahashi wins
    
    for (char c : S) {
        if (c == 'R') { // If Aoki plays Rock
            if (past != 'P') { // If Takahashi can play Paper to win
                ans++;
                past = 'P';
            } else {
                past = 'S'; // Otherwise, play Scissors to draw
            }
        } else if (c == 'P') { // If Aoki plays Paper
            if (past != 'S') { // If Takahashi can play Scissors to win
                ans++;
                past = 'S';
            } else {
                past = 'R'; // Otherwise, play Rock to draw
            }
        } else { // If Aoki plays Scissors
            if (past != 'R') { // If Takahashi can play Rock to win
                ans++;
                past = 'R';
            } else {
                past = 'P'; // Otherwise, play Paper to draw
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}