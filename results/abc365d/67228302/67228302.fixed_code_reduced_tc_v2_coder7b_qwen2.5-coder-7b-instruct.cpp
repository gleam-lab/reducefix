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
    
    // Initialize variables
    int wins = 0;
    char last_move = ' '; // Initial value can be any character not in 'RPS'

    // Iterate through each move in the sequence
    for (char move : s) {
        // If Takahashi's move beats Aoki's move
        if (move == beats[last_move]) {
            wins++; // Increment win count
        }
        // Update last move to current move
        last_move = move;
    }

    cout << wins << endl;

    return 0;
}