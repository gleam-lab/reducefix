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

    // Case 1: First move is beaten by our first move
    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            last_move = s[i];  // We don't change our move
        } else {
            last_move = beats[s[i]];  // We change to beat opponent's current move
            total_1 += 1;
        }
    }

    // Case 2: Start with the same move as opponent's first move
    int total_2 = 0;
    last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            last_move = s[i];  // We keep our previous move
        } else {
            last_move = beats[s[i]];  // Change to beat opponent's current move
            total_2 += 1;
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}