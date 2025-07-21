#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string S;
    cin >> N >> S;

    vector<int> count(3); // Count of 'P', 'R', 'S'
    for (char c : S) {
        count[c - 'P']++;
    }

    int ans = 0;
    int min_count = *min_element(count.begin(), count.end());
    
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'P') {
            if (count[1] > 0) { // Can pair with 'R'
                ans += count[1];
                count[1]--;
            } else if (count[2] > 0) { // Can pair with 'S'
                ans += count[2];
                count[2]--;
            }
        } else if (S[i] == 'R') {
            if (count[2] > 0) { // Can pair with 'S'
                ans += count[2];
                count[2]--;
            } else if (count[0] > 0) { // Can pair with 'P'
                ans += count[0];
                count[0]--;
            }
        } else if (S[i] == 'S') {
            if (count[0] > 0) { // Can pair with 'P'
                ans += count[0];
                count[0]--;
            } else if (count[1] > 0) { // Can pair with 'R'
                ans += count[1];
                count[1]--;
            }
        }
    }

    cout << ans / 2 << '\n'; // Each pairing is counted twice
    return 0;
}