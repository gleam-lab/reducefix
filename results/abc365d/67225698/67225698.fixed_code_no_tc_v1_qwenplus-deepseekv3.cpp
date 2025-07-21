#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int changes = 0;
    
    for (int i = 1; i < n; ) {
        if (s[i] == s[i-1]) {
            changes++;
            // We need to skip the next character because changing the current one
            // already fixes the adjacent duplicates for the next pair
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