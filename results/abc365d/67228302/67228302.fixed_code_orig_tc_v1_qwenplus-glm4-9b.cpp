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
    int total = 1; // Include the first move
    char last_move = beats[s[0]]; // First move beats this

    for (int i = 1; i < n; i++) {
        // Check if the current move is different and beats the last move
        if (s[i] != last_move && beats[s[i]] == last_move) {
            total++; // Increment total because the current move is valid
            last_move = s[i]; // Update the last move to the current move
        }
    }

    cout << total << endl;

    return 0;
}