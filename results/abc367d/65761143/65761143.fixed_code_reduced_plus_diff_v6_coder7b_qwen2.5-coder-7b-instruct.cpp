#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL modpow(LL base, LL exp, LL mod) {
    LL result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<LL> a(n);
    LL sum = 0;
    for (auto& x : a) {
        cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    LL res = 0;
    unordered_map<LL, int> mp;
    mp[0] = 1;
    LL pre = 0;
    for (const auto& x : a) {
        pre = (pre + x) % m;
        res += mp[(pre - sum + m) % m];
        res += mp[pre];
        mp[pre]++;
    }
    
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}