#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char last_move = ' '; // No move initially
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If we can use the winning move without repeating the previous move
        if (winmove != last_move) {
            wins++;
            last_move = winmove;
        } else {
            // Otherwise, we have to play the losing or same move, so no win
            // But we must update last_move to something; use the current opponent's move
            // This avoids blocking future wins unnecessarily
            last_move = c;
        }
    }
    
    cout << wins;
}