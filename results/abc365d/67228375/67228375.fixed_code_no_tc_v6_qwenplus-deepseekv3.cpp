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

    // Strategy 1: Win the first move
    int total_1 = 1;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] != last_move) {
            total_1++;
            last_move = beats[s[i]];
        }
    }

    // Strategy 2: Don't win the first move
    int total_2 = 0;
    last_move = s[0];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] != last_move) {
            total_2++;
            last_move = beats[s[i]];
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}