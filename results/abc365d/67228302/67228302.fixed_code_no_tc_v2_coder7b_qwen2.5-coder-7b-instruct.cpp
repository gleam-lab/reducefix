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
    int wins = 0;
    char last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] != last_move) {
            wins++;
            last_move = beats[last_move];
        } else {
            last_move = beats[s[i]];
        }
    }
    // Check the last move
    if (last_move == s[n-1]) {
        wins++;
    }
    cout << wins << endl;

    return 0;

}