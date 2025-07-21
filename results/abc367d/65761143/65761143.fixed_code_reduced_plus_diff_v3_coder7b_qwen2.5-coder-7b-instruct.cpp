#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, mod; cin >> n >> mod;
    vector<ll> arr(n);
    for(auto &a : arr) cin >> a, a %= mod;

    ll sum = accumulate(arr.begin(), arr.end(), 0LL) % mod;
    if(sum == 0) {
        cout << -1 << "\n";
        return 0;
    }

    unordered_map<ll, ll> mp;
    mp[0] = 1;
    ll res = 0, pre = 0;
    for(auto &a : arr) {
        pre = (pre + a) % mod;
        res += mp[(pre - sum + mod) % mod];
        mp[pre]++;
    }
    
    cout << res << "\n";

    return 0;
}