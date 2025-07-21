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

    // Strategy 1: Start with beating the first move
    int total_1 = 1;
    char last_move_1 = beats[s[0]];

    // Strategy 2: Start with same as first move
    int total_2 = 1;
    char last_move_2 = s[0];

    for (int i = 1; i < n; ++i) {
        // Strategy 1 update
        if (beats[s[i]] == last_move_1) {
            last_move_1 = s[i];
        } else {
            last_move_1 = beats[s[i]];
            total_1 += 1;
        }

        // Strategy 2 update
        if (beats[s[i]] == last_move_2) {
            last_move_2 = s[i];
        } else {
            last_move_2 = beats[s[i]];
            total_2 += 1;
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}