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
            // Our current move gets beaten by opponent's move, no point, continue
            last_move = s[i];
        } else {
            // We win this round
            last_move = beats[s[i]];
            total_1 += 1;
        }
    }

    // Case 2: First move is the same as opponent's first move
    int total_2 = 0;
    last_move = s[0]; // we play same move as opponent, no win
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            // Our previous move beats opponent's current move
            // So we won this round
            last_move = s[i];
        } else {
            // We change to beating their move
            last_move = beats[s[i]];
            total_2 += 1;
        }
    }

    // Case 3: First move beats opponent's first move
    int total_3 = 1;
    last_move = beats[s[0]]; // already beat first move
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            // Cannot repeat the same strategy, must switch
            last_move = s[i];
        } else {
            // Continue with winning strategy
            last_move = beats[s[i]];
            total_3 += 1;
        }
    }

    cout << max({total_1, total_2, total_3}) << endl;

    return 0;
}