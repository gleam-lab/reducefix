#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

void solve() {
    int n;
    ll M;
    cin >> n >> M;
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<ll> s(n + 2);
    for (int i = 1; i <= n; ++i) {
        s[i] = (s[i - 1] + a[i]) % M;
    }

    map<ll, ll> cnt;
    ll ans = 0;
    cnt[0] = 1; // To handle subarrays starting from index 0

    for (int i = 1; i <= n; ++i) {
        ans += cnt[s[i]]++;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}