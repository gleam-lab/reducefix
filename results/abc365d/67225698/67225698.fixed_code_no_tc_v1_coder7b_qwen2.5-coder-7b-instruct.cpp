#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int win = 0;
    char last_played = '?';
    
    for (char c : s) {
        if (c != last_played) {
            ++win;
            last_played = c;
        }
    }
    
    cout << win << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}