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

    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i};
    }

    sort(candidates.begin(), candidates.end());

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    vector<ll> ans(n, -1);

    for (int i = 0; i < n; ++i) {
        ll required = 0;
        for (int j = i + 1; j < n; ++j) {
            if (candidates[j].first > candidates[i].first) {
                required += candidates[j].first - candidates[i].first;
            }
        }

        if (required > k) continue;

        ll x = (k - required) / (n - i - 1);
        if ((k - required) % (n - i - 1)) ++x;

        if (x >= candidates[i].first) {
            ans[candidates[i].second] = 0;
        } else {
            ans[candidates[i].second] = candidates[i].first - x;
        }
    }

    for (auto x : ans) cout << x << " ";

    return 0;
}