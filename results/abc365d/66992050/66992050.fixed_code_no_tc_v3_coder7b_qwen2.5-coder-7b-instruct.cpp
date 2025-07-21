#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    // Initialize variables
    int wins = 0; // Number of games Takahashi could have won
    char lastMove = ' '; // Track the last move made by Takahashi
    
    for(int i = 0; i < N; ++i) {
        char currentMove = S[i];
        
        // Determine the best response for Takahashi to win or at least not lose
        if(currentMove == 'R') {
            if(lastMove != 'P') { // Takahashi plays Paper
                wins++;
                lastMove = 'P';
            } else { // Takahashi plays Scissors
                lastMove = 'S';
            }
        } else if(currentMove == 'P') {
            if(lastMove != 'S') { // Takahashi plays Scissors
                wins++;
                lastMove = 'S';
            } else { // Takahashi plays Rock
                lastMove = 'R';
            }
        } else if(currentMove == 'S') {
            if(lastMove != 'R') { // Takahashi plays Rock
                wins++;
                lastMove = 'R';
            } else { // Takahashi plays Paper
                lastMove = 'P';
            }
        }
    }
    
    // Output the result
    cout << wins << endl;
    
    return 0;
}