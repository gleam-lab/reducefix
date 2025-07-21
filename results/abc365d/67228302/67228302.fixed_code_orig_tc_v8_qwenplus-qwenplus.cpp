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

    // We can use a stack-like approach to simulate the optimal sequence of moves
    // that defeats all consecutive characters in s with minimal total moves
    vector<char> moves;

    for (char c : s) {
        if (!moves.empty() && beats[c] == moves.back()) {
            // Current character is defeated by the last move, no need to add a new move
            continue;
        } else {
            // Add the move that defeats current character
            moves.push_back(beats[c]);
        }
    }

    cout << moves.size() << endl;

    return 0;
}