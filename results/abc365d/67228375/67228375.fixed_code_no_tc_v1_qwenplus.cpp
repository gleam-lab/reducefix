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

    // Case 1: First move beats opponent's first move
    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (s[i] == last_move) {
            // We lose or tie, so we must change strategy
            last_move = beats[s[i]];
            total_1++;
        } else {
            // We win, continue with same move
            last_move = beats[s[i]];
        }
    }

    // Case 2: First move is beaten by opponent's first move (we start with opponent's first move)
    int total_2 = 1;
    last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == last_move) {
            // We lose or tie, so we must change strategy
            last_move = beats[s[i]];
            total_2++;
        } else {
            // We win, continue with same move
            last_move = beats[s[i]];
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}