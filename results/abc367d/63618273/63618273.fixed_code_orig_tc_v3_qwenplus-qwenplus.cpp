#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    // Prefix sum array
    vector<ll> s(n + 2);
    for (int i = 1; i <= n; ++i) {
        s[i] = (s[i - 1] + a[i]) % M;
    }

    map<ll, ll> cnt;
    ll ans = 0;
    cnt[0] = 1; // Handle subarrays starting from index 0

    for (int i = 1; i <= n; ++i) {
        ans += cnt[s[i]]++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}