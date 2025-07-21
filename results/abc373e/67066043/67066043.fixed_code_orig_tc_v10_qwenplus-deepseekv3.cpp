#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (m == n) {
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
        return 0;
    }

    vector<ll> ans(n, -1);
    vector<pair<ll, int>> sorted_a;
    for (int i = 0; i < n; i++) {
        sorted_a.emplace_back(a[i], i);
    }
    sort(all(sorted_a));

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + sorted_a[i].first;
    }

    for (int i = 0; i < n; i++) {
        ll current = sorted_a[i].first;
        int idx = sorted_a[i].second;
        ll required = 0;

        int left = 0, right = k;
        ll best = -1;
        while (left <= right) {
            ll mid = (left + right) / 2;
            ll new_votes = current + mid;

            auto it = upper_bound(all(sorted_a), make_pair(new_votes, n));
            int count = n - (it - sorted_a.begin());
            if (count < m) {
                best = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (best != -1 && best <= k) {
            ans[idx] = best;
        } else {
            ans[idx] = -1;
        }
    }

    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}