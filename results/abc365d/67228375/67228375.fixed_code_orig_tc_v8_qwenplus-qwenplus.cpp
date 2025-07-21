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

    // Strategy 1: First move is the beat of the first character
    int total1 = 1;
    char last_move1 = beats[s[0]];
    for (int i = 1; i < n; ++i) {
        if (beats[s[i]] == last_move1) {
            last_move1 = s[i];  // opponent's move
        } else {
            last_move1 = beats[s[i]];
            total1++;
        }
    }

    // Strategy 2: First move is the actual character (no initial point)
    int total2 = 0;
    char last_move2 = s[0];
    for (int i = 1; i < n; ++i) {
        if (beats[s[i]] == last_move2) {
            last_move2 = s[i];
        } else {
            last_move2 = beats[s[i]];
            total2++;
        }
    }

    cout << max(total1, total2) << endl;

    return 0;
}