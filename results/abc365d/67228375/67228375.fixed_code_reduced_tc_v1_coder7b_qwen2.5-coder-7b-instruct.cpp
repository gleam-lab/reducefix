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

    // Initialize counters for wins
    int wins = 0;

    // Track the previous move
    char prev_move = '\0';

    for (int i = 0; i < n; ++i) {
        char current_move = s[i];

        // Check if Takahashi can win this round
        if (beats[current_move] != prev_move) {
            ++wins;
        }

        // Update the previous move
        prev_move = current_move;
    }

    cout << wins << endl;

    return 0;
}