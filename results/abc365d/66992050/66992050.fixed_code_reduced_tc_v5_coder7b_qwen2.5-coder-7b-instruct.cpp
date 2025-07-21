#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    int ans = 0;
    char past = 'X'; // Initialize past move with a value that doesn't affect the first move
    
    for (char c : S) {
        if (c == 'P') {
            if (past != 'R') { // Takahashi should play Rock if Aoki plays Paper
                ans++;
                past = 'R';
            } else { // Otherwise, play Scissors
                past = 'S';
            }
        } else if (c == 'R') {
            if (past != 'S') { // Takahashi should play Scissors if Aoki plays Rock
                ans++;
                past = 'S';
            } else { // Otherwise, play Paper
                past = 'P';
            }
        } else { // c == 'S'
            if (past != 'P') { // Takahashi should play Paper if Aoki plays Scissors
                ans++;
                past = 'P';
            } else { // Otherwise, play Rock
                past = 'R';
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}