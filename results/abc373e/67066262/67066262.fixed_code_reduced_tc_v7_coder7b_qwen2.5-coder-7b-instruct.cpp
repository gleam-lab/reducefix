#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= k / (n - m)) {
            ans[ord[i]] = 0;
            continue;
        }

        ll needed = 0;
        for (int j = 0; j < n - m; ++j) {
            needed += a[(i + j + 1) % n];
        }

        if (needed <= k) {
            ans[ord[i]] = k - needed;
        }
    }

    for (auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}