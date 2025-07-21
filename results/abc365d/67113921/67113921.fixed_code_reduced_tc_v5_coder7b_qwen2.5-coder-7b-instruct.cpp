#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    
    // Initialize variables
    int wins = 0;
    char prevMove = ' '; // Track the previous move made by Takahashi
    
    // Iterate through each move by Aoki
    for (int i = 0; i < N; ++i) {
        char aokiMove = S[i];
        
        // Determine Takahashi's move based on Aoki's move
        char takahashiMove;
        if (aokiMove == 'R') takahashiMove = 'P'; // Rock beats Scissors
        else if (aokiMove == 'P') takahashiMove = 'S'; // Paper beats Rock
        else takahashiMove = 'R'; // Scissors beat Paper
        
        // Check if Takahashi can make a winning move without repeating the same move consecutively
        if (takahashiMove != prevMove) {
            ++wins;
            prevMove = takahashiMove; // Update the previous move
        }
    }
    
    // Output the maximum number of games Takahashi could have won
    cout << wins << endl;
    
    return 0;
}