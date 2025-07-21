#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    int wins = 0;
    char prev_move = '\0';
    
    for (int i = 0; i < N; ) {
        char current = S[i];
        char win_move;
        if (current == 'R') {
            win_move = 'P';
        } else if (current == 'P') {
            win_move = 'S';
        } else { // 'S'
            win_move = 'R';
        }
        
        if (win_move != prev_move) {
            wins++;
            prev_move = win_move;
            i++;
        } else {
            // Look ahead to find the next different move
            int j = i;
            while (j < N && S[j] == current) {
                j++;
            }
            if (j < N) {
                char next = S[j];
                char next_win_move;
                if (next == 'R') {
                    next_win_move = 'P';
                } else if (next == 'P') {
                    next_win_move = 'S';
                } else { // 'S'
                    next_win_move = 'R';
                }
                if (next_win_move != prev_move) {
                    wins++;
                    prev_move = next_win_move;
                    i = j + 1;
                } else {
                    prev_move = '\0';
                    i = j;
                }
            } else {
                i = j;
            }
        }
    }
    
    cout << wins << endl;
    return 0;
}