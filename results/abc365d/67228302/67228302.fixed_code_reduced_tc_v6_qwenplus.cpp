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

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int total = 1;
    char last_winner = beats[s[0]]; // What move would beat the first opponent's move

    for (int i = 1; i < n; i++) {
        // If current opponent move is same as previous or doesn't change the required winning move
        // we can potentially use same strategy
        if (beats[s[i]] != last_winner) {
            total++;
            last_winner = beats[s[i]];
        }
    }

    cout << total << endl;

    return 0;
}