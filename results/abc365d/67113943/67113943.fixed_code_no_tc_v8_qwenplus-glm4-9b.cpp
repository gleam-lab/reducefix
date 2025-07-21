#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    
    int wins = 0;
    char prev = ' '; // Initialize prev to a space to handle the first character comparison correctly
    for (char c : S) {
        // Determine the winning move for the current character
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }
        
        // Check if the current winning move is different from the previous one
        if (winmove != prev) {
            wins++; // Increment the win count if the winning move changes
            prev = winmove; // Update prev to the winning move
        } else {
            prev = c; // Update prev to the current character if no change in winning move
        }
    }
    
    cout << wins << endl; // Output the number of wins
    return 0;
}