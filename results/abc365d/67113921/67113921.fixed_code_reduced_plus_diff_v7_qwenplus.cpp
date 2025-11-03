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
    char prev = 'a'; // No move made yet
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If the winning move is different from previous move, we can use it
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // If winning move is same as previous, we must play the opponent's move
            // to avoid repeating our own move (rules imply no consecutive same moves by us)
            prev = c;
        }
    }   
    cout << wins;
}