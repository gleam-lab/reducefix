#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char prev_opponent_move = '\0'; // tracks previous opponent move
    char prev_win_move = '\0';      // tracks our previous winning move
    
    for (char c : S) {
        char win_move;
        if (c == 'R') {
            win_move = 'P';
        } else if (c == 'P') {
            win_move = 'S';
        } else { // 'S'
            win_move = 'R';
        }
        
        // Only count as a win if either:
        // 1. This is the first move
        // 2. The opponent's current move is different from previous
        // 3. Our winning move is different from previous
        if (prev_opponent_move == '\0' || c != prev_opponent_move || win_move != prev_win_move) {
            wins++;
            prev_win_move = win_move;
        }
        prev_opponent_move = c;
    }
    
    cout << wins << '\n';
    return 0;
}