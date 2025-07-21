#include <bits/stdc++.h>
using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    ll wins = 0;
    char lastMove = '.';
    bool canWin = true;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] != lastMove) {
            if (canWin) {
                ++wins;
                canWin = false;
            } else {
                canWin = true;
            }
        } else {
            canWin = !canWin;
        }
        lastMove = s[i];
    }
    
    cout << wins << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}