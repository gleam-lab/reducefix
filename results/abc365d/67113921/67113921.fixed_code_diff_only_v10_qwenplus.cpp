#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char last_played = ' '; // No move initially
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // Only count a win if we play a different move than last time
        if (last_played != winmove) {
            wins++;
            last_played = winmove;
        } else {
            // If we would repeat the same winning move, we must play the opponent's move instead
            // This doesn't count as a win, and updates our last played move
            last_played = c;
        }
    }
    
    cout << wins;
    return 0;
}