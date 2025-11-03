#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char last_played = 0; // No move played initially
    
    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // Only count a win if we can play the winning move
        // and it's different from our previous move
        if (last_played != winmove) {
            wins++;
            last_played = winmove;
        } else {
            // We have to play something, so we play the opponent's move
            // This won't win, but it sets up for future moves
            last_played = c;
        }
    }   
    cout << wins;
    return 0;
}