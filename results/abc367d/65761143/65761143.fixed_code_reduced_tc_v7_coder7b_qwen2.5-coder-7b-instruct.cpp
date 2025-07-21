#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);

    int sum = 0;
    for(auto &x : a) {
        cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int pre = 0;
    for(auto x : a) {
        pre = (pre + x) % m;
        res += mp[(pre - sum + m) % m];
        mp[pre]++;
    }

    cout << res << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}