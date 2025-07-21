#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n == 0) {
        cout << "0\n";
        return;
    }
    
    int ans = 0;
    int cnt = 1; // At least one character
    
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            ++cnt;
        } else {
            ans += cnt / 2; // Each pair contributes one pattern
            cnt = 1;
        }
    }
    ans += cnt / 2;
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}