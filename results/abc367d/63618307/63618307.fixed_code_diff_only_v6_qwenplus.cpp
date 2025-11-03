#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> s(n + 1);
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        s[i + 1] = (s[i] + a[i]) % M;
    }
    
    map<int, int> mp;
    ll ans = 0;
    mp[0] = 1; // empty prefix has sum 0
    
    for (int i = 0; i < n; i++) {
        int r = s[i + 1]; // prefix sum mod M
        // We want s[j] ≡ s[i+1] (mod M) so that subarray sum is divisible by M
        ans += mp[r];
        mp[r]++;
    }
    
    cout << ans << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}