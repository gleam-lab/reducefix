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
    char prev = S[0]; // Start with the first move of Aoki
    
    // Iterate through Aoki's moves starting from the second one
    for (size_t i = 1; i < N; ++i) {
        char current = S[i];
        char winmove;
        
        // Determine Takahashi's winning move based on Aoki's current move
        if (current == 'R') {
            winmove = 'P';
        } else if (current == 'P') {
            winmove = 'S';
        } else { // current == 'S'
            winmove = 'R';
        }
        
        // If Takahashi's move differs from the previous move, increment wins
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            prev = current;
        }
    }

    // Output the maximum number of games Takahashi could have won
    cout << wins << endl;
}