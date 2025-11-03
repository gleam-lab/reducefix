#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char prev = 'a'; // previous move played by us
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If our winning move is different from previous move, we can play it and win
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } 
        // Otherwise, we are forced to play the opponent's move (or same as prev) to avoid changing hand,
        // but this won't win, so we just update our current state to opponent's move
        else {
            prev = c;
        }
    }
    
    cout << wins;
    return 0;
}