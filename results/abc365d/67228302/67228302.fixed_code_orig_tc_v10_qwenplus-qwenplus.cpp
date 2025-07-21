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

    // We'll keep track of the length of the current non-overlapping sequence
    vector<int> dp(n, 1);  // dp[i] = length of optimal sequence ending at i
    vector<int> last_move(3, -1); // last_move[0] = last index where 'R' was used, etc.

    // Maps move to index: R -> 0, P -> 1, S -> 2
    auto move_to_idx = [](char c) {
        return (c == 'R') ? 0 : (c == 'P') ? 1 : 2;
    };

    for (int i = 0; i < n; ++i) {
        char curr = s[i];
        char beat = beats[curr];

        // For current character, we can extend any sequence that doesn't end with its beat
        for (int j = 0; j < 3; ++j) {
            if (j != move_to_idx(beat) && last_move[j] != -1) {
                dp[i] = max(dp[i], dp[last_move[j]] + 1);
            }
        }

        // Update the last occurrence of current move
        last_move[move_to_idx(curr)] = i;
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}