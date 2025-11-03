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
    char last_winner = s[0]; // The move that would have won the first round

    for (int i = 1; i < n; i++) {
        // If current move beats the previous winner, then a new tournament starts
        if (beats[s[i]] == last_winner) {
            total++;
            last_winner = s[i];
        } else {
            // Otherwise, the previous winner still dominates
            last_winner = beats[s[i]]; // This is what would beat current move, but we keep chain going
        }
    }

    cout << total << endl;

    return 0;
}