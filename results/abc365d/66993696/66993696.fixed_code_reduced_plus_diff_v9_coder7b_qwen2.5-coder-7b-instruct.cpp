#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> cnt(3), last(3, -1);
    int ans = 0, cur = 0;
    
    for (int i = 0; i < n; ++i) {
        int t = s[i] - 'A';
        if (last[t] != -1) {
            cur -= cnt[(t + 1) % 3] + cnt[(t + 2) % 3];
        }
        cnt[t]++;
        cur += cnt[(t + 1) % 3] + cnt[(t + 2) % 3];
        ans = max(ans, cur);
        last[t] = i;
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}