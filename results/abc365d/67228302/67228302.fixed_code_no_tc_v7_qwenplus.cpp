#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: R beats S, P beats R, S beats P
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int total = 1;
    char last_winner = s[0]; // The winner of the current round

    for (int i = 1; i < n; i++) {
        // Check if current move beats the previous winner
        if (beats[s[i]] == last_winner) {
            // Current move wins
            last_winner = s[i];
        } else if (s[i] != last_winner) {
            // Previous winner still wins, no change
            // Do nothing, continue with same last_winner
        }
        // If move is same as last winner, nothing changes either
    }
    
    // Actually, we need to count the number of rounds where the outcome changes
    // Let's rethink: We want the minimum number of distinct rounds such that each round has a consistent winner
    
    // Correct approach: Count maximal consecutive segments where one move dominates
    total = 1;
    char current_winner = s[0];
    
    for (int i = 1; i < n; i++) {
        // If current move beats the current winner, then winner changes and new round starts
        if (beats[s[i]] == current_winner) {
            current_winner = s[i];
            total++;
        }
        // Otherwise, current_winner remains (either same move or current_winner beats s[i])
    }
    
    cout << total << endl;

    return 0;
}