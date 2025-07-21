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

    // Strategy 1: Start with the move that beats the first move of opponent
    int total1 = 1;
    char last_move1 = beats[s[0]];
    for (int i = 1; i < n; ++i) {
        if (beats[s[i]] == last_move1) {
            continue; // no new sequence needed
        } else {
            last_move1 = beats[s[i]]; // switch to new optimal move
            total1 += 1;
        }
    }

    // Strategy 2: Start by playing the same as opponent's first move
    int total2 = 1;
    char last_move2 = s[0];
    for (int i = 1; i < n; ++i) {
        if (beats[s[i]] == last_move2) {
            continue; // no new sequence needed
        } else {
            last_move2 = beats[s[i]]; // switch to new optimal move
            total2 += 1;
        }
    }

    cout << max(total1, total2) << endl;

    return 0;
}