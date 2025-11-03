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
    
    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // Only count a win if we play the winning move and it's different from previous move
        if (winmove != last_played) {
            wins++;
            last_played = winmove;
        } else {
            // If we can't play the winning move (due to constraint), we play the losing move
            last_played = c;
        }
    }   
    cout << wins;
    return 0;
}