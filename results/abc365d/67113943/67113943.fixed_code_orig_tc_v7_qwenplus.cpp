#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char prev = 'X'; // Use a placeholder that doesn't match any move
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // If we used the same winning move, we can choose any move,
            // but to maximize future wins, we should choose the opponent's current move
            // This sets us up to potentially win the next round
            prev = c;
        }
    }   
    cout << wins;
}