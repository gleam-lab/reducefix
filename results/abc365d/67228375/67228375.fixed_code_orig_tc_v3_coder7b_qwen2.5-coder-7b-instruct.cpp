#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Initialize variables to count the number of moves required to change the sequence
    int total_moves = 0;
    char last_move = s[0];
    
    // Iterate through the string starting from the second character
    for (int i = 1; i < n; i++) {
        // If the current move is not what we want based on the last move, increment the move counter
        if (beats[last_move] != s[i]) {
            total_moves++;
        }
        // Update the last move to the current one
        last_move = s[i];
    }

    // The result is the total moves plus one (for the initial state)
    cout << total_moves + 1 << endl;

    return 0;
}