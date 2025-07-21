#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int cnt = 1;
    vector<int> blocks;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
        } else {
            blocks.push_back(cnt);
            ans += cnt / 2;
            cnt = 1;
        }
    }
    blocks.push_back(cnt);
    ans += cnt / 2;
    
    if (blocks.size() >= 3) {
        bool has_long_block = false;
        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i] >= 2) {
                has_long_block = true;
                break;
            }
        }
        if (has_long_block) {
            ans = max(ans - 1, 0);
        }
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