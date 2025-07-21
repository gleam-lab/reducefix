#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

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

    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i};
    }

    sort(all(candidates));

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll target = candidates[i].first;
        int rank = i;
        ll remaining = k - pref[n];

        if (rank >= n - m) {
            ans[candidates[i].second] = 0;
            continue;
        }

        ll needed = 0;
        for (int j = rank + 1; j < n; ++j) {
            needed += max(0LL, candidates[j].first - target + 1);
        }

        if (needed <= remaining) {
            ans[candidates[i].second] = needed;
        } else {
            ans[candidates[i].second] = -1;
        }
    }

    for (auto x : ans) cout << x << " ";
    return 0;
}