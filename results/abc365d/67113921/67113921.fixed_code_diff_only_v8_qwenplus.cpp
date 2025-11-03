#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char last_move = ' '; // No previous move initially
    
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
        if (last_move != winmove) {
            wins++;
        }
        last_move = winmove;
    }   
    cout << wins;
    return 0;
}