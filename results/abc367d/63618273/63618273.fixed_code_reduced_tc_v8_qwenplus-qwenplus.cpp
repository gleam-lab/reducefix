#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

void solve() {
    int n, M;
    cin >> n >> M;
    vector<ll> a(n + 2);  // Use ll to prevent overflow
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> prefix(n + 2);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % M;
    }

    map<ll, ll> freq;
    ll ans = 0;

    // We want to count number of pairs (i, j) where (prefix[j] - prefix[i]) % M == 0
    // That is equivalent to counting how many times each remainder has occurred
    for (int i = 0; i <= n; ++i) {
        ans += freq[prefix[i]];
        freq[prefix[i]]++;
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