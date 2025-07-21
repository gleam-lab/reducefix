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

    int total = 1;
    char last_move = beats[s[0]];

    for (int i = 1; i < n; i++) {
        char current_beat = beats[s[i]];
        if (current_beat == last_move) {
            // Current move is the same as previous, no new move needed
            continue;
        }
        // Update to the new move
        last_move = current_beat;
        total++;
    }

    cout << total << endl;

    return 0;
}