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
    vector<char> moves;

    // We'll track the sequence of moves our bot makes
    moves.push_back(beats[s[0]]);

    for (int i = 1; i < n; ++i) {
        char next_move = beats[s[i]];

        // If the current move is not the same as the previous one,
        // we need to change our move
        if (moves.empty() || next_move != moves.back()) {
            moves.push_back(next_move);
        }
    }

    cout << moves.size() << endl;

    return 0;
}