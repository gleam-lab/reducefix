#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = 'a'; // Initialize prev to a character not present in the game moves ('a' is chosen here)
    
    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }
        
        // Check if the current move beats the previous one
        if ((prev == 'R' && c == 'P') || (prev == 'P' && c == 'S') || (prev == 'S' && c == 'R')) {
            wins++;
            prev = winmove; // Update prev to the winning move
        } else {
            prev = c; // If no win, update prev to the current move
        }
    }
    
    cout << wins << endl;
    return 0;
}