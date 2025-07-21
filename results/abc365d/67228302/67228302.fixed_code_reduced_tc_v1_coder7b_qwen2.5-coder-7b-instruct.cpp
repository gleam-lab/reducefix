#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total_wins = 0;
    
    // Determine Takahashi's move based on Aoki's first move
    char takahashi_first_move = beats[s[0]];
    
    // Initialize the previous move to be the first move of Takahashi
    char prev_takahashi_move = takahashi_first_move;
    
    for (int i = 0; i < n; i++) {
        char aoki_move = s[i];
        
        // Determine the expected move for Takahashi to win against Aoki's move
        char expected_takahashi_move = beats[aoki_move];
        
        // Check if Takahashi's move alternates correctly
        if (prev_takahashi_move != expected_takahashi_move) {
            total_wins++;
            prev_takahashi_move = expected_takahashi_move;
        } else {
            // If not alternating, take the next move that beats Aoki's move
            prev_takahashi_move = expected_takahashi_move;
        }
    }
    
    cout << total_wins << endl;
    
    return 0;
}