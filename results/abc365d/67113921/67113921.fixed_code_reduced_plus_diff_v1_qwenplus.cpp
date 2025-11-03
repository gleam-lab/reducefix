#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    long long wins = 0;
    char prev = 'a'; // No move has been made initially
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If the winning move is different from the previous move, we can use it
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // If the winning move is same as previous, we must play the opponent's move
            // to avoid repeating our own move (we cannot repeat our move)
            prev = c;
        }
    }
    
    cout << wins;
    return 0;
}