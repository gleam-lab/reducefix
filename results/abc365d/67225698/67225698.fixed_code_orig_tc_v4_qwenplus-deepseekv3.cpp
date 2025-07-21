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
    
    int patches = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == 'R') {
            i++;
            continue;
        }
        // Found a 'P', need to patch
        patches++;
        // Patch covers current position and next 2 positions
        i += 3;
    }
    cout << patches << "\n";
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