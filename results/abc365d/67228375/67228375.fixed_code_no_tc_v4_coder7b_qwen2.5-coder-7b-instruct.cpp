#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Initialize variables to count wins
    int total_wins = 0;
    bool can_win_next = true;
    
    for (int i = 0; i < n; i++) {
        if (can_win_next) {
            // If we can win the next game, do so
            total_wins++;
            // Update the last move based on the current move of Aoki
            if (s[i] == 'R') {
                can_win_next = false; // Next move must be P or S
            } else if (s[i] == 'P') {
                can_win_next = false; // Next move must be R or S
            } else { // s[i] == 'S'
                can_win_next = false; // Next move must be R or P
            }
        } else {
            // If we cannot win the next game, skip it
            can_win_next = true; // Reset for the next possible win
        }
    }
    
    cout << total_wins << endl;

    return 0;
}