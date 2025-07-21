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
    
    int changes = 0;
    for (int i = 1; i < n; ) {
        if (s[i] == s[i-1]) {
            changes++;
            // Skip the next character to prevent overlapping changes
            i += 2;
        } else {
            i++;
        }
    }
    cout << changes << "\n";
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