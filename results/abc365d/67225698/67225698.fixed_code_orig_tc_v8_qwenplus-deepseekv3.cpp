#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> groups;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
        } else {
            groups.push_back(cnt);
            cnt = 1;
        }
    }
    groups.push_back(cnt);
    
    int ans = 0;
    for (int len : groups) {
        ans += len / 2;
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}