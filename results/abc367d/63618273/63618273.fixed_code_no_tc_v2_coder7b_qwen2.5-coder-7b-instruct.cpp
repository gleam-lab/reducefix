#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 10), s(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    s[1] = a[1];
    for (int i = 2; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    map<int, int> mp;
    ll ans = 0, L = s[n];
    for (int i = 1; i <= n; i++) {
        ans += mp[(s[i] - L % M + M) % M];
        ans += mp[s[i] % M]++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}