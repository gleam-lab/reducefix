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

    // To count the number of 1s in the sequence.
    int total = 0;
    char last_move = 'R'; // Since 'R' beats 'P', which is the first character in the sequence.

    for (int i = 0; i < n; i++) {
        // Calculate the winning move for the current move.
        char winning_move = beats[s[i]];
        if (winning_move == last_move) {
            continue; // If the current move is beaten by the last move, we skip to the next.
        }
        // Otherwise, we've found a 1, so we increment the total.
        total++;
        last_move = winning_move; // Update the last move.
    }

    cout << total << endl;

    return 0;

}