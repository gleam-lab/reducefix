#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char last_played = ' '; // No move played initially
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // Only count a win if we play the winning move
        // and we don't have to change our move from the previous round
        if (last_played != winmove) {
            wins++;
        }
        last_played = winmove;
    }   
    
    cout << wins;
    return 0;
}