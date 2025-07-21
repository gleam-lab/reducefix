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
    int total_1 = 0;
    int last_move = -1; // Initialize last move to an invalid state
    for (int i = 0; i < n; i++) {
        char current_beat = beats[s[i]];
        if (current_beat == last_move) {
            last_move = -1; // Reset last move indicator
            total_1++;
        }
        last_move = current_beat;
    }
    int total_2 = (last_move == -1) ? 1 : 0; // If last move was the starting point, set total_2 to 1

    cout << max(total_1, total_2) << endl;

    return 0;
}