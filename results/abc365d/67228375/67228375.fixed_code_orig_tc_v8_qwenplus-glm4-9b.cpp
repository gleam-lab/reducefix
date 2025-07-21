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
    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        // Only increment if the current move beats the last move
        if (beats[s[i]] == last_move) {
            total_1++;
        } else {
            // Reset the last move and total_1 if the beat does not happen
            last_move = beats[s[i]];
            total_1 = 1;
        }
    }
    int total_2 = 1; // Reset starting from the second character
    last_move = beats[s[1]];
    for (int i = 2; i < n; i++) {
        // Only increment if the current move beats the last move
        if (beats[s[i]] == last_move) {
            total_2++;
        } else {
            // Reset the last move and total_2 if the beat does not happen
            last_move = beats[s[i]];
            total_2 = 1;
        }
    }
    cout << max(total_1, total_2) << endl;

    return 0;
}