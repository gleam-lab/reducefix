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
    char prev = ' '; // To keep track of previous move of Takahashi
    
    for (int i = 0; i < N; ++i) {
        char aoki_move = S[i];
        
        // Determine Takahashi's move based on Aoki's move
        char takahashi_move;
        if (aoki_move == 'R') takahashi_move = 'P'; // Rock loses to Paper
        else if (aoki_move == 'P') takahashi_move = 'S'; // Paper loses to Scissors
        else takahashi_move = 'R'; // Scissors lose to Rock
        
        // Check if Takahashi can avoid losing to Aoki
        if (takahashi_move != prev) {
            ++wins;
            prev = takahashi_move;
        }
    }

    cout << wins << endl;
    return 0;
}