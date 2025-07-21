#include <bits/stdc++.h>
using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 1; // Initialize count to 1 for the first character
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2; // Add the number of pairs formed by the current group
            cnt = 1; // Reset count for the new group
        }
    }
    ans += (cnt + 1) / 2; // Add the last group's pairs
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}