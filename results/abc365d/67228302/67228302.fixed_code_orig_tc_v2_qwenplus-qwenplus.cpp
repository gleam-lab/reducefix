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
    vector<char> moves;  // This will store the sequence of moves we choose
    moves.push_back(beats[s[0]]);  // First move is always the beat of the first opponent move

    for (int i = 1; i < n; ++i) {
        char opponent_move = s[i];
        char our_next_move = beats[opponent_move];

        // We can only add a new move if it's different from the last one
        if (our_next_move != moves.back()) {
            moves.push_back(our_next_move);
        }
    }

    cout << moves.size() << endl;

    return 0;
}