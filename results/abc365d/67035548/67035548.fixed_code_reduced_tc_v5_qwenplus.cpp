#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // dp[i][last] = maximum sequences ending at i with last gesture being 'last'
    // We only need previous state, so use two arrays
    map<char, int> prev_dp, curr_dp;

    for (int i = 0; i < n; i++) {
        curr_dp.clear();
        char current = s[i];
        char winner = win(current);

        // Option 1: Start new sequence with the winning move
        curr_dp[winner] = 1;

        // Option 2: Extend existing sequences
        for (auto &[last_char, count] : prev_dp) {
            // We can always start a new sequence with winner
            curr_dp[winner] = max(curr_dp[winner], count + 1);

            // Or continue with same winner if it matches
            if (winner == last_char) {
                curr_dp[winner] = max(curr_dp[winner], count);
            }
        }

        prev_dp = curr_dp;
    }

    int ans = 0;
    for (auto &[k, v] : prev_dp) {
        ans = max(ans, v);
    }

    cout << ans << endl;
}