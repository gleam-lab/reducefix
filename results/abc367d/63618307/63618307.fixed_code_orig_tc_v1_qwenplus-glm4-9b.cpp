#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 10);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> s(n + 10);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
        if (s[i + 1] < 0) s[i + 1] += mod;  // Handle negative prefix sums
    }
    map<int, int> mp;
    ll ans = 0, L = s[n];
    for (int i = 0; i < n; i++) {
        // Use modulo L to avoid negative numbers in map keys
        ll t = (s[i] - L + mod) % mod;
        if (t < 0) t += mod;  // Adjust for cases where subtraction might result in negative
        ans += mp[t];
        mp[t]++;
    }
    cout << ans;
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