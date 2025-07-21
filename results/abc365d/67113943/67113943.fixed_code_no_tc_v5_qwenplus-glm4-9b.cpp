#include <iostream>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;

    int wins = 0;
    char winmove = 'R';  // Start with Rock as the winning move for Rock, Paper, Scissors game
    char prev = 'R';     // Assume the first move is Rock
    
    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == 'R') {
            winmove = 'P';  // Paper beats Rock
        } else if (c == 'P') {
            winmove = 'S';  // Scissors beats Paper
        } else if (c == 'S') {
            winmove = 'R';  // Rock beats Scissors
        }
        if (winmove != prev) {
            wins++;          // Increment wins when the winning move changes
            prev = winmove;  // Update previous move to the new winning move
        } else {
            prev = c;        // Update previous move to the current move if no change in winning move
        }
    }

    cout << wins;
}