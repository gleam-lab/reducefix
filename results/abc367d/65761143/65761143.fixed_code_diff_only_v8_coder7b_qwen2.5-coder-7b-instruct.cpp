#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    
    ll sum = 0;
    for(auto &x : a) {
        cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }
    
    ll res = 0;
    unordered_map<ll, int> mp;
    mp[0] = 1;
    ll pre = 0;
    for(auto x : a) {
        pre = (pre + x) % m;
        res += mp[(pre * 2 - sum + m) % m];
        mp[pre]++;
    }
    
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int T = 1;
    cin >> T;
    while(T--) solve();
    
    return 0;
}