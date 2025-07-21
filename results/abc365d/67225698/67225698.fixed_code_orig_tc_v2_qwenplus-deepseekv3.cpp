#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    int cnt = 1;
    vector<int> segments;
    
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            cnt++;
        } else {
            segments.push_back(cnt);
            cnt = 1;
        }
    }
    segments.push_back(cnt);
    
    for (int seg : segments) {
        ans += seg / 2;
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