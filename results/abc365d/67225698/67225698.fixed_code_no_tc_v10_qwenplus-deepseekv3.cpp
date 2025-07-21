#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int cnt = 0;
    vector<int> v;
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] == s[i - 1]) {
            cnt++;
        } else {
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);
    
    for (int i = 0; i < v.size(); i++) {
        ans += v[i] / 2;
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}