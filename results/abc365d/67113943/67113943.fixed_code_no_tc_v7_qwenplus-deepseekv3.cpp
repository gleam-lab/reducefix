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
    char prev_move = '\0'; // Initialize with no previous move
    
    for (char c : S){
        char current_move;
        if (c == 'R'){
            current_move = 'P';
        } else if (c == 'P'){
            current_move = 'S';
        } else { // 'S'
            current_move = 'R';
        }
        
        if (current_move != prev_move) {
            wins++;
            prev_move = current_move;
        } else {
            // Don't count this as a win, but keep previous move
            // This allows us to potentially win the next round
            // if it's the same opponent move
        }
    }
    cout << wins;
    return 0;
}