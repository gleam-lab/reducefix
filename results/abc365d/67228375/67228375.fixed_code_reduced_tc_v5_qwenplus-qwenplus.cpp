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

    // Case 1: Start with the first move's winning move
    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            continue; // Continue using the same move
        }
        last_move = beats[s[i]];
        total_1 += 1;
    }

    // Case 2: Start by playing the first move itself
    int total_2 = 0;
    last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            continue; // Opponent's move is beaten by current move
        }
        last_move = beats[s[i]];
        total_2 += 1;
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}