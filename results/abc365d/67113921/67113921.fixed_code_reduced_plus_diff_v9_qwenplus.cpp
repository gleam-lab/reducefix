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
        
        // If we can use the winning move without repeating the previous move
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // We cannot repeat the same move, so we must choose a non-winning move
            // But we still need to make a move that doesn't conflict with prev
            // Choose any move different from prev (it won't be a win)
            if (winmove == 'R') {
                prev = (prev == 'P') ? 'S' : 'P';
            } else if (winmove == 'P') {
                prev = (prev == 'R') ? 'S' : 'R';
            } else { // winmove == 'S'
                prev = (prev == 'R') ? 'P' : 'R';
            }
        }
    }   
    cout << wins;
}