#include<bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> PII;
const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> s(n + 10);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i]; // Corrected index to calculate prefix sum correctly
    }
    map<int, int> mp;
    ll ans = 0, L = s[n];
    for (int i = 1; i <= n; i++) {
        ans += mp[(L - s[i] + M) % M]; // Corrected calculation of target value
        mp[s[i] % M]++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}