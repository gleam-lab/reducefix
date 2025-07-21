#include <bits/stdc++.h>
using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    // Initialize variables to keep track of wins and current streaks
    ll wins = 0;
    ll current_streak = 0;
    char prev_move = '\0';
    
    for (char move : s) {
        // If it's the first move or the move is different from the previous one, start a new streak
        if (prev_move != move) {
            current_streak = 1;
        } else {
            // Otherwise, increment the current streak
            current_streak++;
        }
        
        // Add half of the current streak to wins (rounded down)
        wins += current_streak / 2;
        
        // Update the previous move
        prev_move = move;
    }
    
    // Print the total number of wins
    cout << wins << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}