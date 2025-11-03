#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = 'a'; // no previous move
    
    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // We can win this round if we play winmove
        // We are free to choose our move as long as it's not constrained by previous
        if (prev != winmove) {
            wins++;
            prev = winmove; // we choose to play the winning move
        } else {
            // We cannot play winmove because it was just played
            // So we must play something else, and we won't win this round
            // But we still need to pick a move different from prev
            // Doesn't matter which one as long as it's not prev
            // For consistency, pick the next in rotation that isn't winmove
            if (winmove == 'R') {
                prev = 'P'; // pick P (which beats R), though we don't win
            } else if (winmove == 'P') {
                prev = 'S';
            } else { // winmove == 'S'
                prev = 'R';
            }
        }
    }   
    cout << wins;
}