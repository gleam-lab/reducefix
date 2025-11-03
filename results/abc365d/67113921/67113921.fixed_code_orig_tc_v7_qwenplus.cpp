#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char last_move = ' '; // No move has been made initially
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If we can use the winning move without repeating the previous move, do it
        if (winmove != last_move) {
            wins++;
            last_move = winmove;
        } else {
            // Otherwise, we must use a different move (which won't win)
            // But we still need to update last_move to avoid repetition in next round
            // We can use either of the other two moves, but it doesn't matter since we're not winning
            // Just ensure it's different from both current opponent's move and our last move
            // However, simpler: just set last_move to opponent's move or anything that breaks the pattern
            // Actually, we just need to pick any move different from last_move
            // Since winmove == last_move, we can pick the losing move as fallback
            if (c == 'R') {
                last_move = 'S'; // Choose S instead of P
            } else if (c == 'P') {
                last_move = 'R'; // Choose R instead of S
            } else {
                last_move = 'P'; // Choose P instead of R
            }
        }
    }
    
    cout << wins;
    return 0;
}