#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev_move = '\0';
    
    for (char c : S) {
        char current_win_move;
        if (c == 'R') {
            current_win_move = 'P';
        } else if (c == 'P') {
            current_win_move = 'S';
        } else { // 'S'
            current_win_move = 'R';
        }
        
        if (current_win_move != prev_move) {
            wins++;
            prev_move = current_win_move;
        } else {
            // If the same winning move can be used again, we can't count it again
            // So, we reset prev_move to avoid counting consecutive same moves
            prev_move = '\0';
        }
    }
    
    cout << wins;
    return 0;
}