#include <bits/stdc++.h>
using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < n - 1; ) {
        if (s[i] == s[i + 1]) {
            ans++;
            i += 2; // Skip the next character to avoid overlapping pairs
        } else {
            i++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}