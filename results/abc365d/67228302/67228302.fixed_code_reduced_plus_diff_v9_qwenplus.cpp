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
    char last_winner = s[0]; // The move that would beat the current champion

    for (int i = 1; i < n; i++) {
        // If current challenger can beat the last winner, then a new game starts
        if (beats[s[i]] == last_winner) {
            total++;
            last_winner = s[i];
        }
        // Otherwise, the last_winner remains, and we just update to be beaten by the same rule
        // But if the current challenger is the same as the last_winner, then nothing changes
        else if (s[i] != last_winner) {
            // The last_winner stays, but now to beat the champion you must beat s[i]
            // Actually, the champion remains, so only way to beat is still beating last_winner
            // So we don't change last_winner unless someone beats it
            // But if s[i] is beaten by last_winner, then last_winner stays
            // We don't need to update last_winner in this case
        }
        // If s[i] == last_winner, no change either
    }

    cout << total << endl;

    return 0;
}