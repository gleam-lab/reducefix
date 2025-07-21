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

    int switches = 0;
    char current = s[0]; // Start by copying the first move

    for (int i = 1; i < n; ++i) {
        if (beats[s[i]] == current) {
            // Need to switch to beat the current move
            current = beats[s[i]];
            switches++;
        } else if (s[i] != current) {
            // Current move doesn't beat or tie, so switch to beat if advantageous
            // But to maximize switches, we can switch even if it's not necessary
            // So we switch to the move that beats the current opponent's move
            current = beats[s[i]];
            switches++;
        }
    }

    cout << switches << endl;

    return 0;
}